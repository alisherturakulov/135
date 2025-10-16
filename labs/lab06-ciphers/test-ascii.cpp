/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assingment: Lab6A

Given a line of text, prints each char in the line and its ascii value on a separate line.
*/

#include <iostream>
#include <string>

int main(){
    std::string line;
    std::cout << "Input: ";
    std::getline(std::cin, line);

    for(char& ch : line){
        std::cout << ch << " " << (int)ch << '\n';
    }

    return 0;
}