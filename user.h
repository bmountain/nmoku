#ifndef user_h
#define user_h 1

#include "player.h"

using namespace std;

class User : public Player {
  /**
   * @brief ユーザが数字を入力する
   *
   */
public:
  User(string m, string n) : Player(m, n){};
  void move() override;
};
#endif