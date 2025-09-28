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
    //find the indices of the '/' characters
    std::string str = date;
    std::size_t firstSlash = str.find_first_of('/');
    std::size_t secondSlash = str.find_last_of('/');
    
   // int day = stoi(str.substr(0, firstSlash));
   //add a leading zero if the value is one digit
    std::string month = (firstSlash == 1) ? ("0" + str.substr(0, 1)) : (str.substr(0, 2)) ;
    //std::cout << dayStr << "\n";

    //add a leading zero if the month is one digit
    std::string day = str.substr(firstSlash+1, 2);
    if(secondSlash - firstSlash == 2){
        day = "0" + str.substr(firstSlash+1,1);
    }
    
    //construct a new string in mm/dd/yyyy format
    std::string ret;
    ret = month + "/" + day + "/20" + str.substr(str.size()-2);
    //std::cout << ret << std::endl;
    return ret;
}       

int main(){

  //  std::string test = convert("7/8/25");
  //  std::cout << test << std::endl;
    std::string fname;
    std::cout << "Enter a csv file name: ";
    std::cin >> fname;
    
    std::ifstream fin(fname);
    if(fin.fail()){
        std::cerr << "Error when reading " << fname << "\n";
        std::exit(1);
    }

    std::string sDate;
    std::cout << "Enter start date (m/d/yy): ";
    std::cin >> sDate;

    std::string eDate;
    std::cout << "Enter end date (m/d/yy): ";
    std::cin >> eDate;
    std::cout << "\n";

    sDate = convert(sDate);
    eDate = convert(eDate);

    std::string header;
    getline(fin, header);
    std::string row;
    double sum{};
    while(getline(fin, row)){
        //std::cout << "intial" << row << '\n';

        std::string date = row.substr(0, row.find_first_of(','));
        date = convert(date);
        
        //std::cout << date << "\n";
        if(date >= sDate && date <= eDate){
            std::cout << row << '\n';
            
            std::string amount = row.substr(row.find_last_of(',')+1);
            double amt = stod(amount);
            
            sum += amt;
        }
        
    }  

    std::cout << "\nTotal amount: " << sum << "\n";
    fin.close();

    return 0;
}