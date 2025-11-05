/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: Lab6C

Implements a functions encryptVigenere that takes a plaintext string,
keyword string, and uses the all lowercase keyword to shift the characters
in the plaintext and returns the encrypted string.
*/

#include <iostream>
#include <string>
#include <cctype>

//function forward declaration
std::string encryptVigenere(std::string plaintext, std::string keyword);

//helper function to apply caesar cipher shift
char shiftChar(char& ch, int shift);

int main(){
	std::string plaintext{};
	std::string keyword{};
	std::cout << "Enter plaintext: ";
	std::getline(std::cin, plaintext);
	std::cout << "Enter keyword  : ";
	std::cin >> keyword;
	std::string cipherText = encryptVigenere(plaintext, keyword);
	std::cout << "CipherText     : " << cipherText << '\n';
	return 0;
}

//@params char to shift and amount
//@return shifted char
char shiftChar(char& ch, int shift){
	//check 
	if(!std::isalpha(ch)){
		return ch;
	}
	
	//when the letter is upper and a shift would pass Z
	if(ch < 91 && (shift + ch > 90)){
		//subtract num of chars to z
		//char value to add to for overflow
		const int BEFORE_A = 64;
		
		shift = shift - (90-ch);
		//handle further overflow by taking remainder
		shift %= 26;
		
		ch = BEFORE_A +shift;
	//when the letter is lower and shift passes z	
	}else if(ch < 123 && (shift + ch > 122)){
		const int BEFORE_a = 96;
		
		shift = shift - (122 - ch);
		shift %= 26;
		
		ch = BEFORE_a +shift;
	}else{
		ch = ch+shift;
	}
	
	return ch;
}

//@params plaintext string to apply vigenere 
//        shift using given lowercase keyword 
//@return the encrypted plaintext string
std::string encryptVigenere(std::string plaintext, std::string keyword){
	//for cycling through keyword when applying it to encrypt
	int keyIndex{};
	int keyLen = keyword.length();
	//plaintext is pass by value, so we'll directly modify it
	for(std::size_t i =0; i< plaintext.length(); ++i){
		//only shift letters
		char curr = plaintext[i];
		if(std::isalpha(curr)){
			//'a' represents a shift of zero, 'b' 1, ...; 
			//so, we need to -65 to get the shift
			int shift = keyword[keyIndex]-'a';
			char newChar = shiftChar(curr, shift);
			plaintext[i] = newChar;
			keyIndex = (keyIndex+1) % keyLen;
		}
	}
	//return now encrypted plaintext
	return plaintext;
}