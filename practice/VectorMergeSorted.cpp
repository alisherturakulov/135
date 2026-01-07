/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: E6.20

implements function to merge sorted vectors and return the resulting vector
*/


#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> merge_sorted(vector<int> a, vector<int> b){
	int ai{};
	int bi{};
	int i{};
	std::vector<int> result;
	
	while(ai < a.size() || bi < b.size()){
			
		if(ai < a.size() && bi < b.size()){
			if(a.at(ai) < b.at(bi)){
				result.push_back(a.at(ai));
				ai++;
			}else{
				result.push_back(b.at(bi));
				bi++;
			}
		}else if(ai < a.size()){
			result.push_back(a.at(ai));
			ai++;
		}else{//just bi is left
			result.push_back(b.at(bi));
			bi++;
		}
		
		//std::cout << result.at(i) << ' ';
		i++;
	}
	
	return result;
}


int main(){
	vector<int> a {0,0,0,0};
	vector <int> b{1, 2, 3, 4};
	vector<int> result = merge_sorted(a, b);
	vector<int>v1 = {1, 4, 9, 16};
vector<int>	v2 = {4, 7, 9, 9, 11};
	result = merge_sorted(v1, v2);
	return 0;
}