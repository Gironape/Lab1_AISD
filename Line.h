#include <exception>
#include <stdexcept>
#include <cmath>
#include <iostream>
const int MAX_SIZE = 10000;
class Line;
struct Point {
    double x;
    double y;
    Point() {
        x = 0.0;
        y = 0.0;
    }
    Point operator =(const Point& b);
    Line operator +(Line& v);
};
class Line {
private:
    Point* data;
    int sz;
    static double eps;
public:
    Line(int n = 1);
    Line(const Line& v);
    int size();
    Point& operator [](int i);
    bool operator==(const Line& v);
    bool operator!=(const Line& v);
    Line& operator = (const Line& v);
    Line operator +(const Line& v);
    Line operator +(const Point& p);
    double len();
    friend std::ostream& operator<<(std::ostream& ostr, const Line& v);
    ~Line();
};
