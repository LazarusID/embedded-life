#ifndef _GAME_H_
#define _GAME_H_

#include <led-matrix.h>

using rgb_matrix::Canvas;

class Game {
public:
  Canvas *canvas = NULL;

  // Run once at program startup.  Handles all of the initialization.
  void init(int argc, char **argv);

  // Contains the logic for a single iteration of the
  // main logic loop for the program.
  void loop();
};

#endif