#include <iostream>

class Rectangle {
private:
    double m_width;
    double m_height;

public:
    void set_width( double width );
    void set_height( double height );
    double get_area() const;
};

// Implemmentations

void Rectangle::set_width( double width ) {
    m_width = width;
};

void Rectangle::set_height( double height ) {
    m_height = height;
};

double Rectangle::get_area() const {
    return m_width * m_height;
};

int main()
{
    Rectangle r;
    r.set_width(  10.0 );
    r.set_height( 20.0 );

    std::cout << "Area: " << r.get_area() << std::endl;

    return 0;
}
