/*
Author: Alisherjon Turakulov
Course:	CS 135
Instructor: Tong Yi
Assignment: Lab12A
 
defines a function that returns a vector of n integers with the same values as their indices
and tests in the main function
*/


#include <iostream>
#include <string>
#include <vector>

//returns a vector of n ints with indices as values
std::vector<int> makeVector(int n){
	std::vector<int> list(n);
	for(int i{}; i< n; ++i){
		list.at(i) = i;
	}
	return list;
}

int main(){
	std::vector<int> test1= makeVector(5);
	for(int i{}; i<5; ++i){
		std::cout << test1[i] << " " ;
	}
	
	return 0;
}