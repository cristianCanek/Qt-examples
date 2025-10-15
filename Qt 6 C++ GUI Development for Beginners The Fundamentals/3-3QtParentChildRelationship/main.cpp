#include <QCoreApplication>
#include <QDebug>

#include "house.h"

void do_stuff() {
    // Qt Parent Child relationship
    //House* p_parent = new House( nullptr, "Parent" );

    // Can even manage the parent  through smart pointers if necessary
    std::unique_ptr<House> p_parent { new House( nullptr, "Parent" ) };

    House* p_house1 = new House( p_parent.get(), "Child 1" );
    House* p_house2 = new House( p_house1, "Grand child 1" );

    //delete p_parent;
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
