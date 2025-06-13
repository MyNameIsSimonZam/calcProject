#include "Header.h"

int main(int, char**) {
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
        addition(firstValue, secondValue);
      } else if (baseCommand == "multiple") {
        multiple(firstValue, secondValue);
      } else if (baseCommand == "divided") {
        divided(firstValue, secondValue);
      } else if (baseCommand == "power") {
        power(firstValue, secondValue);
      }
    } else if (baseCommand == "factorial") {
      std::cout << "Enter a value: ";
      int firstValue{readInt()};
      std::cout << findFactorial(firstValue) << "\n";
    } else
      std::cout << "Unknown command...\n";
  } while (baseCommand != "q");
  return 0;
}
