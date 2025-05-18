#include "board.h"
#include "user.h"
#include "utils.h"
#include <iostream>
#include <vector>
using namespace std;
int main() {
  const int boardSize = 20;
  const int requiredLength = 5;
  Board board(boardSize, requiredLength);

  User user1("O", "Player1");
  User user2("X", "Player2");
  vector<Player *> players = {&user1, &user2};
  Player *player;
  int turn = 0;
  do {
    board.show();
    player = players[turn];
    prompt(player);
    do {
      player->move();
    } while (!board.isValidMove(*player));
    board.update(*player);
    turn = 1 - turn;
    board.verticalLine();
  } while (board.isOngoing());
  if (board.isDraw()) {
    cout << "引き分け" << endl;
    board.show();
    return 0;
  }
  showWinner(player);
  board.show();
}