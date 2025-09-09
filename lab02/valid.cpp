/*
Author: Alisherjon Turakulov
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab2A

Asks for a number input and keeps reasking if the number n doesn't statisfy 0 < n < 100 
Once a valid n is obtained, print the square of n.
*/

#include <iostream>

int main(){
    int n{};//initialize n
    std::cout << "Please enter an interger: ";
    std::cin >> n; //initially acept n
    while(!(n > 0 && n < 100)){//while loop until valid input received
        std::cout << "Please reenter the number: ";
        std::cin >> n;
    }
    
    std::cout<< n*n << std::endl; //print to stdout n^2
    return 0; //siginify successful execution
}