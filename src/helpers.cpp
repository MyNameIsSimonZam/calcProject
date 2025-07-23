#include <iostream>

#include "helpers.h"
#include "math.h"
#include "spdlog/spdlog.h"
#include <spdlog/sinks/basic_file_sink.h>

void init_logger()
{
  try
  {
    auto file_logger = spdlog::basic_logger_mt("file_logger", "logs/calc-log.txt");
    spdlog::set_default_logger(file_logger);
  }
  catch (const spdlog::spdlog_ex &ex)
  {
    std::cerr << "Log init failed: " << ex.what() << std::endl;
  }
}

int readInt()
{
  while (true)
  {
    std::string input;
    std::getline(std::cin, input);
    try
    {
      return std::stoi(input);
    }
    catch (const std::exception &)
    {
      spdlog::error("Enter an integer number {}", 0);
    }
  }
}

double readDouble()
{
  while (true)
  {
    std::string input;
    std::getline(std::cin, input);
    try
    {
      return std::stod(input);
    }
    catch (const std::exception &)
    {
      spdlog::error("Error... Enter a floating-point number {}", 0);
    }
  }
}

void calculate()
{
  std::cout << "This is a console calculator\nValid command: \"addition\" / "
               "\"multiple\" / \"divided\" / \"power\" / \"factorial\"\nEnter ";
  std::string baseCommand;
  do
  {
    std::cout << "Enter a command: ";
    std::cin >> baseCommand;
    std::cin.ignore();
    if (baseCommand == "addition" || baseCommand == "multiple" ||
        baseCommand == "divided" || baseCommand == "power")
    {
      std::cout << "Enter first value: ";
      double firstValue{readDouble()};
      std::cout << "Enter second value: ";
      double secondValue{readDouble()};
      if (baseCommand == "addition")
      {
        std::cout << math::addition(firstValue, secondValue) << "\n";
      }
      else if (baseCommand == "multiple")
      {
        std::cout << math::multiple(firstValue, secondValue) << "\n";
      }
      else if (baseCommand == "divided")
      {
        bool ziroCheck{};
        double result{math::divided(firstValue, secondValue, ziroCheck)};
        if (ziroCheck)
        {
          spdlog::error("don't divide by zero {}", 0);
          continue;
        }
        std::cout << result << "\n";
      }
      else if (baseCommand == "power")
      {
        std::cout << math::power(firstValue, secondValue) << "\n";
      }
    }
    else if (baseCommand == "factorial")
    {
      std::cout << "Enter a value: ";
      int firstValue{readInt()};
      if (firstValue < 0)
      {
        spdlog::error("isn't be less then zero {}", 1);
        continue;
      }
      std::cout << math::findFactorial(firstValue) << "\n";
    }
    else
      spdlog::warn("Unknown command...");
  } while (baseCommand != "q");
}