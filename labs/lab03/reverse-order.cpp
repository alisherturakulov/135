/*
Author: Alisherjon Turakulov
Course: CSCI 135
Instructor: Tong Yi
Assingment: lab 3D

Asks for input of an earlier and later date and prints out the West basin elevations
for every date in the interval in starting from the later date to the earlier date.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <climits>


int main(){

    //read and check for success
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.fail()){
        std::cerr << "File read error\n";
        std::exit(1);
    }
    
    //remove header
    std::string header;
    std::getline(fin, header);

    //declare necessary vars and arrays    
    std::string date;
    double EastSt, EastEl, WestSt, WestEl;
    bool inInterval = false;

    std::string dates[366];
    double wElevations[366];

    std::string sDate;
    std::string eDate;
    std::cout << "Enter earlier date : ";
    std::cin >> sDate;
    std::cout << "Enter later date: ";
    std::cin >> eDate;
    std::cout << "\n";
    int i{}; //index
    const int SIZE = std::string::compare(sDate, eDate);
    std::cout << "size: " << SIZE << std::endl;
    std::string dates[SIZE];
    double wElevations[SIZE];
    

    while(fin >> date >> EastSt >> EastEl >> WestSt >> WestEl){
        if(date == sDate){
            inInterval = true;
        }
        if(inInterval){
            dates[i] = date;
            wElevations[i] = WestEl;
            i++;
        }
        if(date == eDate){
            fin.close();
            
        }
        fin.ignore(INT_MAX, '\n');
    }
    //print the date elevation pairs in reverse order 
    for(int j = i-1; j >= 0; j--){
        std::cout << dates[j] << " " << wElevations[j] << " ft\n";
    }

    if(inInterval == false){
        fin.close();
    }

    return 0;
}