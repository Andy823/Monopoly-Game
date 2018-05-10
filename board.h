// The head file of the function "board"
#ifndef __board__
#define __board__

class board{//define a class board
public:
	board();
	int p1[82];
	int initial[82];//define an int initial with 80 components
	int price[82];//define an int price with 80 components
	int LV[82];//define an int LV with 80 components
	void draw(int x, int y);//the function to print the board on the screen
	void set();//the function to set the original number of each property as 2
	void getprice();//the function to generate the price of each property
	void promote();//the function to set the LV of the property
};
#endif