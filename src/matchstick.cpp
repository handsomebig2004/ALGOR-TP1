#include <string>
#include <vector>
using namespace std;
#include <iostream>
#include "matchstick.h"

void Match_create(Matchstick Match_name, int size, int color) {
    printf("Matchstick created\n");
    Match_name.size = size;
    Match_name.color = color;

}

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