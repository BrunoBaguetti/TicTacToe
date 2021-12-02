
#include "TicTacToe.h"
#include <stdexcept>
#include <map>

std::map<TicTacToe::PlayerTurn, char> mapPlayer = {{TicTacToe::PlayerTurn::CROSS_X, 'X'}, {TicTacToe::PlayerTurn::CIRCLES_O, 'O'}};

TicTacToe::TicTacToe()
{
	for (auto &x : displayChar)
	{
		for (auto &y : x)
		{
			y = '_';
		}
	}

	playTurn = PlayerTurn::CROSS_X;
	gameStatus = GameState::PLAYING;
}

TicTacToe::~TicTacToe()
{
	// TODO Auto-generated destructor stub
}

void TicTacToe::display()
{

	std::cout << displayChar[0][0] << " " << displayChar[0][1] << " "
			  << displayChar[0][2] << std::endl;

	std::cout << displayChar[1][0] << " " << displayChar[1][1] << " "
			  << displayChar[1][2] << std::endl;

	std::cout << displayChar[2][0] << " " << displayChar[2][1] << " "
			  << displayChar[2][2] << std::endl;
}

void TicTacToe::writePlayBoard()
{
	auto num = 0;

	std::cout << mapPlayer[playTurn] << " Plays\n";
	std::cin >> num;

	auto count = 0;
	for (auto &x : displayChar)
	{
		for (auto &y : x)
		{
			count++;
			if (count == num)
			{
				if (y != '_')
				{
					throw std::runtime_error("Can't choose that place, already ocupied!");
				}
				else
					y = mapPlayer[playTurn];
			}
		}
	}
}

void TicTacToe::evaluateGame()
{
	auto count{0};
	for (auto i = 0; i < 3; i++)
	{
		for (auto j = 0; j < 3; j++)
		{
			if (displayChar[i][j] == mapPlayer[playTurn])
			{
				count++;
			}
		}
		if (count == 3)
		{
			gameStatus = TicTacToe::GameState::ENDED;
			std::cout << mapPlayer[playTurn] << " Wins\n";
			return;
		}
		count = 0;
	}

	for (auto i = 0; i < 3; i++)
	{
		for (auto j = 0; j < 3; j++)
		{
			if (displayChar[j][i] == mapPlayer[playTurn])
			{
				count++;
			}
		}
		if (count == 3)
		{
			gameStatus = TicTacToe::GameState::ENDED;
			std::cout << mapPlayer[playTurn] << " Wins\n";
			return;
		}
		count = 0;
	}

	if ((displayChar[0][0] == displayChar[1][1] && displayChar[1][1] == displayChar[2][2]) && displayChar[1][1] != '_')
	{
		gameStatus = TicTacToe::GameState::ENDED;
		std::cout << mapPlayer[playTurn] << " Wins\n";
		return;
	}

	if ((displayChar[0][2] == displayChar[1][1] && displayChar[2][0] == displayChar[1][1]) && displayChar[1][1] != '_')
	{
		gameStatus = TicTacToe::GameState::ENDED;
		std::cout << mapPlayer[playTurn] << " Wins\n";
		return;
	}
}

void TicTacToe::makeMove()
{
	try
	{
		writePlayBoard();
	}
	catch (const std::runtime_error &message)
	{
		std::cout << message.what() << std::endl;
		return;
	}
	evaluateGame();
	display();

	if (static_cast<int>(playTurn) % 2 == 0)
	{
		playTurn = PlayerTurn::CROSS_X;
	}
	else
		playTurn = PlayerTurn::CIRCLES_O;
}

TicTacToe::GameState TicTacToe::getGameState()
{
	return gameStatus;
}