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

void Match_create(Matchstick Match_name, int size, int color) {
    Match_name.size = size;
    Match_name.color = color;
}
//string Match_Showcolor(int color) {

//}

std::istream& operator>>(std::istream& is, Matchstick& ms)
{   
    int color = {};
    int size = {};
    is >> size >> color;
    if (is) {
        Match_create(ms, size, color);
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Matchstick& ms)
{
    os << ms.size << ' ' << ms.color;
    return os;
}

bool operator>(const Matchstick& Match1, const Matchstick& Match2) {
    return (Match1.size > Match2.size);
}

bool operator<(const Matchstick& Match1, const Matchstick& Match2) {
    return (Match1.size < Match2.size);
}

bool operator==(const Matchstick& Match1, const Matchstick& Match2) {
    return (Match1.size == Match2.size);
}
#endif