using namespace std;
#include <iostream>
#include <vector>
#include "matchstick.h"
#include "utils.h"
#include "sort.h"

int main(int argc, char **argv)
{
  vector<Matchstick> matchsticks;
  matchsticks = readMatchsticksFromFile(argv[1]);

  insertionSort(matchsticks);
  writeMatchsticksToFile("sorted.txt",matchsticks);
}
