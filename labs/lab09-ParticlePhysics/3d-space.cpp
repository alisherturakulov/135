/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: Lab 9A

Given a pointer to a Coord3D that stores double coordinates x, y, z
defines a function length, which returns the euclidean distance
from origin 
*/

#include <iostream>
#include <string>
#include <cmath>

//3 dimensional coordinate class definition
class Coord3D{
	public:
		double x;
		double y;
		double z;
};

/** Returns the distance to the origin of a Coord3D
  *@param p a pointer to a Coord3D object
  *@return a double, the distance to the origin
  */
double length(Coord3D *p){
	//using euclidean distance formula
	double x = (*p).x; //dereferencing and using access by reference
	double y = p->y; //access by pointer
	double z = (*p).z;
	double distxyz = std::sqrt(x*x + y*y + z*z);
	return distxyz;
}


int main(){
	Coord3D coord{10, 10, 10};
	//std::cout << "x " << coord.x << std::endl;
	std::cout << "should be  between 17 and 18: " << length(&coord) << std::endl; //pass address of coord
	return 0;
}