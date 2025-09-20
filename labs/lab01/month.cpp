/*
Author: Alisherjon Turakulov
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab1D

Takes in two integers (year and month), and returns the number days in the month taking into account leap years.
*/


#include <iostream>

using namespace std;

int main(){
    int y, m;
    bool leap = false;
    cout << "Enter year: ";
    cin >> y;
    cout << "Enter month: ";
    cin >> m;

    //use leap year checker form 1C on y
    if(y % 4 != 0){ // Common
        
        //removed print 
    }else if(y % 100 != 0){ // Leap
        leap = true;
    }else if(y % 400 == 0){ // leap
        leap = true;
    }else{
       //remove print
    }
//odd = 30 except feb 28/29
//even month = 31 
//above only if month less than or equal to 7 
// if month above or qual  to 8 even =31 odd 30
    if(m <= 7){
        if(leap && m == 2){
            cout << 29 << " days";
        }else if(!leap && m ==2){
            cout << 28 << " days";
        }else if(m % 2 == 0){
            cout << 30 << " days";
        }else{
            cout << 31 << " days";
        }
    }else if(m >= 8){
        if(m % 2 ==0){
            cout << 31 << " days";
        }else {
            cout << 30 << " days";
        }
    }

}