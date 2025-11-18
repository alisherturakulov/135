/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: E6.8 Equal Arrays

Defines a function which takes two int arrays and their sizes, 
and returns true if they contain the same elements in the same order
*/

#include <iostream>
#include <string>


bool equals(int a[], int a_size, int b[], int b_size){
	if(a_size != b_size){
		return false;
	}
	
	for(int i= 0;i<a_size;++i){
		if(a[i] != b[i]){
			return false;
		}
	}
	return true;
};

int main(){
	
	int arr1[] = {1, 2, 3};
	int arr2[] = {1, 2, 3};
	std::cout << "should be true: " << equals(arr1, 3, arr2, 3) << std::endl;
	
	arr1[2] = 2;
	std::cout << "should be false: " << equals(arr1, 3, arr2, 3) << std::endl;
	return 0;
}