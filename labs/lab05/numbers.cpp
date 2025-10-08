/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assingnment: Lab5AtoG

A Takes two integers, n and d. Prints whether n is divisible by d.
B Takes an integer n and returns whether it is prime
C takes an integer n and returns the next prime number greater than n
D takes in two ints a, b and returns the count of primes in [a,b]
E 
*/

#include <iostream>
#include <string>
#include <cmath>

//A
//short circuit if d is zero
bool isDivisibleBy(int n, int d){
    return d != 0 && n % d ==0;
}

//B
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

//C
int nextPrime(int n){
	//start by checking n+1 and continue if not prime
	while(!isPrime(++n)){
		//keep looping until its prime
	}
	return n;
}

//D
int countPrimes(int a, int b){
	//check each value using isPrime() function.
	int count{};
	while(a <= b){
		if(isPrime(a)){
			++count;
		}
		++a;
	}
	return count;
}

//E
bool isTwinPrime(int n){
	return isPrime(n+2) || isPrime(n-2);
}


int main(){
    int n{};
    int d{};
    /*std::cout << "Enter number to divide: ";
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
	
	int m{};
	std::cout << "Enter two integers to count the number of primes between them: ";
	while(std::cin >> n >> m && n > m){
		std::cout << "Error, first number needs to be <= second number, re-enter: ";
	}
	std::cout << "There are " << countPrimes(n, m) << " primes in the interval [" << n << "," << m << "]\n";
	*/

	std::cout << "Enter number to check if its a twin prime: ";
	std::cin >> n;
	std::cout<< ((isTwinPrime(n)) ? "Yes" : "No") << '\n';
    return 0;
}