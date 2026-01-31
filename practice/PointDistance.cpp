/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: E7.16

defines a Point structure and a function to calculate its distance 
*/

#include <iostream>
#include <string>
#include <cmath>

struct Point{
	double x;
	double y;	
};

//Takes two Point Objects and returns the double distance between them
double distance(Point A, Point B){
	//distance = sqrt( (ax - bx)^2 (ay - by)^2 )
	double dist = std::sqrt(std::pow(A.x - B.x, 2) +std::pow(A.y - B.y, 2));
	return dist;
}


int main(){
	double x, y;
	std::cout << "Enter first point coordinates\n";
	std::cin >> x>> y;
	Point pointA{x, y};
	
	std::cout << "Enter second point coordinates\n";
	std::cin >> x >> y;
	Point pointB{x, y};
	
	double dist = distance(pointA, pointB);
	
	std::cout << "The distance between these points is: " << dist << '\n'; 
	return 0;
}