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
    else if (ms == tab[pos]) break;
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

void bubbleSort(vector<Matchstick> &tab)
{
  for (int i = 1; i < tab.size();++i)
  {
    if(tab[i] < tab[i-1])
    {
      Matchstick temp = tab[i];
      tab[i] = tab[i-1];
      tab[i-1] = temp;
    }
  }
}
