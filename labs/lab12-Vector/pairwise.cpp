/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: Lab 12D

implements a function sumPairWise that takes two vector<int> objects
and returns a vector with the pairwise sums of the parameter's elements. 
The pair is zero if the parameter lengths differ
*/

#include <iostream>
#include <string>
#include <vector>

std::vector<int> sumPairWise( std::vector<int> &v1,  std::vector<int> &v2){
	int min = v1.size();
	int max = v2.size();
	
	if(v1.size() > v2.size()){
		min = v2.size();
		max = v1.size();
	}

	std::vector<int> result(max);
	
	for(int i{}; i <max; ++i ){
		if(i < min){
			result.at(i) = v1.at(i) + v2.at(i);
		}else{
			if(v1.size() == min){
				result.at(i) = v2.at(i);
			}else{
				result.at(i) = v1.at(i);
			}
		}
	}
	
	return result;
}


int main(){
	std::vector<int> test1{1, 2, 3, 4, 5};
	std::vector<int> test2{6, 7, 8, 9, 10};
	
	std::vector<int> sum1 = sumPairWise(test1, test2);
	
	for(int i{}; i<sum1.size(); ++i){
		std::cout << sum1.at(i) << " ";
	}
	std::cout << std::endl;
	return 0;
}