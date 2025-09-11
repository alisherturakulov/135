/*
Author: Alisherjon Turakulov
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab1A

The program takes in two integer inputs and prints the smaller number.
*/
// 08/27
#include <iostream>

using namespace std;

int main(){
    int x, y;

    cout << "Enter the first number: ";
    cin >> x;
    cout << "Enter the second number: ";
    cin >> y;

    if(x > y){
        cout << "The smaller number is " << y;
    }else if(y > x){
        cout << "The smaller number is " << x;
    }else{
        cout << "The numbers " << x << " and " << y << " are equal!";
    }

    return 0;
}