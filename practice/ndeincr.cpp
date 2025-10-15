/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assingment: E3.5

Takes in a sequence of three numbers, returns whether they are (strictly) increasing, decreasing, or neither.
*/

#include <iostream>
#include <string>

int main(){
	//take in values for s t u
	int s, t, u;
	std::cout << "Enter sequence of integers: ";
	std::cin >> s >> t >> u;
	
	//this ase checks s < u as well as strictly increasing / descreasing
	if(s < t && t < u){
		std::cout << "Increasing\n";
	}else if(s > t && t > u){
		std::cout << "Decreasing\n";
	}else{
		std::cout << "Neither\n";
	}
	
	return 0;
}
