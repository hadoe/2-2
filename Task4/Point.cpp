#include "Point.h"
#include <sstream>

point::point(int x, int y, const std::string& s) : x(x), y(y), s(s) {}

bool point::operator<(const point& other) const
{
    return x < other.x || (x == other.x && y < other.y);
}

bool point::operator>(const point& other) const
{
    return other < *this;
}

std::istream& operator>>(std::istream& is, point& p)
{
    is >> p.x >> p.y >> p.s;
    return is;
}

std::ostream& operator<<(std::ostream& os, const point& p)
{
    os << p.x << " " << p.y << " " << p.s;
    return os;
}

point::operator std::string() const
{
    std::ostringstream oss;
    oss << x << " " << y << " " << s;
    return oss.str();
}

bool point::is_positive() const
{
    return x > 0 && y > 0;
}
