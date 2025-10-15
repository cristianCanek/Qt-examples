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

class Box {
private:
    Rectangle m_r;
    double m_heigth;

public:
    Box( int w, int l, int h ): m_r( w, l ), m_heigth( h ) {
        std::cout << "Para Constructor Called!" << std::endl;
    };

    double get_volume() {
        return m_r.get_area() * m_heigth;
    };

};

int main()
{
    Rectangle r( 10.0, 20.0 );
    std::cout << "Area: " << r.get_area() << std::endl;

    Box b( 10.0, 20.0, 30.0 );
    std::cout << "Volume: " << b.get_volume() << std::endl;

    return 0;
};

// Class: Rectangle -----------------------------------------
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

// Class: Box -----------------------------------------
