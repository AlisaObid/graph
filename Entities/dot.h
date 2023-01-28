#include <istream>
template <class T>
struct dot
{

    dot(): x(0), y(0)
    {}

    dot(T x, T y): x(x), y(y)
    {}

    T x;
    T y;

    std::ostream* out(std::ostream& out)
    {
        out << '(' << x << "; " << y << ')';
        return &out;
    }
};
