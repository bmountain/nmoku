#include "utils.h"
#include "board.h"
#include <iostream>
#include <string>
using namespace std;

bool isNumber(string choice) {
  if (choice.size() == 0)
    return false;
  for (const auto c : choice)
    if (c < '0' || '9' < c)
      return false;
  return true;
}

void prompt(const Player *player) {
  cout << "\n" << player->getName() << "(" << player->getMark() << ")の手番：";
}

void showResult(const Board board, const Player *player) {
  if (board.isDraw()) {
    cout << "引き分け" << endl;
    board.show();
  }
  cout << player->getName() << "(" << player->getMark() << ")の勝ち" << endl;
  board.show();
}