/*
09-15-2025
getline and reading csv files
getline can be used with a custom delimeter (default '\n')
getline(streamObj, stringVar, delimiter);
Name, Test1, Test2, Test3
Ann Smith, 96, 23, 35
Bob, 78, 85, 65 

however, will need to use cin for last column or the \n will be included

to convert a string to a number, use built in methods:
  int data = std::stoi("123"); 123
  std::stod("123.12") for doubles
use INT_MAX to pass through the columns for the minimum

#include <iostream>
#include <fstream>
#include <climits>//for limits
#include <string>

int main(){
  

  std::string fname = "scores.csv";
  //load file to ifstream
  std::ifstream fin(fname);

  //check for erros
  if(fin.fail()){ 
    std::cerr << fname << " cannot be opened" << std::endl;
    exit(1);
  }

  //since scores.csv has a column head, line before
  //actual data,
  //read this line without further processing
  std::string line;
  getline(fin, line);

  int minTest1 = INT_MAX; //climits library
  std::string name;
  std::string t1Str;
  int test1;
  std::string t2Str;
  std::string t3Str;
  
  while(getline(fin, name, ',')){
    //get test1 and convert it to an int
    getline(fin, t1Str, ',');
    test1 = std::stoi(t1Str);

    if(test1 < minTest1){
      minTest1 = test1;
    }
    //dont need to convert other columns to integers
    getline(fin t2Str, ',');
    
    //use getline() with '\n' default delimiter 
    getline(fin, t3Str);
  }
  fin.close();
  std::cout << "min test1: " << minTest1 << std::endl; 
  
  
  return 0;
}


*/
