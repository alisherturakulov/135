/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: E5.14

implements function sort2() that uses reference parameters
to two integers a and b, swapping their values if a > b
then implements sort3() that sorts 3 reference parameteres 
in ascending order directly swapping their values
*/

#include <iostream>
#include <string>


//forward declaration

void sort2(int& a, int& b);
void sort3(int& a, int& b, int& c);

int main(){
	
	int a{};
	int b{};
	int c{};
	std::cout << "Enter first number : ";
	std::cin >> a;
	std::cout << "Enter second number: ";
	std::cin >> b;
	std::cout << "Enter third number : ";
	std::cin >> c;
	sort3(a, b, c);
	std::cout << "First number after sort2 : " << a << '\n';
	std::cout << "Second number after sort2: " << b << '\n';
	std::cout << "Third number after sort3 : " << c << '\n';
	
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

//swaps values of 3 integers to sort them in ascending order
//@param ints a, b, and c passed by reference
void sort3(int& a, int& b, int& c){
	if(a > b){
		sort2(a, b);
	}
	if(a > c){
		sort2(a, c);
	}
	if(b > c){
		sort2(b, c);
	}	
}