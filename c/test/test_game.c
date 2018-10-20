#include <check.h>

#include "board.h"
#include "game.h"
#include "mock_led_matrix.h"

START_TEST(loop_givenInitializedBoard_appliesRules) {
  board_setFutureCell(1, 1, true);
  board_makeFutureStateCurrent();

  game_loop();

  ck_assert_int_eq(false, board_getCurrentCell(1, 1));
}
END_TEST

START_TEST(init_byDefault_callsled_matrix_create_from_options) {
  int argc = 1;
  char *argv[] = {"testgame", NULL};
  struct RGBLedMatrix *expectedMatrix = (struct RGBLedMatrix *)0xdeadbeef;

  led_matrix_create_from_options_will_return(expectedMatrix);

  game_init(argc, argv);

  ck_assert_int_eq(1, led_matrix_create_from_options_argc());
  ck_assert_ptr_eq(argv, led_matrix_create_from_options_argv());
}
END_TEST

TCase *tcase_game() {
  TCase *tc = tcase_create("game");
  tcase_add_test(tc, loop_givenInitializedBoard_appliesRules);
  tcase_add_test(tc, init_byDefault_callsled_matrix_create_from_options);
  return tc;
}

Suite *suite_game() {
  Suite *s;

  s = suite_create("game");
  suite_add_tcase(s, tcase_game());

  return s;
}