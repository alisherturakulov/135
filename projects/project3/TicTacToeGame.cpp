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
TicTacToeGame::TicTacToeGame(int size): tttBoard(size){//to prevent errors in isGameOver
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
		tttBoard.clear();
	}while(continueInput == "yes" || continueInput.at(0) == 'y');
	std::cout << "exit runRepeat\n";
}


/**Start a game and stop once its over
*/
void TicTacToeGame::start(){
	int round{1};
	int debugContinue{};
	std::cout << tttBoard.to_string();//initial print
	
	//round 1
	std::cout << "User, enter row and col to place X: ";
	std::cin >> currRow >> currCol;
	humanPlay();//uses currRow/Col
	std::cout << tttBoard.to_string();
	round++;
	
	while( !isGameOver() ||  debugContinue != -1){
		//rounds
		std::cout << "Round " << round << ": ";
		if(round % 2 == 1){
			std::cout << "User, enter row and col to place X: ";
			std::cin >> currRow >> currCol;
			humanPlay();//uses currRow/Col
			std::cout << tttBoard.to_string();
			round++;
		}else{
			computerPlay();//updates currRow/Col
			std::cout << "Round " << round << ": Computer places O at row" << currRow << " and col " << currCol << '.';
			std::cout << tttBoard.to_string();
			round++;
		}
		std::cout << "enter -1 to end";
		std::cin >> debugContinue;
	}
}

/**Check if the game is over
  *@return bool whether or not the game is over
*/
bool TicTacToeGame::isGameOver() const{
	if(tttBoard.tie()){
		std::cout << "It is a tie.\n" ;
		return true;
	}else if(tttBoard.win(currRow, currCol)){//the game stops at a win, so 
		if(tttBoard.getValue(currRow, currCol) == 'X'){//check who won by ID
			std::cout << "Human Wins. Yay!!!\n";
		}else{
			std::cout << "Computer Wins. Yuck.\n";
		}
		return true;
	}
	
	return false;
}


/**ask for user input for the row, col on the board, updates currRow/Col
  *
*/
void TicTacToeGame::humanPlay(){
	//note: if there are no possible turns, this method would not be called; no infinite loop
	while(!tttBoard.isValidRow(currRow) || !tttBoard.isValidCol(currCol) || !tttBoard.isAvailable(currRow, currCol)){
		std::cout << "Error: row/col is incorrect; please reenter row and col indices: ";
		std::cin >> currRow >> currCol;
	}
	
	tttBoard.mark(currRow, currCol, HUMAN_ID);
}


/**make the computer play a turn, updates currRow/Col
  *
*/
void TicTacToeGame::computerPlay(){}
