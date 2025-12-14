/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: Lab 13ABCD

implements a recursive function to print numbers in a range
a recrusive function to sum numbers in a range
a recursive sumArray function
a recursive isAlphanumeric function
a recursive nestedParens function
and tests them all
*/


#include <iostream>
#include <string>
#include <cctype>

void printRange(int left, int right);
int sumRange(int left, int right);
int sumArray(int* arr, int size);
bool isAlphanumeric(std::string s);
bool nestedParens(std::string s);

int main(){
	
	printRange(-2, 10);
	
	int x = sumRange(1, 3);
	std::cout << "\nthis is: " << x << '\n';
	
	x = sumRange(-2, 10);
	std::cout << "this is: " << x << '\n';
	
	const int size = 10;
	int* arr = new int[size];
	arr[0] = 12;
    arr[1] = 17;
    arr[2] = -5;
    arr[3] = 3;
    arr[4] = 7;
    arr[5] = -15;
    arr[6] = 27;
    arr[7] = 5;
    arr[8] = 13;
    arr[9] = -21;

    int sum1 = sumArray(arr, size); // Add all elements
    std::cout << "Sum is " << sum1 << std::endl;  // Sum is 43
    
    int sum2 = sumArray(arr, 5); // Add up first five elements
    std::cout << "Sum is " << sum2 << std::endl;  // Sum is 34

    delete[] arr;         // deallocate it

	std::string str1 = "&hello1";
	std::cout << str1 << ": " << isAlphanumeric(str1) << '\n';
	str1 = "hello1&";
	std::cout << str1 << ": " << isAlphanumeric(str1) << '\n';
	str1 = "hello1";
	std::cout << str1 << ": " << isAlphanumeric(str1) << '\n';
	
	std::cout << nestedParens("((()))") << std::endl;      // true (1)
	std::cout<< nestedParens("()") << std::endl;          // true (1)
	std::cout << nestedParens("") << std::endl;            // true (1)

	std::cout << nestedParens("(((") << std::endl;         // false (0)
	std::cout << nestedParens("(()") << std::endl;         // false (0)
	std::cout << nestedParens(")(") << std::endl;          // false (0)
	std::cout << nestedParens("a(b)c") << std::endl;       // false (0)

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

//sums the elements of a int array of length size
int sumArray(int* arr, int size){
	if(size == 0){
		return 0;
	}
	return arr[size-1] + sumArray(arr, size-1);
}

//returns true if all the chars in a string are alphanumeric
bool isAlphanumeric(std::string s){
	if(s.length() == 0){
		return true;
	}else if(std::isalnum(s.at(s.length()-1))){
		return isAlphanumeric(s.substr(0, s.length()-1));
	}
	return false;
}

//checks that a sring contains only nested parents
bool nestedParens(std::string s){
	if(s.length() == 0){
		return true;
	}else if(s.length() == 1){
		return false;
	}else if(s.at(0) == '(' && s.at(s.length()-1) == ')'){
		
			return nestedParens(s.substr(1, s.length()-2));
		
	}
		return false;
	
		
}