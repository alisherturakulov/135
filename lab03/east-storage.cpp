
/*
Author: Alisherjon Turakulov
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab3A

This program takes a data in MM/DD/YYYY format and uses the fstream library to read a tsv file with data on water and elevations 
and print the East Basin sotrage levels on that date
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <fstream>

int main(){

    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.fail()){
        std::cerr << "File cannot be opened for reading." << std::endl;
        std::exit(1);
    }
    std::string junk;
    std::getline(fin, junk);
    
    std::string date, targetDate;
    double EastSt, EastEl, WestSt, WestEl;
    std::cout << "Enter date: ";
    std::cin >> targetDate;
    while(fin >> date >> EastSt >> EastEl >> WestSt >> WestEl){
        //loop until we get the target row 
        fin.ignore(INT_MAX, '\n');
        if(date == targetDate){
            fin.close();
        }
        
    }
    
    std::cout << "East basin storage: " << EastSt << " billion gallons" << std::endl;
    
    //fin.close();

    return 0;
}