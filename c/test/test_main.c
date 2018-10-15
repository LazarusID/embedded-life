#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "suites.h"

int main(int argc, char **argv) {
  SRunner *runner;
  int failed_tests;

  runner = srunner_create(suite_rules());
  srunner_add_suite(runner, suite_board());
  srunner_run_all(runner, CK_NORMAL);

  failed_tests = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed_tests;
}