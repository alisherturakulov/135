/*
Author: Alisherjon Turakulov
Course: CSCI-135
Instructor: Tong Yi
Assignment: E2.10

Takes in: 
the number of gallons in a tank; 
the fuel efficiency in miles/gallon; 
cost per gallon.
Then prints the cost for 100 miles and the distance the current 
amount of gass can cover.
*/

#include <iostream>
#include <string>

int main(){
	double currentGallons;
	double fuelEfficiency;
	double costPerGal;
	
	std::cout << "Enter gallons of fuel in tank: ";
	std::cin >> currentGallons;
	std::cout << "Enter fuel efficiency in miles/gallon: ";
	std::cin >> fuelEfficiency;
	std::cout << "Enter fuel cost per gallon: ";
	std::cin >> costPerGal;

	double numMiles = 100;
	double cost100 =  (numMiles / fuelEfficiency) * costPerGal;
	
	std::cout << cost100 << "\n";
	
	double distanceCovered = currentGallons * fuelEfficiency;
	
	std::cout << distanceCovered << "\n";
	
	return 0;
}


