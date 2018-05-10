#include <iostream>//include information about standard library iostream
#include <string.h>
using namespace std;//using standard name
#include "player.h"//include the information about the head file of funciton player

player::player(string a,board pphd)//initialize the function
{
	name = a;//set the name as 1
	cashp = 10000;//set the cash of player as 10000
	location = 1;//set the location as 1
	decision = 0;//set the value of decision as 0
	phd = pphd;//set the pointer phd
}

//function to move forward
int player::advance(){
	printf("You need to advance %d\n", getd1());//print on the screen the distance player need to advance
	location += getd1();//location equals to itself plus the number from the dice
	if (location > 80)//do the loop when location is larger than 80
		location = getd1() - (location - 80) + 1;//put locaton back on to the right track
	if (location == 1)//do the loop when location is equal to 1
		cashp = cashp + 200;//plus 200 cash
	return location;//return the value of location
}

//the function to buy a property
int player::buy(){
	if (phd.initial[location] == 2){//do the loop when the initial of this property is 2
		printf("The price of this property is %d\n", phd.price[location]);
		cout << "Do you want to buy this property?(Y/N), or input" << endl;//ask the user whether want to buy this proerty or not
		cin >> choice;//read in user's choice
		if (choice == 'Y' || choice == 'y'){//do the loop when the user choose yes
			if (cashp - phd.price[location] < 0)//do the loop if the cash is smaller than the price of this property
			{
				printf("You don't have enough money for this");//print on the screen that user don't have enough money
			}
			else{
				printf("Buy successfully");
				phd.initial[location] = 1;//set the initial of this property as 1
				phd.p1[location] = 92;//set the number printed on the board as 92
				cashp = cashp - phd.price[location];//player cash decrease
			}
		}
		else if (choice == 'N' || choice == 'n')
		{
			printf("The player won't buy this property");//print on the screen the player won't buy this property
			printf("It is very wired for you not to buy this property");//print on the screen comment on this move
		}
		else if (choice == 'q'||choice=='Q')//if player choose to quit, then return 0
		{
			return 0;
		}
	}
	return 1;//return the value of cashp
}

//the function to upgrade the property
int player::upgrade(){
	if (phd.initial[location] == 1){//do the loop when the initial of the property is 0
		cout << "Do you want to upgrade this property?" << endl;//ask the user whether want to upgrade this property or not
		cin >> choice;//read in the user's choice
		if (choice == 'Y' || choice == 'y'){//do the loop if the choice is yes
			if (cashp - phd.price[location] < 0){//if the cash is smaller than the price
				printf("You don't have enough money for this\n");//print no money
			}
			else{
				cashp = cashp - phd.price[location] * 0.5;//upgrade the property and the cash reduces
				phd.LV[location] = phd.LV[location] + 1;//the LV of this property is upgraded
				printf("The LV of your property is:%d\n", phd.LV[location]);//print on the screen the LV of this property
				printf("The remain of your cash is:%d\n", cashp);//print on the screen the remaining cash
			}
		}
		else if (choice == 'N' || choice == 'n'){
			printf("It is very wired for you not to upgrade this property\n");//print on the screen the comment on this move
		}
		else if (choice = 'q' || choice == 'Q'){
			return 0;
		}
		return 1;//return the value of cashp
	}
}

//the function to fine the player
int player::fine(computer a){
	if (phd.initial[location] == 0){//do the loop if this property belongs to the computer
		cout << "You will be fined" << endl;//print on the screen player will be fined
		printf("This is a %d LV property\n", phd.LV[location]);//print on the screen the LV of this property
		//do the loop if either property beside blong to the computer
		if (phd.initial[location - 1] == 0 || phd.initial[location + 1] == 0)
		{
			//if the property hasn't been upgraded, then the fine is 15% of the price
			if (phd.LV[location] == 0){
				cashp = cashp - phd.price[location] * 0.15;
				a.cash = a.cash + phd.price[location] * 0.15;
				//do the loop when the cash is not larger than 0, and print on the screen game over
				if (cashp < 0 || cashp == 0){
					cout << "Game Over" << endl;
					exit(0);
				}
			}
			//if the property has been upgraded, then the fine will add another 5%
			else{
				cashp = cashp - phd.price[location] * (0.15 + 0.05*phd.LV[location]);
				a.cash = a.cash + phd.price[location] * (0.15 + 0.05*phd.LV[location]);
				//do the loop when the cash is not larger than 0, and print on the screen game over
				if (cashp < 0 || cashp == 0){
					cout << "Game Over" << endl;
					exit(0);
				}
			}
		}
		//do the loop if the property beside hasn't been bouth by computer or is player's 
		else if (phd.initial[location + 1] == 2 || phd.initial[location - 1] == 2 || phd.initial[location] == 1 || phd.initial[location] == 1)
		{
			//if the property hasn't been upgraded, the fine is 10% of the property price
			if (phd.LV[location] == 0){
				cashp = cashp - phd.price[location] * 0.1;
				a.cash = a.cash + phd.price[location] * 0.1;
				//do the loop when the cash is not larger than 0, and print on the screen game over
				if (cashp < 0 || cashp == 0){
					cout << "Game Over" << endl;
					exit(0);
				}
			}
			//if the property has been upgraded, the fine will add another 5%
			else{
				cashp = cashp - phd.price[location] * (0.1 + 0.05*phd.LV[location]);
				a.cash = a.cash + phd.price[location] * (0.1 + 0.05*phd.LV[location]);
				//do the loop when the cash is not larger than 0, and print on the screen game over
				if (cashp < 0 || cashp == 0){
					cout << "Game Over" << endl;
					exit(0);
				}
			}
		}
		//do the loop if there are three continuous property belong to the player
		else if (phd.initial[location + 1] == 1 && phd.initial[location + 2] == 1 || phd.initial[location - 1] == 1 && phd.initial[location + 1] == 1 || phd.initial[location - 1] == 1 && phd.initial[location - 2] == 1){
			//if the property hasn't been upgraded, the fine will be 20% of the property price
			if (phd.LV[location] == 0){
				cashp = cashp - phd.price[location] * 0.2;
				a.cash = a.cash + phd.price[location] * 0.2;
				//do the loop when the cash is not larger than 0, and print on the screen game over
				if (cashp < 0 || cashp == 0){
					cout << "Game Over" << endl;
					exit(0);
				}
			}
			//if the property has been upgraded, the fine will add another 5%
			else
			{
				cashp = cashp - phd.price[location] * (0.2 + 0.05*phd.LV[location]);
				a.cash = a.cash + phd.price[location] * (0.2 + 0.05*phd.LV[location]);
				//do the loop when the cash is not larger than 0, and print on the screen game over
				if (cashp < 0 || cashp == 0){
					cout << "Game Over" << endl;
					exit(0);
				}
			}
		}
		printf("The remain of your cash is: %d\n", cashp);//print on the screen the remaining cash
		return cashp;
	}
	else if (phd.initial[a.position] == 1){
		cout << "Computer will be fined" << endl;//print on the screen the computer will be fined
		printf("This is a %d LV property", phd.LV[a.position]);//print the LV on the screen
		//do the if loop when either properties beside belong to player
		if (phd.initial[a.position - 1] == 0 || phd.initial[a.position + 1] == 0)
		{
			//do the if loop when the LV of the property is 0
			if (phd.LV[a.position] == 0){
				a.cash = a.cash - phd.price[a.position] * 0.15;//the fine will be 15% of the price
				cashp = cashp + phd.price[a.position] * 0.15;
				//do the loop when the cash is not larger than 0, and print on the screen game over
				if (a.cash < 0 || a.cash == 0){
					cout << "Game Over" << endl;
					exit(0);
				}
			}
			else{
				//if the LV of the property isn't 0, then the fine will add another 5%
				a.cash = a.cash - phd.price[a.position] * (0.15 + 0.05*phd.LV[a.position]);
				cashp = cashp + phd.price[a.position] * (0.15 + 0.05*phd.LV[a.position]);
				//do the loop when the cash is not larger than 0, and print on the screen game over
				if (a.cash < 0 || a.cash == 0){
					cout << "Game Over" << endl;
					exit(0);
				}
			}
		}
		//do the if loop when the property beside is empty or belong to computer 
		else if (phd.initial[a.position + 1] == 2 || phd.initial[a.position - 1] == 2 || phd.initial[a.position] == 1 || phd.initial[a.position] == 1)
		{
			//if the LV of the property is 0, the fine will be 10% of the price
			if (phd.LV[a.position] == 0){
				a.cash = a.cash - phd.price[a.position] * 0.1;
				cashp = cashp + phd.price[a.position] * 0.1;
				//do the loop when the cash is not larger than 0, and print on the screen game over
				if (a.cash < 0 || a.cash == 0){
					cout << "Game Over" << endl;
					exit(0);
				}
			}
			//if the LV of the property isn't 0, the fine will add another 5%
			else{
				a.cash = a.cash - phd.price[a.position] * (0.1 + 0.05*phd.LV[a.position]);
				cashp = cashp + phd.price[a.position] * (0.1 + 0.05*phd.LV[a.position]);
				//do the loop when the cash is not larger than 0, and print on the screen game over
				if (a.cash < 0 || a.cash == 0){
					cout << "Game Over" << endl;
					exit(0);
				}
			}
		}
		//if there are three continuous properties belong to player, than the fine will be 20%
		else if (phd.initial[a.position + 1] == 1 && phd.initial[a.position + 2] == 1 || phd.initial[a.position - 1] == 1 && phd.initial[a.position + 1] == 1 || phd.initial[a.position - 1] == 1 && phd.initial[a.position - 2] == 1){
			if (phd.LV[a.position] == 0){
				a.cash = a.cash - phd.price[a.position] * 0.2;
				cashp = cashp + phd.price[a.position] * 0.2;
				//do the loop when the cash is not larger than 0, and print on the screen game over
				if (a.cash < 0 || a.cash == 0){
					cout << "Game Over" << endl;
					exit(0);
				}
			}
			//if the LV of the property isn't 0, than the fine will add another 5%
			else
			{
				a.cash = a.cash - phd.price[a.position] * (0.2 + 0.05*phd.LV[a.position]);
				cashp = cashp + phd.price[a.position] * (0.2 + 0.05*phd.LV[a.position]);
				if (a.cash < 0 || a.cash == 0){
					cout << "Game Over" << endl;
					exit(0);
				}
			}
		}
	}
	printf("The remain of computer cash is: %d\n", a.cash);//print on the board the remaining cash
	return a.cash;//return the value of cash
}

//the function when the player goes bankruptcy
void player::bankruptcy(){
	//do the loop when the cash is not larger than 0, and print on the screen game over
	if (cashp == 0||cashp<0){
		cout << "Game Over" << endl;
	}
}
