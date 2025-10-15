#include <QCoreApplication>
#include <QDebug>

#include "house.h"

void do_stuff() {
    // Stack memory
    //House h1( nullptr, "First" );
    //h1.print_info();

    // Heap memory
    //House* p_h1 = new House( nullptr, "First" );
    //p_h1->print_info();
    //delete p_h1;

    // Unique ptr
    //std::unique_ptr<House> up_house_1 { new House( nullptr, "Second" ) };
    //up_house_1->print_info();

    // Shared ptr
    std::shared_ptr<House> shrd_ptr_1 { new House( nullptr, "Third" ) };
    shrd_ptr_1->print_info();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.

    qDebug() << "Starting ...";
    do_stuff();
    qDebug() << "Ending ...";

    return a.exec();
}
