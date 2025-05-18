#include "user.h"
#include "utils.h"
#include <iostream>

void User::move() {
  string choice;
  while (!isNumber(choice) || stoi(choice) < 0) {
    prompt(this);
    cin >> choice;
  }
  number = stoi(choice);
}
