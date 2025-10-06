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
 
also can use interval [2, sqrt(n)]
#include <cmath>
(int) std::sqrt(n);
Note: handle 1 to 3 manually since thise checks only numbers >= 4.
Note: by definition 1 is not prime
bool numDigits(std::string str){
    for(char in str){
        if(){
        
        }
    }
}
    

*/

int main(){

    return 0;
}
