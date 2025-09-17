/*
Author: Alisherjon Turakulov
Instructor: Tong Yee
Course: CSCI 136
Assignment: lab3C

takes in two dates on an interval and 
prints each date and West East or Both for the higher elevations on that date
*/

#include <iostream>
#include <fstream>
#include <climits>
#include <cstdlib>

int main(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.fail()){
        std::cerr << "File read error";
        std::exit(1);
    }

    //will ask for user input:
    std::string startDate;
    std::cout << "Enter starting date: ";
    std::cin >> startDate; //cin leaves newline from user pressing enter key
    std::string endDate;
    std::cout << "Enter ending date: ";
    std::cin >> endDate;

    //remove the header
    std::string header;
    getline(fin, header);
 
    bool inInterval = false;
    std::string date;
    double EastSt, EastEl, WestSt, WestEl;
    while(fin >> date >> EastSt >> EastEl >> WestSt >> WestEl){
        fin.ignore(INT_MAX, '\n');
        //start processing rows if inInverval is true
        if(date == startDate ){

        }

        //stop once endingDate processed
        if(date == endDate){
            fin.close();
        }
    }


    return 0;
}