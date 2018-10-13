#include "../life/game.h"
#include "mock-led-matrix.h"

#include <gtest/gtest.h>

using namespace ::testing;
using namespace rgb_matrix;

class testGame : public testing::Test {
 public:
  Game game;
};

TEST_F(testGame, init_createsCanvasFromArguments) {
  int argc = 1;
  char argv0[] = {'t', 'e', 's', 't', 0};
  char *argv[] = {argv0, NULL};
  rgb_matrix::GPIO gpio;
  MockRGBMatrix expectedCanvas(&gpio);

  CreateMatrixFromFlags_willReturn(&expectedCanvas);

  game.init(argc, argv);

  ASSERT_TRUE(CreateMatrixFromFlags_wasCalled());
  ASSERT_EQ(&expectedCanvas, game.canvas);
  ASSERT_EQ(argc, CreateMatrixFromFlags_argc());
  ASSERT_EQ(argv, CreateMatrixFromFlags_argv());
}