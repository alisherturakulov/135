/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: Lab 4G

take in a width and height and print a checkerboard of 3x3
squares with that width and height using asterisks without needing
dimensions to be multiples of 3.
*/

#include <iostream>
#include <string>

int main(){
	//take inputs
	int width{};
	std::cout << "Input width: ";
	std::cin >> width;
	int height{};
	std::cout << "Input height: ";
	std::cin >> height;
	std::cout << "\nShape:\n";
	
	//print checkerboard pattern
	for(int i=0; i< height; ++i){
		for(int j=0; j<width; ++j){
			if((i / 3) % 2 == 0){
				if((j / 3) % 2 == 0){
					std::cout << "*";
				}else{
					std::cout << " ";
				}
			}else{
				if((j /3) % 2 == 1){
					std::cout << "*";
				}else{
					std::cout << " ";
				}
			}
		}
		std::cout << '\n';
	}
	
	
	return 0;
}