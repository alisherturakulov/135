/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: Project 3D

implements the constructor and the member methods of TicTacToeGame
*/

//include class declaration
#include "TicTacToeGame.hpp"


using namespace std;


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
	//std::cout << "start runRepeat()\n";
	//bool start = true;
	std::string continueInput{};
	
	start();
	tttBoard.clear();
	std::cout << "Do you want to continue (yes/no): ";
	std::cin >> continueInput;
	
	
	while(continueInput == "yes" || continueInput.at(0) == 'y'){
		start();
		tttBoard.clear();
		std::cout << "Do you want to continue (yes/no): ";
		std::cin >> continueInput;
	
		
	}
	//std::cout << "exit runRepeat\n";
}


/**Start a game and stop once its over
*/
void TicTacToeGame::start(){
	int round{1};
	//int debugContinue{};
	std::cout << tttBoard.to_string();//initial print
	
	//round 1
	std::cout << "Round " << round << ": ";
	std::cout << "User, enter row and col to place X: ";
	std::cin >> currRow >> currCol;
	humanPlay();//uses currRow/Col
	std::cout << tttBoard.to_string();
	round++;
	
	while( !isGameOver() /*||  debugContinue != -1*/){
		//rounds
		std::cout << "Round " << round << ": ";
		if(round % 2 == 1){
			std::cout << "User, enter row and col to place X: ";
			std::cin >> currRow >> currCol;
			humanPlay();//uses currRow/Col
			std::cout << tttBoard.to_string();
			
		}else{
			computerPlay();//updates currRow/Col
			std::cout << "Round " << round << ": Computer places O at row " << currRow << " and col " << currCol << ".\n";
			std::cout << tttBoard.to_string();
			
		}
		round++;
/* 		std::cout << "enter -1 to end";
		std::cin >> debugContinue;
 */	
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
		char currSymbol = tttBoard.getValue(currRow, currCol);
		if(currSymbol == 'X'){//check who won by ID
			std::cout << "Human wins. Yay!!!\n";
		}else if(currSymbol == 'O'){
			std::cout << "Computer wins. Yuck.\n";
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
  *Checks for a win, a draw, and otherwise marks the first available cell
*/
void TicTacToeGame::computerPlay(){
	/*bool canWin{true};
	bool canDraw{true};
	const int SIZE{tttBoard.size()};
	
	for(int i{0}; i < SIZE; ++i){
		for(int j={0}; j< SIZE; ++j){
			if(tttBoard.isAvailable(i,j)){//only if the cell is empty
				if(canWin){
					tttBoard.mark(i, j, COMPUTER_ID);
					if(tttBoard.win(i, j)){
						currRow = i;
						currCol = j;
						std::cout << "chose first win\n";
						return;
					}
					tttBoard.mark(i, j, ' ');
					if(i == SIZE-1 && j == SIZE-1){
						canWin=false;
						i= 0;//will be 0 after this iteration
						j= -1;
						std::cout << "cant win\n";
					}
					
				}else if(canDraw){
					tttBoard.mark(i, j, HUMAN_ID);
					if(tttBoard.win(i, j)){
						tttBoard.mark(i, j, COMPUTER_ID);
						currRow = i;
						currCol = j;
						std::cout << "chose first draw\n";
						return;
					}
					tttBoard.mark(i, j, ' ');//unmark if cell wont draw
					if(i==SIZE-1 && j == SIZE-1){
						canDraw = false;
						i= 0;
						j= -1;
						std::cout << "cant draw\n";
					}
				}else{
					tttBoard.mark(i, j, COMPUTER_ID);
					currRow = i;
					currCol = j;
					//i = SIZE;
					//j = SIZE;
					std::cout << "chose first available\n";
					return;
				}
			}else if(i == SIZE-1 && j == SIZE-1){
				std::cout << "none available\n";
			}else{
				std::cout << i << " " << j << " not available.\n";
			}
		}
	}*/
	bool canWin{true};
	bool canDraw{true};
	const int SIZE{tttBoard.size()};
	
	for(int i{0}; i < SIZE; ++i){
		for(int j{0}; j< SIZE; ++j){
			if(tttBoard.isAvailable(i,j)){//only if the cell is empty
				if(canWin){
					tttBoard.mark(i, j, COMPUTER_ID);
					if(tttBoard.win(i, j)){
						currRow = i;
						currCol = j;
						//std::cout << "chose first win\n";
						return;
					}
					tttBoard.mark(i, j, ' ');
					if(i == SIZE-1 && j == SIZE-1){
						canWin=false;
						i= -1;//will be 0 after this iteration
						j= -1;
					}
					
				}else if(canDraw){
					tttBoard.mark(i, j, HUMAN_ID);
					if(tttBoard.win(i, j)){
						tttBoard.mark(i, j, COMPUTER_ID);
						currRow = i;
						currCol = j;
						//std::cout << "chose first draw\n";
						return;
					}
					tttBoard.mark(i, j, ' ');//unmark if cell wont draw
					if(i==SIZE-1 && j == SIZE-1){
						canDraw = false;
						i= -1;
						j= -1;
					}
				}else{
					tttBoard.mark(i, j, COMPUTER_ID);
					currRow = i;
					currCol = j;
					//std::cout << "chose first available\n";
					return;
				}
			}/*else if(i == SIZE-1 && j == SIZE-1){
				std::cout << "none available\n";
			}*/
		}
	}
}
