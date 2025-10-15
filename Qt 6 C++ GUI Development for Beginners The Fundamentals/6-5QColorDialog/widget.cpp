#include "widget.h"
#include "ui_widget.h"

#include <QColorDialog>
#include <QDebug>
#include <QFontDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setAutoFillBackground( true );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_textColorPushButton_clicked()
{
    QPalette palette = ui->label->palette();
    QColor color = palette.color( QPalette::WindowText );
    QColor chosenColor = QColorDialog::getColor( color, this, QString() );

    if ( chosenColor.isValid() ) {
        palette.setColor( QPalette::WindowText, chosenColor );
        ui->label->setPalette( palette );

        qDebug() << "User choose a valid color!";
    }
    else {
        qDebug() << "User choose an invalid color!";
    }
}


void Widget::on_backgroundColorPushButton_clicked()
{
    QPalette palette = ui->label->palette();
    QColor color = palette.color( QPalette::Window );
    QColor chosenColor = QColorDialog::getColor( color, this, QString() );

    if ( chosenColor.isValid() ) {
        palette.setColor( QPalette::Window, chosenColor );
        ui->label->setPalette( palette );

        qDebug() << "User choose a valid color!";
    }
    else {
        qDebug() << "User choose an invalid color!";
    }
}


void Widget::on_fontPushButton_clicked()
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

