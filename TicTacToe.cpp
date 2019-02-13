#include <iostream>

using namespace std;

// function prototypes
void vsFriend();
void board(int condition[]);

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
			//vsAI();
		}
		else if (menuChoice == 2)
		{
			vsFriend();
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
// vsFriend()
//-----------------------------------------------------
// in: none
// out:none
//-----------------------------------------------------
void vsFriend()
{
	int placed[9] = { 0,0,0,0,0,0,0,0,0 };
	bool victory = false;
	
	board(placed);
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
		rep = true;
		cout << "\n";
		board(placed);
		cout << '\n';
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
		board(placed);

		//victory = true;
		cout << '\n';
	}
}

//-----------------------------------------------------
// board()
//-----------------------------------------------------
// in:int array with '1' representing P1
//		'2' representing P2
//		'0' blank
// out:tic tac toe board
//-----------------------------------------------------
void board(int condition[])
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
