/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: E9.5

implements a member functions of a rectangle class to interact with scale and compute area and perimeter
*/

#include <iostream>
#include <string>


class Rectangle {
	public:
		Rectangle(double input_w, double input_h);
		double get_perimeter();
		double get_area();
		void resize(double factor);
	private:
		double width;
		double height;
};

Rectangle::Rectangle(double input_w, double input_h): width{input_w}, height{input_h}{}

double Rectangle::get_area(){
	return width*height;
}
double Rectangle::get_perimeter(){
	return (width+width+height+height);
}

void Rectangle::resize(double factor){
	width*=factor;
	height*=factor;
}