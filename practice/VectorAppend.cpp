/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: E6.18

implements function to append a vector to another
*/


#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> append(vector<int> a, vector<int> b){
	for(int i =0; i<b.size(); i++){
		a.push_back(b.at(i));
	}
	return a;
}

int main(){
	
	return 0;
}