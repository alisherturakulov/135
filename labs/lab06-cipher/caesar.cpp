/*
Author: Alisherjon Turakulov
Course: CSCI 135
Instructor: Tong Yi
Assignment: Lab6B

takes in a line of text, an integer n representing the right shift, and prints out the 
caesar cipher shifted n units to the right of the text.
*/

#include <iostream>
#include <string> 
#include <cctype>

//forward declarations
// A helper function to shift one character by rshift
char shiftChar(char c, int rshift);

// Caesar cipher encryption
std::string encryptCaesar(std::string plaintext, int rshift);

int main(){
    std::string text;
    std::cout << "Enter plaintext: ";
    getline(std::cin, text);
    int s{};
    std::cout << "Enter shift: ";
    std::cin >> s;

    std::string cipherText = encryptCaesar(text, s);
    std::cout << "Ciphertext: " << cipherText << '\n';

    return 0;
}

char shiftChar(char c, int rshift){
    if(!std::isalpha(c)){
        return c;
    }
    //convert to int
    int cInt = (int) c;
    //std::cout << c << " is ; " << cInt<< '\n';
    //is an int to prevent signed char overflow errors (past 128)
    int shifted = cInt+rshift;
    if(c <= 'Z' && shifted > 'Z'){
        //for uppercase overflows.
        rshift = rshift - (90 - cInt);
        shifted = 64 + (rshift % 26);
        if(rshift % 26 ==0){
            shifted = 64+26;
        }
    }else if(c <= 'z' && shifted > 'z'){
        //std::cout << c << "will be changed to ";
        // first decrement rshift until we can add starting from the first letter of the alphabet
        rshift = rshift - (122 -cInt);
        // otherwise rshift would give the same value of h if given x,y,z shift +8.
        shifted = 96 + (rshift % 26);
        //so that if rshift is 25 we dont end up with a non-alphabet char
        if(rshift % 26 == 0){
            shifted = 96 + 26;
        }
    }
    
    char ret = (char) shifted;
    
    return ret;

}

std::string encryptCaesar(std::string plaintext, int rshift){
    //params are pass by value, so this plaintext is different from what was passed in
    for(int i =0; i< plaintext.size(); ++i){
        char ch = plaintext.at(i);
        if(std::isalpha(ch)){
            char shifted = shiftChar(ch, rshift);
            plaintext[i] = shifted;
        }
    }
    return plaintext;
}
 
