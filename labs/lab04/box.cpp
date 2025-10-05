/*
Author: Alisherjon Turakulov
Course: CSCI 135
Instructor: Tong Yi
Assignment: Lab 4A

takes two integers: a width, and a height. Returns a rectanglular
box of that size using asterisks
*/

#include <iostream>
#include <string>

int main(){
	int width;
	int height;
	std::cout << "Input width: ";
	std::cin >> width;
	std::cout << "Input height: ";
	std::cin >> height;
	std::cout << "\nShape:\n";
	
	for(int i =0; i < height; i++){
		for(int j =0; j<width; j++){
			std::cout << "*";
		}
		std::cout<<"\n";
	}
	

	return 0;
}