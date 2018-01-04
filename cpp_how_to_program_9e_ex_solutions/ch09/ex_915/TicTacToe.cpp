#include <iostream>
#include "TicTacToe.h"

using namespace std;

TicTacToe::TicTacToe(){
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			positions[i][j] = 0;//set every position to zero
		}
	}
}

bool TicTacToe::setPosition(int i, int j, unsigned int gamer){
	if(gamer > 2) {
		cout << "2 gamers at most" << endl; 
		return 0;
	}		
	if(i < 0 || i > 2 || j < 0 || j > 2) {
		cout << "size of board is only 3x3" << endl; 
		return 0;
	}	
	if(0 != getPosition(i, j)) {
		cout << "this position has been occupied" << endl; 
		return 0;
	}	
	positions[i][j] = gamer;
	return 1;
}

int TicTacToe::move(int i, int j, unsigned int gamer){
	if(!setPosition(i, j, gamer))
		return -1;//invalid step
	return checkResult();
}

int TicTacToe::checkResult(){
	for(int i = 0; i < 3; ++i){
		if(getPosition(i, 0) == getPosition(i, 1)
		&& getPosition(i, 1) == getPosition(i, 2)
		&& 0 != getPosition(i, 0))
			return getPosition(i, 0);
	}
	for(int i = 0; i < 3; ++i){
		if(getPosition(0, i) == getPosition(1, i) 
		&& getPosition(1, i) == getPosition(2, i)
		&& 0 != getPosition(0, i))
			return getPosition(0, i);
	}
	if(getPosition(0, 0) == getPosition(1, 1) 
	&& getPosition(1, 1) == getPosition(2, 2)
	&& 0 != getPosition(0, 0))
		return getPosition(0, 0);
	if(getPosition(0, 2) == getPosition(1, 1) 
	&& getPosition(1, 1) == getPosition(2, 0)
	&& 0 != getPosition(0, 2))
		return getPosition(0, 2);
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			if(0 == getPosition(i, j))
				return 0;//game continue
		}
	}
	return 3;//tie
}

int TicTacToe::getPosition(int i, int j) {
	return positions[i][j];
}

void TicTacToe::printBoard(){
	for(int i = 0; i < 3; ++i){
		for(int j = 0;j < 3; ++j){
			cout << getPosition(i, j) << ' ';
		}
		cout << '\n';
	}
}






















