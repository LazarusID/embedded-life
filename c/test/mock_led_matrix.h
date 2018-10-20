#ifndef _MOCK_LED_MATRIX_H_
#define _MOCK_LED_MATRIX_H_

#include <led-matrix-c.h>

void mock_led_matrix_init(void);

void led_matrix_create_from_options_will_return(struct RGBLedMatrix*);
int led_matrix_create_from_options_argc(void);
char** led_matrix_create_from_options_argv(void);
struct RGBLedMatrix* led_matrix_create_from_options_options(void);

#endif