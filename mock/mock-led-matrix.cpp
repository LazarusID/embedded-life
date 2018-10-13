#include "mock-led-matrix.h"
#include <stdlib.h>

using namespace rgb_matrix;

RGBMatrix *creatematrix_returnValue = NULL;
bool creatematrix_wascalled = false;
int creatematrix_argc = -1;
char **creatematrix_argv = NULL;

RGBMatrix *rgb_matrix::CreateMatrixFromFlags(
    int *argc, char ***argv, RGBMatrix::Options *default_options,
    RuntimeOptions *default_runtime_opts, bool remove_consumed_flags) {
  creatematrix_argc = *argc;
  creatematrix_argv = *argv;
  creatematrix_wascalled = true;
  return creatematrix_returnValue;
}

void CreateMatrixFromFlags_willReturn(RGBMatrix *toreturn) {
  creatematrix_returnValue = toreturn;
}
bool CreateMatrixFromFlags_wasCalled(void) { return creatematrix_wascalled; }

int CreateMatrixFromFlags_argc(void) { return creatematrix_argc; }
char **CreateMatrixFromFlags_argv(void) { return creatematrix_argv; }

// Local overrides for methods the compiler will look for but we don't have
rgb_matrix::RGBMatrix::Options::Options() {
  // Do Nothing
}
rgb_matrix::RGBMatrix::RGBMatrix(rgb_matrix::GPIO *io, int rows,
                                 int chained_displays, int parallel_displays) {
  // Do Nothing
}
rgb_matrix::RGBMatrix::~RGBMatrix() {
  // Do Nothing
}
int rgb_matrix::RGBMatrix::width() const { return -1; }
int rgb_matrix::RGBMatrix::height() const { return -1; }
void rgb_matrix::RGBMatrix::SetPixel(int x, int y, uint8_t red, uint8_t green,
                                     uint8_t blue) {
  // Do Nothing
}
void rgb_matrix::RGBMatrix::Clear() {
  // Do Nothing
}
void rgb_matrix::RGBMatrix::Fill(uint8_t red, uint8_t green, uint8_t blue) {
  // Do Nothing
}

GPIO::GPIO() {
  // Do Nothing
}
MockRGBMatrix::MockRGBMatrix(rgb_matrix::GPIO *io, int rows,
                             int chained_displays, int parallel_displays)
    : RGBMatrix(io, rows, chained_displays, parallel_displays) {
  // Do Nothing
}
MockRGBMatrix::~MockRGBMatrix() {
  // Nothing to do
}
int MockRGBMatrix::width() const { return -1; }
int MockRGBMatrix::height() const { return -1; }
void MockRGBMatrix::SetPixel(int x, int y, uint8_t red, uint8_t green,
                             uint8_t blue) {
  // Do Nothing
}
void MockRGBMatrix::Clear() {
  // Do Nothing
}
void MockRGBMatrix::Fill(uint8_t red, uint8_t green, uint8_t blue) {
  // Do Nothing
}
