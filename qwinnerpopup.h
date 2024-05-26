#ifndef QWINNERPOPUP_H
#define QWINNERPOPUP_H

#include <QDialog>

namespace Ui {
class QWinnerPopup;
}

class QWinnerPopup : public QDialog
{
    Q_OBJECT

public:
    explicit QWinnerPopup(QWidget *parent = nullptr);
    ~QWinnerPopup();

private slots:
    void on_pushButton_clicked();

private:
    Ui::QWinnerPopup *ui;
};

#endif // QWINNERPOPUP_H
