#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>

namespace Ui {
class InfoDialog;
}

class InfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialog(QWidget *parent = nullptr);
    ~InfoDialog();

    const QString &getPosition() const;
    const QString &getFavoriteOS() const;

private slots:
    void on_okPushButton_clicked();

    void on_cancelPushButton_clicked();

private:
    QString m_position;
    QString m_favorite_os;
    Ui::InfoDialog *ui;
};

#endif // INFODIALOG_H
