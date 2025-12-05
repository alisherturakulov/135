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


/**start the game
  *
*/
void TicTacToeGame::runRepeat(){
	std::cout << "start runRepeat()\n";
	//bool start = true;
	std::string continueInput{};
	
	
	do{
/* 		if(start){
			start = false;
		}
 */		start();
		
		std::cout << "Do you want to continue (yes/no): ";
		std::cin >> continueInput;
	}while(continueInput == "yes" || continueInput.at(0) == 'y');
	std::cout << "exit runRepeat\n";
}


/**Start a round
*/
void TicTacToeGame::start(){
	while(!isGameOver()){
		//rounds
	}
	return;
	std::cout << "ran start" << std::endl;
}

/**Check if the game is over
  *@return bool whether or not the game is over
*/
bool TicTacToeGame::isGameOver() const{
	return true;
}


/**ask for user input for the row, col on the board
  *
*/
void TicTacToeGame::humanPlay(){}


/**make the computer play a turn
  *
*/
void TicTacToeGame::computerPlay(){}
