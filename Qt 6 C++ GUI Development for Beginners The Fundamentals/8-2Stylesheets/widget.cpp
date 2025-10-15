#include "widget.h"
#include "ui_widget.h"

#include "somedialog.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 1. Set the stylesheet to a leaf independent component
    //ui->pushButton->setStyleSheet( "QPushButton { background-color : yellow; color : red; }" );

    // 4. Setting the stylesheet directly to a single component
    ui->pushButton->setStyleSheet( "background-color : yellow; color : red;" );

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    SomeDialog *dialog = new SomeDialog( this );

    // 3. Set the stylesheet to the parent widget
    //dialog->setStyleSheet( "QPushButton { background-color : yellow; color : red; }" );

    dialog->exec();
}

