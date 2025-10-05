/*
Author: Alisherjon Turakulov
Course: CSCI 135
Instructor: Tong Yi
Assignment: Lab 4E

takes in an integer length as input, and returns the upper half 
of a sqaure made with length asterisks per side
*/

#include <iostream>
#include <string>

int main(){
	int side{};
	std::cout << "Input side length: ";
	std::cin >> side;
	std::cout << "\nShape:\n";
	
	//prints when the column is greater than or equal to the row
	for(int i=0; i < side; ++i){
		for(int j=0; j<side; ++j){
			if(j >= i){
				std::cout <<"*";
			}else{
				std::cout << " ";
			}
		}
		std::cout <<'\n';
	}
	
	return 0;
}