/*
Author:Alisherjon Turakulov
Course: CS 135
Incstructor: Tong Yi
Assingment: Lab 8G

reads the data from inImage.pgm, and writes to outImage.pgm with
the horizontal sobel operator applied to the original image
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
    //const int SCALED_W = 2* w;
    //const int SCLAED_H = 2* h;
	int out[MAX_H][MAX_W];

    //set the outer edges to black
    for(int i= 0;i< h; i++){//sides
        out[i][0] = 0;
        out[i][w-1] = 0;
    }
    for(int i = 0; i<w; i++){//top and bottom
        out[0][i] = 0;
        out[h-1][i] = 0;
    }
    
    //for each row, col pair calculate the sobel using the top and bottom pixels
    // row-1 col-1; row-1 col; row+-1 col+1; and same but with row+1
    // then set the pixel in the output image to the horizontal sobel result
	for(int row = 1; row < h-1; row++) {
		for(int col = 1; col < w-1; col++) {
            int horizontal_sobel = (img[row+1][col-1] + 2* (img[row+1][col]) + img[row+1][col+1]) - (img[row-1][col-1] + 2*(img[row-1][col]) + img[row-1][col+1]);
			if (horizontal_sobel < 0){
                horizontal_sobel = 0;
            }else if(horizontal_sobel > 255){
                horizontal_sobel = 255;
            }
            out[row][col] = horizontal_sobel;
		}
	}

	// and save this new image to file "outImage.pgm"
	writeImage(out, h, w);

}
