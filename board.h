#ifndef BOARD_H
#define BOARD_H

class Grid;

class Board{
	//could improve to dynamic
	Grid *playBoard[9][9];
	int gameSize;
public:
	Board(int size);
	void toggle(int x, int y);
	void drawBoard();
	bool win();
	~Board();
};

#endif