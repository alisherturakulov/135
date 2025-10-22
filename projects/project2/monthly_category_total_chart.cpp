/*
Author: Alisherjon Turakulov
Course: CS 135
Instrcutor: Tong Yi
Assignment: Project2A

Given a csv file with spending data, reads the file, 
prints the spending categories in alphabetical order
prompts the user to choose a category
calculates and prints the maximum monthly total across categories
then prints a chart of the monthly spending for a selected category
adds rows of asterisks next to the chart (1 * = $5)
Uses helper functions defined below.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

//sorts an array of strings in ascending order
//@param end, index to sort until
//@param arr, string array to sort
void selectionSort(std::string arr[], int end){
    for(){
        for(){

        }
    }
}

//retrieves and returns the row string from a line from a spending csv file
//@param row, the line from the csv file
//@return the category string
std::string getCategory(std::string row){

    std::string category;
    return category;
}

//reads from fstream to add category totals to an array
//@param fin, reference to a opened input fstream
//@param category, category to get the totals for
//@param totals, a zero-initialized array of 12 doubles 
void getMonthlyCatTotal(std::ifstream fin&, std::string category, double totals[]){

}



int main(){
    std::cout << "Enter csv file name: ";
    std::string fname;
    std::ifstream fin(fname);
    if(fin.fail()){
        std::cerr << "Cant open " << fname;
        std::exit(1);
    }   

    //remove header for reading
    std::string header;
    std::getline(fin, header);

    std::string categoryList[20] = {};
    int categoriesEnd{};

    //initial read to store the categories in 
    
    std::string row{};
    while(getline(fin, row)){
        std::string category = getCategory(row);
        bool found= false;
        for(int i =0; i< categoriesEnd; ++i){
            if(categoryList[i] == category){
                found = true;
            }
        }
        if(!found){
            categoryList[categoriesEnd] = category;
            categoriesEnd++;
        }
    }

    //sort the category list
    selectionSort(categoryList, categoriesEnd);

    std::cout << "select one of the following categories \n";
    //print ordered category list
    for(int i =0; i< categoriesEnd; ++i){
        std::cout << i << "." << categoryList[i]<< '\n';
    }

    //get the chosen category
    int seekIndex{};
    std::cout << "Choose a number in [" << 0 << "," << --categoriesEnd << "]";
    std::string seekCategory{};
    std::cin >> seekIndex;
    seekCategory =  categoryList[seekIndex];
    
    //array to hold total monthly spending for each category
    //where each index corresponds to the index in categoriesList;
    double monthlySpending[categoriesEnd][12];
    //get ready to reread for each category
    fin.reset();
    fin.seekg(0);
    return 0;
}



