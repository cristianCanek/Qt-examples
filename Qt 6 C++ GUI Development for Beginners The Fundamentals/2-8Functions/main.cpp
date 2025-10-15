#include <iostream>

int add( int a, int b ) {
    return a + b;
}

float add( float a, float b ) {
    return a + b;
}

double add( double a, double b ) {
    return a + b;
}

void sayHi() {
    std::cout << "Hello World!" << std::endl;
}

int main()
{
    float a { 3.8f };
    float b { 7.3f };
    float c { 34.0f };

    auto result = add( a, b );
    std::cout << "Result: " << result << std::endl;

    auto result1 = add( a, c );
    std::cout << "Result 1: " << result1 << std::endl;

    sayHi();
    sayHi();

    for( int i = 0; i < 20; ++i ) {
        sayHi();
    }

    return 0;
}
