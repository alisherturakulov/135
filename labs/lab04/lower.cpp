/*
Author: Alisherjon Turakulov
Course: CSCI 135
Instructor: Tong Yi
Assignment: Lab 4D

takes an integer side length as input, and prints the bottom left of a
right triangle with that many asterisks on each side
*/

#include <iostream>
#include <string>

int main(){
	int side{};
	std::cout << "Input side length: ";
	std::cin >> side;
	std::cout << "\nShape:\n";
	
	//only print when the column is less than or equal to the row
	for(int i = 0; i<side; ++i ){
		for(int j=0; j< side; ++j){
			if(j <= i){
				std::cout << "*";
			}
		}
		std::cout <<'\n';
	}
	return 0;
}