#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// function prototypes
void VsFriend();
void Board(int condition[]);
int VictoryCon(int current[]);
bool Tie(int full[]);
void VsAI();

int main()
{
	bool menuLoop = true;
	
	while (menuLoop)
	{
		cout << "Welcome to TIC TAC TOE\n"
			<< "\n"
			<< "Press '1' to play AI\n"
			<< "Press '2' to play against friend\n"
			<< "Press '3' to quit\n";

		//user input
		int menuChoice = 0;
	
		cin >> menuChoice;
		if (menuChoice == 1)
		{
			VsAI();
		}
		else if (menuChoice == 2)
		{
			VsFriend();
			cout << "\n";
		}
		else if (menuChoice == 3)
		{
			menuLoop = false;
		}
		else
		{
			cout << "invalid input\n\n";
		}
	}
	cout << "Thank you for playing!\n";
	system("pause");
	return 0;
}
//-----------------------------------------------------
// VsFriend()
//-----------------------------------------------------
// in: none
// out:none
//-----------------------------------------------------
void VsFriend()
{
	int placed[9] = { 0,0,0,0,0,0,0,0,0 };
	bool victory = false;
	
	Board(placed);
	cout << '\n';
	while (!victory)
	{
		int playerChoice;
		bool rep = true;
		
		while (rep)
		{
			
			cout << "Player 1, please pick a square by entering a number 1-9: ";
			cin >> playerChoice;
			if (placed[playerChoice - 1] == 0)
			{
				placed[playerChoice - 1] = 1;
				rep = false;
			}
			else
			{
				cout << "Square is already being used, please pick another.\n";
			}
		}
		cout << "\n";
		Board(placed);
		cout << '\n';
		if (VictoryCon(placed) == 1)
		{
			cout << "\nCongratulations, Player 1 wins\n";
			victory = true;
		}
		else if (Tie(placed))
		{
			cout << "\nIt's a tie\n";
			victory = true;
		}
		else
		{
			rep = true;

			while (rep)
			{
				cout << "Player 2, please pick a square by entering a number 1-9: ";
				cin >> playerChoice;
				if (placed[playerChoice - 1] == 0)
				{
					placed[playerChoice - 1] = 2;
					rep = false;
				}
				else
				{
					cout << "Square is already being used, please pick another.\n";
				}
			}
			Board(placed);
			if (VictoryCon(placed) == 2)
			{
				cout << "\nCongratulations, Player 2 wins\n";
				victory = true;
			}
			else if (Tie(placed))
			{
				cout << "\nIt's a tie\n";
				victory = true;
			}
			else
			{
				cout << '\n';
			}
		}
	}
}

//-----------------------------------------------------
// Board()
//-----------------------------------------------------
// in:int array with '1' representing P1
//		'2' representing P2
//		'0' blank
// out:tic tac toe Board
//-----------------------------------------------------
void Board(int condition[])
{
	for (int i = 0; i < 9; ++i)
	{
		if (condition[i] == 1)
		{
			cout << "O";
		}
		else if (condition[i] == 2)
		{
			cout << "X";
		}
		else
		{
			cout << " ";
		}
		if ((i == 0) || (i == 1) || (i == 3) || (i == 4) || (i == 6) || (i == 7))
		{
			cout << "|";
		}
		if ((i == 2) || (i == 5))
		{
			cout << '\n' << "-+-+-\n";
		}
	}
}

//------------------------------------------------------------
// VictoryCon
//---------------------------------------------------------------
//in:int array with '1' representing P1
//		'2' representing P2
//		'0' blank
//out:'1'equals player1 vic
//		'2' = player2 vic
//		'0' = no winner yet
//---------------------------------------------------------------
int VictoryCon(int current[])
{
	int vic = 0;
	//0|1|2
	//3|4|5
	//6|7|8
	//player1 vic condition
	if (current[0] == 1)
		if (current[1] == 1)
			if (current[2] == 1)
				vic = 1;
	if (current[0] == 1)
		if (current[3] == 1)
			if (current[6] == 1)
				vic = 1;
	if (current[0] == 1)
		if (current[4] == 1)
			if (current[8] == 1)
				vic = 1;
	if (current[1] == 1)
		if (current[4] == 1)
			if (current[7] == 1)
				vic = 1;
	if (current[2] == 1)
		if (current[5] == 1)
			if (current[8] == 1)
				vic = 1;
	if (current[2] == 1)
		if (current[4] == 1)
			if (current[6] == 1)
				vic = 1;
	if (current[3] == 1)
		if (current[4] == 1)
			if (current[5] == 1)
				vic = 1;
	if (current[6] == 1)
		if (current[7] == 1)
			if (current[8] == 1)
				vic = 1;
	//player2 vic condition
	if (current[0] == 2)
		if (current[1] == 2)
			if (current[2] == 2)
				vic = 2;
	if (current[0] == 2)
		if (current[3] == 2)
			if (current[6] == 2)
				vic = 2;
	if (current[0] == 2)
		if (current[4] == 2)
			if (current[8] == 2)
				vic = 2;
	if (current[1] == 2)
		if (current[4] == 2)
			if (current[7] == 2)
				vic = 2;
	if (current[2] == 2)
		if (current[5] == 2)
			if (current[8] == 2)
				vic = 2;
	if (current[2] == 2)
		if (current[4] == 2)
			if (current[6] == 2)
				vic = 2;
	if (current[3] == 2)
		if (current[4] == 2)
			if (current[5] == 2)
				vic = 2;
	if (current[6] == 2)
		if (current[7] == 2)
			if (current[8] == 2)
				vic = 2;
	return vic;
}

//------------------------------------------
// Tie
//------------------------------------------
//in:int array with '1' representing P1
//		'2' representing P2
//		'0' blank
//out:bool true = tie
//			false = no tie
//----------------------------------------------
bool Tie(int full[])
{
	bool isTie = true;
	for (int i = 0; i < 9; ++i)
	{
		if (full[i] == 0)
		{
			isTie = false;
		}
	}
	return isTie;
}

//----------------------------------------------------------
// VsAI
//----------------------------------------------------------
//in:none
//out:none
//--------------------------------------------------------------
void VsAI()
{
	srand(time(NULL));
	int firstOrSec=rand()%3;
	int placed[9] = { 0,0,0,0,0,0,0,0,0 };
	bool victory = false;
	if (firstOrSec == 1)
	{
		cout << "Player goes first\n";
		Board(placed);
		cout << '\n';
		while (!victory)
		{
			int playerChoice;
			bool rep = true;

			while (rep)
			{

				cout << "Player, please pick a square by entering a number 1-9: ";
				cin >> playerChoice;
				if (placed[playerChoice - 1] == 0)
				{
					placed[playerChoice - 1] = 1;
					rep = false;
				}
				else
				{
					cout << "Square is already being used, please pick another.\n";
				}
			}
			cout << "\n";
			Board(placed);
			cout << '\n';
			if (VictoryCon(placed) == 1)
			{
				cout << "\nCongratulations, Player wins\n";
				victory = true;
			}
			else if (Tie(placed))
			{
				cout << "\nIt's a tie\n";
				victory = true;
			}
			else
			{
				rep = true;
				while (rep)
				{
					playerChoice=rand()%10;
					if (placed[playerChoice - 1] == 0)
					{
						placed[playerChoice - 1] = 2;
						rep = false;
					}
				}
				cout << '\n';
				Board(placed);
				cout << '\n';
				if (VictoryCon(placed) == 2)
				{
					cout << "\nCongratulations, AI wins\n";
					victory = true;
				}
				else if (Tie(placed))
				{
					cout << "\nIt's a tie\n";
					victory = true;
				}
				else
				{
					cout << '\n';
				}
			}
		}
	}
	if (firstOrSec == 2)
	{
		cout << "AI goes first\n";
		cout << '\n';
		while (!victory)
		{
			int playerChoice;
			bool rep = true;

			while (rep)
			{
				playerChoice = rand() % 10;
				if (placed[playerChoice - 1] == 0)
				{
					placed[playerChoice - 1] = 1;
					rep = false;
				}
			}
			cout << '\n';
			Board(placed);
			cout << '\n';
			if (VictoryCon(placed) == 1)
			{
				cout << "\nOh no, AI wins\n";
				victory = true;
			}
			else if (Tie(placed))
			{
				cout << "\nIt's a tie\n";
				victory = true;
			}
			else
			{
				rep = true;
				while (rep)
				{

					cout << "Player, please pick a square by entering a number 1-9: ";
					cin >> playerChoice;
					if (placed[playerChoice - 1] == 0)
					{
						placed[playerChoice - 1] = 2;
						rep = false;
					}
					else
					{
						cout << "Square is already being used, please pick another.\n";
					}
				}
				cout << "\n";
				Board(placed);
				cout << '\n';
				if (VictoryCon(placed) == 2)
				{
					cout << "\nCongratulations, Player wins\n";
					victory = true;
				}
				else if (Tie(placed))
				{
					cout << "\nIt's a tie\n";
					victory = true;
				}
				else
				{
					cout << '\n';
				}
			}
		}
	}
}
