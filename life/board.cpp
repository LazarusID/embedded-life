#include "board.h"

class BoardImpl {
 public:
  unsigned int current_state = 0;
  unsigned int future_state = 1;

  bool cells[2][Board::X_SIZE][Board::Y_SIZE];

  bool getAlive(unsigned int x, unsigned int y);
  void setAlive(unsigned int x, unsigned int y, bool alive);

  unsigned int neighbors(unsigned int x, unsigned int y);

  void newCycle(void);
};

bool BoardImpl::getAlive(unsigned int x, unsigned int y) {
  return cells[current_state][x][y];
}
void BoardImpl::setAlive(unsigned int x, unsigned int y, bool alive) {
  cells[future_state][x][y] = alive;
}

unsigned int BoardImpl::neighbors(unsigned int x, unsigned int y) {
  unsigned int count = 0;
  unsigned int minx, maxx, miny, maxy;

  if (0 == x)
    minx = 0;
  else
    minx = x - 1;

  if (0 == y)
    miny = 0;
  else
    miny = y - 1;

  maxx = x + 1;
  maxy = y + 1;

  if (Board::X_SIZE <= maxx) maxx == Board::X_SIZE - 1;
  if (Board::Y_SIZE <= maxy) maxy == Board::Y_SIZE - 1;

  for (unsigned int i = minx; i <= maxx; ++i) {
    for (unsigned int j = miny; j <= maxy; ++j) {
      if (i != x || j != y) {
        if (getAlive(i, j)) ++count;
      }
    }
  }

  return count;
}

void BoardImpl::newCycle(void) {
  if (0 == current_state) {
    current_state = 1;
    future_state = 0;
  } else {
    current_state = 0;
    future_state = 1;
  }
}

/////
// Passthrough to implementation
/////

Board::Board() { p = new BoardImpl(); }

bool Board::getAlive(unsigned int x, unsigned int y) {
  return p->getAlive(x, y);
}
void Board::setAlive(unsigned int x, unsigned int y, bool alive) {
  p->setAlive(x, y, alive);
}

unsigned int Board::neighbors(unsigned int x, unsigned int y) {
  return p->neighbors(x, y);
}

void Board::newCycle(void) { p->newCycle(); }
