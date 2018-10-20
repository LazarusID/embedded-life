#include "board.h"

static int current_generation = 0;
static int future_generation = 1;
static bool cells_initialized = false;

static bool cell[2][BOARD_X][BOARD_Y];

void initialize_cells() {
  for (int x = 0; x < BOARD_X; ++x) {
    for (int y = 0; y < BOARD_Y; ++y) {
      cell[current_generation][x][y] = false;
      cell[future_generation][x][y] = false;
    }
  }
  cells_initialized = true;
}

bool board_getCurrentCell(unsigned int x, unsigned int y) {
  if (!cells_initialized) {
    initialize_cells();
  }
  if (x >= BOARD_X || y >= BOARD_Y) {
    return false;
  }
  return cell[current_generation][x][y];
}

void board_setFutureCell(unsigned int x, unsigned int y, bool alive) {
  if (!cells_initialized) {
    initialize_cells();
  }
  if (x >= BOARD_X)
    return;
  if (y >= BOARD_Y)
    return;
  cell[future_generation][x][y] = alive;
}

void board_makeFutureStateCurrent() {
  if (0 == current_generation) {
    current_generation = 1;
    future_generation = 0;
  } else {
    current_generation = 0;
    future_generation = 1;
  }
}

int board_currentNeighbors(unsigned int x, unsigned int y) {
  int count = 0;

  for (int i = x - 1; i <= x + 1; ++i) {
    for (int j = y - 1; j <= y + 1; ++j) {
      if (x != i || y != j) {
        count += board_getCurrentCell(i, j);
      }
    }
  }

  return count;
}