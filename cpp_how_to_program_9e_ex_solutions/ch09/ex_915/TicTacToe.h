#pragma once

class TicTacToe{
public:
	TicTacToe();//default constructor
	//set functions
	bool setPosition(int i, int j, unsigned int gamer);	
	int move(int i, int j, unsigned int gamer);//set position and determine result
	//return 1 if gamer 1 wins, return 2 if gamer 2 wins, return 3 if tie, else return 0
	int checkResult();//check after every move
	//get functions
	int getPosition(int i, int j);//get num in (i, j) position
	//print functions
	void printBoard();
private:
	int positions[3][3];	
};