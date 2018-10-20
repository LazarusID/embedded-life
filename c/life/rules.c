#include "rules.h"

bool is_alive(bool currently_alive, int neighbors) {
  switch (neighbors) {
    case 2:
      return currently_alive;
    case 3:
      return true;
    default:
      return false;
  }
}