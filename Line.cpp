#include "Line.h"
Point Point::operator =(const Point& b) {
    x = b.x;
    y = b.y;
    return *this;
}
Line::Line(int n) {
    sz = n;
    if (sz <= 0 || sz > MAX_SIZE) {
        throw std::out_of_range("incorrect size");
    }
    data = new Point[sz]();
}
Line::Line(const Line& v) {
    sz = v.sz;
    data = new Point[sz]();
    for (int i = 0; i < sz; ++i) {
        data[i] = v.data[i];
    }
}
int Line::size() { return sz; }
Point& Line::operator [](int i) {
    if (i >= sz || i < 0) throw std::out_of_range("index out of range");
    //std::cout<<data[i].x;
    return data[i];
}
bool Line::operator==(const Line& v) {
    if (sz != v.sz) return false;
    for (int i = 0; i < sz; ++i) {
        if (std::abs(data[i].x - v.data[i].x) > eps || std::abs(data[i].y - v.data[i].y) > eps) return false;
    }
    return true;
}
bool Line::operator!=(const Line& v) {
    return !(*this == v);
}
Line& Line::operator = (const Line& v) {
    if (this == &v) return *this;
    sz = v.sz;
    delete[]data;
    data = new Point[sz]();
    for (int i = 0; i < sz; ++i) data[i] = v.data[i];
    return *this;
}
Line Line::operator +(const Line& v) {
    if (sz + v.sz > MAX_SIZE) throw std::out_of_range("too large concat result");
    Line tmp(sz + v.sz);
    for (int i = 0; i < sz; ++i) tmp[i] = data[i];
    for (int i = 0; i < v.sz; ++i) {
        tmp[sz + i] = v.data[i];
    }
    return tmp;
}
Line Line::operator +(const Point& p) {
    if (sz == MAX_SIZE) throw std::out_of_range("too large concat result");
    Line tmp(sz + 1);
    for (int i = 0; i < sz; ++i) tmp[i] = data[i];
    tmp[sz] = p;
    return tmp;
}
double Line::len() {
    double ans = 0;
    for (int i = 0; i < sz - 1; ++i) {
        double dx = data[i + 1].x - data[i].x;
        double dy = data[i + 1].y - data[i].y;
        ans += sqrt(dx * dx + dy * dy);
    }
    return ans;
}
std::ostream& operator<<(std::ostream& ostr, const Line& v) {
    for (int i = 0; i < v.sz; i++)
        ostr << v.data[i].x << ' ' << v.data[i].y << "\n";
    return ostr;
}
Line::~Line() {
    delete[]data;
}
Line Point::operator+(Line& v) {
    if (v.size() == MAX_SIZE) throw std::out_of_range("too large concat result");
    Line tmp(v.size() + 1);
    tmp[0] = *this;
    for (int i = 1; i <= v.size(); ++i) tmp[i] = v[i - 1];
    return tmp;
}