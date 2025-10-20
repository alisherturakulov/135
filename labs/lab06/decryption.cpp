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
	/*
	char ch;
	int s;
	std::cin >> ch;
	std::cin >> s;
	std::cout << shiftChar(ch, s);
	*/
	std::cout << "Enter plaintext: ";
	getline(std::cin, plaintext);
	
	
	std::cout <<"\n\n= Caesar =\n";
	
	int rshift{};
	std::cout << "Enter shift    : ";
	std::cin >> rshift;
	getline(std::cin, plaintext);//remove newline
	
	std::string cipherText{};
	std::cout << "Ciphertext     : ";
	getline(std::cin, cipherText);
	
	std::string decrypted = decryptCaesar(cipherText, rshift);
	std::cout << "Decrypted      : ";
	std::cout << decrypted;
	
	
	std::cout <<"\n\n= Vigenere =\n";
	
	std::string keyword{};
	std::cout <<"Enter keyword   : ";
	std::getline(std::cin, keyword);
	
	std::cout << "Ciphertext     : ";
	getline(std::cin, cipherText);
	
	decrypted = decryptVigenere(cipherText, keyword);
	std::cout << "Decrypted      : ";
	std::cout << decrypted;
	std::cout << '\n';
	
	return 0;
}

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
	//if negative shift	
	}else if(ch < 91 && (shift+ch < 65)){
		//subtract num of chars to z
		//char value to add to for overflow
		const int AFTER_Z = 91;
		
		shift = shift + (ch-65);
		//handle further overflow by taking remainder
		shift %= 26;
		std::cout <<shift << " shift";
		ch = AFTER_Z + shift;
	//when the letter is lower and shift passes z
	}else if((ch < 123 && (shift + ch > 122)) && ch > 90){
		const int BEFORE_a = 96;
		
		shift = shift - (122 - ch);
		shift %= 26;
		
		ch = BEFORE_a +shift;
	}else if((ch < 123 && (shift + ch < 97)) && ch > 90){
		//subtract num of chars to z
		//char value to add to for overflow
		const int AFTER_z = 123;
		
		shift += (ch-97);
		//handle further overflow by taking remainder
		shift %= 26;
		
		std::cout <<shift << " shift";
		ch = AFTER_z + shift;
	}else{
		ch += shift;
	}
	
	return ch;
}

std::string decryptCaesar(std::string ciphertext, int rshift){
	for(std::size_t i = 0; i<ciphertext.length(); ++i){
		char curr = ciphertext[i];
		if(std::isalpha(curr)){
			char shifted = shiftChar(curr, (-1*rshift));
			ciphertext[i] = shifted;
		}
	}
	
	return ciphertext;
}

std::string decryptVigenere(std::string ciphertext, std::string keyword){
	//for cycling through keyword when applying it to encrypt
	int keyIndex{};
	int keyLen = keyword.length();
	//ciphertext is pass by value, so we'll directly modify it
	for(std::size_t i =0; i< ciphertext.length(); ++i){
		//only shift letters
		char curr = ciphertext[i];
		if(std::isalpha(curr)){
			//'a' represents a shift of zero, 'b' 1, ...; 
			//so, we need to -65 to get the shift
			int shift = (keyword[keyIndex]-'a')*-1;
			char newChar = shiftChar(curr, shift);
			ciphertext[i] = newChar;
			keyIndex = (keyIndex+1) % keyLen;
		}
	}
	//return now encrypted plaintext
	return ciphertext;
}