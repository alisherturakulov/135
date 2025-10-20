/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: E8.1 File Writing

a program that opens a opens a output fstream for 
a file "hello.txt," stores the message "Hello, World!"
in the file, closes and reopens the file to read the line 
into a string and prints the string.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> //for exit()

int main(){
	std::ofstream out_file;
	out_file.open("hello.txt");
	if(out_file.fail()){
		std::cerr << "can't open hello.txt for writing";
		std::exit(1);
	}
	out_file << "Hello, World!";
	out_file.close();//close output stream to open
	
	std::string message{};
	std::ifstream in_file;
	in_file.open("hello.txt");
	if(in_file.fail()){
		std::cerr << "can't open hello.txt for reading";
		std::exit(1);
	}
	getline(in_file, message);
	std::cout << message << '\n';
	in_file.close();
	return 0;
}