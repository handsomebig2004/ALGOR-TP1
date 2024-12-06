using namespace std;
#include <iostream>
#include <vector>
#include "matchstick.h"
#include <math.h>

void shiftRight(vector<Matchstick> &tab, int pos, int end)
{
  for (int i = end; i > pos; --i)
  {
    tab[i] = tab[i - 1];
  }
}
int locate(Matchstick ms, vector<Matchstick> &tab, int end)
{
  int pos = floor(end / 2);
  for (int move = floor(end / 2); move > 0;move = floor(move / 2))
  {
    if (ms < tab[pos])
    {
      pos = pos - move;
    }
    else if (ms > tab[pos])
    {
      pos = pos + move;
    }
    else if (ms == tab[pos]) return pos;
  }
  return pos;
}
void insertionSort(vector<Matchstick> &tab)
{
  for (int i = 1; i < tab.size(); ++i) // Iterate through the vector
  {
    Matchstick ms = tab[i];
    // Store current element
    int pos = locate(ms, tab, i);
    // Find position in sorted portion
    shiftRight(tab, pos, i);
    // Shift elements to the right
    tab[pos] = ms;
    // Insert element at correct position
  }
}

void exchange(vector<Matchstick> &tab,int pos1,int pos2){
  Matchstick temp = tab[pos1];
  tab[pos1] = tab[pos2];
  tab[pos2] = temp;
}

void bubbleSort(vector<Matchstick> &tab)
{
  bool sorted = false;
  while (!sorted)
  {
    sorted = true;
    for (int i = 0; i < tab.size() - 1; ++i)
    {
      if (tab[i] > tab[i + 1])
      {
        exchange(tab, i, i + 1);
        sorted = false;
      }
    }
  }
}

