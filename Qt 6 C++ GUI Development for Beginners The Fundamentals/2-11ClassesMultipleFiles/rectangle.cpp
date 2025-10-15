#include "rectangle.h"

Rectangle::Rectangle() {
    std::cout << "No param constructor called!" << std::endl;
};

Rectangle::Rectangle( double w, double l) {
    std::cout << "Two param constructor called!" << std::endl;

    m_width = w;
    m_length = l;
};

void Rectangle::setWidth( double width ) {
    m_width = width;
};

void Rectangle::setLength( double length ) {
    m_length = length;
};

double Rectangle::get_area() const{
    return m_width * m_length;
};
