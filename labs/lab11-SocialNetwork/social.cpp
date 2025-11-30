/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: lab11A

Impements a class Profile storing data members full name and display name
and implementing accessor and modifier methods.
*/

#include <iostream>
#include <string>

using namespace std;
//declaration
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



int main(){
	Profile p1("marco", "Marco");
    cout << p1.getUsername() << endl; 
    cout << p1.getFullName() << endl; 

    p1.setDisplayName("Marco Rossi");
    cout << p1.getUsername() << endl; 
    cout << p1.getFullName() << endl; 

    Profile p2("tarma1", "Tarma Roving");
    cout << p2.getUsername() << endl; 
    cout << p2.getFullName() << endl; 
}
//example didn't include a return 0
//implementations

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