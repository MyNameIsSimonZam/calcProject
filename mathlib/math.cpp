#include <iostream>
#include "math.h"

namespace math {
double addition(double firstValue, double secondValue) {
  return firstValue + secondValue;
}

double multiple(double firstValue, double secondValue) {
  return firstValue * secondValue;
}

double divided(double firstValue, double secondValue, bool &zeroCheck) {
  if (secondValue == 0) {
    zeroCheck = true;
    return 0;
  }
  zeroCheck = false;
  return firstValue / secondValue;
}

double power(double firstValue, double secondValue) {
  double result{firstValue};
  for (int i{1}; i < secondValue; ++i) {
    result *= firstValue;
  }
  return result;
}

int findFactorial(int value) {
  if (value == 0 || value == 1) return 1;
  return value * findFactorial(value - 1);
}
}  // namespace math