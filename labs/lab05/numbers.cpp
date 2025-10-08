/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assingnment: Lab5AtoG

Takes two integers, n and d. Prints whether n is divisible by d.
*/

#include <iostream>
#include <string>
#include <cmath>

//short circuit if d is zero
bool isDivisibleBy(int n, int d){
    return d != 0 && n % d ==0;
}

bool isPrime(int n){
	double end = std::sqrt(n);
	if(n <= 1){
		return false;
	}else if(n <= 3){
		return true;
	}
	for(int i=2; i< end; ++i){
		if(n % i == 0){
			 return false;
		}
	}
	return true;
}

int nextPrime(int n){
	//start by checking n+1 and continue if not prime
	while(!isPrime(++n)){
		//keep looping until its prime
	}
	return n;
}

int main(){
    int n{};
    int d{};
    std::cout << "Enter number to divide: ";
    std::cin >> n;
    std::cout << "Enter divisor: ";
    std::cin >> d;
	//print result of division
    if(isDivisibleBy(n, d) ){
        std::cout << "Yes\n";
    }else{
        std::cout <<"No\n";
    }
	
	std::cout << "Enter a number to check if it's prime: ";
	std::cin >> n;
	if(isPrime(n)){
		std::cout << "Yes\n";
	}else{
		std::cout << "No\n";
	}
	
	std::cout << "Enter a number to find the next prime: ";
	std::cin >> n;
	std::cout << "Next prime after " << n << " is: " << nextPrime(n) << '\n';
	
	
    return 0;
}