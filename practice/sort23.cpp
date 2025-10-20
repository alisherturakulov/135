/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: E5.14

implements a functoins sort2() that uses reference parameters
to two integers a and b, swapping their values if a > b
*/

#include <iostream>
#include <string>


//forward declaration

void sort2(int& a, int& b);

int main(){
	
	int a{};
	int b{};
	std::cout << "Enter first number : ";
	std::cin >> a;
	std::cout << "Enter second number: ";
	std::cin >> b;
	sort2(a, b);
	std::cout << "First number after sort2 : " << a << '\n';
	std::cout << "Second number after sort2: " << b << '\n';
	
	return 0;
}

//Swaps parameter values so that a < b
//@param integer references a and b
void sort2(int& a, int& b){
	if(a > b){
		int temp = a;
		a = b;
		b = temp;
	}
}