/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: Lab 9F

Defines a class Particle, which uses Coord3D objects and provides an interface with
functions to move, set velocity, and dynamically allocate/deallocate memory
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

/**allocate memory and initialize
  *@params x,y,z double values to initialize the coordinate object
  *@return pointer to a coordinate object
  */
Coord3D* createCoord3D(double x, double y, double z){
	
	return new Coord3D{x, y, z};
}

/** free memory
  *@param p, a pointer to a coordinate object
  */
void deleteCoord3D(Coord3D *p){
	delete p;
	p=nullptr;
}
class Particle{
	public:
		Coord3D posCoord{};
		Coord3D velCoord{};
};

/**dynamically allocate memory for a particle and initialize it
  *@params double values for position and velocity Coordinate Objects
  *@return pointer to a Particle pointer
*/
Particle* createParticle(double x, double y, double z, 
						 double vx, double vy, double vz)
{
	Particle* particlePtr = new Particle;
	particlePtr->posCoord= {x, y, z};
	particlePtr->velCoord= {vx, vy, vz};
	return particlePtr;
}
						 
// set its velocity to (vx, vy, vz)
void setVelocity(Particle *p, double vx, double vy, double vz){
	p->velCoord = {vx, vy, vz};
}
// get its current position
Coord3D getPosition(Particle *p){
	return p->posCoord;
}
// update particle's position after elapsed time dt
void move(Particle *p, double dt){
	move(&(p->posCoord), &(p->velCoord), dt);//uses move method from 3d-space.cpp
}
// delete all memory allocated for the particle passed by pointer
void deleteParticle(Particle *p){
	delete p;
	p=nullptr;
}


int main() {//using example from lab9 page
    // make new particle
    Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
	std::cout << "should be 1: " << getPosition(p).x << std::endl;
	setVelocity(p, 1.0, 1.0, 1.0);
	std::cout << "should be 1: " << p->velCoord.x << std::endl;
	deleteParticle(p);
	std::cout << p;
    /*double time = 0.0;
    double dt = 0.1;
    while(time < 3.0) {
        // update its velocity
        setVelocity(p, 10.0 * time, 0.3, 0.1);

        // move the particle
        move(p, dt);
        time += dt;

        // reporting its coordinates
        std::cout << "Time: " << time << " \t";
        std::cout << "Position: "
             << getPosition(p).x << ", "
             << getPosition(p).y << ", "
             << getPosition(p).z << std::endl;
    }
    // remove the particle, deallocating its memory
    deleteParticle(p);
	*/
	return 0;
}
