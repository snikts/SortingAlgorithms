#include "sortutils.hpp"
#include <array>
#include <iostream>
#include <random>

int main() {

  std::random_device rd;
  std::default_random_engine engine(rd());
  std::uniform_real_distribution<double> numberGenerator(-1000000, 10000000);
  SourceArray sorted;
  SourceArray random;
  SourceArray organPipe;
  SourceArray reversed;
  SourceArray rotated;
  for (long unsigned int i = 0; i < HOW_MANY_ELEMENTS; ++i) {
    sorted[i] = round(numberGenerator(engine));
    random[i] = round(numberGenerator(engine));
    organPipe[i] = round(numberGenerator(engine));
    reversed[i] = round(numberGenerator(engine));
    rotated[i] = round(numberGenerator(engine));
  }
  std::sort(sorted.begin(), sorted.end());

  std::sort(reversed.begin(), reversed.end());
  std::reverse(reversed.begin(), reversed.end());

  std::sort(rotated.begin(), rotated.end());
  std::rotate(rotated.begin(), rotated.begin() + 1, rotated.end());

  std::sort(organPipe.begin(), organPipe.end());
  organPipeStdArray(organPipe);

  std::cout << "--- Raw Array Performance ---" << std::endl;
  evaluateRawArray(random, sorted, reversed, organPipe, rotated);
  std::cout << "--- std::array Performance ---" << std::endl;
  evaluateStdArray(random, sorted, reversed, organPipe, rotated);
  std::cout << "--- std::vector Performance ---" << std::endl;
  evaluateStdVector(random, sorted, reversed, organPipe, rotated);

  return 0;
}