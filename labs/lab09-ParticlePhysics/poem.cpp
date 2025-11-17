/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: Lab 9D

completes the dynamic memory allocation process by adding deallocation using delete
so that the program doesnt run out of memory and crash
*/

#include <iostream>
using namespace std;

string * createAPoemDynamically() {
    string *p = new string;
    *p = "Roses are red, violets are blue";
    return p;
}

int main() {
    while(true) {
        string *p;
        p = createAPoemDynamically();

        // assume that the poem p is not needed at this point
		delete p; //deallocates memory allocated by function call

    }
}
