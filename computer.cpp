#include <iostream>//include information about the standard library iostream
#include <time.h>//include information about the standard library time
using namespace std;//using standard name
#include "computer.h"//include the information about the head file of function computer
#include "dice.h"//include the information about the head file of function dice
#include "board.h"//include the information about the head file of function board

//initialize the function "computer"
computer::computer(board pphd)
{
	position = 1;//set the position as 1
	cash = 10000;//set cash as 10000
	phd = pphd;//set the pointer phd
}

//function to move forward
void computer::advance(){
	cout << "You need to advance" << getd2() << endl;//print on the board the distance computer need to advance
	position += getd2();//position equals to itself plus the number of the dice
	if (position > 80)//do the loop if position is larger than 80
		position = getd2() - (position - 80) + 1;
	if (position ==1)//do the loop when position is 1
		cash = cash + 200;//cash plus 200
	return;
}

//function to buy the property
int computer::buy(){
	int c1;//define a int c1
	if (phd.initial[position] == 2){//do the loop when the initial of the property is 2
		cout << "Do you want to buy this property?" << endl;/*ask the computer want to buy this property or not*/
		//generate the outcome of the computer on deciding whether buy this property or not
		srand(time(NULL));
		c1 = rand() % 2;
		//do the loop when the c1 equals to 1
		if (c1 == 1){
			//do the loop when cash is smaller than the price of the property
			if (cash - phd.price[position] < 0){
				printf("You don't have enough money for this");//print on the board computer don't have enough money for this
			}
			else{
				printf("The computer will buy this property");//print on screen the computer will buy the property
				phd.p1[position] = 82;//set the number printed on the board as 82
				phd.initial[position] = 0;//set the initial of the property as 1
				cash = cash - phd.price[position];//computer cash reduces
				printf("The remain of computer cash is:%d", cash);//prinr on the screen the remaining cash
			}
		}
		else{
			printf("The computer won't buy this property");//print on the screen computer's choice
			printf("It is very wired for you not to buy this property");//print on the screen the comment of this move
		}
	}
	return cash;//return the value of cash
}

//the function to upgrade the property
int computer::upgrade(){
	int c2;//define an int c2
	//do the loop when the property belongs to the computer
	if (phd.initial[position] == 0){
		cout << "Do you want to upgrade this property?" << endl;//ask the computer whether want to upgrade or not
		//generate the choice of the computer
		srand(time(NULL));
		c2 = rand() % 1 + 1;
		//do the loop when c2 is 1 
		if (c2 == 1){
			if (cash - phd.price[position] < 0){//if the cash is smaller than the price
				printf("You don't have enough money for this.");//print on the screen computer don't have enough money for this
				system("cls");//clear the screen
			}
			else{
				printf("Computer will upgrade this property\n");//print on the board the computer will upgrade this property
				cash = cash - phd.price[position] * 0.5;//reduce the cash
				LV[position] = LV[position] + 1;//the LV of the property is upgraded
				printf("The LV of your property is:%d\n", LV[position]);//print the LV on the screen
				printf("The remain of your cash is:%d\n", cash);//print the remaining cash on the screen
			}
		}
		else{
			printf("Computer decide not to upgrade this property\n");//print computer choice on the screen
			printf("It is very wired for you not to upgrade this property\n");//print comment on the screen
		}
	}
	else{
		printf("No upgrade this time");
	}
	return cash;//return the value of cash
}


//the function to declare bankruptcy
void computer::bankruptcy(){
	if (cash == 0 || cash < 0){//if the cash is smaller than 0, than announce game over
		cout << "Game Over" << endl;
	}
}



