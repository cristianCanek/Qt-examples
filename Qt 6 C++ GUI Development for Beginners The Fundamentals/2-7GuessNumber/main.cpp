#include <iostream>
#include <stdlib.h>
#include <ctime>

int main()
{
    std::srand( std::time( nullptr ) );

    int random_number = std::rand();

    std::cout << "Number: " << random_number << std::endl;
    std::cout << "RAND_MAX: " << RAND_MAX << std::endl;

    // Make sure the number is between 1 and 10.
    int secret_number = random_number % 10 + 1;
    std::cout << "Secret number: " << secret_number << std::endl;

    int guess_number;

    // Ask the user to guess
    std::cout << "Guess my number ( 1 - 10 ): ";

    do {
        std::cin >> guess_number;

        if( secret_number < guess_number ) {
            std::cout << "The number is lower than that" << std::endl;
        }

        if( secret_number > guess_number) {
            std::cout << "The number is higher than that" << std::endl;
        }
    } while ( guess_number != secret_number );

    std::cout << "Congratulations! The number is: " << guess_number << std::endl;

    return 0;
}
