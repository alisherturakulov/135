/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: Lab 12B

implements a functions goodVibes that takes a vector<int> and returns
a vector<int> with the positive integers in the same order from the parameter
*/

#include <iostream>
#include <string>
#include <vector>


//returns a vector with the positive ints in the same order given a vector
std::vector<int> goodVibes(const std::vector<int>& v){
	std::vector<int> poss;
	for(int i{}; i<v.size(); ++i){
		if(v.at(i) >= 0){
			poss.push_back(v.at(i));
		}
	}
	
	return poss;
}

int main(){
	std::vector<int> test1 = goodVibes({0, 1, 2, 3, -1, 5});
	
	for(int i{}; i<test1.size(); ++i){
		std::cout << test1.at(i) << " ";
		
	}
	return 0;
}