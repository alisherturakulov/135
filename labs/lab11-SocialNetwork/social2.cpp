/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: lab11B

Impements a Network class storing an array of Profiles and 
providing methods to lookup and add profiles
*/

#include <iostream>
#include <string>

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

  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  int findID (string usrn);
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network();
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(string usrn, string dspn);
};

//implementations for network

Network::Network(): numUsers{}{}

int Network::findID(string usrn){
	for(int i{}; i<numUsers; ++i){
		if(profiles[i].getUsername() == usrn){
			return i;
		}
	}
	return -1;
}

bool Network::addUser(string usrn, string dspn){
	return false;
/* 	if(usrn){
		
	}
 */}


int main(){
	Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     // true (1)
  cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

  cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
  cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
  cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

  for(int i = 2; i < 20; i++)
      cout << nw.addUser("mario" + to_string(i), 
                 "Mario" + to_string(i)) << endl;   // true (1)

  cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}
