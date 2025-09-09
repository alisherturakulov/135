/*
Author: Alisherjon Turakulov
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab2B

Accepts two integers, L and U, and prints all the integers 
separated by spaces in the interval [L, U); inclusive of L and exclusive of U. 
*/

#include <iostream>

int main(){
    int L{}, U{};
    std::cout << "Please enter L: ";
    std::cin >> L;
    std::cout << "Please enter U: ";
    std::cin >> U;
    
    for(int i=L; i < U; i++){
        if(i == L){
            std::cout << i;
        }else{
            std::cout << " " << i;
        }
    }
    std::cout << std::endl;
    return 0;
}