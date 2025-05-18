#ifndef player_h
#define player_h
#include <string>
using namespace std;

class Player {
protected:
  const string mark; // プレイヤーが書き込む記号
  int number;        // 選択したセル番号
  string name;

public:
  Player() : mark(" "), number(-1), name(""){};

  /**
   * @brief プレイヤーが盤面に書く記号を設定する
   *
   * @param m 記号
   * @param n 名前
   */
  Player(string m, string n) : mark(m), name(n){};

  /**
   * @brief 書き込み先のセル番号を選ぶ
   *
   */
  virtual void move() = 0;

  /**
   * @brief 直前の手番で選択したセルのインデックスを返す
   *
   */
  int getNumber() const {
    return number;
  }

  /**
   * @brief マークを返す
   *
   */
  string getMark() const {
    return mark;
  }

  /**
   * @brief 名前を返す
   *
   */
  string getName() const {
    return name;
  }
};

#endif