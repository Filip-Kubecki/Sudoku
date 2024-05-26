#include "qwinnerpopup.h"
#include "ui_qwinnerpopup.h"

QWinnerPopup::QWinnerPopup(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QWinnerPopup){
    ui->setupUi(this);
}

QWinnerPopup::~QWinnerPopup(){
    delete ui;
}

void QWinnerPopup::on_pushButton_clicked(){
    this -> close();
}

