#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QPushButton"
#include <QPainter>
#include <QEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void setCurrentButton();
    void clearBoard();
    void setBoardValue();
    void generateBoard();
    void showPosibleSolution();
protected:
    void keyPressedEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    void addWidget(QPushButton *);

};
#endif // MAINWINDOW_H
