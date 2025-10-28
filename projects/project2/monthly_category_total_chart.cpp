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

//sorts an array of strings in ascending order, using insertion sort
//@param end, index to sort until
//@param arr, string array to sort
void insertionSort(std::string arr[], int end){
    for(int i = 1; i< end; ++i){
		std::string current = arr[i];
		int j =i;
		while(arr[j] >= arr[i]){
			j--;
		}
		arr[i] = arr[j];
		arr[j] = current;
    }
}

//retrieves and returns the row string from a line from a spending csv file
//@param row, the line from the csv file
//@return the category string
std::string getCategory(std::string& row){
    std::string category;
	int indicesBefore2nd = row.find(",", row.find(",")+1);
	int firstComma = row.find(",");
	int secondComma = row.find(",", firstComma+1);
	int lastComma = row.find_last_of(',');
	category = row.substr(secondCommma+1, lastComma-secondComma);
    return category;
}

//reads the amount from a line and returns the double value
//@param row, line of text from csv file
double getTotal(const std::string& row) const{
	int lastComma = row.find_last_of(',');
	std::string amountStr = row.substr(lastComma+1);
	double amount = std::stod(amountStr);
	return amount;
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
    insertionSort(categoryList, categoriesEnd);

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
    double monthlySpending[categoriesEnd][12] = {};
    //get ready to reread for each category
    fin.reset();
    fin.seekg(0);
    if(fin.fail()){
        std::cerr << "Cannot reopen file";
        std::exit(1);
    }

    while(getline(fin, row)){
        //apply increments to corresponding monthlySpending indices
        int firstSlash = row.find("/");
		int monthIndex = std::stoi(row.substr(0, firstSlash));
		double amount = agetTotal(row);
		std::string& category = getCategory(row);
		int catIndex = 0;
		for(int i = 0; i< categoriesEnd; ++i){
			if(categories[i] == category){
				catIndex= i;
				i = categoriesEnd;
			}
		}
		monthlySpending[catIndex][monthIndex] += amount;
        
    }
    
    return 0;
}



