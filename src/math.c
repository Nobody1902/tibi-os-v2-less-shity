#include "math.h"

float log(float x) {
  if(x <= 0) {
    return -1;
  }
  float ln_x = 0.0f;
  // Using the series expansion for ln((1 + u)/(1 - u))
  float term = (x - 1) / (x + 1);
  float term_squared = term * term;
  // Taylor series expansion
  for (int n = 1; n < 100000; n += 2) {
    ln_x += (1.0f / n) * term;
    term *= term_squared;
  }

  return 2 * ln_x;
}

float log10(float x) {
  if(x <= 0) {
    return -1;
  }
  return log(x) / log(10);
}
