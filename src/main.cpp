#include <iostream>
#include "spdlog/spdlog.h"

#include "helpers.h"

int main(int, char **)
{
  init_logger();
  spdlog::info("Calculator started!");
  calculate();
  return 0;
}
