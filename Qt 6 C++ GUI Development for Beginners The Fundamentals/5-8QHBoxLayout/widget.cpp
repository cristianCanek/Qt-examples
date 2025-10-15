#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Setting the HBoxLayout
    QHBoxLayout *layout = new QHBoxLayout( this );

    // Adding the buttons to the layout
    layout->addWidget( ui->oneButton   );
    layout->addWidget( ui->twoButton   );
    layout->addWidget( ui->threeButton );
    layout->addWidget( ui->fourButton  );
    layout->addWidget( ui->fiveButton  );
}

Widget::~Widget()
{
    delete ui;
}
