#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string>
#include <cstdlib>
using namespace std;

void Superman();
void Hulk();
int main()
{
	int Hulk_health=0;
	int Superman_health=0;
	string n;
	string continueNum;

	cout << "You are entering the game--Superman vs the Hulk." << endl;

	while (1)//include ask the player if like to continue or quit
	{
		while (1)
		{
			cout << "Please choose a chracter that make the first attack. Enter 1 for superman and 2 for Hulk--"; cin >> n;  cout << endl;
			if (n == "1") Superman();
			else if (n == "2") Hulk();

			else if (n != "1" || n != "2")
			{
				cout << "The entry is unvalid." << endl;
				cout << endl;
			}

			if (Superman_health <= 0 || Hulk_health <= 0) break;//break out the 2rd while loop and proceed to ask the player if he or she would like to continue
																//whithout this, new game will restart automaticaly
		}//break out this and ask continue or not, stay in = continue play without asking
		while (1)
		{
			cout << endl;
			cout << "Would you like to continue to play? Enter 3 then press the Enter key or enter 4 to quit->";
			cin >> continueNum;
			cout << endl;


			if (continueNum == "3") break;//break out this while loop only and back to begining of welcome to the game
			else if (continueNum == "4") return 0;//terminate the game when player choose not to continue to ply the game

			else if (continueNum != "3" || continueNum != "4") cout << "The Entery is unvalid" << endl;

			cout << "Please enter the correct numner." << endl;
			cout << endl;
			//when 3 is entered, goes back to enteringthegame
		}//enter 3 ill break out this loop and restart the game
	}//this while loop make sure the game can be continued to run as along as 4 is not entered.
	system("pause");
}
			
void Superman()
{
string number;
int Hulk_health = 110;	 // are able to be initialized when a new game is played.
int Superman_health = 100;//must place here to initialize the hp on each new game

cout << "You chose Superman to make the first attack. Please press the Enter key to start the game" << endl;
system("pause");
cout << endl;

while (true)
{
	int Superman_attack_power = 2 + rand() % 15;
	cout << "Superman attack Hulk. Hulk lost " << Superman_attack_power << " HP" << endl;
	cout << "Hulk has " << Hulk_health - Superman_attack_power << " HP left" << endl;
	Hulk_health = Hulk_health - Superman_attack_power;
	cout << endl;

	if (Hulk_health <= 0)
	{
		cout << "Hulk lost all his HP. Superman is the winner." << endl;
		cout << "The game is over. Press the Enter key to close the game." << endl;
		system("pause");
		break;//break out this while loop
	}
	cout << "Press the Enter key to let Hulk attack Superman." << endl;
	system("pause");
	cout << endl;

	int Hulk_attack_power = 1 + rand() % 14;
	cout << " Hulk attacked Superman. Superman lost " << Hulk_attack_power << " HP" << endl;
	cout << "Superman has " << Superman_health - Hulk_attack_power << " HP left." << endl;
	Superman_health = Superman_health - Hulk_attack_power;
	cout << endl;

	if (Superman_health <= 0)
	{
		cout << "Superman lost all his HP. HUlk is the winner." << endl;
		cout << "The game is over. Press the Enter key to close the game." << endl;
		system("pause");
		break;
	}
	cout << "Press the Enter key to let Superman attack the Hulk." << endl;
	system("pause");
	cout << endl;
}
}
void Hulk()
{
	string number;
	int Hulk_health = 110;	 // are able to be initialized when a new game is played.
	int Superman_health = 100;

	cout << "You chose Hulk to make the first attack. Please press the Enter key to start the game. "; system("pause");
	cout << endl;

	while (1)
	{
		int Hulk_attack_power = 1 + rand() % 14;//Hulk will have attack power between 1 and 15

		cout << " Hulk attacked Superman. Superman lost " << Hulk_attack_power << " HP. " << endl;
		cout << "Superman has " << Superman_health - Hulk_attack_power << " HP left." << endl;
		Superman_health = Superman_health - Hulk_attack_power;//this will reassign superman's health point. and keep what is remain for the next run
		cout << endl;

		if (Superman_health <= 0)//this if statement must put here or it will run hulk attack and lost hp then tells super is dead.
		{
			cout << "Superman lost all his HP. HUlk is the winner." << endl;
			cout << "The game is over.Press the Enter key to close the game." << endl;
			system("pause");
			break;//break out this while loop, and proceed to the outer while loop
		}

		cout << "Press the Enter key to let Superman attack the Hulk." << endl;
		system("pause");
		cout << endl;

		int Superman_attack_power = 2 + rand() % 15;
		cout << "Superman attack Hulk. Hulk lost " << Superman_attack_power << " HP" << endl;
		cout << "Hulk has " << Hulk_health - Superman_attack_power << " HP left" << endl;
		Hulk_health = Hulk_health - Superman_attack_power;
		cout << endl;

		if (Hulk_health <= 0)
		{
			cout << "Hulk lost all his HP. Superman is the winner." << endl;
			cout << "The game is over. Press the Enter key to close the game." << endl;
			system("pause");
			break;
			//cout << "Would you like to continue to play? Press the Enter key to continue, or enter no to quit the program.  " << endl; cin >> answer;	
		}

		cout << "Press the Enter key to let Hulk attack Superman." << endl;
		system("pause");
		cout << endl;
	}//end while
}
