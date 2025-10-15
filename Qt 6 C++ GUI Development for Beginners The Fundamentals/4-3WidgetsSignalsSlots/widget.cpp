#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // String notation
    //connect( ui->horizontalSlider, SIGNAL( valueChanged( int ) ), ui->progressBar, SLOT( setValue( int ) ) );
    //connect( ui->horizontalSlider, SIGNAL( valueChanged( int ) ), this,            SLOT( respond( int ) ) );

    // Functor notation: Regular slots
    //connect( ui->horizontalSlider, &QSlider::valueChanged, ui->progressBar, &QProgressBar::setValue );
    //connect( ui->horizontalSlider, &QSlider::valueChanged, this,            &Widget::respond );

    // Functor notation: lambda
    connect( ui->horizontalSlider, &QSlider::valueChanged,
            [=](){
                ui->progressBar->setValue( ui->horizontalSlider->value());
                respond( ui->horizontalSlider->value() );
            }
    );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::respond( int value ) {
    qDebug() << "The value is: " << value;
}
