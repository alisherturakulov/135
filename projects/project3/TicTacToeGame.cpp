/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: Project 3C

implements the constructor and the member methods of TicTacToeGame
*/

//include class declaration
#include "TicTacToeGame.hpp"

//using namespace std;


/**Default Constructor initializes tttBoard member using its default constructor
  *
*/
TicTacToeGame::TicTacToeGame(): tttBoard(){
	//tttBoard already initialized in list
}

/**non-Default Constructor initializes tttBoard member with custom size
  *@param size, game board size
*/
TicTacToeGame::TicTacToeGame(int size): tttBoard(size){
	//tttBoard already initialized in decalration
}


/**
  *
*/
void TicTacToeGame::runRepeat(){
	
	std::cout << "ran runRepeat\n";
}


//Start the game loop
void TicTacToeGame::start(){
	
	std::cout << "ran start" << std::endl;
}

/**Check if the game is over
  *@return bool whether or not the game is over
*/
bool TicTacToeGame::isGameOver() const{
	return false;
}


/**
  *
*/
void TicTacToeGame::humanPlay(){}


/**
  *
*/
void TicTacToeGame::computerPlay(){}
