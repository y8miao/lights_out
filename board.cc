#include <iostream>
#include "board.h"
#include "grid.h"

using std::cout;
using std::endl;

Board::Board(int size):gameSize(size){
	//pass 1, instantiate all the Grids
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			Grid *temp = new Grid();
			playBoard[i][j] = temp;
		}
	}
	//pass 2, attach the observers to each Grid
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(i-1 >= 0) (playBoard[i][j])->attach(playBoard[i-1][j]);
			if(j-1 >= 0) (playBoard[i][j])->attach(playBoard[i][j-1]);
			if(i+1 < size) (playBoard[i][j])->attach(playBoard[i+1][j]);
			if(j+1 < size) (playBoard[i][j])->attach(playBoard[i][j+1]);
		}
	}
}

void Board::toggle(int x, int y){
	(playBoard[x][y])->toggle();
}

void Board::drawBoard(){
	for(int i = 0; i < gameSize; i++){
		for(int j = 0; j < gameSize; j++){
			if((playBoard[i][j])->getState()) cout<<"O";
			else cout<<"X";
		}
		cout<<endl;
	}
}

bool Board::win(){
	for(int i = 0; i < gameSize; i++){
		for(int j = 0; j < gameSize; j++){
			if(!((playBoard[i][j])->getState())) return 0;
		}
	}
	return 1;
}

Board::~Board(){
	for(int i =0; i < gameSize; i++){
		for(int j = 0; j < gameSize; j++){
			delete (playBoard[i][j]);
		}
	}
}