/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: E7.1

defines a sort function to sort two doubles given pointers to their addresses
*/

#include <iostream>
#include <string>

/**sorts two pointers in ascending order
  *@params p, q pointers to doubles
  */
void sort2(double* p, double* q){
	if(*p > *q){//sort them in-place using cancelling operations
		*p = *p - *q;
		*q = *p + *q;
		*p = *q - *p;
		//p holds value of q and q holds value of p
	}
}

int main(){
	double x{};
	double y{};
	
	std::cout << "Enter two doubles to sort: ";
	std::cin >> x >> y;
	sort2(&x, &y);
	std::cout << "after sorting: " << x << " " << y << '\n';
	
	return 0;
}