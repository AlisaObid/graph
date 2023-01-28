#include <istream>
struct dot
{

    dot() : x(0), y(0)
    {}

    dot(double x, double y) : x(x), y(y)
    {}

    double x;
    double y;

    std::ostream* out(std::ostream& out)
    {
        out << '(' << x << "; " << y << ')';
        return &out;
    }
};
