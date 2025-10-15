#ifndef BOX_H
#define BOX_H

#include "rectangle.h"

class Box {
private:
    Rectangle m_r;
    double m_heigth;

public:
    Box( int w, int l, int h );
    double get_volume() const;

};

#endif // BOX_H
