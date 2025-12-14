/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: Lab 13AB

implements a recursive function to print numbers in a range
and a recrusive function to sum numbers in a range
*/


#include <iostream>
#include <string>

void printRange(int left, int right);
int sumRange(int left, int right);

int main(){
	
	printRange(-2, 10);
	
	int x = sumRange(1, 3);
	std::cout << "this is: " << x << '\n';
	
	x = sumRange(-2, 10);
	std::cout << "this is: " << x << '\n';
	return 0;
}

//prints numbers in the range [left, right]
void printRange(int left, int right){
	if(left <= right){//base case the left>right
		std::cout << left << " ";
		printRange(left+1, right);
	}
}

//sums the numbers in range [left, right]
int sumRange(int left, int right){
	if(left > right){
		return 0;
	}
	return left + sumRange(left+1, right);
}

