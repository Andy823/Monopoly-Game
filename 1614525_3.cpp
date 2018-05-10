#include<iostream>//include information about the standard library iostream
#include <fstream>//include information about the standard library fstream
#include <Windows.h>//include information about the standard library windows.h
#include <string>//include information about the standard library string
using namespace std;//using standard name
#include "board.h"//include information of the head file of the function board
#include "computer.h"//include information of the head file of the function computer
#include "dice.h"//include information of the head file of the function dice
#include "player.h"//include information of the head file of the function player

//define a struct user
struct user 
{
	char username[15];//define a char username with a range of 15
	int playermoney;//define an int as playermoney
	int computermoney;//define an int as computermoney
	int propertyprice[82];
	board playboard;//define an array of board 
};


void showinfo(player x, computer y);
const char * file = "gameusers.dat";//define a file as gameuser.dat

//print a board contains the cash of player and computer on the screen
void showinfo(player x,computer y){
	cout << "############################################" << endl;
	cout << "Your cash is:" << x.cashp << ", computer cash is :" << y.cash << "\n";
	cout << "############################################" << endl;
	cout << "You can quit game anytime you want, if you do, please enter q to quit" << endl;
	
}

int main(){
	user info;//define an array of user as info
	board p1;//define an array of board p1
	info.computermoney = 10000;//define the initial value of computermoney to be 10000
	info.playermoney = 10000;//define the initial value of playermoney to be 10000
	int i;//define an int i
	//assign the value of property price to the file
	for (i = 2; i < 82; i++){
		info.propertyprice[i] = p1.price[i];
	}
	board plate1;//define an array of board as plate1
	board plate;//define an array of board as plate
	string usern;//define an string as usern
	int choice;//define an int choice
	char name[15];//define c char name with a range of 15
	int num;//define an int num
	//ask user to register of login
	cout << "1.Register" << endl;
	cout << "2.Login" << endl;
	//do the loop continuously
	for (;;){
		cin >> choice;//read in the choice
		ofstream fout;//define an array of the ofstream as fout
		fout.open(file, ios_base::out | ios_base::app | ios_base::binary);//write the input into the file
		//if can't open the file, then print on the screen can't open it
		if (!fout.is_open()){
			cerr << "Can't open" << file << "file for output:\n";
			exit(EXIT_FAILURE);
		}
		fout.close();//close the file
		ifstream fin;//read the read
		switch (choice)//do different case
		{
		//register
		case 1:
			fout.open(file, ios_base::out | ios_base::app | ios_base::binary);//open the file to input 
			cout << "Please enter your username:" << endl;//ask the user to input the username
			cin >> info.username;//read in the username
			fout.write((char*)&info, sizeof info);//write the input into the file
			fout.close();//close the file
			break;
		//login
		case 2:
			fin.open(file, ios_base::in | ios_base::binary);//open the file to find
			cout << "Please enter your previous username:" << endl;//ask user to input the username
			cin >> name;//read in the name
			//continue the loop when the name can't be found in the file
			while (fin.read((char*)&info, sizeof info) && strcmp(info.username,name)){
				continue;
			}
			//if the name is the same as the username, then assign the value and close the file
			if (!(strcmp(info.username, name))){
				cout << "login successfully" << endl;
				_sleep(1000);
				break;
			}
			else{
				cout << "This user doesn't exist" << endl;//print the user doesn't exist
				fin.close();//close the file
				return 0;
			}
		default:
			cout << "Wrong input, please enter again:" << endl;//if the input isn't correct, ask user to input again
			break;
		}
		if (choice == 1 || choice == 2){ break; }
	}
	//switch the string usern to char
	char *b = info.username;
	usern = b;
	player a(usern, plate);//define an arrary of player
	computer ai(plate1);//define an arrary of computer
	a.cashp = info.playermoney;//assign the value of playermoney to cashp
	ai.cash = info.computermoney;//assign the value of computermoney to cash
	//assign the value of property price to the file
	for (i = 2; i < 82; i++){
		p1.price[i] = info.propertyprice[i];
	}
	a.phd = info.playboard;//assign the value of playboard to phd
	plate.draw(0, 0);//print the original plate
	//do the loop continuously
	for (;;){
		for (;;){
			showinfo(a, ai);//do the showinfo function of player
			a.advance();//do the advance function of player
			ifstream fin;
			ofstream fout;
			if (a.buy() == 0){//if player choose to quit the game
				streampos sp;//define a sp of streampos
				fin.open(file, ios_base::in | ios_base::binary);//open the file to find
				while (fin.read((char*)&info, sizeof info) && strcmp(info.username, name)){//continue the loop if no match is found
					continue;
				}
				//if the name is the same as the username, then assign the value and close the file
				if (!(strcmp(info.username, name))){
					sp = fin.tellg();//assign sp as the data found in the file
				}
				fin.close();//close the file
				fout.open(file, ios_base::out | ios_base::binary);//open the file
				info.computermoney = ai.cash;//assign the value of computermoney as cash
				info.playermoney = a.cashp;//assign the playermoney as cashp
				//assign the value of property price to the file
				for (i = 2; i < 82; i++){
					info.propertyprice[i] = p1.price[i];
				}
				info.playboard = ai.phd;
				fout.seekp(sp);//assign the position of the inputted value
				fout.write((char*)&info, sizeof info);//write the input into the file
				fout.close();//close the file
				exit(0);//close the file
			};
			_sleep(1000);
			ai.phd = a.phd;//set the phd of computer equal to the phd of player
			system("cls");//clear the system
			a.phd.draw(a.location, ai.position);//print the updated board on the screen
			showinfo(a, ai);//do the showinfo function
			if (a.upgrade() == 0){//if player choose to quit the game
				streampos sp;//define a sp of streampos
				fin.open(file, ios_base::in | ios_base::binary);//open the file to find
				while (fin.read((char*)&info, sizeof info) && strcmp(info.username, name)){//continue the loop if no match is found
					continue;
				}
				//if the name is the same as the username, then assign the value and close the file
				if (!(strcmp(info.username, name))){
					sp = fin.tellg();//assign sp as the data found in the file
				}
				fin.close();//close the file
				fout.open(file, ios_base::out | ios_base::binary);//open the file
				info.computermoney = ai.cash;//assign the value of computermoney as cash
				info.playermoney = a.cashp;//assign the playermoney as cashp
				//assign the value of property price to the file
				for (i = 2; i < 82; i++){
					info.propertyprice[i] = p1.price[i];
				}
				info.playboard = ai.phd;
				fout.seekp(sp);//assign the position of the inputted value
				fout.write((char*)&info, sizeof info);//write the input into the file
				fout.close();//close the file
				exit(0);//close the file
			};//do the buy function of player
			ai.phd = a.phd;//set the phd of computer equal to the phd of player
			a.fine(ai);//do the fine function of player
			_sleep(2000); //pause the function for 1000sec
			a.bankruptcy();//do the bankruptcy function of player
			_sleep(1000);//pause the function for 1000sec
			system("cls");//clear the system
			ai.phd.draw(a.location, ai.position);//draw the updated board on the screen
			showinfo(a, ai);//do the showinfo function
			ai.advance();//do the advance function of computer
			ai.buy();//do the buy function of computer
			a.phd = ai.phd;//set the phd of player the same as the phd of computer
			_sleep(1000);//pause the function for 1000sec
			system("cls");//clear the system
			ai.phd.draw(a.location, ai.position);//draw the updated board on the screen
			showinfo(a, ai);//do the showinfo function
			ai.upgrade();//do the upgrade function of computer
			a.fine(ai);//do the fine function of computer
			_sleep(2000);//pause the system for 2000sec
			ai.bankruptcy();//do the bankruptcy function of computer
			_sleep(1000);//pause the system for 1000sec
			system("cls");//clear the system
			a.phd.draw(a.location, ai.position);//print the updated board on the screen
		}
		break;
	}
}

