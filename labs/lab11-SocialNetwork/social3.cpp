/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: lab11C

Impements a Network class storing an array of Profiles and 
providing methods to lookup and add profiles
as well as methods adding following functionality among network members

*/

#include <iostream>
#include <string>
#include <cctype>

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
	fullName += "(@" + username + ")";
	return fullName;
}

void Profile::setDisplayName(string dspn){
	displayname = dspn;
}

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
};

//implementations for network

Network::Network(): numUsers{}, following{}{}//list-initialize

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

int main(){
	 Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}