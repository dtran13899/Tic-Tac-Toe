#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int player = 1;
char turn = 'X';
int choice;
bool draw = false;
int i, j;

// give instruction to players
void instruction();

// display the board
void display_board(std::vector<std::vector<char>>& board);

// check if the game have a winner, or game draw
bool game_over(std::vector<std::vector<char>>& board);

// get player's input and update the board
void player_input(std::vector<std::vector<char>>& board);

// annouce the winner
void winner(std::vector<std::vector<char>>& board);

int main()
{
	std::vector<std::vector<char>> board = { { '1', '2', '3'}, {'4', '5', '6' }, {'7', '8', '9'} };
	instruction();
	display_board(board);
	while (!game_over(board))
	{
		player_input(board);
		display_board(board);
	}
	winner(board);
}


void instruction()
{
	cout << "\t\t\tWelcome to the Tic-Tac-Toe game!\n\n";
	cout << "\tTwo players will make their move by entering a number from 1-9.\n";
	cout << "As the board display, the number will correspond to the position on the board.\n\n";
}


void display_board(std::vector<std::vector<char>>& board)
{
	cout << "-------------" << endl;
	for (auto vec : board)
	{
		for (char c : vec)
		{
			cout << "| " << c << " ";
		}
		cout << "|" << endl;
		cout << "-------------" << endl;
	}
}


bool game_over(std::vector<std::vector<char>>& board)
{
	if (board[0][0] == board[0][1] && board[0][1] == board[0][2])
		return true;
	else if (board[1][0] == board[1][1] && board[1][1] == board[1][2])
		return true;
	else if (board[2][0] == board[2][1] && board[2][1] == board[2][2])
		return true;
	else if (board[0][0] == board[1][0] && board[1][0] == board[2][0])
		return true;
	else if (board[0][1] == board[1][1] && board[1][1] == board[2][1])
		return true;
	else if (board[0][2] == board[1][2] && board[1][2] == board[2][2])
		return true;
	else if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return true;
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return true;
	else if (board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3' &&
		board[1][0] != '4' && board[1][1] != '5' && board[1][2] != '6' &&
		board[2][0] != '7' && board[2][1] != '8' && board[2][2] != '9')
	{
		draw = true;
		return true;
	}
	return false;
}


void player_input(std::vector<std::vector<char>>& board)
{
	if (turn == 'X') {
		cout << "Player 1 - [X] turn - ";
	}
	else if (turn == 'O') {
		cout << "Player 2 - [O] turn - ";
	}
	cout << "Player choose position: ";
	while (!(cin >> choice)) {
		cout << "Wrong input! Please enter your choice again: ";
		cin.clear();
		cin.ignore();
	}
	// switch case to get which i and j will be update
	switch (choice) {
	case 1: i = 0; j = 0; break;
	case 2: i = 0; j = 1; break;
	case 3: i = 0; j = 2; break;
	case 4: i = 1; j = 0; break;
	case 5: i = 1; j = 1; break;
	case 6: i = 1; j = 2; break;
	case 7: i = 2; j = 0; break;
	case 8: i = 2; j = 1; break;
	case 9: i = 2; j = 2; break;
	}

	if (turn == 'X' && board[i][j] != 'X' && board[i][j] != 'O')
	{
		// updating the position for 'X' symbol if
		// it is not already occupied
		board[i][j] = 'X';
		turn = 'O';
	}
	else if (turn == 'O' && board[i][j] != 'X' && board[i][j] != 'O')
	{
		// updating the position for 'O' symbol if
		// it is not already occupied
		board[i][j] = 'O';
		turn = 'X';
	}
	else
	{
		// if input position already filled
		cout << "\nPlease choose another!!\n\n";
		player_input(board);
	}
}


void winner(std::vector<std::vector<char>>& board)
{
	if (turn == 'X' && draw == false)
		cout << "\n-----Congratulations! Player with 'O' is the winner-----";
	else if (turn == 'O' && draw == false)
		cout << "\n-----Congratulations! Player with 'X' is the winner-----";
	else
		cout << "\n-----Both players are tie-----!!!\n";
}