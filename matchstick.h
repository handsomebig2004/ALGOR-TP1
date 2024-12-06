#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#include <string>
#include <vector>
using namespace std;
#include <iostream>

struct Matchstick {
    int size;
    int color;
};

void Match_create(Matchstick Match_name, int size, int color);
//string Match_Showcolor(int color) {

//}

std::istream& operator>>(std::istream& is, Matchstick& ms);
std::ostream& operator<<(std::ostream& os, const Matchstick& ms);

bool operator>(const Matchstick& Match1, const Matchstick& Match2);
bool operator<(const Matchstick& Match1, const Matchstick& Match2);
bool operator==(const Matchstick& Match1, const Matchstick& Match2);

#endif