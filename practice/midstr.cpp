/*
Author: Alisherjon Turakulov
Course: CS 135 
Instructor: Tong Yi
Assingment: E5.6

Implements a middle(str) function that takes in a string, and returns the middle character (if odd length), 
or the middle 2 characters (if even length).
*/

#include <iostream>
#include <string>

//forward declaration of funciton
std::string middle(std::string str);

int main(){
	std::string str;
	std::cout << "Input string to get the middle: ";
	std::cin >> str;
	std::string mid = middle(str);
	std::cout << "Middle: " << mid << '\n';
	
	return 0;
}

std::string middle(std::string str){
	std::string mid; //initializes to ""
	//since std::string is an object we have length() member function
	int len = str.length();
	if(len % 2 ==0){
		//tried using .at() + .at() which caused undefined character to be added (two chars fused to unknown)
		mid+= str.substr((len/2 -1), 2);
	}else{//using integer division
		mid+= str.at((len/2));
	}
	return mid;
}