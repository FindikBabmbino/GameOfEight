#include <iostream>
using namespace std;

/*
The game of 8 is played by 2 players. 
The game starts with the initial number 8 (from here on refered to as the initial number). 
The first player will choose a number from 1 to 3 (from here on refered to as the chosen number). 
If the player inputs something outside of the 1 to 3 range it should be an error and the player must choose again. 
The initial number is subtracted by the chosen number. 
Then the next player's turn happens. The next player cannot choose the number that the last player chose. 
If the initial number goes to 0 on your turn, then you win. 
Otherwise if the number goes below 0, your opponent wins. 
The player should always see what choices are available to him when prompted to enter his choice. 
After the game is over, the user should be prompted whether they want to play again.
*/


void PlayGame();
int GetInput(int compareInput);
bool ContinuePlaying();
bool CheckWin(int initialNum,int currentPlayer);
void DisplayCurrentPlayer(int playerNum);

const int IGNORE_CHARS = 256;


int main()
{
	/*
		do
		{
			PlayGame();
		}while(ContinuePlaying());

		1. Set the initial number to 8
		2. Start the game
		3. Set currentPlayerInt to 0 so that it starts from the first player.
		4. Let the player choose a number from 1-3 store what they chose in an int 
			4a1. if the player chooses out of range or they choose what the other player chose send an error message.
		5.Switch players and repeat.
		6.End of the game display the results if you get zero you win if it is below zero you lose.
		7. ask to restart game

		do
		{
			userInput = GetInput(int compareInput)
			compareInput = userInput
		}while(CheckWin())

		Functions
		Plays the game -> PlayGame()
		Gets the int input from the player ->GetInput()
		Checks the win condition and displays win -> CheckWin()
		Display the current player -> DisplayCurrentPlayer(int playerNum)
	*/

	do
	{
		PlayGame();
	} while (ContinuePlaying());

}

void PlayGame()
{
	int initialNum = 8;
	int userInput = 0;
	int compareInput = 0;
	int currentPlayer = 0;


	do
	{
		cout << endl;
		DisplayCurrentPlayer(currentPlayer);

		cout << "Current initial number is: " << initialNum << endl;

		userInput = GetInput(compareInput);
		compareInput = userInput;
		initialNum -= userInput;
		if(initialNum > 0)
		{
			if (currentPlayer == 0) currentPlayer++;
			else currentPlayer--;
		}
	} while (!CheckWin(initialNum,currentPlayer));
}

int GetInput(int compareInput)
{
	int input;
	bool failure;
	
	do
	{
		failure = false;
		cout << "Enter an input between 1 to 3, but don't enter what the player before you entered. (Player before you has chose: " << compareInput << ") ";
	
		cin >> input;
		if (cin.fail() || input == compareInput || input > 3)
		{
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			cout << "Please enter a valid number" << endl;
			failure = true;
		}
	} while (failure);
	return input;
}

bool ContinuePlaying()
{
	char input;
	bool failure;
	do
	{
		failure = false;
		cout << "Do you wish to play again? (y/n) ";
		cin >> input;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			cout << "Enter a valid character" << endl;
			failure = true;
		}
		else
		{
			cin.ignore(IGNORE_CHARS, '\n');
			input = tolower(input);
		}
	} while (failure);
	return input == 'y';
}

bool CheckWin(int initialNum,int currentPlayer)
{
	if(initialNum == 0)
	{
		if(currentPlayer == 0)
			cout << "Congrats, player 1 has won!" << endl;
		else
			cout << "Congrats, player 2 has won!" << endl;
		return true;
	}
	else if(initialNum < 0)
	{
		if(currentPlayer == 0)
			cout << "Congrats, player 2 has won!" << endl;
		else
			cout << "Congrats, player 1 has won!" << endl;
		return true;
	}
	return false;
}

void DisplayCurrentPlayer(int playerNum)
{
	if(playerNum == 0)
	{
		cout << "Player 1's turn." << endl;
	}
	else
	{
		cout << "Player 2's turn." << endl;
	}
}