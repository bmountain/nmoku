#include "utils.h"
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

void showWinner(const Player *player) {
  cout << player->getName() << "(" << player->getMark() << ")の勝ち" << endl;
}
