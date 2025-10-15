#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 2. Set the stylesheet to the entire application
    //a.setStyleSheet( "QPushButton { background-color : yellow; color : red; }" );

    Widget w;
    w.show();
    return a.exec();
}
