//the head file for function "computer"
#ifndef __computer__
#define __computer__
#include <iostream>//include information about standard library iostream
using namespace std;//using standard names
#include"board.h"//include the information about the head file of funciton board

class computer:public board{//define a class computer
public:
	board phd;
	int cash;//define an int cash
	int position;//define an int position
	computer(board pphd);
	void advance();//define a function advance
	int buy();//define a function buy
	int upgrade();//define a function upgrade
	void bankruptcy();//define a function bankruptcy
};
#endif