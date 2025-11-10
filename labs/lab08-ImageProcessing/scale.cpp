/*
Author:Alisherjon Turakulov
Course: CS 135
Incstructor: Tong Yi
Assingment: Lab 8E

reads the data from inImage.pgm, and writes to outImage.pgm with
the original image sclaed up 200%
by doubling the width and height and each pixel 
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
void writeImage(int image[1024][1024], int height, int width) {
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
    //const int SCALED_W = 2* w;
    //const int SCLAED_H = 2* h;
	int out[1024][1024];


    
    //for each row, col pair set the output
    // row col; row col+1; row+1 col; and row+1 col+1 to the pixel value
    int outRow =0;
    int outCol =0;
	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {
            outRow = row*2;
            outCol = col*2;
			out[outRow][outCol] = img[row][col];
            out[outRow][outCol+1]  = img[row][col];
            out[outRow+1][outCol] = img[row][col];
            out[outRow+1][outCol+1]  = img[row][col];
		}
	}

	// and save this new image to file "outImage.pgm"
    //double the height and width
	writeImage(out, h*2, w*2);

}
