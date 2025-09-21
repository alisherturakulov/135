/*
Author: Alisherjon Turakulov
Course: CSCI 135
Instructor: Tong Yi
Assignment: Project 1B 

accepts a csv file name as input, and prints the sum of column Amount
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>

//given a row from getline input, return the double value of amount column
double getAmountCol(std::string& row){
	
	bool notLast = true;

	while(notLast){
		row=row.substr(row.find(',')+1);
		if(row.find(',') == row.npos){
			notLast = false;
		}
	}
	//std::cout << row << std::endl;
	double ret{};
	try{
		ret = std::stod(row);
	}catch(std::invalid_argument&){
		std::cerr << "stod argument invalid: " << row << "\n";
		std::exit(1);
	}
	
	return ret;
}

int main(){
	std::string fname;
	std::cout << "Enter a csv file: ";
	std::cin >> fname;
	std::ifstream fin(fname);
	if(fin.fail()){
		std::cerr << "File open error\n";
		std::exit(1);
	}
	
	//remove the header
	std::string header;
	getline(fin, header);
	 
	double sum{};
	std::string row;
	//keep only the text after the third comment
	while(getline(fin, row)){
	sum+=getAmountCol(row);
	//std::cout << row << ";" << sum << "\n";
	}
	
	std::cout << "sum = " << sum << "\n";
	return 0;
}