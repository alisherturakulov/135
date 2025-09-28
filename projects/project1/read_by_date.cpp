/*
Author: Alisherjon Turakulov
Course: 135
Instructor: Tong Yi
Assignment: Project 1C

This program takes in the name of a csv file with spending data, a start and end date in m/d/yy or 
mm/dd/yyyy format and returns the sum of the spending between those dates inclusive.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

//Input: str in m/d/yy format
//Returns: str in mm/dd/yyyy format
std::string convert(std::string date){
    std::string str = date;
    std::size_t firstSlash = str.find_first_of('/');
    std::size_t secondSlash = str.find_last_of('/');
    
   // int day = stoi(str.substr(0, firstSlash));
   //add a space to the day value if it is one digit
    std::string dayStr = (firstSlash == 1) ? ("0" + str.substr(0, 1)) : (str.substr(0, 2)) ;
    //std::cout << dayStr << "\n";

    std::string month = str.substr(firstSlash+1, 2);
    if(secondSlash - firstSlash == 2){
        month = "0" + str.substr(firstSlash+1,1);
    }
    
    

    std::string ret;
    ret = dayStr + "/" + month + "/2025";
    
    return ret;
}       

int main(){

    std::string test = convert("7/8/25");
    std::cout << test << std::endl;
    /*std::string fname;
    std::cout << "Enter csv file name: ";
    std::cin fname;
    
    std::ifstream fin(fname);
    if(fin.fail()){
        std::cerr << "Error when reading " << fname << "\n";
        std::exit(1);
    }

    std::string sDate;
    std::cout << "Enter starting date: ";
    std::cin >> sDate;

    std::string eDate;
    std::cout << "Enter later date: ";
    std::cin >> eDate;

    sDate = convert(sDate);
    eDate = convert(eDate);

    std::string row;
    int sum{};
    while(std::getline(cin, row)){
        std::cout << "intial" << row << '\n';

        std::string date = row.substr(0, row.find_first_of(',')+1);
        
        date = convert(date);
        if(date >= sDate || date <= eDate){
            std::cout << row << '\n';
        }
        std::string amt = row.substr(row.find_last_of(','));
        int amount = stoi(amt);

        sum+= amount;
    }  

    std::cout << "Sum of amounts: " << amount << "\n";

*/
    return 0;
}