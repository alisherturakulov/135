/*
Author: Alisherjon Turakulov
Course: CSCI 136
Instructor: Tong Yee
Assignment: Lab3B

This program reads the current reservoir levels csv file and returns
the min and max east basin scores.
*/

#include <iostream>
#include <string>
#include <fstream> //reading files
#include <cstdlib>
#include <climits>

int main(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.fail()){
        std::cerr << "" << std::endl;
        std::exit(1);
    }

    std::string header;
    getline(fin, header);

    int max{INT_MIN};
    int min{INT_MAX};
    std::string date, EastSt, EastEl, WestSt, WestEl;
    //go down all dates; all data from 2018
    while(fin >> date >> EastSt >> EastEl >> WestSt >> WestEl){
        fin.ignore(INT_MAX, '\n');
        if(EastSt > max){
            max = EastSt;
        }
        if(EastSt < min){
            min = EastSt;
        }
    }

    std::cout << "minimum storage in east basin: " << min << "\n";
    std::cout << "maximum storage in east basin: " << max << "\n";
    fin.close();

    
    return 0;
}

