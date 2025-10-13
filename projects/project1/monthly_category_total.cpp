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


//get the category from a row of the csv file
std::string getCategory(std::string& row){
    //find indices of the commas enclosing teh category
    std::size_t firstCommaInd = row.find(",", row.find(",")+1);
    std::size_t lastCommaInd = row.find_last_of(',');
	

    
    return row.substr(firstCommaInd+1, lastCommaInd-firstCommaInd-1);
}

//selection sort an array of strings
void mySort(std::string arr[], int end){
	//std::string max = arr[0];
	int max{};
	while(end > 0){
		max = end-1;
		for(int j =0; j <end; ++j){
			if(arr[j] > arr[max]){
				max = j;
			}
			if(j == end-1 && arr[max] > arr[end-1]){
				//swap max with end
				std::string temp = arr[max];
				arr[max] = arr[end-1];
				arr[end-1] = temp;
			}
		}
		//move end down
		--end;
	}
}

int main(){
	/*std::string s[] = {"a", "A", "b", "B", "BC"};
	mySort(s, 5);
	for(std::string& str: s){
		std::cout << str << std::endl;
	}*/
    std::string fname;
    std::cout << "Enter a csv file name: ";
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
	const int catLen = 50;
    std::string categories[catLen];
    int categoryIndex{}; //next empty index in categories
    
	std::string row{};
     //extract unique categories into array
    while(std::getline(fin, row)){
        //category is between the second and third commas
        //std::size_t lastCommaInd = row.find_last_of(',');
        //std::size_t secondCommaInd = row.find(",", row.find(",")+1);
        //std::string catStr = row.substr(secondCommaInd+1, lastCommaInd-secondCommaInd-1);
        std::string catStr = getCategory(row);
        //std::cout << catStr << "\n";
        bool found = false;
        int ind{};
        while(!found && ind < catLen){
            
            if(categories[ind] == catStr){
                found = true;
            }
            ind++;
        }
        //add the category if it isn't already in the category array
        if(!found){
            if(categoryIndex >= catLen){
                std::cerr << "Category array overflow\n";
                std::exit(1);
            }
            categories[categoryIndex] = catStr;
            categoryIndex++;
        }
    }
	
	
    //sort category array using built in sort
	mySort(categories, categoryIndex);
    //std::sort(categories, categories+categoryIndex);
	//for(auto& s : categories){
	//	std::cout << s << ", ";
	//}
	
    std::cout << "select one of the following categories:\n";
    for(int i = 0; i< categoryIndex; ++i ){
            std::cout << i << "." << categories[i] << '\n';
    }
	
    int seekIndex{};
    std::cout << "choose a number in [0," << categoryIndex-1 <<"]: ";
    std::cin >> seekIndex;
    std::string seekCategory = categories[seekIndex];
	//std::cout <<seekCategory;
	
    //reset the std::ifstream object to point back to the start of the file
	//clear any errors first
	//tried but getline kept getting the first line
	//not getting after the first line
	
	fin.close();
	//fin.clear();
	//fin.seekg(0, std::ios::beg);
	std::ifstream fin2(fname);
	//fin.seekg(0);
	
    if(fin2.fail()){
		std::cerr<<"error reading " << fname << std::endl;
		std::exit(1);
	}
	row = {};
   

    double monthlyCatTotals[12] = {};
    std::string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    //again setup for reading, this time adding to monthly cat total
	//std::cout <<"entering while loop"<<"\n";
	//std::cout << (std::getline(fin, row)) << std::endl;
	std::getline(fin2, header);
    while(getline(fin2, row)){
      // std::cout <<row<< getCategory(row)<<std::endl;
		
        //continue if we have a matching category
        if(getCategory(row) == seekCategory){
            //get month index
            int mIndex = std::stoi(row.substr(0, row.find("/")))-1;
            //get the amount for that row
			std::string amStr = row.substr(row.find_last_of(',')+1);
			//std::cout <<amStr<<"\n";
            double amount = std::stod(amStr);
            //add to the corresponding monthly totals, subtract 1 from mIndex
            monthlyCatTotals[mIndex] += amount;
			
        }
    }

    std::cout <<"Month    " << seekCategory << " TOTAL\n";
    for(int i =0; i< 12; ++i){
        std::cout << months[i] << "      " << std::fixed << std::setprecision(2) << monthlyCatTotals[i] << '\n';
    }

    
	
    fin2.close();
    return 0; 
}