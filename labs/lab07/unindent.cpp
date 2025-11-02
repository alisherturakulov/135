/*
Author: Alisherjon Turakulov
Course: cs 135
Instructor: Tong Yi
Assignment: Lab 7A

reads from cin and prints each line with the leading whitespace removed
*/

#include <iostream>
#include <string>
#include <cctype>

//function to remove leading ws
std::string removeLeadingSpaces(std::string line);


int main(){
	std::string line{};
	while(getline(std::cin, line)){
		std::string unindented = removeLeadingSpaces(line);
		std::cout << unindented << '\n';
	}
	return 0;
}


//removes leading ws from a line
//@param line, a string with one line of code
//@reutrn the unindented string
std::string removeLeadingSpaces(std::string line){
	std::string unindented{};
	for(int i =0; i<line.length(); ++i){
		if(!std::isspace(line[i])){
			unindented = line.substr(i);
			i = line.length();
		}
	}
	
	return unindented;
}