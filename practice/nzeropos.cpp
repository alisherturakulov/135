/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assingment: E3.1 

takes in a number and prints whether it is negative, zero, or positive.
*/

#include <iostream>
#include <string>

int main(){
	int n;
	std::cout << "Enter a number: ";
	std::cin >> n;
	//use a if else chain
	if(n > 0){
		std::cout << "Positive\n";
	}else if(n < 0){
		std::cout << "Negative\n";
	}else{
		std::cout <<"Zero\n";
	}
	
	return 0;
}
