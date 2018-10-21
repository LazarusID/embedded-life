#include "game.h"
#include "led-matrix.h"

using namespace rgb_matrix;

void Game::init(int argc, char **argv) {
  canvas = CreateMatrixFromFlags(&argc, &argv);
}