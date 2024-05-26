/********************************************************************************
** Form generated from reading UI file 'qwinnerpopup.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWINNERPOPUP_H
#define UI_QWINNERPOPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QWinnerPopup
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *QWinnerPopup)
    {
        if (QWinnerPopup->objectName().isEmpty())
            QWinnerPopup->setObjectName("QWinnerPopup");
        QWinnerPopup->resize(219, 174);
        QWinnerPopup->setAutoFillBackground(true);
        verticalLayoutWidget = new QWidget(QWinnerPopup);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(9, 9, 201, 151));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Haettenschweiler")});
        font.setPointSize(22);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);


        retranslateUi(QWinnerPopup);

        QMetaObject::connectSlotsByName(QWinnerPopup);
    } // setupUi

    void retranslateUi(QDialog *QWinnerPopup)
    {
        QWinnerPopup->setWindowTitle(QCoreApplication::translate("QWinnerPopup", "Winner!!!!", nullptr));
        label->setText(QCoreApplication::translate("QWinnerPopup", "You won!!!!", nullptr));
        pushButton->setText(QCoreApplication::translate("QWinnerPopup", "Continue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QWinnerPopup: public Ui_QWinnerPopup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWINNERPOPUP_H
