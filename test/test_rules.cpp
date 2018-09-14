#include "../life/rules.h"

#include <gtest/gtest.h>

using namespace ::testing;

class testRules : public testing::Test {
public:
  Rules rules;
};

TEST_F(testRules, isAlive_liveCellTwoNeighbors_returnsTrue) {
  ASSERT_TRUE(rules.isAlive(true, 2));
}

TEST_F(testRules, isAlive_deadCellTwoNeighbors_returnsFalse) {
  ASSERT_FALSE(rules.isAlive(false, 2));
}

TEST_F(testRules, isAlive_liveCellOneNeighbor_returnsFalse) {
  ASSERT_FALSE(rules.isAlive(true, 1));
}

TEST_F(testRules, isAlive_deadCellOneNeighbor_returnsFalse) {
  ASSERT_FALSE(rules.isAlive(false, 1));
}

TEST_F(testRules, isAlive_liveCellThreeNeighbors_returnsTrue) {
  ASSERT_TRUE(rules.isAlive(true, 3));
}

TEST_F(testRules, isAlive_deadCellThreeNeighbors_returnsTrue) {
  ASSERT_TRUE(rules.isAlive(false, 3));
}

TEST_F(testRules, isAlive_liveCellFourNeighbors_returnsFalse) {
  ASSERT_FALSE(rules.isAlive(true, 4));
}

TEST_F(testRules, isAlive_deadCellFourNeighbors_returnsFalse) {
  ASSERT_FALSE(rules.isAlive(false, 4));
}

TEST_F(testRules, isAlive_liveCellMoreThanFourNeighbors_returnsFalse) {
  ASSERT_FALSE(rules.isAlive(true, 10));
}