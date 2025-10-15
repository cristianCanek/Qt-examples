#include "widget.h"
#include "ui_widget.h"

#include <QFontDialog>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    // Get a Font selected by the user
    bool ok;
    QFont font = QFontDialog::getFont( &ok, QFont( "Helvetica [Cronyx]", 10 ), this );

    if ( ok ) {
        ui->label->setFont( font );
    }
    else {
        qDebug() << "User didn't choose any font!";
    }
}

