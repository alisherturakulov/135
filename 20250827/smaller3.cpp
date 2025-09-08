/*
Author: Alisherjon Turakulov
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab1B

The program takes three integer inputs as input and prints the smallest of the three.
*/

#include <iostream>

using namespace std;

int main(){
    int x, y, z;
    cout << "Enter the first number: ";
    cin  >> x;
    cout << "Enter the second number: ";
    cin >> y;
    cout << "Enter the third number: ";
    cin >> z;

    if(x > y){//check starting with x and y
        if(z > y){//check y
            cout << "The smaller of the three is " << y;
        }else{ //otherwise z
            cout << "The smaller of the three is " << z;
        }
    }else if(y > x){
        if(z > x){//check x
            cout << "The smaller of the three is " << x;
        }else{
            cout << "The smaller of the three is " << z;
        }
    }
    return 0;
}