#ifndef GRID_H
#define GRID_H

class Grid{
	bool state;
	int numObservers;
	Grid *observers[4];
public:
	Grid();
	bool attach(Grid *observer);
	void detach(Grid *observer);
	void notifyAll();
	bool getState();
	void toggle();
	void notify();
};

#endif
