#include "widget.h"
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *button = new QPushButton( this );
    button->setText( "Click me!" );
    button->move( 200, 200 );

    connect( button, &QPushButton::clicked, [=](){
        qDebug() << "You clicked on the button!";

        // 1. Adding a MessageBox (the hard way)
        //QMessageBox message;

        //message.setMinimumSize( 700, 200 );
        //message.setWindowTitle( "setWindowTitle" );
        //message.setText( "setText" );
        //message.setInformativeText("setInformativeText");
        //message.setIcon( QMessageBox::Critical );
        //message.setStandardButtons( QMessageBox::Ok | QMessageBox::Cancel );
        //message.setDefaultButton( QMessageBox::Cancel );

        //int ret = message.exec();

        // 2. Adding a MessageBox using the crtitical message
        //int ret = QMessageBox::critical( this, "setWindowTitle", "setText", QMessageBox::Ok | QMessageBox::Cancel );

        // 3. Adding a MesageBox using the information message
        //int ret = QMessageBox::information( this, "setWindowTitle", "setText", QMessageBox::Ok | QMessageBox::Cancel );

        // 4. Adding a MesageBox using the question message
        int ret = QMessageBox::question( this, "setWindowTitle", "setText", QMessageBox::Ok | QMessageBox::Cancel );

        if( ret == QMessageBox::Ok ) {
            qDebug() << "User clicked the OK option";
        }

        if( ret == QMessageBox::Cancel ) {
            qDebug() << "User clicked the CANCEL option";
        }
    });
}

Widget::~Widget() {}
