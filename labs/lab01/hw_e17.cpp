/*
Author: Alisherjon Turakulov
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW_E1.7

Takes in three names and prints them out, one line each.
*/
//remooved cout prompts due to errors Try 1
#include <iostream>

using namespace std;

int main(){
    std::string a{}, b{}, c{}; //initialize three strings
    //cout<< "Enter the first name: "; //ask for a name
    cin >> a; //store input into std::string a
    //cout << "Enter the second name: "; //same but for next name
    cin >> b;
    //cout << "Enter the third name: ";
    cin >> c; 
    //output all names at once using newline escape character
    cout << a << "\n" << b << "\n" << c << endl;  //added endl Try 2
    
    return 0;
}