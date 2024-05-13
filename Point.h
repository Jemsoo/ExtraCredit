//
// Created by citygirls on 5/12/24.
//

#ifndef POINTCLASS_POINT_H
#define POINTCLASS_POINT_H

#include <string>

class Point {
public:

    // Constructor declaration
    Point(double x = 0.0, double y = 0.0, double z = 0.0);

    void SetX(double x);
    void SetY(double y);
    void SetZ(double z);

    double GetX() const;
    double GetY() const;
    double GetZ() const;

    std::string ToString() const;

private:
    double _x;
    double _y;
    double _z;

};


#endif //POINTCLASS_POINT_H
