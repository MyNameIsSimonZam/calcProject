#include <iostream>

#include "helpers.h"
#include "math.h"

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

void calculate() {
  std::cout << "This is a console calculator\nValid command: \"addition\" / "
               "\"multiple\" / \"divided\" / \"power\" / \"factorial\"\nEnter ";
  std::string baseCommand;
  do {
    std::cout << "Enter a command: ";
    std::cin >> baseCommand;
    std::cin.ignore();
    if (baseCommand == "addition" || baseCommand == "multiple" ||
        baseCommand == "divided" || baseCommand == "power") {
      std::cout << "Enter first value: ";
      double firstValue{readDouble()};
      std::cout << "Enter second value: ";
      double secondValue{readDouble()};
      if (baseCommand == "addition") {
        std::cout << math::addition(firstValue, secondValue) << "\n";
      } else if (baseCommand == "multiple") {
        std::cout << math::multiple(firstValue, secondValue) << "\n";
      } else if (baseCommand == "divided") {
        bool ziroCheck{};
        double result{math::divided(firstValue, secondValue, ziroCheck)};
        if (ziroCheck) {
          std::cout << "don't divide by zero\n";
          continue;
        }
        std::cout << result << "\n";
      } else if (baseCommand == "power") {
        std::cout << math::power(firstValue, secondValue) << "\n";
      }
    } else if (baseCommand == "factorial") {
      std::cout << "Enter a value: ";
      int firstValue{readInt()};
      if (firstValue < 0) {
        std::cout << "isn't be less then zero" << "\n";
        continue;
      }
      std::cout << math::findFactorial(firstValue) << "\n";
    } else
      std::cout << "Unknown command...\n";
  } while (baseCommand != "q");
}