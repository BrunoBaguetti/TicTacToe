#pragma once

#include <iostream>
#include <string>

class TicTacToe
{
public:
  TicTacToe();

  virtual ~TicTacToe();
  void display();
  void makeMove();

  enum class PlayerTurn
  {
    CROSS_X = 1,
    CIRCLES_O = 2,
  };

  enum class GameState
  {
    PLAYING,
    ENDED
  };

  GameState getGameState();

private:
  void writePlayBoard();
  void evaluateGame();

  PlayerTurn playTurn;
  GameState gameStatus;
  char displayChar[3][3];
};
