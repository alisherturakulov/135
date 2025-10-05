/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assingment: Lab4C

takes in a integer, size. and prints an x shape of asterisks
with that height
*/


#include <iostream>
#include <string>

int main(){
	//take input
	int size{};
	std::cout << "Input size: ";
	std::cin >> size;
	std::cout << "\nShape:\n";
	
	//only have asterisks when the column equals the row or the last index minus the row
	for(int i= 0; i< size; i++){
		for(int j=0 ; j< size; j++){
			if(j == i || j == size-i-1){
				std::cout << "*";
			}else{
				std::cout << " ";
			}
		}
		std::cout << '\n';
	}
	return 0;
}