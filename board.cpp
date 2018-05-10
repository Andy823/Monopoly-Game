#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "board.h"

//initialize the function "board"
board::board(){
	set();
	getprice();
	promote();
}


void board::draw(int x, int y)//Print the board
{
	int i;//Define an int i
	int a = 1;//Define an int a as 1
	//This loop is to print the number on the board
	for (i = 2; i < 82; i++){
		p1[i] = a;
		a++;
		if (initial[i] == 1){ p1[i] = 92; }
		if (initial[i] == 0){ p1[i] = 82; }
	}
	p1[x] = 92;
	p1[y] = 82;
	p1[1] = 200;
	//Print the board on the screen
	system("cls");
	cout << "_____________________________________________________________________________________________________" << endl;
	cout << "| " << p1[1] << "  | " << p1[2] << "  |  " << p1[3] << " |  " << p1[4] << " |  " << p1[5] << " |  " << p1[6] << " | " << p1[7] << "  | " << p1[8] << "  |  " << p1[9] << " |  " << p1[10] << "| " << p1[11] << " | " << p1[12] << " | " << p1[13] << " | " << p1[14] << " | " << p1[15] << " | " << p1[16] << " | " << p1[17] << " | " << p1[18] << " | " << p1[19] << " | " << p1[20] << " | " << endl;
	cout << "|____|____|____|____|____|____|____|____|____|____|____|____|____|____|____|____|____|____|____|____|" << endl;
	cout << "|" << p1[80] << "  |    |                                                                               |    | " << p1[21] << " |  " << endl;
	cout << "|" << p1[79] << "  |    |                                                                               |    | " << p1[22] << " |  " << endl;
	cout << "|" << p1[78] << "  |    |                                                                               |    | " << p1[23] << " |  " << endl;
	cout << "|" << p1[77] << "  |    |                                                                               |    | " << p1[24] << " |  " << endl;
	cout << "|" << p1[76] << "  |    |                                                                               |    | " << p1[25] << " |  " << endl;
	cout << "|" << p1[75] << "  |    |                                                                               |    | " << p1[26] << " |  " << endl;
	cout << "|" << p1[74] << "  |    |                                                                               |    | " << p1[27] << " |  " << endl;
	cout << "|" << p1[73] << "  |    |                                                                               |    | " << p1[28] << " |  " << endl;
	cout << "|" << p1[72] << "  |    |                                                                               |    | " << p1[29] << " |  " << endl;
	cout << "|" << p1[71] << "  |    |                                                                               |    | " << p1[30] << " |  " << endl;
	cout << "|" << p1[70] << "  |    |                                                                               |    | " << p1[31] << " |  " << endl;
	cout << "|" << p1[69] << "  |    |                                                                               |    | " << p1[32] << " |  " << endl;
	cout << "|" << p1[68] << "  |    |                                                                               |    | " << p1[33] << " |  " << endl;
	cout << "|" << p1[67] << "  |    |                                                                               |    | " << p1[34] << " |  " << endl;
	cout << "|" << p1[66] << "  |    |                                                                               |    | " << p1[35] << " |  " << endl;
	cout << "|" << p1[65] << "  |    |                                                                               |    | " << p1[36] << " |  " << endl;
	cout << "|" << p1[64] << "  |    |                                                                               |    | " << p1[37] << " |  " << endl;
	cout << "|" << p1[63] << "  |    |                                                                               |    | " << p1[38] << " |  " << endl;
	cout << "|" << p1[62] << "  |    |                                                                               |    | " << p1[39] << " |  " << endl;
	cout << "|" << p1[61] << "  |    |                                                                               |    | " << p1[40] << " |  " << endl;
	cout << "|____|____|_______________________________________________________________________________|____|____|" << endl;
	cout << "| " << p1[60] << " | " << p1[59] << " | " << p1[58] << " | " << p1[57] << " | " << p1[56] << " | " << p1[55] << " | " << p1[54] << " | " << p1[53] << " | " << p1[52] << " | " << p1[51] << " | " << p1[50] << " | " << p1[49] << " | " << p1[48] << " | " << p1[47] << " | " << p1[46] << " | " << p1[45] << " | " << p1[44] << " | " << p1[43] << " | " << p1[42] << " | " << p1[41] << " | " << endl;
	cout << "|____|____|____|____|____|____|____|____|____|____|____|____|____|____|____|____|____|____|____|____|" << endl;
}

void board::set(){
	int i;//define an int i
	for (i = 2; i < 82; i++){//do the loop when i is smaller than 81 and begin from 2
		initial[i] = 2;//the initial number of each property is 2
	}
}

void board::getprice(){
	int i;//define an int i
	for (i = 2; i < 82; i++){//do the loop when i is smaller than 81 and begin from 2
		price[i] = (rand() % 491) + 10;//generate the price of the property randomly feom 10 to 500
	}
}

void board::promote(){
	int i;//define an int i
	for (i = 2; i < 82; i++){//do the loop when i is smaller than 81 and begin from 2
		LV[i] = 0;//the origin LV of each property is 0
	}
}