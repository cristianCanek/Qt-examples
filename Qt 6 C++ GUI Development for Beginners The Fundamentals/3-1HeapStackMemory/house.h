#ifndef HOUSE_H
#define HOUSE_H

#include <QObject>

class House : public QObject
{
    Q_OBJECT
private:
    QString m_descr;
public:
    explicit House(QObject *parent = nullptr, const QString &descr = "");
    void print_info() const;
    ~House();
};

#endif // HOUSE_H
