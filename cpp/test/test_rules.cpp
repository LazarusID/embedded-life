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