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
    //will convert to char on assigning
    
    char shifted = c+rshift;
    return shifted;

}

std::string encryptCaesar(std::string plaintext, int rshift){
    //params are pass by value, so this plaintext is different from what was passed in
    for(int i =0; i< plaintext.size(); ++i){
        char shifted = shiftChar(plaintext.at(i), rshift);
        plaintext[i] = shifted;
    }
    return plaintext;
}
 
