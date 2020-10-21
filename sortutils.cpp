#include "sortutils.hpp"
#include <array>
#include <chrono>
#include <iostream>
#include <vector>

void initializeRawArrayFromStdArray(
    const std::array<int, HOW_MANY_ELEMENTS> &source, int dest[]) {
  for (long unsigned int i = 0; i < HOW_MANY_ELEMENTS; ++i) {
    dest[i] = source[i];
  }
}

void organPipeStdArray(std::array<int, HOW_MANY_ELEMENTS> &data) {
  for (long unsigned int i = data.size() / 2; i < data.size(); ++i) {
    data[i] = data[data.size() - i - 1];
  }
}

void evaluateRawArray(const SourceArray &random, const SourceArray &sorted,
                      const SourceArray &reversed, const SourceArray &organPipe,
                      const SourceArray &rotated) {
  std::chrono::milliseconds randomTime = std::chrono::milliseconds(0);
  for (int i = 0; i < HOW_MANY_TIMES; ++i) {
    int rawRandom[HOW_MANY_ELEMENTS];
    initializeRawArrayFromStdArray(random, rawRandom);
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(std::begin(rawRandom), std::end(rawRandom));
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    randomTime.operator+=(duration);
  }

  std::cout << "Random Time: " << randomTime.count() << std::endl;

  std::chrono::milliseconds sortedTime = std::chrono::milliseconds(0);
  for (int i = 0; i < HOW_MANY_TIMES; ++i) {
    int rawSorted[HOW_MANY_ELEMENTS];
    initializeRawArrayFromStdArray(sorted, rawSorted);
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(std::begin(rawSorted), std::end(rawSorted));
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    sortedTime.operator+=(duration);
  }

  std::cout << "Sorted Time: " << sortedTime.count() << std::endl;

  std::chrono::milliseconds reversedTime = std::chrono::milliseconds(0);
  for (int i = 0; i < HOW_MANY_TIMES; ++i) {
    int rawReversed[HOW_MANY_ELEMENTS];
    initializeRawArrayFromStdArray(reversed, rawReversed);
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(std::begin(rawReversed), std::end(rawReversed));
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    reversedTime.operator+=(duration);
  }

  std::cout << "Reversed Time: " << reversedTime.count() << std::endl;

  std::chrono::milliseconds organPipeTime = std::chrono::milliseconds(0);
  for (int i = 0; i < HOW_MANY_TIMES; ++i) {
    int rawOrganPipe[HOW_MANY_ELEMENTS];
    initializeRawArrayFromStdArray(organPipe, rawOrganPipe);
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(std::begin(rawOrganPipe), std::end(rawOrganPipe));
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    organPipeTime.operator+=(duration);
  }

  std::cout << "Organ Pipe Time: " << organPipeTime.count() << std::endl;

  std::chrono::milliseconds rotatedTime = std::chrono::milliseconds(0);
  for (int i = 0; i < HOW_MANY_TIMES; ++i) {
    int rawRotated[HOW_MANY_ELEMENTS];
    initializeRawArrayFromStdArray(rotated, rawRotated);
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(std::begin(rawRotated), std::end(rawRotated));
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    rotatedTime.operator+=(duration);
  }

  std::cout << "Rotated Time: " << rotatedTime.count() << std::endl;
}

void evaluateStdArray(const SourceArray &random, const SourceArray &sorted,
                      const SourceArray &reversed, const SourceArray &organPipe,
                      const SourceArray &rotated) {
  std::chrono::milliseconds randomTime = std::chrono::milliseconds(0);
  for (int i = 0; i < HOW_MANY_TIMES; ++i) {
    SourceArray newRandom = random;
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(newRandom.begin(), newRandom.end());
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    randomTime.operator+=(duration);
  }

  std::cout << "Random Time: " << randomTime.count() << std::endl;

  std::chrono::milliseconds sortedTime = std::chrono::milliseconds(0);
  for (int i = 0; i < HOW_MANY_TIMES; ++i) {
    SourceArray newSorted = sorted;
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(newSorted.begin(), newSorted.end());
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    sortedTime.operator+=(duration);
  }

  std::cout << "Sorted Time: " << sortedTime.count() << std::endl;

  std::chrono::milliseconds reversedTime = std::chrono::milliseconds(0);
  for (int i = 0; i < HOW_MANY_TIMES; ++i) {
    SourceArray newReversed = reversed;
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(newReversed.begin(), newReversed.end());
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    reversedTime.operator+=(duration);
  }

  std::cout << "Reversed Time: " << reversedTime.count() << std::endl;

  std::chrono::milliseconds organPipeTime = std::chrono::milliseconds(0);
  for (int i = 0; i < HOW_MANY_TIMES; ++i) {
    SourceArray newOrganPipe = organPipe;
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(newOrganPipe.begin(), newOrganPipe.end());
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    organPipeTime.operator+=(duration);
  }

  std::cout << "Organ Pipe Time: " << organPipeTime.count() << std::endl;

  std::chrono::milliseconds rotatedTime = std::chrono::milliseconds(0);
  for (int i = 0; i < HOW_MANY_TIMES; ++i) {
    SourceArray newRotated = rotated;
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(newRotated.begin(), newRotated.end());
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    rotatedTime.operator+=(duration);
  }

  std::cout << "Rotated Time: " << rotatedTime.count() << std::endl;
}
void evaluateStdVector(const SourceArray &random, const SourceArray &sorted,
                       const SourceArray &reversed,
                       const SourceArray &organPipe,
                       const SourceArray &rotated) {
  std::chrono::milliseconds randomTime = std::chrono::milliseconds(0);
  for (int i = 0; i < HOW_MANY_TIMES; ++i) {
    std::vector<int> newRandom(random.begin(), random.end());
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(newRandom.begin(), newRandom.end());
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    randomTime.operator+=(duration);
  }

  std::cout << "Random Time: " << randomTime.count() << std::endl;

  std::chrono::milliseconds sortedTime = std::chrono::milliseconds(0);
  for (int i = 0; i < HOW_MANY_TIMES; ++i) {
    std::vector<int> newSorted(sorted.begin(), sorted.end());
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(newSorted.begin(), newSorted.end());
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    sortedTime.operator+=(duration);
  }

  std::cout << "Sorted Time: " << sortedTime.count() << std::endl;

  std::chrono::milliseconds reversedTime = std::chrono::milliseconds(0);
  for (int i = 0; i < HOW_MANY_TIMES; ++i) {
    std::vector<int> newReversed(reversed.begin(), reversed.end());
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(newReversed.begin(), newReversed.end());
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    reversedTime.operator+=(duration);
  }

  std::cout << "Reversed Time: " << reversedTime.count() << std::endl;

  std::chrono::milliseconds organPipeTime = std::chrono::milliseconds(0);
  for (int i = 0; i < HOW_MANY_TIMES; ++i) {
    std::vector<int> newOrganPipe(organPipe.begin(), organPipe.end());
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(newOrganPipe.begin(), newOrganPipe.end());
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    organPipeTime.operator+=(duration);
  }

  std::cout << "Organ Pipe Time: " << organPipeTime.count() << std::endl;

  std::chrono::milliseconds rotatedTime = std::chrono::milliseconds(0);
  for (int i = 0; i < HOW_MANY_TIMES; ++i) {
    std::vector<int> newRotated(rotated.begin(), rotated.end());
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(newRotated.begin(), newRotated.end());
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    rotatedTime.operator+=(duration);
  }

  std::cout << "Rotated Time: " << rotatedTime.count() << std::endl;
}
