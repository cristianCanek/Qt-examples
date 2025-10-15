#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

class Rectangle {
private:
    double m_width;
    double m_length;

public:
    Rectangle();
    Rectangle( double w, double l);

    void setWidth( double width );
    void setLength( double length );
    double get_area() const;
};

#endif // RECTANGLE_H
