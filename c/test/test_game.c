#include "board.h"
#include "game.h"
#include <check.h>

START_TEST(loop_givenInitializedBoard_appliesRules) {
  board_setFutureCell(1, 1, true);
  board_makeFutureStateCurrent();

  game_loop();

  ck_assert_int_eq(false, board_getCurrentCell(1, 1));
}
END_TEST

TCase *tcase_game() {
  TCase *tc = tcase_create("game");
  tcase_add_test(tc, loop_givenInitializedBoard_appliesRules);
  return tc;
}

Suite *suite_game() {
  Suite *s;

  s = suite_create("game");
  suite_add_tcase(s, tcase_game());

  return s;
}