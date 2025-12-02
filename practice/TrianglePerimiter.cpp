/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: E 7.18

defines a struct Triangle, and a method that calculates the perimiter of a given Triangle object
takes input from main to test
*/

#include <iostream>
#include <string>
#include <cmath>
struct Point{
	double x;
	double y;	
};

//Takes two Point Objects and returns the double distance between them
double distance(Point& A, Point& B){
	//distance = sqrt( (ax - bx)^2 (ay - by)^2 )
	double dist = std::sqrt(std::pow(A.x - B.x, 2) +std::pow(A.y - B.y, 2));
	return dist;
}


struct Triangle{
	Point x;
	Point y;
	Point z;
};

double getPerimiter(Triangle triangle){
	double perimiter = distance(triangle.x, triangle.y) + distance(triangle.y, triangle.z) + distance(triangle.x, triangle.z);
	return perimiter;
}



int main(){
	double x1, y1, x2, y2, x3, y3;
	std::cout << "Enter Coordinates of points for first triangle: ";
	std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	Point PointA{x1, y1};
	Point PointB{x2, y2};
	Point PointC{x3, y3};
	
	Triangle triangle{PointA, PointB, PointC};
	
	double perimeter = getPerimiter(triangle);
	
	std::cout << "Perimiter of triangle: " << perimeter << '\n';
	return 0;
}