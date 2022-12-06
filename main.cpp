#include "Line.h"
double const PI = 3.14159265359;
double Line::eps = 0.0001;
void get_trinagle() {
    double alp, a;
    std::cout << "angle alpha in degrees = "; std::cin >> alp;
    while (alp <= 0 || alp >= 180) {
        std::cout << "Incorrect angle\n";
        std::cout << "angle alpha in degrees = "; std::cin >> alp;
    }
    std::cout << "lengh of side = "; std::cin >> a;
    while (a < 1e-5) {
        std::cout << "incorrect lenght\n";
        std::cout << "angle alpha in degrees = "; std::cin >> alp;
    }
    Line ans(4);
    ans[1].x = a * sin(alp / 2 * PI / 180.0);
    ans[1].y = a * cos(alp / 2 * PI / 180.0);
    ans[2].y = 0;
    ans[2].x = a;
    std::cout << ans;
}
void point(Line& res);
void set_tmp(Line& res) {
    int n;
    std::cout << "num of elems = "; std::cin >> n;
    res = Line(n);
    for (int i = 0; i < res.size(); ++i) point(res);
}
void point(Line& res) {
    int id;
    std::cout << "num of point = "; std::cin >> id;
    std::cout << res[id].x << " " << res[id].y << "\n";
    int cmd;
    std::cout << "do you want to change? (1/0) "; std::cin >> cmd;
    if (cmd) {
        double x, y;
        std::cout << "x = "; std::cin >> x;
        std::cout << "y = "; std::cin >> y;
        res[id].x = x;
        res[id].y = y;
    }
}
void concat1(Line& a, Line& b) {
    set_tmp(b);
    Line tmp = a + b;
    std::cout << tmp;
}
void concat2(Line& a, Point b) {
    double x, y;
    std::cout << "x = "; std::cin >> x;
    std::cout << "y = "; std::cin >> y;
    b.x = x;
    b.y = y;
    Line tmp = a + b;
    std::cout << tmp;
}
void concat3(Point b, Line& a) {
    double x, y;
    std::cout << "x = "; std::cin >> x;
    std::cout << "y = "; std::cin >> y;
    b.x = x;
    b.y = y;
    Line tmp = b + a;
    std::cout << tmp;
}
void len(Line& a) {
    std::cout << a.len() << "\n";
}
int main() {
    Line tmp1(1);
    Point tmp2;
    Line tmp3;
    int cmd;
    while (true) {
        std::cout << "1 set the line\n2 set/get point in line\n3 concat with other line\n4 concat with point (end)\n5 concat with point (begin)\n6 get lenght of line\n7 get trinagle\n8 print the line\n9 exit\n";
        std::cin >> cmd;
        switch (cmd)
        {
        case 1: 
            system("cls");
            set_tmp(tmp1);
            break;
        case 2:
            system("cls");
            point(tmp1);
            break;
        case 3:
            system("cls");
            concat1(tmp1, tmp3);
            break;
        case 4:
            system("cls");
            concat2(tmp1, tmp2);
            break;
        case 5:
            system("cls");
            concat3(tmp2, tmp1);
            break;
        case 6:
            system("cls");
            len(tmp1);
            break;
        case 7:
            system("cls");
            get_trinagle();
            break;
        case 8:
            system("cls");
            std::cout << tmp1;
            break;
        case 9:
            break;
        }
        
    }
    
}