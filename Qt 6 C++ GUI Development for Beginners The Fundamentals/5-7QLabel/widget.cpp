#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi( this );
    ui->minionTextLabel->move( 100, 30 );

    QPixmap my_image( ":/images/image.png" );
    if ( my_image.isNull() ) {
        qDebug() << "Null";
    }

    ui->imageLabel->move( 0, 70 );
    ui->imageLabel->setPixmap( my_image.scaled( 200, 200 ) );
    ui->imageLabel->show();
}

Widget::~Widget()
{
    delete ui;
}
