using namespace std;
#include <iostream>
#include <vector>
#include "matchstick.h"
#include <math.h>
#include <random>
#include <fstream>

vector<Matchstick> readMatchsticksFromFile(string filename) {
  ifstream infile;
  infile.open(filename);
  int numOfMatch;
  infile >> numOfMatch;
  vector<Matchstick> matchsticks;
  for(int i = 0;i<numOfMatch;i++)
  {
    infile >> matchsticks[i];
  }
  return matchsticks;
}

void writeMatchsticksToFile(string filename, vector<Matchstick> matchsticks) {
  ofstream outfile;
  outfile.open(filename);
  outfile << matchsticks.size() << endl;
  for(int i = 0;i<matchsticks.size();i++)
  {
    outfile << matchsticks[i] << endl;
  }
}

vector<Matchstick> randomGeneration(int numOfMatch, int maxColors, int maxSizes) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> colorDist(1, maxColors);
  uniform_int_distribution<> sizeDist(1, maxSizes);
  
  vector<Matchstick> matchsticks;
  for(int i = 0;i<numOfMatch;i++)
  {
    Match_create(matchsticks[i], sizeDist(gen), colorDist(gen));
  }
  return matchsticks;
}

