#include <iostream>

int main()
{
    int a = 20;
    int b = 20;

    // Math Operators
    std::cout << "---------- Math Operators ----------" << std::endl;

    std::cout << "a + b = " << a + b         << std::endl;
    std::cout << "a - b = " << a - b         << std::endl;
    std::cout << "a * b = " << a * b         << std::endl;
    std::cout << "a / b = " << (float) a / b << std::endl;
    std::cout << "a % b = " << a % b         << std::endl;

    std::cout << std::endl << std::endl;

    // Logical Operators
    std::cout << "---------- Logical Operators ----------" << std::endl;

    // Decisions
    if ( a == b ) {
        std::cout << "A is equal to b" << std::endl;
    }
    else {
        std::cout << "A is not equal to b" << std::endl;
    }

    std::cout << std::endl << std::endl;

    // Loops
    std::cout << "---------- Loops ----------" << std::endl;
    std::cout << "Hello 1" << std::endl;
    std::cout << "Hello 2" << std::endl;
    std::cout << "Hello 3" << std::endl;
    std::cout << "Hello 4" << std::endl;
    std::cout << "Hello 5" << std::endl;
    std::cout << "Hello 6" << std::endl;
    std::cout << "Hello 7" << std::endl;
    std::cout << "Hello 8" << std::endl;
    std::cout << "Hello 9" << std::endl;
    std::cout << "Hello 10" << std::endl;

    std::cout << std::endl << std::endl;

    // For Loop
    std::cout << "---------- For Loop ----------" << std::endl;
    for( int i = 1; i <= 10; i = i + 1 ) {
        std::cout << "Hello " << i << std::endl;
    }

    std::cout << std::endl << std::endl;

    // While Loop
    std::cout << "---------- While Loop ----------" << std::endl;

    int i = 1;

    while( i <= 10 ) {
        std::cout << "Hello " << i << std::endl;
        i = i + 1;
    }

    std::cout << std::endl << std::endl;

    // Do-While Loop
    std::cout << "---------- Do-While Loop ----------" << std::endl;

    int j = 1;

    do {
        std::cout << "Hello " << j << std::endl;
        j = j + 1;
    } while( j <= 10 );

    std::cout << std::endl << std::endl;

    return 0;
}
