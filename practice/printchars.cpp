/*
Author: Alisherjon Turakulov
Course: CSCI 135
Instructor: Tong Yi
Assignment: HW E4.8

take in a string and output each character in its own line
*/

#include <iostream>
#include <string>

int main(){
	std::string str;
	std::cout << "Enter word: ";
	std::cin >> str;
	
	for(int i =0; i < str.length(); i++){
		std::cout << str.at(i) << "\n";
	}
	
	return 0;
}