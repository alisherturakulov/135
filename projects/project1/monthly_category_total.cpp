/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: project1E

Takes in a csv file with spending data, lists the different categories of spending in alphabetical order
and asks the user to input which category they want to analyze the monthly spending on.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

/*//makes a sorted copy of array
int[] sortedCopy(int[] arr){ 
    std::sort(arr, arr.begin(), arr.end());
    return arr;
}

std::string[]& extractCategories(){
    std::string[50] categories;

    std::string fname;
    std::ifstream fin(fname);
    if(fin.fail()){
        std::cerr << "Error reading " << fname << '\n';
        std::exit(1);
    }

    std::string header 

    return categories;
}

void printMonthlyCategoryTotal(const std::string& fname, std::string& category){
    std::ifstream fin(fname);
    std::cout << Enter;
}
*/

//get the category from a row of the csv file
std::string getCategory(std::string& row){
    //find indices of the commas enclosing teh category
    int firstCommaInd = row.substr(row.find(",")+1).find(",");
    int lastCommaInd = row.find_last_of(',');

    
    return row.substr(firstCommaInd+1, lastCommaInd);
}


int main(){
    std::string fname;
    std::cout << "Enter csv file name: ";
    std::cin >> fname;

    std::ifstream fin(fname);
    if(fin.fail()){
        std::cerr << "Error reading csv file " << fname << '\n' ;
        std::exit(1);
    }
    //remove header
    std::string header;
    std::getline(fin, header);

    //read file for rows, store each row into a string array?
    //instead of reopening the file use the fin.clear() and then fin.seek(0) to restart at the start of the file

    std::string[50] categories = {};
    int categoryIndex{}; //next empty index in categories
    int[] amounts;
    
    int i =0;

     //extract unique categories into array
    while(std::getline(fin, row)){
        //category is between the second and third commas
        int lastCommaInd = row.find_last_of(',');
        int secondCommaInd = row.substr(row.find(",")+1).find(",");
        std::string catStr = row.substr(secondCommaInd, lastCommaInd);
        catStr = getCategory(row);
        std::cout <<catStr;
        bool found = false;
        int ind{};
        while(!found && ind < categories.length()){
            
            if(categories[ind] == catStr){
                found = true;
            }
            ind++;
        }
        //add the category if it isn't already in the category array
        if(!found){
            if(categoryIndex >= 50){
                std::cerr << "Category array overflow\n";
                std::exit(1);
            }
            categories[categoryIndex] = catStr;
            categoryIndex++;
        }
    }

    //sort category array
    std::sort(categories, categories.begin(), categories.end());

    std::cout << "select one of the following categories:\n";
    for(int i = 0; i< categoryIndex; ++i ){
            std::cout << i << "." << categories[i] << '\n';
    }

    int seekIndex{};
    std::cout << "choose a number in [0," << categoryIndex-1 <<"]:/n";
    std::cin >> seekIndex;
    std::string seekCategory = categories[seekIndex];

    //reset the std::ifstream object to point back to the start of the file
    fin.clear();
    fin.seek(0);

    double monthlyCatTotals[12]{};
    std::string[12] months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    //again setup for reading, this time adding to monthly cat total
    std::getline(fin, header);
    while(std::getline(fin, row)){
        //get the category for this row
        std::string catStr = getCategory(row);
        //continue if we have a matching category
        if(catStr == seekCategory){
            //get month index
            int mIndex = std::stoi(row.substr(0,1));
            //get the amount for that row
            double amount = std::stod(row.substr(row.find_last_of(',')+1));
            //add to the corresponding monthly totals, subtract 1 from mIndex
            monthlyCatTotals[mIndex-1] = amount;
        }
    }

    std::cout <<"Month    " << seekCategory << " TOTAL\n";
    for(int i =0; i< 12; ++i){
        std::cout << months[i] << "      " << std::fixed << std::setprecision(2) << monthlyCatTotals[i] << '\n';
    }

    //rewite sort with selection sort

    fin.close();
    return 0; 
}