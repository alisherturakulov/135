/*
Author: Alisherjon Turakulov
Course: cs 135
Instructor: Tong Yi
Assignment: Lab 7B

reads from cin and prints the lines with corrected indentation using
a count of the curly braces.

*/

#include <iostream>
#include <string>
#include <cctype>

//function to remove leading ws
std::string removeLeadingSpaces(std::string line);

int countChar(std::string line, char c);

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

//return the number of occurences of char in line
//@param string line; line of code
//@param char c, char to count
//@return number of occurences of char in line
int countChar(std::string line, char c){
	int count{};
	for(char& ch: line){
		if(ch == c){
			++count;
		}
	}
	
	return count;
}