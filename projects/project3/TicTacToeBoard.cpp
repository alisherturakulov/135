/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: Project 3AB

implements the constructor and the member methods of TicTacToeBoard
*/
//include class declaration
#include "TicTacToeBoard.hpp"
#include <iostream>
#include <string>

using namespace std;
//Do not forget TicTacToeBoard:: before constructors and methods of TicTacToeBoard class
//TODO: default constructor creates a 3x3 board 
TicTacToeBoard::TicTacToeBoard(): TicTacToeBoard(3){
	/*for(int i =0; i<3; ++i){
		// intiialize each row with 3 spaces
		std::vector<char> row(3, ' ');
		board.push_back(row);
		
	}*/
}

//TODO: If givenSize is less than 3, create a 3x3 board.
//Otherwise, initialize the board with the given size for both rows and columns.
TicTacToeBoard::TicTacToeBoard(int givenSize) {
	int size = givenSize;
	if(givenSize < 3){
		size = 3;
	}
	//std::cout << "constructor: \n";
	for(int i =0 ;i<size; ++i){
		vector<char> aRow(size, ' ');
		this->board.push_back(aRow);
		//std::cout << "at " << i << "," << i << ":" << board[i][i] << '\n';
	}
	
}

//TODO: set each cell of the board to be a space character.
//Warning: our clear method of TicTacToeBoard is different from clear method of a vector.
//(1) clear method of a vector removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
//(2) That is, board.clear() removes all elements of board and make board an empty vector.
//(3) Our clear method does not change the structure of board -- its number of rows and number of columns will still keep the same -- just set each element to be a space.
void TicTacToeBoard::clear() {
	
	for(int i = 0; i<board.size(); ++i){
		for(int j=0;j<board.size(); ++j){
			board[i][j] = ' ';
		}
	}
}

//TODO: if row and col are valid indices,
//return the value of the cell of the board at (row, col)
//otherwise, return 'W' (means wrong)
//Warning: a function with non-void return type
//needs to return a value of that return type in every execution path.
char TicTacToeBoard::getValue(int row, int col) const {
	if(isValidRow(row) && isValidCol(col)){
		return this->board[row][col];
	}
    return 'W'; 
}

//TODO: Checks if the cell at (row, col) is available or not.
//A cell is available if the following conditions satisify.
//(1) row and col indices are valid 
//(2) the value at that cell is a space character (' ').
//Otherwise, the cell is not available.
bool TicTacToeBoard::isAvailable(int row, int col) const {
    return isValidRow(row) && isValidCol(col) && board[row][col] == ' '; //TODO: placeholder
}

//TODO: Check whether the given parameter row is valid row index or not.
//that is, whether row is in [0, board.size()-1]
bool TicTacToeBoard::isValidRow(int row) const {
    return row >= 0 && row < board.size();
}

//TODO: Check whether the given parameter col is a valid column index or not
//that is, whether col is in [0, board[0].size()-1]
bool TicTacToeBoard::isValidCol(int col) const {
    return col >= 0 && col < board.size();
}

//Finish first!!
//TODO: Return the number of rows of board  
int TicTacToeBoard::size() const {
    return board.size(); // may have 4x4, 5x5, ... board
}

//TODO: IF row and col are valid indices, 
//place symbol at board[row][col],
//otherwise, do nothing.
//Note that before we can use board[row][col],
//need to make sure that row and col indices are valid.
void TicTacToeBoard::mark(int row, int col, char symbol) {
    if( isValidRow(row) && isValidCol(col) ){
		board[row][col] = symbol;
	}
}

//TODO: Return a string representation of the contents of board.
//(1) The returned string typically formats the board in a grid layout
//for easy display and debugging.
//(2) 'X', 'O', and ' ' characters in the string are
//    separated by ONLY ONE vertical bar pipe character '|'.
//    For example, one row with values 'X', ' ', and 'O' looks like
//    | X |  | O |

//prints the horizontal borders for a board of given size
std::string drawLine(int size);

//return a string representing the board
std::string TicTacToeBoard::to_string() const {
	std::string ret_str = "     0";
	for(int i =1; i< size(); i++){
		ret_str += "   ";
		ret_str += std::to_string(i); //convert integer to string before concatenating
	}
	ret_str += "  ";
	ret_str += "\n";
	ret_str += drawLine(board.size());
	for(int i=0; i< board.size(); ++i){
		ret_str += " ";
		ret_str += std::to_string(i);
		ret_str += ' ';
		for(int j =0; j < board.size(); ++j){
			//try{
			//char value = board[i][j];
			ret_str += "| ";
			ret_str += board[i][j];
			ret_str += ' ';
			
		}
		ret_str +=  "|\n";
		ret_str += drawLine(board.size());
	}
	
   return ret_str; 
}

std::string drawLine(int size){ //doesnt need const; non-member helper function
	std::string str = "   +";//initial space
	for(int i= 0;i<size; ++i){
		str += "---+";
	}
	str += "\n";
	return str;
}

//TODO: If every single row, column, main diagonal, AND anti-diagonal 
//each contain both 'X' and 'O' symbols,
//then the board is in a tie state (return true).
//Otherwise, if any of those lines (row/col/main diagonal/anti-digonal)
//is missing an 'X' or an 'O', a win is still possible (return false for tie status).
bool TicTacToeBoard::tie() const {
	int countXr{};//looks like a love letter
	int countOr{};
	int countXc{};
	int countOc{};
	int countXd{};
	int countOd{};
	int countXa{};
	int countOa{};
	const int size = board.size();
	for(int i{}; i<size; ++i){
		
		countXr =0;
		countOr = 0;
		countXc = 0;
		countOc = 0;
		for(int j{}; j<size; ++j){
			//going across each row
			if(countXr == 0 || countOr == 0){//stop counting once a row is found with both
				if(board[i][j] == 'X'){
					countXr++;
				}else if( board[i][j] == 'O'){
					countOr++;
				}
			}
			//going down each col
			if(countXc ==0 || countOc == 0){
				if(board[j][i] == 'X'){
					countXc++;
				}else if(board[j][i] == 'O'){
					countOc++;
				}
			}
		}
			if(countXr ==0 || countOr ==0 /* && (countXr+countOr >0) */ ){
				return false;
			}
			if(countXc ==0 || countOc==0 /* && (countXc+countOc >0) */ ){
				return false;
			}
	}
	//checking diagnol '\\'
	for(int i =0; i<size; i++){
	
		if(board[i][i] == 'X'){
			countXd++;
		}else if( board[i][i] == 'O'){
			countOd++;
		}
			
		//chekcing anti-diagnol '//'
		if(board[i][size-1-i] == 'X'){
			countXa++;
		}else if( board[i][size-1-i] == 'O'){
			countOa++;
		}
			
	}
	if(countXa==0 ||countOa==0){
		return false;
	}
	if(countXd==0 ||countOd==0){
		return false;
	}
	//check for a tie (all possible configurations contain both symbols
	return true;
	
}

//TODO: Check whether the player at row and col wins.
//If there is any win in horizonal, vertical,
//diagonal, or anti-diagonal direction, return true,
//otherwise, return false.
bool TicTacToeBoard::win(int row, int col) const {
    return winByRow(row, col) || winByCol(row, col) || winByDiagonal(row, col); //TODO: placeholder
}

//TODO: Check Horizontal Win: 
//Evaluate the row containing the cell (row, col). 
//If the current player's symbol forms a continuous, 
//unbroken sequence of the required length within this row, 
//the function returns true (win found); otherwise, it returns false.
//Check whether the player at (row, col) can win that row or not.
bool TicTacToeBoard::winByRow(int row, int col) const {
	int countX{};
	int countO{};
	const int size = board.size();
	for(int i =0; i<board.size(); i++){
		
		
			if(board[row][i] == 'X'){
				countX++;
			}else if(board[row][i] == 'O'){
				countO++;
			}
	}
/* 	if(countX == size ){
			return true;
		}
		if(countX == size ){//typo; I didn't check countO
			return true;
		}
 */   return countX == size || countO == size;
}
//TODO: Check Vertical Win: 
//Evaluate the column containing the cell (row, col). 
//If the current player's symbol forms a continuous, 
//unbroken sequence of the required length within this column, 
//the function returns true (win found); otherwise, it returns false.
bool TicTacToeBoard::winByCol(int row, int col) const {
	int countX{};
	int countO{};
	const int size = board.size();
	for(int i =0; i<board.size(); i++){
		
		
			if(board[i][col] == 'X'){
				countX++;
			}else if(board[i][col] == 'O'){
				countO++;
			}
	}
/* 	if(countX == size ){
			return true;
		}
		if(countX == size ){//same typo; countO needs a check
			return true;
		}
 */   return countX == size || countO == size; //TODO: placeholder
}

//TODO: Check Digonal (including both diagonal and anti-diagonal) Win: 
//If the cell (row, col) is not in diagonal or anti-diagonal, return false.
//If the cell (row, col) is in the diagonal,
//evaluate the diagonal containing the cell (row, col). 
//If the current player's symbol forms a continuous, 
//unbroken sequence of the required length within this diagonal, 
//the function returns true (win found); 
//otherwise, evaluate the anti-diagonal containing the cell (row, col). 
//If the current player's symbol forms a continuous, 
//unbroken sequence of the required length within this anti-diagonal, 
//the function returns true (win found); otherwise, return false. 
bool TicTacToeBoard::winByDiagonal(int row, int col) const {
	bool wdiagonal{true};
	bool wanti_diagonal{true};
	const int size = board.size();
	//if(board[row][col] == ' '){
	//	return false;
	//}
	if(row == col || col == (size-1-row)){//check that cell is in a diagnol
		const char& playerSymbol = board[row][col];
		for(int i{}; i<size; ++i){
			if(board[i][i] != playerSymbol){
				wdiagonal = false;
			}
			if(board[i][size-1-i] != playerSymbol){
				wanti_diagonal = false;
			}
		}
/* 		if(row == col){//this is wrong; it short circuits if row,col is the center cell
			return wdiagnol;
		}
		if(col == size-1-row){
			return wanti_diagnol;
		}
 */	}else{return false;}
 
	if(row!= col){
		wdiagonal = false;
	}else if(col != size-1-row){
		wanti_diagonal = false;
	}	
	
   return wdiagonal || wanti_diagonal; //TODO: placeholder
}
