#include "Header.h"

void addition(double& firstValue, double& secondValue) {
  std::cout << "Addition result is " << firstValue + secondValue << "\n";
}

void multiple(double& firstValue, double& secondValue) {
  std::cout << "Multiple result is " << firstValue * secondValue << "\n";
}

void divided(double& firstValue, double& secondValue) {
  std::cout << "Divided result is " << firstValue / secondValue << "\n";
}

void power(double& firstValue, double& secondValue) {
  double result{firstValue};
  for (int i{1}; i < secondValue; ++i) {
    result *= firstValue;
  }
  std::cout << "Power result is " << result << "\n";
}

int findFactorial(int value) {
  if (value == 0 || value == 1)
    return 1;
  return value * findFactorial(value - 1);
}

int readInt() {
  while (true) {
    std::string input;
    std::getline(std::cin, input);
    try {
      return std::stoi(input);
    } catch (const std::exception&) {
      std::cout << "Error... Enter an integer number\n";
    }
  }
}

double readDouble() {
  while (true) {
    std::string input;
    std::getline(std::cin, input);
    try {
      return std::stod(input);
    } catch (const std::exception&) {
      std::cout << "Error... Enter a floating-point number\n";
    }
  }
}
