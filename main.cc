#include <iostream>
#include "grid.h"
#include "board.h"

using std::cin;
using std::cout;
using std::endl;

int main (void){
	int input, x, y;
	char char_in;
	//flag
	int terminate = 0;
	cout<<"please specify the size of the game you want to play:(2-9)"<<endl;
	while(1){
		//check
		if(!(cin>>input)) break;
		if(input>=2 && input <=9){
			int pos_x, pos_y;
			Board gameBoard(input);
			gameBoard.drawBoard();
			while(1){
				cout<<"enter the operation you want to perform: t(followed by position, separated by space exp:t 0 8) - toggle, r - restart, q - quit"<<endl;
				cin>>char_in;
				if(char_in == 'q'){
					terminate = 1;
					break;
				}
				else if(char_in == 'r'){
					terminate = 0;
					cout<<"please specify the size of the game you want to play:(2-9)"<<endl;
					break;
				}
				else if(char_in == 't'){
					if((cin>>pos_x) && (pos_x >= 0) && (pos_x <= input) && (cin>>pos_y) && (pos_y >= 0) && (pos_y <= input)) {
						gameBoard.toggle(pos_x, pos_y);
						gameBoard.drawBoard();
						if(gameBoard.win()){
							cout<<"congratuations, you have won, try higher levels!"<<endl;
							break;
						}
						continue;
					}
					else{
						cout<<"format error, please follow operation instruction."<<endl;
						continue;
					}
				}
				else{
					cout<<"cannot recognize the command."<<endl;
					continue;
				}
			}
			if(terminate == 1) break;
			else continue;
		}
		else{
			cout<<"please enter a number between 2 and 9."<<endl;
			continue;
		}
	}
}
