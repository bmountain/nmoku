#ifndef board_h
#define board_h 1

#include "player.h"
#include <string>
#include <vector>
using namespace std;

typedef pair<int, int> Coordinate;

/**
 * @brief
 *
 */
class Board {
  const int size;           // 縦幅（=横幅）
  const int requiredLength; // 勝つためにいくつ並べるか
  vector<vector<string>> cells;
  bool ongoing;
  int count;

public:
  /**
   * @brief 盤面を数字で埋めて初期化する
   *
   */
  Board(int size_, int requiredLength_);

  /**
   * @brief 盤面をコンソールに表示する
   *
   */
  void show() const;

  /**
   * @brief 有効なmoveか判定する
   *
   */
  bool isValidMove(const Player &) const;

  /**
   * @brief プレイヤーが選択した手を盤面に反映し継続判定する
   *
   */
  void update(const Player &);

  /**
   * @brief 継続中か問い合わせ
   *
   */
  bool isOngoing() const;

  /**
   * @brief 引き分けか判定
   *
   * @return true 引き分け
   * @return false 引き分けでない
   */
  bool isDraw() const;

  /**
   * @brief 区切り線を表示
   *
   */
  void verticalLine() const;

private:
  /**
   * @brief ある手番で勝ちが決まったか判定する
   *
   */
  bool isWinningMove(const Player &) const;

  /**
   * @brief 横方向の勝ちラインを作ったか
   *
   */
  bool isHorizontalWinningMove(const Player &) const;

  /**
   * @brief 縦方向の勝ちラインを作ったか
   *
   */
  bool isVerticalWinningMove(const Player &) const;

  /**
   * @brief 左上から右下への勝ちラインを作ったか
   *
   */
  bool isBackSlashWinningMove(const Player &) const;

  /**
   * @brief 右上から左下への勝ちラインを作ったか
   *
   */
  bool isSlashWinningMove(const Player &) const;

  /**
   * @brief セルの番号を座標に変換する
   *
   */
  Coordinate toCoordinate(const int number) const;

  /**
   * @brief 罫線を作る
   *
   */
  string getRule() const;

  /**
   * @brief セル幅を返す
   *
   */
  int getCellWidth() const;
};

#endif