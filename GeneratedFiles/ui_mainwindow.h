/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_6;
    QTableWidget *tableWidget;
    QPushButton *pushButton_7;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_8;
    QLabel *label_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(745, 522);
        MainWindow->setContextMenuPolicy(Qt::DefaultContextMenu);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 470, 42, 42));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(715, 0, 30, 30));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(678, 0, 30, 30));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(130, 470, 42, 42));
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_4->setIconSize(QSize(42, 42));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(10, 470, 42, 42));
        pushButton_5->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_5->setIconSize(QSize(42, 42));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(640, 490, 200, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setCursor(QCursor(Qt::PointingHandCursor));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(200, 470, 420, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        label_2->setFont(font1);
        label_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(640, 0, 30, 30));
        pushButton_6->setCursor(QCursor(Qt::PointingHandCursor));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(80, 50, 640, 361));
        tableWidget->setStyleSheet(QStringLiteral(""));
        tableWidget->setDragEnabled(true);
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(70, 470, 42, 42));
        pushButton_7->setCursor(QCursor(Qt::PointingHandCursor));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(640, 470, 180, 16));
        label_3->setFont(font);
        label_3->setCursor(QCursor(Qt::PointingHandCursor));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 420, 741, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setWeight(50);
        label_4->setFont(font2);
        label_4->setContextMenuPolicy(Qt::NoContextMenu);
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(20, 90, 30, 30));
        pushButton_8->setCursor(QCursor(Qt::PointingHandCursor));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(570, 10, 54, 21));
        label_5->setContextMenuPolicy(Qt::NoContextMenu);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\351\237\263\344\271\220\346\222\255\346\224\276\345\231\250", 0));
#ifndef QT_NO_TOOLTIP
        MainWindow->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("MainWindow", "\346\232\202\345\201\234", 0));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\351\200\200\345\207\272</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_2->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\346\234\200\345\260\217\345\214\226</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_3->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_4->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\344\270\213\344\270\200\346\233\262</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_4->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_5->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\344\270\212\344\270\200\346\233\262</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_5->setText(QString());
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("MainWindow", "\345\275\223\345\211\215\346\227\266\351\227\264 / \346\200\273\346\227\266\351\227\264", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("MainWindow", "00:00 / 00:00", 0));
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\346\240\207\351\242\230-\350\211\272\346\234\257\345\256\266</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("MainWindow", "-", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_6->setToolTip(QApplication::translate("MainWindow", "\351\200\211\351\241\271", 0));
#endif // QT_NO_TOOLTIP
        pushButton_6->setText(QString());
#ifndef QT_NO_TOOLTIP
        tableWidget->setToolTip(QApplication::translate("MainWindow", "\346\222\255\346\224\276\345\210\227\350\241\250", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pushButton_7->setToolTip(QApplication::translate("MainWindow", "\346\232\202\345\201\234", 0));
#endif // QT_NO_TOOLTIP
        pushButton_7->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_3->setToolTip(QApplication::translate("MainWindow", "\345\275\223\345\211\215 / \346\255\214\346\233\262\346\200\273\346\225\260", 0));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("MainWindow", "0 / 0", 0));
        label_4->setText(QApplication::translate("MainWindow", "\346\255\214\350\257\215", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_8->setToolTip(QApplication::translate("MainWindow", "\344\272\221\344\270\213\350\275\275", 0));
#endif // QT_NO_TOOLTIP
        pushButton_8->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><a href=\"http://wpa.qq.com/msgrd?v=3&amp;uin=771911064&amp;site=qq&amp;menu=yes\"><span style=\" text-decoration: underline; color:#0000ff;\">\347\202\271\346\210\221\345\217\215\351\246\210</span></a></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
