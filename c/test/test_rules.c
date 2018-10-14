#include "rules.h"
#include <check.h>


START_TEST(isalive_AlivewithThreeNeighbors_returnsTrue) {
  ck_assert_int_eq(true, is_alive(true, 3));
}
END_TEST

TCase *tcase_rules() {
  TCase *tc = tcase_create("rules");
  tcase_add_test(tc, isalive_AlivewithThreeNeighbors_returnsTrue);
  return tc;
}

Suite *suite_rules() {
  Suite *s = suite_create("life-rules");
  suite_add_tcase(s, tcase_rules());
  return s;
}