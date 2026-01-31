/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: Lab 12C

implements a function that takes two vectors, appends the elements of the second to the first, and leaves the second empty
*/

#include <iostream>
#include <string>
#include <vector>

//takes two vector<int> objects by reference, appends the second vector onto the first, and leaves the second empty.
//@params goku, vegeta, vector<int> passed by reference
void gogeta(std::vector<int> &goku, std::vector<int> &vegeta){//I've only watched the first 5 episodes of the original dragon ball
	for(int i{}; i<vegeta.size(); ++i){
		goku.push_back(vegeta.at(i));
	}
	vegeta.clear();
}

int main(){
	std::vector<int> test1{0, 1, 2, 3, 4, 5, 6, 7};
	std::vector<int> test2{8, 9};
	
	gogeta(test1, test2);
	
	for(int i{}; i< test1.size(); ++i){
		std::cout << test1.at(i) << " ";
		
	}
	std::cout << "\nsize of second: " << test2.size()<< std::endl;
	return 0;
}