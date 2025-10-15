#include "widget.h"
#include "ui_widget.h"

#include <QInputDialog>
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
    // 1. QDoubleSpinBox mode
    //bool ok;
    //double d = QInputDialog::getDouble( this, "QInputDialog::getDouble()", "Amount:", 37.56, -10000, 10000, 2, &ok );

    //if ( ok ) {
        //qDebug() << "Your double value is: " << QString::number( d );
    //}

    // 2. QComboBox mode
    bool ok;
    QStringList items;

    items << "Spring" << "Summer" << "Fall" << "Winter";

    QString item = QInputDialog::getItem( this, "QInputDialog::getItem", "Season:", items, 0, false, &ok );

    if ( ok && !item.isEmpty() ) {
        qDebug() << "Your chosen item is: " << item;
    }
}

