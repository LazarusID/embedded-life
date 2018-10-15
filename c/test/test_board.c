#include "board.h"

#include <check.h>

START_TEST(getCurrentCell_afterBoardSetAndMakeFutureCurrent_returnsTrue) {
  // Arrange
  board_setFutureCell(1, 1, true);

  // Act
  board_makeFutureStateCurrent();

  // Assert
  ck_assert_int_eq(true, board_getCurrentCell(1, 1));
}
END_TEST

START_TEST(getCurrentCell_afterBoardSet_returnsFalse) {
  board_setFutureCell(1, 1, true);
  ck_assert_int_eq(false, board_getCurrentCell(1, 1));
}
END_TEST

START_TEST(getCurrentCell_afterSetOutsideBoard_returnsFalse) {
  board_setFutureCell(BOARD_X, BOARD_Y, true);
  board_makeFutureStateCurrent();
  ck_assert_int_eq(false, board_getCurrentCell(BOARD_X, BOARD_Y));
}
END_TEST

TCase *tcase_board() {
  TCase *tc = tcase_create("board");
  tcase_add_test(tc,
                 getCurrentCell_afterBoardSetAndMakeFutureCurrent_returnsTrue);
  tcase_add_test(tc, getCurrentCell_afterBoardSet_returnsFalse);
  tcase_add_test(tc, getCurrentCell_afterSetOutsideBoard_returnsFalse);
  return tc;
}

Suite *suite_board() {
  Suite *s = suite_create("board");
  suite_add_tcase(s, tcase_board());
  return s;
}