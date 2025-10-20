/*
Author: Alisherjon Turakulov
Course: CSCI 135 
Instructor: Tong Yi
Assingment: Lab6D

Implement decryption functions for caesar cipher and vigenere
ciphere encrypted plaintext that use the right/keyword shift 
to decrypt
*/

#include <iostream>
#include <string>
#include <cctype>

char shiftChar(char& ch, int shift);
std::string decryptCaesar(std::string ciphertext, int rshift);
std::string decryptVigenere(std::string ciphertext, std::string keyword);

int main(){
	std::string plaintext{};
	std::cout << "Enter plaintext: ";
	getline(std::cin, plaintext);
	
	
	std::cout <<"\n\n= Caesar =\n";
	
	int rshift{};
	std::cout << "Enter shift    : ";
	std::cin >> rshift;
	
	std::string cipherText{};
	std::cout << "Ciphertext     : ";
	std::cin >>cipherText;
	
	std::string decrypted= decryptCaesar(cipherText, rshift);
	std::cout << "Decrypted      : ";
	std::cout <<decrypted;
	
	
	std::cout <<"\n\n= Vigenere =\n";
	
	std::string keyword{};
	std::cout <<"Enter keyword   : ";
	std::cin >> keyword;
	
	std::cout << "Ciphertext     : ";
	std::cin >> cipherText;
	
	decrypted = decryptVigenere(cipherText, keyword);
	std::cout << "Decrypted      : ";
	std::cout << decrypted;
	std::cout << '\n';
	return 0;
}

char shiftChar(char& ch, int shift){
	
	return ch;
}
std::string decryptCaesar(std::string ciphertext, int rshift){
	
	return ciphertext;
}

std::string decryptVigenere(std::string ciphertext, std::string keyword){
	
	return ciphertext;
}