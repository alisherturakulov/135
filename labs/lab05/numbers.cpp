/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assingnment: Lab5A

Takes two integers, n and d. Prints whether n is divisible by d.
*/

#include <iostream>
#include <string>

//short circuit if d is zero
bool isDivisibleBy(int n, int d){
    return d != 0 && n % d ==0;
}

int main(){
    int n{};
    int d{};
    std::cout << "Enter number to divide: ";
    std::cin >> n;
    std::cout << "Enter divisor: ";
    std::cin >> d;


    //print result of division
    if(isDivisibleBy(n, d) ){
        std::cout << "Yes\n";
    }else{
        std::cout <<"No\n";
    }

    return 0;
}