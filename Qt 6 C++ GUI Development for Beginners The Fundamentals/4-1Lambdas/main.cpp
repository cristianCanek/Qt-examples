#include <iostream>

int main()
{
    // Lambda functions
    // [capture list](parameter list) -> return_value_type { function body }

    // 1. Give lambda function a name and call it
    //auto func = [](){
    //std::cout << "Hello world!" << std::endl;
    //};

    //func();
    //func();
    //func();

    // 2. Call lambda function directly after definition
    //[](){
        //std::cout << "Hello world!" << std::endl;
    //}();

    // 3. Define lambda function that takes parameters
    //[]( int a, int b ){
        //std::cout << "a + b = " << a + b << std::endl;
    //}( 7, 3 );

    // 4. Store lambda variable
    //auto func = []( int a, int b ){
        //std::cout << "a + b = " << a + b << std::endl;
    //};

    //func( 7, 3 );

    // 5.Define a lambda that returns something
    //auto func = []( int a, int b )->int{
        //return a + b;
    //};

    //auto value = func( 7, 3 );

    //std::cout << "The sum is: " << value << std::endl;

    // 6. Return something within a cout statement

    //std::cout << "The sum is: " << []( int a, int b )->int{
        //return a + b;
    //}( 7, 3 ) << std::endl;

    // 7. Capture list
    //int a = 7;
    //int b = 3;

    //[ a, b ](){
        //std::cout << "a + b = " << a + b << std::endl;
    //}();

    // 8. Capturing by value
    //int c = 42;

    //auto func = [ c ](){
        // c is a copy
        //std::cout << "The inner value of c is: " << c << std::endl;
    //};

    //for( int i = 1; i < 5; i++ ) {
        //std::cout << "The outer value of c is: " << c << std::endl;
        //func();
        //c++;
    //}

    // 9. Capturing by reference
    //int c = 42;

    //auto func = [ &c ](){
        // c is a copy
        //std::cout << "The inner value of c is: " << c << std::endl;
    //};

    //for( int i = 1; i < 5; i++ ) {
        //::cout << "The outer value of c is: " << c << std::endl;
        //func();
        //c++;
    //}

    // 10. Capturing everything by value
    //int c = 42;
    //int d = 6;

    //auto func = [ = ](){
        // c and d are copies
        //std::cout << "The inner value of c is: " << c << std::endl;
        //std::cout << "The inner value of d is: " << d << std::endl;
    //};

    //for( int i = 1; i < 5; i++ ) {
        //std::cout << "The outer value of c is: " << c << std::endl;
        //func();
        //c++;
    //}

    // 11. Capturing everything by reference
    int c = 42;
    int d = 6;

    auto func = [ & ](){
        // c and d are copies
        std::cout << "The inner value of c is: " << c << std::endl;
        std::cout << "The inner value of d is: " << d << std::endl;
    };

    for( int i = 1; i < 5; i++ ) {
        std::cout << "The outer value of c is: " << c << std::endl;
        func();
        c++;
    }

    return 0;
}
