#include <iostream>

double add ( double a, double b );

int main()
{
    auto result = add( 10.0, 20.0 );
    std::cout << "Result: " << result << std::endl;
    return 0;
}
