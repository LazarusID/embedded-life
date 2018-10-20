#ifndef _BOARD_H_
#define _BOARD_H_

#include <stdbool.h>

#define BOARD_X 32
#define BOARD_Y 64

bool board_getCurrentCell(unsigned int x, unsigned int y);
void board_setFutureCell(unsigned int x, unsigned int y, bool alive);
void board_makeFutureStateCurrent();
int board_currentNeighbors(unsigned int x, unsigned int y);

#endif