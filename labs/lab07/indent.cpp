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
	std::string line;
	int numBraces = 0;
	while(getline(std::cin, line)){
		std::string unindented = removeLeadingSpaces(line);
		std::string indented = unindented;
		int countOpen = countChar(indented, (char) 123);
		int countClose = countChar(indented, (char) 125);
		if(indented[0] == '}'){
			--numBraces;
		}
		//subtract from braces if theres a closing brace
		
		//add 1 tab for each open brace
		for(int i = 0; i<numBraces; ++i){
			indented = '\t' + indented;
		}
		
		if(countOpen >= countClose){
			numBraces += countOpen - countClose;
		}
		//to prevent double counting closing braces
		if(unindented[0] == '}' && countOpen == countClose){
			++numBraces;
		}
		
		//increment for future indents
		
		
		std::cout << indented << '\n';
	}
	
	return 0;
}


//removes leading ws from a line
//@param line, a string with one line of code
//@reutrn the unindented string
std::string removeLeadingSpaces(std::string line){
	std::string unindented;
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
	int count=0;
	for(int i=0; i<line.length(); ++i){
		if(line[i] == c){
			++count;
		}
	}
	
	return count;
}