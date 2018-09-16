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

TEST_F(testBoard, neighbors_oneSetAtZeroZero_returnsOne) {
  board.setAlive(1, 1, true);
  board.newCycle();

  ASSERT_EQ(1, board.neighbors(0, 0));
}

TEST_F(testBoard, neighbors_oneSetAtMax_returnsOne) {
  board.setAlive(Board::X_SIZE - 2, Board::Y_SIZE - 2, true);
  board.newCycle();

  ASSERT_EQ(1, board.neighbors(Board::X_SIZE - 1, Board::Y_SIZE - 1));
}