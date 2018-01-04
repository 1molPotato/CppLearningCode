#include "TicTacToe.h"
#include <iostream>
using namespace std;

//test program
int main(){
	TicTacToe *t = new TicTacToe;//initialize the game	
	cout << "gamer1 plays first, then play in turn" << endl;
	cout << "game begin: " << endl;
	t->printBoard();
	int gamer = 1;//gamer 1 play first
	while(true){
		int i, j, result;
		cout << "gamer " << gamer << " play: ";
		cin >> i >> j;
		result = t->move(i, j, gamer);
		if(-1 == result)
			continue;
		gamer = gamer % 2 + 1;//play in turn
		t->printBoard();//print the board
		if(0 == result)
			continue;//game continue
		else if(3 == result)
			cout << "game over, tie" << endl;
		else
			cout << "gamer " << result << " won" << endl;
		break;
	}
	delete t;
	return 0;
}