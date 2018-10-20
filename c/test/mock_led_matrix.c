#include "mock_led_matrix.h"

struct RGBLedMatrixOptions *actual_options = NULL;
int actual_argc = 0;
char **actual_argv = NULL;

struct RGBLedMatrix *expected_create_return = NULL;

void mock_led_matrix_init(void) {
  actual_options = NULL;
  actual_argc = 0;
  actual_argv = NULL;

  expected_create_return = NULL;
}

void led_matrix_create_from_options_will_return(struct RGBLedMatrix *expected) {
  expected_create_return = expected;
}

int led_matrix_create_from_options_argc(void) { return actual_argc; }
char **led_matrix_create_from_options_argv(void) { return actual_argv; }
struct RGBLedMatrix *led_matrix_create_from_options_options(void) {
  return actual_options;
}

struct RGBLedMatrix *led_matrix_create_from_options(
    struct RGBLedMatrixOptions *options, int *argc, char ***argv) {
  actual_options = options;
  actual_argc = *argc;
  actual_argv = *argv;

  return expected_create_return;
}
