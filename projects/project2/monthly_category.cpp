/*
Author: Alisherjon Turakulov
Course: CS 135
Instrcutor: Tong Yi
Assignment: Project2B

Uses initial setup from Project2A to record into table
Given a csv file with spending data, reads the file, 
and records monthly spending for each category into a 2d array
prints a table with row number of months; each column being a category
the final rows have total spending for each category
and the percentage of the annual spending for each category total
the final columns have total spending for each month
the total annual spending is at the last row and column
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>

//sorts an array of strings in ascending order, using insertion sort
//@param end, index to sort until
//@param arr, string array to sort
void insertionSort(std::string arr[], int end){
    for(int i = 1; i< end; ++i){
        //while the lower index element is greater, swap
		for(int j =i; j > 0; --j){
            //swap back until elem at index j is in correct position
			std::string current = arr[j];
            if (arr[j-1] > current){
                arr[j] = arr[j-1];
                arr[j-1] = current;
            }
		}
    }
}

//retrieves and returns the row string from a line from a spending csv file
//@param row, the line from the csv file
//@return the category string
std::string getCategory(const std::string& row){
    std::string category;
	int firstComma = row.find(",");
	int secondComma = row.find(",", firstComma+1);
	int lastComma = row.find_last_of(',');
    //subtract 1 to prevent inclusion of the last comma
	category = row.substr(secondComma+1, lastComma-secondComma-1);
    return category;
}

//reads the amount from a line and returns the double value
//@param row, line of text from csv file
double getAmount(const std::string& row) {
	int lastComma = row.find_last_of(',');
	std::string amountStr = row.substr(lastComma+1);
	double amount = std::stod(amountStr);
	return amount;
}


//returns the percentage of the total spending made up by a 
//a categories total spending
//@param catTotal, total for the category
//@param annualTotal, total across categories
double getPercentAnnualTotal(double catTotal, double annualTotal){
	return catTotal*100 / annualTotal;
}

int main(){
    /*
    //Test for insertionSort; pass
    std::string arr[] = {"a", "A", "A", "B", "apple","aapplw", "zeta"};
    insertionSort(arr, 7);
    for(std::string& str : arr){
        std::cout << str << " ";
    }
    //test for get functions; pass
    std::string testRow= "01/,null,cat,10.00";
    std::cout << "Category should be \"cat\": " << getCategory(testRow) <<'\n';
    std::cout << "Amount should be 10.00: " << getAmount(testRow) << '\n';
    */

    
    std::cout << "Enter csv file name: ";
    std::string fname;
    std::cin >> fname;
    std::ifstream fin(fname);
    if(fin.fail()){
        std::cerr << "Cant open " << fname << std::endl;
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
        bool found= false; //check if the category is already recorded
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

    //for(std::string& str: categoryList){
    //    std::cout << str << " ";
    //}
    //sort the category list
    insertionSort(categoryList, categoriesEnd);
    
    
   
    //zero-initialized array to hold total monthly spending for each category
    //where each row corresponds to categoryList values
	double monthlySpending[20][12] = {};
	
    //get ready to reread for each category
	/*std::cout << "before clear" << fin.fail() <<'\n';
    fin.clear();
	std::cout << "before seekg" << fin.fail() << '\n';
	int offset{};//for seekg()
    fin.seekg(0, std::ios::beg);
	std::cout << "after seekg" << fin.fail() << '\n';
	
    
	fin.clear();
   
   */
	fin.close();
	fin.open(fname);
	if(fin.fail()){
		std::cerr<< "Cant reopen file" <<'\n';
		std::exit(1);
	}
	getline(fin, row);
    //std::cout << row << '\n';
	
    while(getline(fin, row)){
		//std::cout << "row: " << row << '\n';
        //get the amount and category
        int firstSlash = row.find('/');
		int monthIndex = std::stoi(row.substr(0, firstSlash))-1;
		double amount = getAmount(row);
		std::string category = getCategory(row);
		int catIndex = 0;
        //locate the corresponding category's index
		for(int i = 0; i< categoriesEnd; ++i){
			if(categoryList[i] == category){
				catIndex= i;
				i = categoriesEnd;
			}
		}
        //add amount to corresponding monthlySpending indices
		monthlySpending[catIndex][monthIndex] += amount;
		amount = 0;
		//std::cout << amount << " catIndex: " << catIndex << '\n';
		
	}
	
    //loop over data to record total spending per month
	//and per category in separate arrays
    double monthTotals[12] = {};
	double categoryTotals[20] = {};
	double annualTotal{};
    for(int i = 0 ; i < 12; ++i){
        for(int j= 0 ; j<categoriesEnd; ++j ){
            double currentSpending = monthlySpending[j][i];
			monthTotals[i] += currentSpending;
			categoryTotals[j] += currentSpending;
			annualTotal += currentSpending;
        }
    }
	
    //std::cout << "max monthly total across all categories = "<< maxMonTotal << '\n';
    //using setw() to add witespace after month
    std::cout << "MON";
	for(int i =0; i<categoriesEnd; ++i){
		std::cout<< std::setw(15) << std::right << categoryList[i]; 
	}
	std::cout << std::setw(15) << std::right << "TOTAL\n";
	const int LINE_LEN = categoriesEnd*15+20;
	for(int i =0; i< LINE_LEN; ++i){
		std::cout << '-';
	}
	std::cout<<'\n';
	std::string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	
	for(int i =0; i < 12; ++i){
		std::cout << months[i];
		for(int j=0; j<categoriesEnd; ++j){
			std::cout << std::setw(15) << std::right << std::fixed 
					  << std::setprecision(2) << monthlySpending[j][i];
		}
		std::cout << std::setw(15) << std::right << std::fixed 
		          << std::setprecision(2) << monthTotals[i] << '\n';
	}
	for(int i =0 ; i<LINE_LEN; ++i){
		std::cout <<'=';
	}
	std::cout << "\n   ";
	for(int i =0; i<categoriesEnd; ++i){
		std::cout << std::setw(15) << std::right << std::fixed 
		          << std::setprecision(2) << categoryTotals[i];
	}
	std::cout << std::setw(15) << std::right << std::fixed 
	          << std::setprecision(2) << annualTotal << '\n';
	std::cout << "   ";
	for(int i =0; i< categoriesEnd; ++i){
		double percentAnnualT = getPercentAnnualTotal(categoryTotals[i], annualTotal);
		std::cout << std::setw(14) << std::right << std::fixed 
			      << std::setprecision(2) << percentAnnualT << std::left<< "%";
	}
	std::cout <<'\n';
    return 0;
}



