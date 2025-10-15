/*
Functions: 
    have headers: returns type, identifier, args.
    Require braces for body
    Helps make modular programs, organizes and helps with debugging code.

    Examples: main() functions is a caller for isPrime() which is a callee.
    Caller:
        saves local vars and return point
    Callee: 
        does actions when called, then yeilds control back to caller

ret_t funcName(parameter_list)
{

}

isPrime() implementation
A prime number has no non-trivial factors. Trivial Factors are 1 and itself.
Divide integer n by 2 (niteger division) and check for any non trivial factors from possible candidates:
[2, (n/2))
Once a non-trivial factor is found, return false immediately.
 
also can use interval [2, sqrt(n)] since we only need one non-trivial factor to determine if its prime
and a pair of factors cannot both be greater than sqrt(n).
#include <cmath>
std::sqrt(n)
Note: handle 1 to 3 manually since thise checks only numbers >= 4.
Note: by definition 1 is not prime
*/
#include <iostream>
#include <string>
#include <cmath>
#include <cctype> //isdigit()

bool isPrime(int n){
    bool bFoundFactor = false;
    if(n <= 1){
        return false;
    }else if(n<= 3){
        return true;
    }
    for( int candidate =2; !bFoundFactor && candidate <= sqrt(n); ++candidate){
        if(n % candidate == 0){
            bFoundFactor = true;
        }
    }
    return !bFoundFactor;
}

//only the address of the first elements of the array will passed into the function
//need to pass the array size as well
bool no_digit(char arr[], int size){
    //dont try calculating size from inside the function;
    for( int i = 0; i < size; ++i){
        char ch = arr[i];
        //'0' is char; 0 is int 
        if(arr[i] >= '0' || arr[i] <= '9'){
            return false;
        }
    }
    return true;
}

//can use DeMorgans law on if statement condition
bool only_digit(char arr[], int size){
    for(int i =0 ;i < size;++i ){
        if( !(arr[i] >= '0' && arr[i] <= '9') ){
            return false;
        }
    }
    return true;

}


   


int main(){
    char arr[] = {'a', 'b', 'c'};
    int size = (sizeof(arr)) / (sizeof(arr[0]));
    std::cout << std::boolalpha << no_digit(arr, size)<< 0+'z' << '\n';
    return 0; 
}
