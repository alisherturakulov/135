/*
Author: Alisherjon Turakulov
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab2D

Prints the first 60 fibonacci numbers, starting with f(0) = 0 and f(1) = 1
uses an int array to store and compute subsequent numbers
*/
//turns negative after f(46): 1836311903; exceeds the integer limit and wraps around

#include <iostream>

int main(){

    int fibArr[60]; //initialize int array with 60 cells
    fibArr[0]= 0; //initialize intial fib values for first two
    fibArr[1]= 1;
    std::cout << fibArr[0] << "\n"<< fibArr[1] <<std::endl;
    int fibi{};

    for(int i = 2; i<60; i++){ //calculate and assign subsequent fib numbers and add to array
        fibi = fibArr[i-1] + fibArr[i-2];
        fibArr[i] = fibi; 
        std::cout << fibArr[i] << std::endl; //print all fib numbers as they're calculated and added
    }

    return 0;
}