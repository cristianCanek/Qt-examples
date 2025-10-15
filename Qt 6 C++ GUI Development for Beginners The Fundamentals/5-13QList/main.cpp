#include <QCoreApplication>
#include <QDebug>

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

    // Declare the list
    QList<QString> stringList;

    // Put data in the list
    stringList << "I am" << "loving" << "Qt"; // [ "I am", "loving", "Qt" ]
    stringList.append( "a" );
    stringList.append( "lot" );

    // Get data from the list
    qDebug() << "The first element is: "  << stringList[ 0 ];
    qDebug() << "The second element is: " << stringList[ 1 ];
    qDebug() << "The third element is: "  << stringList[ 2 ];

    // Get the total number of elements
    qDebug() << "The number of elements in my list is: " << stringList.count();

    // Loop through the elements
    for ( int i = 0; i < stringList.count(); i++ ) {
        qDebug() << "The element at index " << QString::number( i ) << " is: " << stringList.at( i );
    }

    return a.exec();
}
