using namespace std;
#include <vector>
#include "matchstick.h"

bool operator<=(const Matchstick& other) const {
    return !(*this > other);
}

bool operator>=(const Matchstick& other) const {
    return !(*this < other);
}

void shiftRight(vector<Matchstick> &tab, int pos, int end)
{
  for (int i = end; i > pos; --i)
  {
    tab[i] = tab[i - 1];
  }
}
int locate(Matchstick ms, vector<Matchstick> &tab, int end)
{
  for (int i = 0; i < end; ++i)
  {
    if (ms < tab[i])
    {
      return i;
    }
  }
  return end;
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

