#include "box.h"
#include <iostream>

Box::Box( int w, int l, int h ): m_r( w, l ), m_heigth( h ) {
    std::cout << "Para Constructor Called!" << std::endl;
};

double Box::get_volume() const {
    return m_r.get_area() * m_heigth;
};
