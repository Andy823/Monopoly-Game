#include <cstdlib>//include information about the standard library cstdlib
#include <time.h>//include information about the standard library time.h
#include <iostream>//include information about the standrd libraty iostream
using namespace std;//using standard name
#include "dice.h"//include information of the head file of the function "dice"

//function to get the dice number for player
int getd1(){
	int v1;//define an int v1
	//generate the number of a dice
	srand(time(NULL));
	v1 = rand() % 6 + 1;
	return v1;//return the value of v1
}

//function to get the dice number for computer
int getd2(){
	int v2;//define an int v2
	//generate the number of a dice
	srand(time(NULL));
	v2 = rand() % 6 + 1;
	return v2;//return the value of v2
}




