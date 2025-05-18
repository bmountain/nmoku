#include "board.h"
#include "utils.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isConsecutive(vector<string> strings, string c);

Board::Board(int size_, int requiredLength_)
    : size(size_), requiredLength(requiredLength_), ongoing(true), count(0) {
  for (int i = 0; i < size; ++i) {
    vector<string> line;
    for (int j = 0; j < size; ++j) {
      line.push_back(to_string(size * i + j));
    }
    cells.push_back(line);
  }
}

bool Board::isOngoing() const {
  return ongoing;
}

string Board::getRule() const {
  string segment = "+";
  int num = size * size - 1;
  while (num > 0) {
    num /= 10;
    segment += "-";
  }

  string rule;
  for (int i = 0; i != size; ++i)
    rule += segment;
  rule += "+";
  return rule;
}

void Board::show() const {
  const string rule = getRule();

  cout << rule << "\n";
  for (int i = 0; i != size; ++i) {
    cout << "|";
    for (int j = 0; j != size; ++j) {
      string content = cells[i][j];
      for (int i = 0; i < getCellWidth() - content.size(); ++i)
        cout << " ";
      cout << content << "|";
    }
    cout << "\n";
  }
  cout << rule << endl;
}

void Board::update(const Player &player) {
  int number = player.getNumber();
  string mark = player.getMark();
  cells[number / size][number % size] = mark;
  count++;
  if (isWinningMove(player) || count == size * size)
    ongoing = false;
}

Coordinate Board::toCoordinate(int number) const {
  return make_pair(number / size, number % size);
}

bool Board::isWinningMove(const Player &player) const {
  return isHorizontalWinningMove(player) || isVerticalWinningMove(player) ||
         isBackSlashWinningMove(player) || isSlashWinningMove(player);
}

bool Board::isHorizontalWinningMove(const Player &player) const {
  string mark = player.getMark();
  Coordinate coord = toCoordinate(player.getNumber());
  const int x = coord.first, y = coord.second;

  int leftLimit = y - requiredLength + 1;
  for (int left = leftLimit; left <= y; ++left) {
    if (left < 0)
      continue;
    int rightEnd = left + requiredLength;
    if (rightEnd > size)
      break;

    // (left, y)から右方向に必要な数のマークがある？
    vector<string> line;
    for (int i = 0; i < requiredLength; ++i) {
      line.push_back(cells[x][left + i]);
    }
    if (isConsecutive(line, mark))
      return true;
  }
  return false;
}

bool Board::isVerticalWinningMove(const Player &player) const {
  string mark = player.getMark();
  Coordinate coord = toCoordinate(player.getNumber());
  const int x = coord.first, y = coord.second;

  int topLimit = x - requiredLength + 1;
  for (int top = topLimit; top <= x; ++top) {
    if (top < 0)
      continue;
    int bottomEnd = top + requiredLength;
    if (bottomEnd > size)
      break;

    // (top, y)から下方向に必要な数のマークがある？
    vector<string> line;
    for (int i = 0; i < requiredLength; ++i) {
      line.push_back(cells[top + i][y]);
    }
    if (isConsecutive(line, mark))
      return true;
  }
  return false;
}

bool Board::isBackSlashWinningMove(const Player &player) const {
  Coordinate coord = toCoordinate(player.getNumber());
  string mark = player.getMark();
  const int x = coord.first, y = coord.second;

  int topLimit = x - requiredLength + 1;
  int leftLimit = y - requiredLength + 1;
  for (int top = topLimit, left = leftLimit; top <= x && left <= y;
       ++top, ++left) {
    if (top < 0 || left < 0)
      continue;
    int bottomEnd = top + requiredLength;
    int rightEnd = left + requiredLength;
    if (bottomEnd > size || rightEnd > size)
      break;

    vector<string> line;
    for (int i = 0; i < requiredLength; ++i) {
      line.push_back(cells[top + i][left + i]);
    }
    if (isConsecutive(line, mark))
      return true;
  }
  return false;
}

bool Board::isSlashWinningMove(const Player &player) const {
  string mark = player.getMark();
  Coordinate coord = toCoordinate(player.getNumber());
  const int x = coord.first, y = coord.second;

  int topLimit = x - requiredLength + 1;
  int rightLimit = y + requiredLength - 1;
  for (int top = topLimit, right = rightLimit; top <= x && right >= y;
       ++top, --right) {
    if (top < 0 || right >= size)
      continue;
    int bottom = top + requiredLength - 1;
    int left = right - requiredLength + 1;
    if (bottom >= size || left < 0)
      break;

    vector<string> line;
    for (int i = 0; i < requiredLength; ++i) {
      line.push_back(cells[top + i][right - i]);
    }
    if (isConsecutive(line, mark))
      return true;
  }
  return false;
}

/**
 * @brief 一列がすべて特定の記号か判定する
 *
 */
bool isConsecutive(vector<string> chars, string c) {
  return all_of(chars.begin(), chars.end(), [c](string d) {
    return c == d;
  });
}

bool Board::isValidMove(const Player &player) const {
  const int choice = player.getNumber();
  if (choice < 0 || choice >= size * size)
    return false;
  const string cellContent = cells[choice / size][choice % size];
  return isNumber(cellContent);
}

bool Board::isDraw() const {
  if (!ongoing && count < size * size)
    return false;
  return true;
}

int Board::getCellWidth() const {
  int number = size * size - 1;
  int count = 0;
  while (number > 0) {
    number /= 10;
    count++;
  }
  return count;
}

void Board::verticalLine() const {
  const char c = '*';
  const int length = (1 + getCellWidth()) * size + 1;
  string vline;
  for (int i = 0; i < length; ++i)
    vline += c;
  cout << "\n" << vline << endl;
}