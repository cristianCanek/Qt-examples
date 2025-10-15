#include <iostream>
#include "rectangle.h"
#include "box.h"

int main()
{
    Rectangle r( 10.0, 20.0 );
    std::cout << "Area: " << r.get_area() << std::endl;

    Box b( 10.0, 20.0, 30.0 );
    std::cout << "Volume: " << b.get_volume() << std::endl;

    return 0;
};
