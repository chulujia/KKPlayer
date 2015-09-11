/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog1
{
public:
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QDialog *Dialog1)
    {
        if (Dialog1->objectName().isEmpty())
            Dialog1->setObjectName(QStringLiteral("Dialog1"));
        Dialog1->resize(382, 163);
        pushButton = new QPushButton(Dialog1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(350, 0, 30, 30));
        label_2 = new QLabel(Dialog1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 30, 161, 71));
        label_2->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));
        label_3 = new QLabel(Dialog1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 135, 311, 21));
        label_3->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));
        label_4 = new QLabel(Dialog1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(130, 10, 121, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));
        pushButton_2 = new QPushButton(Dialog1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 50, 42, 42));
        label_5 = new QLabel(Dialog1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, -10, 101, 51));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color: rgb(21, 116, 240);"));
        label_6 = new QLabel(Dialog1);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(310, 100, 51, 31));
        label_6->setFont(font);
        label_6->setContextMenuPolicy(Qt::NoContextMenu);
        label_6->setStyleSheet(QStringLiteral(""));
        label_7 = new QLabel(Dialog1);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 110, 91, 21));
        label_7->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));
        label_8 = new QLabel(Dialog1);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(140, 110, 161, 21));
        label_8->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));

        retranslateUi(Dialog1);

        QMetaObject::connectSlotsByName(Dialog1);
    } // setupUi

    void retranslateUi(QDialog *Dialog1)
    {
        Dialog1->setWindowTitle(QApplication::translate("Dialog1", "about", 0));
        pushButton->setText(QString());
        label_2->setText(QApplication::translate("Dialog1", "<html><head/><body><p>\345\256\214\346\210\220\346\227\245\346\234\237:2015-08-11</p><p>\344\270\200\346\254\276\347\256\200\346\264\201\347\232\204\351\237\263\344\271\220\346\222\255\346\224\276\345\231\250</p></body></html>", 0));
        label_3->setText(QApplication::translate("Dialog1", "<html><head/><body><p><span style=\" font-size:10pt;\">Copyright (C) 2015 HK. All Right reserved.</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("Dialog1", "<html><head/><body><p>KKPlayer 1.0 Beta</p></body></html>", 0));
        pushButton_2->setText(QString());
        label_5->setText(QApplication::translate("Dialog1", "<html><head/><body><p>\345\205\263\344\272\216</p></body></html>", 0));
#ifndef QT_NO_TOOLTIP
        label_6->setToolTip(QApplication::translate("Dialog1", "www.dreamyouxi.com", 0));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("Dialog1", "<html><head/><body><p><a href=\"www.dreamyouxi.com\"><span style=\" text-decoration: underline; color:#0000ff;\">\350\256\277\351\227\256\345\256\230\347\275\221</span></a></p></body></html>", 0));
        label_7->setText(QApplication::translate("Dialog1", "<html><head/><body><p>\350\275\257\344\273\266\345\220\257\345\212\250\346\254\241\346\225\260\344\270\272:</p></body></html>", 0));
        label_8->setText(QApplication::translate("Dialog1", "<html><head/><body><p>times</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog1: public Ui_Dialog1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
