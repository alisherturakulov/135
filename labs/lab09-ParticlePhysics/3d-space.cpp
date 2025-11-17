/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: Lab 9ABC

A
Given a pointer to a Coord3D that stores double coordinates x, y, z
defines a function length, which returns the euclidean distance
from origin 

B 
defines a function fartherFromOrigin which takes pointers to two Coord3D objects
and returns a pointer to the Coord3D farther from the origin

C

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
/** Returns the pointer to the larger of two Coord3D objects
  *@params  p1, and p2, both pointers to a Coord3D
  *@return a pointer to a Coord3D
  */
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2){
	double distanceP1 = length(p1);
	double distanceP2 = length(p2);
	if(distanceP1 > distanceP2){
		return p1;
	}
	return p2;
}
/**Changes the position coordinates of the coordinate by velocity coordinates
  *@param ppos, pvel, pointer to the position and velocity coordinates
  *@param dt, double value representing time in seconds 
  */
void move(Coord3D *ppos, Coord3D *pvel, double dt){
	//change each coordinate by velocity
	//pos = pos + velocity*time
	ppos->x = ppos->x + pvel->x*dt;
	ppos->y = ppos->y + pvel->y*dt;
	ppos->z = ppos->z + (*pvel).z*dt;
}



int main(){
	std::cout << "Tests for A: " << std::endl;
	Coord3D coord{10, 10, 10};
	//std::cout << "x " << coord.x << std::endl;
	std::cout << "should be  between 17 and 18: " << length(&coord) << std::endl; //pass address of coord
	
	std::cout <<"Tests for B: " << std::endl;
	Coord3D coord2{1, 1, 1};
	std::cout << "Addres of coord: " << &coord << '\n';
	std::cout << "Address of coord2: " << &coord2 << '\n';
	Coord3D *fartherPtr = fartherFromOrigin(&coord, &coord2);//passing with address of 
	std::cout << "Farther coordinate: " << fartherPtr << " should be " << &coord << '\n';
	
	std::cout << "Tests for C: " << '\n';
	move(&coord, &coord2, 7.0);
	std::cout << "Should be {17, 17, 17}: {" << coord.x << ", " << coord.y << ", " << coord.z << "}\n";
	
	return 0;
}