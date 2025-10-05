/*
Author: Alisherjon Turakulov
Course: 135
Instructor: Tong Yi
Assignment: Project 1D

Reads a csv file with spending data and outputs the
monthly totals.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>

int main(){
	//read file name from stdin
	std::string fname;
	std::cout << "Enter a csv file name for credit card transactions: ";
	std::cin >> fname;
	
	//open the file and check for errors
	std::ifstream fin(fname);
	if(fin.fail()){
		std::cerr << "Error can't open " << fname <<"\n";
		std::exit(1);
	}
	
	//remove the header of the data
	std::string header;
	std::getline(fin, header);
	
	
	double monthlySpending[12] = {};
	std::string row;
	int mIndex{};
	double amount{};
	//read each row and extract date/spending for adding to the corresponding array index
	while(getline(fin, row)){
		//std::cout << "row: " << row << "\n";
		//get the month index
		//if(row.length() >= 9){
			
		
			//std::cout << "got: " <<  row.substr(0,1) << "\n";
			try{ //to return what argument caused stoi error
			mIndex = std::stoi(row.substr(0, 1))-1;
			}catch(std::invalid_argument& err){
				std::cout << "invalid stoi arg: " << row.substr(0,1) <<"\n";
				
			}
			//get the amount as a double
			std::size_t amtIndex = row.find_last_of(',')+1;
			amount = std::stod(row.substr(amtIndex));
			
			monthlySpending[mIndex] += amount;
			//std::cout << monthlySpending[mIndex] << " for " << mIndex << std::endl;
		//}
	}
	
	
	//print each monthly total
	std::string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	std::cout << "MON"<< std::setw(7) << "TOTAL\n";
	for(int i =0; i < 12; i++){
		double spending = monthlySpending[i];
		
		std::cout << months[i] << std::setw(5) << std::fixed 
				  << std::setprecision(2) << spending << "\n";
	}
	
	
	fin.close();
	
	
	return 0;
}