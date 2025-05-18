#ifndef utils_h
#define utils_h 1
#include "board.h"
#include "player.h"
#include <string>
using namespace std;

bool isNumber(string);
void prompt(const Player *);
void showWinner(const Player *);
void showResult(const Board, const Player *);

#endif