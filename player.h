//The head file of the function "player"
#ifndef __player__
#define __player__

#include <iostream>//include information about standard library iostream
using namespace std;//using the standard name
#include"board.h"
#include "dice.h"
#include"computer.h"
//include the head file of function "computer"
class player :public board{//define a sub class player of class board
private:
	string name;//define a private char name
	char choice;//define a privat chat choice
	
public:
	board phd;
	player(string a,board pphd);
	int location;//define an int location
	int cashp;//define an int cashp
	int decision;
	void getinfo();//define a function getinfo
	int advance();//define a function advance
	int buy();//define a function buy
	int upgrade();//define a function upgrade
	int fine(computer a);//define a function fine
	void bankruptcy();//define a function bankruptcy
};
#endif