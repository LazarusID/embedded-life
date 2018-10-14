#include "rules.h"
#include <check.h>


START_TEST(isalive_AlivewithThreeNeighbors_returnsTrue) {
  ck_assert_int_eq(true, is_alive(true, 3));
}
END_TEST

START_TEST(isalive_DeadWithTwoNeighbors_returnsFalse) {
  ck_assert_int_eq(false, is_alive(false, 2));
}
END_TEST

START_TEST(isalive_AliveWithTwoNeighbors_returnsTrue) {
  ck_assert_int_eq(true, is_alive(true, 2));
}
END_TEST

START_TEST(isalive_withFourNeighbors_returnsFalse) {
  ck_assert_int_eq(false, is_alive(true, 4));
  ck_assert_int_eq(false, is_alive(false, 4));
}
END_TEST

START_TEST(isalive_withoneneighbor_returnsfalse) {
  ck_assert_int_eq(false, is_alive(true, 1));
  ck_assert_int_eq(false, is_alive(false, 1));
}
END_TEST

TCase *tcase_rules() {
  TCase *tc = tcase_create("rules");
  tcase_add_test(tc, isalive_AlivewithThreeNeighbors_returnsTrue);
  tcase_add_test(tc, isalive_DeadWithTwoNeighbors_returnsFalse);
  tcase_add_test(tc, isalive_AliveWithTwoNeighbors_returnsTrue);
  tcase_add_test(tc, isalive_withFourNeighbors_returnsFalse);
  tcase_add_test(tc, isalive_withoneneighbor_returnsfalse);
  return tc;
}

Suite *suite_rules() {
  Suite *s = suite_create("life-rules");
  suite_add_tcase(s, tcase_rules());
  return s;
}