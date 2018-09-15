#include "board.h"

class BoardImpl {
public:
  bool cell[Board::X_MAX][Board::Y_MAX];

  bool getAlive(unsigned int x, unsigned int y);
  void setAlive(unsigned int x, unsigned int y, bool alive);

  unsigned int neighbors(unsigned int x, unsigned int y);

  void newCycle(void);
};

bool BoardImpl::getAlive(unsigned int x, unsigned int y) { return false; }
void BoardImpl::setAlive(unsigned int x, unsigned int y, bool alive) {
  // Do nothing
}

unsigned int BoardImpl::neighbors(unsigned int x, unsigned int y) { return 0; }

void BoardImpl::newCycle(void) {
  // Do nothing
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
