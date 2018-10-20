#include "rules.h"

bool Rules::isAlive(bool currentlyAlive, int neighbors) {
  switch (neighbors) {
  case 2:
    return currentlyAlive;
  case 3:
    return true;
  default:
    return false;
  }
}