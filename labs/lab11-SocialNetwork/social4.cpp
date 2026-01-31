/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: lab11D

Impements a Network class storing an array of Profiles and 
providing methods to lookup and add profiles
as well as methods adding following functionality among network members
adds posting funcitonality with a Post struct member and methods.
*/

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

class Profile {
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn): username{usrn}, displayname{dspn}{};
    // Default Profile constructor (username="", displayname="")
    Profile(): username{}, displayname{}{};
    // Return username
    string getUsername();
    // Return name in the format: "displayname (@username)"
    string getFullName();
    // Change display name
    void setDisplayName(string dspn);
};

//implementations for profile
string Profile::getUsername(){
	return username;
}

string Profile::getFullName(){
	string fullName = "";
	fullName += displayname;
	fullName += " (@" + username + ")";
	return fullName;
}

void Profile::setDisplayName(string dspn){
	displayname = dspn;
}


struct Post{
  string username;
  string message;
};

class Network {
private:
  static const int MAX_USERS = 20; // max number of user profiles
  int numUsers;                    // number of registered users
  Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile
  bool following[MAX_USERS][MAX_USERS];  // friendship matrix:
  // following[id1][id2] == true when id1 is following id2
 
  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  int findID (string usrn);
  
   static const int MAX_POSTS = 100;
   int numPosts;                    // number of posts
   Post posts[MAX_POSTS];           // array of all posts
 
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network();
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(string usrn, string dspn);
  // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
 // return true if success (if both usernames exist), otherwise return false
 bool follow(string usrn1, string usrn2);

 // Print Dot file (graphical representation of the network)
 void printDot();
 
  // Add a new post
 bool writePost(string usrn, string msg);
 // Print user's "timeline"; posts by them or people they follow
 bool printTimeline(string usrn);
};

//implementations for network

Network::Network(): numUsers{}, following{}, numPosts{}{}//list-initialize

int Network::findID(string usrn){
	for(int i{}; i<numUsers; ++i){
		if(profiles[i].getUsername() == usrn){
			return i;
		}
	}
	return -1;
}

bool Network::addUser(string usrn, string dspn){
	if(numUsers == MAX_USERS || usrn == "" || findID(usrn) != -1){
		return false;
	}
	for(char& ch : usrn){
		if(!isalnum(ch)){
			return false;
		}
	}
	Profile nUser(usrn, dspn);
	profiles[numUsers] = nUser;
	++numUsers;
	return true;
}

bool Network::follow(string usrn1, string usrn2){
	int id1 = findID(usrn1);
	int id2 = findID(usrn2);
	if(id1 != -1 && id2 != -1){
		return following[id1][id2] = true;
	}
	return false;
}

void Network::printDot(){
	std::cout << "digraph {\n";
	for(int i{}; i<numUsers; ++i){
		cout << "\t\"@" << profiles[i].getUsername() << "\"\n";
	}
	
	for(int i{}; i<numUsers; ++i){
		for(int j{}; j<numUsers; ++j){
			if(following[i][j]){
				std::cout << "\t\"@" << profiles[i].getUsername() << "\" -> \"@" << profiles[j].getUsername() << "\"\n";
			}
		}
	}
	std::cout << "}\n";
}

bool Network::writePost(string usrn, string msg){
	if(numPosts < MAX_POSTS){
		Post nPost{usrn, msg};
		posts[numPosts] = nPost;
		numPosts++;
		return true;
	}
	return false;
}

bool Network::printTimeline(string usrn){
	bool hasPosts{};
	for(int i{min(numPosts, MAX_POSTS-1)}; i >= 0; --i){
		string postUser = posts[i].username;
		int idUser = findID(usrn);
		int idPost = findID(postUser);
		if(postUser == usrn){
			if(idUser != -1){
				hasPosts= true;
				std::cout << profiles[idUser].getFullName() << ": " << posts[i].message << '\n';
			}
		}else if( idUser != -1 && idPost != -1 && following[idUser][idPost]){
			hasPosts = true;
			std::cout << profiles[idPost].getFullName() << ": " << posts[i].message << '\n';
		}
	}
	return hasPosts;
}


int main(){
	Network nw;
  // add three users
  nw.addUser("mario", "Mario");
  nw.addUser("luigi", "Luigi");
  nw.addUser("yoshi", "Yoshi");
   
  nw.follow("mario", "luigi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");

  // write some posts
  nw.writePost("mario", "It's a-me, Mario!");
  nw.writePost("luigi", "Hey hey!");
  nw.writePost("mario", "Hi Luigi!");
  nw.writePost("yoshi", "Test 1");
  nw.writePost("yoshi", "Test 2");
  nw.writePost("luigi", "I just hope this crazy plan of yours works!");
  nw.writePost("mario", "My crazy plans always work!");
  nw.writePost("yoshi", "Test 3");
  nw.writePost("yoshi", "Test 4");
  nw.writePost("yoshi", "Test 5");

  cout << endl;
  cout << "======= Mario's timeline =======" << endl;
  nw.printTimeline("mario");
  cout << endl;

  cout << "======= Yoshi's timeline =======" << endl;
  nw.printTimeline("yoshi");
  cout << endl;
}