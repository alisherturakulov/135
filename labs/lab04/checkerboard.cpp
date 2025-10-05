/*
Author: Alisherjon Turakulov
Course: CSCI 135
Instructor: Tong Yi
Assignment: Lab4B

takes in two integers, a width and height, and outputs a 
checkerboard pattern of asteriscks with those dimensions
*/

#include <iostream>
#include <string>

int main(){
	//take inputs for width and height
	int width;
	int height;
	std::cout << "Input width: ";
	std::cin >> width;
	std::cout << "Input height: ";
	std::cin >> height;
	
	//print the checlerboard
	for(int i= 0; i< height; i++){
		for(int j =0; j< width; j++){
			//if even row put spaces after each asterisk
			if(i % 2 ==0){
				std::cout << "* ";
			}else{
			//spaces before each asterisk for odd rows
				std::cout << " *";
			}
		}
		std::cout << '\n';
	}
	
	return 0;
}