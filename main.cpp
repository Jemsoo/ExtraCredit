#include <iostream>
#include <math.h>
#include "Point.h"
using std::cout;
using std::endl;
double Distance(const Point& p1, const Point& p2) {
    double dx = p1.GetX() - p2.GetX();
    double dy = p1.GetY() - p2.GetY();
    double dz = p1.GetZ() - p2.GetZ();
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

int main() {
    Point p1(1, 2, 3);
    Point p2(4, 5, 6);
    Point p3;

    p3.SetY(7);
    p3.SetY(8);
    p3.SetY(9);

    std::cout << p3.ToString() << std::endl;
    std::cout << p3.GetX() << std::endl;
    std::cout << p3.GetY() << std::endl;
    std::cout << p3.GetZ() << std::endl;
    std::cout << Distance(p1, p2) << std::endl;

    return 0;
}
