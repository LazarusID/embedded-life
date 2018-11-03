#include "game.h"
#include "board.h"
#include "rules.h"

void game_run(int argc, char **argv) {
  // Do Nothing
}

void game_init(int argc, char **argv) {
  // Do Nothing
}

void game_loop(void) {
  for (int x = 0; x < BOARD_X; ++x) {
    for (int y = 0; y < BOARD_Y; ++y) {
      board_setFutureCell(
          x, y,
          is_alive(board_getCurrentCell(x, y), board_currentNeighbors(x, y)));
    }
  }
  board_makeFutureStateCurrent();
}

void game_draw(void) {
  // Do Nothing
}