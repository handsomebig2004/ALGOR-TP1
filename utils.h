using namespace std;
#include <iostream>
#include <vector>
#include "matchstick.h"
#include <math.h>
#include <random>
#include <fstream>

vector<Matchstick> readMatchsticksFromFile(string filename);
void writeMatchsticksToFile(string filename, vector<Matchstick> matchsticks);
vector<Matchstick> randomGeneration(int numOfMatch, int maxColors, int maxSizes);