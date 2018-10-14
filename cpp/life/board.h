#ifndef _BOARD_H_
#define _BOARD_H_

class BoardImpl;

class Board {
 public:
  Board();

  static const unsigned int X_SIZE = 64;
  static const unsigned int Y_SIZE = 64;

  bool getAlive(unsigned int x, unsigned int y);
  void setAlive(unsigned int x, unsigned int y, bool alive);

  unsigned int neighbors(unsigned int x, unsigned int y);

  void newCycle(void);

 private:
  BoardImpl *p;
};

#endif