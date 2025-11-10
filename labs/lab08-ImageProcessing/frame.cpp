/*
Author: Alisherjon TUrakulov
Course: CS 135 
Instructor: Tong Yi
Assingment: Lab 8D

reads pgm file inImage.pgm into a 2d integer array of pixel values
edites the pixel values and writes to outImage.pgm with a white 1px frame
around the center of the image; with dimensions 50% by 50% of the height and width.
*/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;

// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
	char c;
	int x;
	ifstream instr;
	instr.open("inImage.pgm");

	// read the header P2
	instr >> c;
	assert(c == 'P');
	instr >> c;
	assert(c == '2');

	// skip the comments (if any)
	while ((instr>>ws).peek() == '#') {
		instr.ignore(4096, '\n');
	}

	instr >> width;
	instr >> height;

	assert(width <= MAX_W);
	assert(height <= MAX_H);
	int max;
	instr >> max;
	assert(max == 255);

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			instr >> image[row][col];
	instr.close();
	return;
}


// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(int image[MAX_H][MAX_W], int height, int width) {
	ofstream ostr;
	ostr.open("outImage.pgm");
	if (ostr.fail()) {
		cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << endl;
	// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << image[row][col] << ' ';
			ostr << endl;
		}
	}
	ostr.close();
	return;
}


int main() {

	int img[MAX_H][MAX_W];
	int h, w;

	readImage(img, h, w); // read it from the file "inImage.pgm"
	// h and w were passed by reference and
	// now contain the dimensions of the picture
	// and the 2-dimesional array img contains the image data

	// Now we can manipulate the image the way we like
	// for example we copy its contents into a new array
	//int out[MAX_H][MAX_W]; will directly edit the img 2d array

    //calculate the frame dimensions and row/col start indices
    //note: row corresponds to height; col corresponds to width
    int boxWidth = w/2; 
    int boxHeight = h/2;
    int rowStart = h/4 ; // rowSart =  height / 2 - boxHeight /2 
    int colStart = w/4;

	//loop through and set pixel colors to white at the outer pixels of the box.
    //top
	int row = rowStart;
    for(int col = colStart; col < colStart+boxWidth; col++) {
        img[row][col] = 255;
    }
    //bottom
	row = rowStart+boxHeight-1;
    for(int col = colStart; col < colStart+boxWidth; col++) {
        img[row][col] = 255;
    }
	//left
    int coln = colStart;
    for(row = rowStart; row < rowStart +boxHeight; row++) {
		img[row][coln] = 255;
	}
    //right
    coln = colStart+boxWidth-1;
    for(row = rowStart; row < rowStart +boxHeight; row++) {
		img[row][coln] = 255;
	}
    

	// and save this new image to file "outImage.pgm"
	writeImage(img, h, w);
    return 0;
}