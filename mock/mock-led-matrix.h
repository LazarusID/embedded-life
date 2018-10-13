#ifndef _LED_MATRIX_H_
#define _LED_MATRIX_H_

#include "led-matrix.h"

void CreateMatrixFromFlags_willReturn(rgb_matrix::RGBMatrix *);
bool CreateMatrixFromFlags_wasCalled(void);
int CreateMatrixFromFlags_argc(void);
char **CreateMatrixFromFlags_argv(void);

class MockRGBMatrix : public rgb_matrix::RGBMatrix {
public:
  MockRGBMatrix(rgb_matrix::GPIO *io, int rows = 32, int chained_displays = 1,
                int parallel_displays = 1);

  virtual ~MockRGBMatrix();

  virtual int width() const;
  virtual int height() const;
  virtual void SetPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
  virtual void Clear();
  virtual void Fill(uint8_t red, uint8_t green, uint8_t blue);
};

#endif