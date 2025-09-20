/*
Author: Alisherjon Turakulov
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab1C

The program takes in an integer input (year) and prints whether it is a leap year or common year.
*/

#include <iostream>

using namespace std;

int main(){
    int x;//declare int x
    cout << "Enter the year: ";
    cin >> x;

    if(x % 4 != 0){ //not divisible by 4; Common
        cout << "Common Year";
    }else if(x % 100 != 0){ //divisible by 4 and not a century; Leap
        cout << "Leap Year";
    }else if(x % 400 == 0){ //divisble by 400 and century; leap
        cout << "Leap Year";
    }else{
        cout << "Common Year";
    }
}