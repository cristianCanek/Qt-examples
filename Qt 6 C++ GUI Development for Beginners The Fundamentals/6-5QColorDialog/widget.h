#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_textColorPushButton_clicked();
    void on_backgroundColorPushButton_clicked();
    void on_fontPushButton_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
