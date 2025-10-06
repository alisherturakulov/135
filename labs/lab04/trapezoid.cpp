/*
Author: Alisherjon Turakulov
Course: CSCI 135
Instructor: Tong Yi
Assignment: Lab 4F

takes in integers for the width and height of an upside down
trapezoid. If the height is at most width/2 +1 then 
print the trapezoid with asterisks
*/

#include <iostream>
#include <string>
#include <cstdlib>

int main(){
	//take input
	int width;
	std::cout << "Enter width: ";
	std::cin >> width;
	int height;
	std::cout << "Enter height: ";
	std::cin >> height;
	
	
	//check that the height is reasonable with the given width
	if(((width % 2 == 0) && (height > width/2) )||( (width%2 == 1) && (height > width/2 +1))){
		std::cerr << "Impossible shape!" << std::endl;
		std::exit(1);
	}
	
	//print the shape
	std::cout << "\nShape:\n";
	for(int i =0; i< height; ++i){
		for(int j=0; j<width; ++j){
			if(j >= i && j <= width-1-i){
				std::cout << "*";
			}else{
				std::cout << " ";
			}
		}
		std::cout << '\n';
	}
	
	return 0;
}