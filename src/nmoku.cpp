#include "board.h"
#include "user.h"
#include "utils.h"
#include <vector>
using namespace std;
int main() {
  const int boardSize = 5;
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
    do {
      player->move();
    } while (!board.isValidMove(*player));
    board.update(*player);
    board.verticalLine();
    turn = 1 - turn;
  } while (board.isOngoing());
  showResult(board, player);
}