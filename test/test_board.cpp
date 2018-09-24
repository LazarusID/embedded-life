#include "../life/board.h"

#include <gtest/gtest.h>

using namespace ::testing;

class testBoard : public testing::Test {
public:
  Board board;
};

TEST_F(testBoard, getAlive_afterSetAndNewCycle_returnsTrue) {
  board.setAlive(2, 2, true);
  board.newCycle();

  ASSERT_TRUE(board.getAlive(2, 2));
}

TEST_F(testBoard, getAlive_afterSetBeforeNewCycle_returnsFalse) {
  board.setAlive(2, 2, true);
  ASSERT_FALSE(board.getAlive(2, 2));
}

TEST_F(testBoard, neighbors_twoSetAfterNewCycle_returnsTwo) {
  board.setAlive(1, 1, true);
  board.setAlive(3, 3, true);
  board.newCycle();

  ASSERT_EQ(2, board.neighbors(2, 2));
}

TEST_F(testBoard, neighbors_oneSetAfterNewCycle_returnsOne) {
  board.setAlive(1, 1, true);
  board.newCycle();

  ASSERT_EQ(1, board.neighbors(2, 2));
}

TEST_F(testBoard, neighbors_liveCellOneSete_returnsOne) {
  board.setAlive(2, 1, true);
  board.setAlive(2, 2, true);
  board.newCycle();

  ASSERT_EQ(1, board.neighbors(2, 2));
}

TEST_F(testBoard, neighbors_SurroundedAtZeroZero_returnsThree) {
  board.setAlive(1, 1, true);
  board.setAlive(0, 1, true);
  board.setAlive(1, 0, true);
  board.newCycle();

  ASSERT_EQ(3, board.neighbors(0, 0));
}

TEST_F(testBoard, neighbors_oneSetAtMax_returnsOne) {
  board.setAlive(62, 62, true);
  board.newCycle();

  ASSERT_EQ(1, board.neighbors(63, 63));
}

TEST_F(testBoard, neighbors_whenSurrounded_returnsEight) {
	board.setAlive(31, 31, true);
	board.setAlive(32, 31, true);
	board.setAlive(33, 31, true);
	board.setAlive(31, 32, true);
	board.setAlive(33, 32, true);
	board.setAlive(31, 33, true);
	board.setAlive(32, 33, true);
	board.setAlive(33, 33, true);
	board.newCycle();

	ASSERT_EQ(8, board.neighbors(32, 32));
}
