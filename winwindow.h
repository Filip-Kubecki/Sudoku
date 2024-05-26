#ifndef WINWINDOW_H
#define WINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>

class WinWindow : public QDialog
{
public:
    WinWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // WINWINDOW_H
