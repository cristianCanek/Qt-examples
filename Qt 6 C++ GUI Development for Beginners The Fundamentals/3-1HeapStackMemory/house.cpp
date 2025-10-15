#include "house.h"
#include <QDebug>

House::House( QObject *parent, const QString &descr )
    : QObject( parent ), m_descr( ( descr ) )
{
    qDebug() << "[CONSTRUCTOR] House object constructed!";
}

void House::print_info() const
{
    qDebug() << "Hi! I'm a house object named: " << m_descr;
}

House::~House()
{
    qDebug() << "[DESTRUCTOR] House object: " << m_descr << " is dying! ...";
}
