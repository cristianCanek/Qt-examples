#include "widget.h"
#include "ui_widget.h"

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

void Widget::on_pushButtonListItems_clicked()
{
    // qDebug() << "Count: " << ui->listWidget->count();

    for ( size_t i{}; i < ui->listWidget->count(); i++ ) {
        auto item_ptr = ui->listWidget->item( i );
        QVariant data = item_ptr->data( Qt::DisplayRole );
        qDebug() << data.toString();
    }
}


void Widget::on_pushButtonAddItem_clicked()
{
    ui->listWidget->addItem( "My new item" );
}

