/*
135 lecture 9-25
array input with cin, 
will stop after array's filled, or if cin returns false: input stopped or invalid
cin can be stopped with ctrl-z on windows for end of input (ctrl-d mac).

on linux command line:
bc -le  "(sum)  / count"

ex. 
while(count < cap && cin >> num){

}

Accumulation functions maintain a sum and add each array element, 
then use the sum: ex. to calculat avg.
integer division requires double conversion.

double average = 1.0 * sum / count;
c-style type casting
double average = (double) sum/ count;

chars are a subset of ints, 1+'A' converts to int 66; can type cast to 'B'
can use a for loop from 0 to 26 with a (char) (i+'A');

asterix pattern: print row asterixs for every row
*\n
**\n
***\n

int size= 5; 
int numAsts = 1; 

while(numAsts <= size){
    //numPreSp = num preceding spaces before first *
    //num SuccSp = num succeeding spaes after last *
    //each has only spaces and asterisks
    //numPre + numAst + numSucc = size
    //by symmetry numPre = numSucc
    //2* numPre + numAsts = size
    //numPre = (size - numAsts) / 2;

    //print pre
    for(int i=0; i< (size-numAsts)/2; i++){
     print preceding " "
    }

    //print ast
    for(int i =0; i < numAsts; i++){
    
    }
    //newline
    cout << '\n'
    numAsts+=2;
}

Intro to Classses:
    Classse provide: Encapsulation, Abstraction, and Polymorphism
    String is a class; has data char array and methods on the data.
    method size_t size() const; const means the methods don't modify the data of the class.

    the concat op + doesn't apply to c-style strings: "hello" + " , world" is invalid in C++
    if at least one is a String class, then + op works: str += ", world";

    access using [] after string var identifier or .at() method.


    Funcitons are overloaded if:
        same name
        similar funcitonality
        different input parameters (in type, num, and/or order)
        returns do not matter, can be same or different
    Example: 
    find methods in string class, 
        notice default value of pos (optional param to search starting from index)
    size_t find(const string& str, size_t pos = 0) const;
    size_t find(char* c, size_t pos = 0) const;

    next occurence would take found index+1 (size_t types)

    substr9) method of string class: npos chars starting from pos 
    std::string substr(size_type pos = 0, size_type len = npos) const;

*/
#include <iostream>

int main(){
    std::cout << "open file to see notes";
    return 0;
}