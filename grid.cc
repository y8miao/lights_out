#include <cstring>
#include <iostream>
#include "grid.h"

using std::cout;
using std::endl;

Grid::Grid():state(0), numObservers(0){
	memset(observers, 0, 4 *sizeof(Grid *));
}

bool Grid::attach(Grid *observer){
	if(numObservers < 4){
		observers[numObservers] = observer;
		numObservers++;
		return 1;
	}
	else{
		cout<<"exceed the limit for observers."<<endl;
		return 0;
	}
}

void Grid::detach(Grid *observer){
	for(int i = 0; i <numObservers; i++){
		if(observers[i] == observer){
			for(int j = i; j < numObservers - 1; j++){
				observers[j] = observers[j+1];
			}
			numObservers --;
		}
	}
}

void Grid::notifyAll(){
	for(int i = 0; i < numObservers; i++){
		(observers[i])->notify();
	}
}

bool Grid::getState(){
	return state;
}

void Grid::toggle(){
	state = !state;
	notifyAll();
}

void Grid::notify(){
	state = !state;
}
