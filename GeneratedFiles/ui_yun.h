/********************************************************************************
** Form generated from reading UI file 'yun.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YUN_H
#define UI_YUN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog5
{
public:
    QPushButton *pushButton_2;
    QFrame *line_2;
    QLabel *label_16;
    QPushButton *btn_download;
    QPushButton *btn_try;
    QProgressBar *progressBar;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *input_title;
    QLineEdit *input_art;
    QPushButton *btn_search;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *btn_stop;

    void setupUi(QDialog *Dialog5)
    {
        if (Dialog5->objectName().isEmpty())
            Dialog5->setObjectName(QStringLiteral("Dialog5"));
        Dialog5->resize(727, 374);
        Dialog5->setStyleSheet(QStringLiteral(""));
        pushButton_2 = new QPushButton(Dialog5);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(630, 10, 30, 30));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        line_2 = new QFrame(Dialog5);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(20, 40, 691, 21));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_16 = new QLabel(Dialog5);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(60, 20, 511, 21));
        QFont font;
        font.setPointSize(12);
        label_16->setFont(font);
        label_16->setStyleSheet(QStringLiteral(""));
        btn_download = new QPushButton(Dialog5);
        btn_download->setObjectName(QStringLiteral("btn_download"));
        btn_download->setGeometry(QRect(605, 180, 42, 42));
        btn_try = new QPushButton(Dialog5);
        btn_try->setObjectName(QStringLiteral("btn_try"));
        btn_try->setGeometry(QRect(600, 90, 50, 50));
        progressBar = new QProgressBar(Dialog5);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(150, 340, 461, 16));
        progressBar->setValue(0);
        groupBox = new QGroupBox(Dialog5);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(130, 80, 431, 161));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 60, 54, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 110, 54, 20));
        input_title = new QLineEdit(groupBox);
        input_title->setObjectName(QStringLiteral("input_title"));
        input_title->setGeometry(QRect(90, 60, 200, 20));
        input_art = new QLineEdit(groupBox);
        input_art->setObjectName(QStringLiteral("input_art"));
        input_art->setGeometry(QRect(90, 110, 200, 20));
        btn_search = new QPushButton(groupBox);
        btn_search->setObjectName(QStringLiteral("btn_search"));
        btn_search->setGeometry(QRect(330, 50, 80, 80));
        label_3 = new QLabel(Dialog5);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(230, 340, 300, 16));
        label_4 = new QLabel(Dialog5);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(350, 280, 300, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(12);
        label_4->setFont(font1);
        btn_stop = new QPushButton(Dialog5);
        btn_stop->setObjectName(QStringLiteral("btn_stop"));
        btn_stop->setGeometry(QRect(600, 90, 50, 50));
        pushButton_2->raise();
        line_2->raise();
        label_16->raise();
        btn_download->raise();
        progressBar->raise();
        groupBox->raise();
        label_3->raise();
        label_4->raise();
        btn_stop->raise();
        btn_try->raise();

        retranslateUi(Dialog5);

        QMetaObject::connectSlotsByName(Dialog5);
    } // setupUi

    void retranslateUi(QDialog *Dialog5)
    {
        Dialog5->setWindowTitle(QApplication::translate("Dialog5", "Dialog", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("Dialog5", "<html><head/><body><p>\351\200\200\345\207\272</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_2->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_16->setToolTip(QApplication::translate("Dialog5", "\346\226\207\344\273\266\345\261\236\346\200\247", 0));
#endif // QT_NO_TOOLTIP
        label_16->setText(QApplication::translate("Dialog5", "\344\272\221\344\270\213\350\275\275", 0));
#ifndef QT_NO_TOOLTIP
        btn_download->setToolTip(QApplication::translate("Dialog5", "\344\270\213\350\275\275\350\257\245\346\255\214\346\233\262", 0));
#endif // QT_NO_TOOLTIP
        btn_download->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_try->setToolTip(QApplication::translate("Dialog5", "\350\257\225\345\220\254", 0));
#endif // QT_NO_TOOLTIP
        btn_try->setText(QString());
        groupBox->setTitle(QApplication::translate("Dialog5", "\346\217\220\347\244\272:  \344\270\272\344\272\206\346\233\264\347\262\276\347\241\256\346\220\234\347\264\242\350\257\267\345\256\214\346\225\264\350\276\223\345\205\245\346\255\214\346\233\262\345\222\214\350\211\272\346\234\257\345\256\266", 0));
        label->setText(QApplication::translate("Dialog5", "\346\255\214\346\233\262", 0));
        label_2->setText(QApplication::translate("Dialog5", "\350\211\272\346\234\257\345\256\266", 0));
        input_title->setText(QApplication::translate("Dialog5", "\345\260\261\346\230\257\347\210\261\344\275\240", 0));
        input_art->setText(QApplication::translate("Dialog5", "\351\231\266\345\226\206", 0));
#ifndef QT_NO_TOOLTIP
        btn_search->setToolTip(QApplication::translate("Dialog5", "\344\273\216\346\234\215\345\212\241\345\231\250\346\237\245\346\211\276", 0));
#endif // QT_NO_TOOLTIP
        btn_search->setText(QString());
        label_3->setText(QApplication::translate("Dialog5", "\350\277\236\346\216\245\344\270\255", 0));
        label_4->setText(QApplication::translate("Dialog5", "\347\274\223\345\255\230\345\244\261\350\264\245", 0));
#ifndef QT_NO_TOOLTIP
        btn_stop->setToolTip(QApplication::translate("Dialog5", "\345\201\234\346\255\242\350\257\225\345\220\254", 0));
#endif // QT_NO_TOOLTIP
        btn_stop->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog5: public Ui_Dialog5 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YUN_H
