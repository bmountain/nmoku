#include "user.h"
#include "utils.h"
#include <iostream>

void User::move() {
  string choice;
  while (!isNumber(choice)) {
    cin >> choice;
  }
  number = stoi(choice);
}
