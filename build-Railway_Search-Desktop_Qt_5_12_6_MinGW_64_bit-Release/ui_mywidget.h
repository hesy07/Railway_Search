/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QComboBox *comboBox;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *comboBox_2;
    QPushButton *pushButton;
    QLabel *label_4;
    QLabel *label_beijing;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTextEdit *textEdit;
    QWidget *tab_2;
    QTextEdit *textEdit_2;
    QWidget *tab_3;
    QTextEdit *textEdit_3;
    QWidget *tab_4;
    QTextEdit *textEdit_4;
    QLabel *label_chengdu;
    QLabel *label_xian;
    QLabel *label_zhengzhou;
    QLabel *label_guangzhou;
    QLabel *label_xuzhou;
    QLabel *label_shanghai;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *pushButton_2;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QString::fromUtf8("MyWidget"));
        MyWidget->resize(637, 666);
        MyWidget->setStyleSheet(QString::fromUtf8(""));
        comboBox = new QComboBox(MyWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(124, 260, 78, 29));
        comboBox->setMouseTracking(true);
        comboBox->setStyleSheet(QString::fromUtf8("font: 20pt \"Agency FB\";\n"
"font: 14pt \"\345\271\274\345\234\206\";"));
        label_2 = new QLabel(MyWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(44, 260, 72, 23));
        label_2->setMouseTracking(true);
        label_2->setStyleSheet(QString::fromUtf8("font: 20pt \"Agency FB\";\n"
"font: 14pt \"\345\271\274\345\234\206\";"));
        label_3 = new QLabel(MyWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(44, 330, 72, 25));
        label_3->setMouseTracking(true);
        label_3->setStyleSheet(QString::fromUtf8("font: 20pt \"Agency FB\";\n"
"font: 14pt \"\345\271\274\345\234\206\";"));
        comboBox_2 = new QComboBox(MyWidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(124, 330, 78, 29));
        comboBox_2->setMouseTracking(true);
        comboBox_2->setStyleSheet(QString::fromUtf8("font: 20pt \"Agency FB\";\n"
"\n"
"font: 14pt \"\345\271\274\345\234\206\";"));
        pushButton = new QPushButton(MyWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(202, 330, 41, 31));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setMouseTracking(true);
        pushButton->setStyleSheet(QString::fromUtf8("\n"
"border-image: url(:/res/SearchButton2.png);\n"
"border-image: url(:/res/SearchButton3.png);\n"
"border-image: url(:/res/searchbutton4.png);"));
        label_4 = new QLabel(MyWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(312, 195, 291, 251));
        label_4->setStyleSheet(QString::fromUtf8("\n"
"\n"
"border-image: url(:/res/railway1.png);"));
        label_beijing = new QLabel(MyWidget);
        label_beijing->setObjectName(QString::fromUtf8("label_beijing"));
        label_beijing->setGeometry(QRect(442, 175, 51, 20));
        label_beijing->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\271\274\345\234\206\";"));
        label = new QLabel(MyWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 40, 241, 61));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/res/tietle1.png);"));
        tabWidget = new QTabWidget(MyWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(40, 490, 571, 131));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        tabWidget->setFont(font);
        tabWidget->setCursor(QCursor(Qt::ArrowCursor));
        tabWidget->setMouseTracking(true);
        tabWidget->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\271\274\345\234\206\";\n"
"\n"
"color: rgb(68, 114, 196);\n"
"color: rgb(0, 0, 0);\n"
""));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab->setStyleSheet(QString::fromUtf8(""));
        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 0, 611, 131));
        textEdit->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\271\274\345\234\206\";\n"
"color: rgb(0, 0, 0);\n"
"border-image: url(:/res/background3.png);\n"
"background-image: url(:/res/background3.png);\n"
"font: 9pt \"\345\271\274\345\234\206\";"));
        textEdit->setReadOnly(true);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        textEdit_2 = new QTextEdit(tab_2);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(0, 0, 611, 131));
        textEdit_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\271\274\345\234\206\";\n"
"color: rgb(0, 0, 0);\n"
"border-image: url(:/res/background3.png);\n"
"background-image: url(:/res/background3.png);\n"
"font: 9pt \"\345\271\274\345\234\206\";"));
        textEdit_2->setReadOnly(true);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        textEdit_3 = new QTextEdit(tab_3);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setGeometry(QRect(0, 0, 611, 131));
        textEdit_3->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\271\274\345\234\206\";\n"
"color: rgb(0, 0, 0);\n"
"border-image: url(:/res/background3.png);\n"
"background-image: url(:/res/background3.png);\n"
"font: 9pt \"\345\271\274\345\234\206\";"));
        textEdit_3->setReadOnly(true);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        textEdit_4 = new QTextEdit(tab_4);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));
        textEdit_4->setGeometry(QRect(0, 0, 611, 131));
        textEdit_4->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\271\274\345\234\206\";\n"
"color: rgb(0, 0, 0);\n"
"border-image: url(:/res/background3.png);\n"
"background-image: url(:/res/background3.png);\n"
"font: 9pt \"\345\271\274\345\234\206\";"));
        textEdit_4->setReadOnly(true);
        tabWidget->addTab(tab_4, QString());
        label_chengdu = new QLabel(MyWidget);
        label_chengdu->setObjectName(QString::fromUtf8("label_chengdu"));
        label_chengdu->setGeometry(QRect(282, 405, 31, 20));
        label_chengdu->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\271\274\345\234\206\";"));
        label_xian = new QLabel(MyWidget);
        label_xian->setObjectName(QString::fromUtf8("label_xian"));
        label_xian->setGeometry(QRect(312, 285, 31, 16));
        label_xian->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\271\274\345\234\206\";"));
        label_zhengzhou = new QLabel(MyWidget);
        label_zhengzhou->setObjectName(QString::fromUtf8("label_zhengzhou"));
        label_zhengzhou->setGeometry(QRect(412, 305, 31, 16));
        label_zhengzhou->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\271\274\345\234\206\";"));
        label_guangzhou = new QLabel(MyWidget);
        label_guangzhou->setObjectName(QString::fromUtf8("label_guangzhou"));
        label_guangzhou->setGeometry(QRect(452, 455, 31, 16));
        label_guangzhou->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\271\274\345\234\206\";"));
        label_xuzhou = new QLabel(MyWidget);
        label_xuzhou->setObjectName(QString::fromUtf8("label_xuzhou"));
        label_xuzhou->setGeometry(QRect(552, 255, 31, 16));
        label_xuzhou->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\271\274\345\234\206\";"));
        label_shanghai = new QLabel(MyWidget);
        label_shanghai->setObjectName(QString::fromUtf8("label_shanghai"));
        label_shanghai->setGeometry(QRect(592, 385, 31, 16));
        label_shanghai->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\271\274\345\234\206\";"));
        label_5 = new QLabel(MyWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(45, 448, 251, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\271\274\345\234\206\";"));
        label_7 = new QLabel(MyWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(452, 195, 21, 21));
        label_7->setStyleSheet(QString::fromUtf8("border-image: url(:/res/bluePoint1.png);"));
        label_8 = new QLabel(MyWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(444, 290, 21, 20));
        label_8->setStyleSheet(QString::fromUtf8("border-image: url(:/res/bluePoint1.png);"));
        label_9 = new QLabel(MyWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(349, 284, 21, 21));
        label_9->setStyleSheet(QString::fromUtf8("border-image: url(:/res/bluePoint1.png);"));
        label_10 = new QLabel(MyWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(312, 384, 21, 21));
        label_10->setStyleSheet(QString::fromUtf8("border-image: url(:/res/bluePoint1.png);"));
        label_11 = new QLabel(MyWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(461, 427, 21, 21));
        label_11->setStyleSheet(QString::fromUtf8("border-image: url(:/res/bluePoint1.png);"));
        label_12 = new QLabel(MyWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(583, 366, 21, 21));
        label_12->setStyleSheet(QString::fromUtf8("border-image: url(:/res/bluePoint1.png);"));
        label_13 = new QLabel(MyWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(541, 277, 21, 21));
        label_13->setStyleSheet(QString::fromUtf8("border-image: url(:/res/bluePoint1.png);"));
        pushButton_2 = new QPushButton(MyWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(540, 450, 92, 28));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\271\274\345\234\206\";"));

        retranslateUi(MyWidget);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QApplication::translate("MyWidget", "\351\223\201\350\267\257\346\237\245\350\257\242", nullptr));
        comboBox->setItemText(0, QApplication::translate("MyWidget", "\345\214\227\344\272\254", nullptr));
        comboBox->setItemText(1, QApplication::translate("MyWidget", "\350\245\277\345\256\211", nullptr));
        comboBox->setItemText(2, QApplication::translate("MyWidget", "\351\203\221\345\267\236", nullptr));
        comboBox->setItemText(3, QApplication::translate("MyWidget", "\345\276\220\345\267\236", nullptr));
        comboBox->setItemText(4, QApplication::translate("MyWidget", "\346\210\220\351\203\275", nullptr));
        comboBox->setItemText(5, QApplication::translate("MyWidget", "\345\271\277\345\267\236", nullptr));
        comboBox->setItemText(6, QApplication::translate("MyWidget", "\344\270\212\346\265\267", nullptr));

        label_2->setText(QApplication::translate("MyWidget", "\345\207\272\345\217\221\345\234\260", nullptr));
        label_3->setText(QApplication::translate("MyWidget", "<html><head/><body><p><span style=\" color:#000000;\">\345\210\260\350\276\276\345\234\260</span></p></body></html>", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("MyWidget", "\345\214\227\344\272\254", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("MyWidget", "\350\245\277\345\256\211", nullptr));
        comboBox_2->setItemText(2, QApplication::translate("MyWidget", "\351\203\221\345\267\236", nullptr));
        comboBox_2->setItemText(3, QApplication::translate("MyWidget", "\345\276\220\345\267\236", nullptr));
        comboBox_2->setItemText(4, QApplication::translate("MyWidget", "\346\210\220\351\203\275", nullptr));
        comboBox_2->setItemText(5, QApplication::translate("MyWidget", "\345\271\277\345\267\236", nullptr));
        comboBox_2->setItemText(6, QApplication::translate("MyWidget", "\344\270\212\346\265\267", nullptr));

        pushButton->setText(QString());
        label_4->setText(QString());
        label_beijing->setText(QApplication::translate("MyWidget", "\345\214\227\344\272\254", nullptr));
        label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MyWidget", "\350\267\235\347\246\273\346\234\200\347\237\255", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MyWidget", "\346\227\266\351\227\264\346\234\200\347\237\255", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MyWidget", "\350\264\271\347\224\250\346\234\200\345\260\221", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MyWidget", "\344\270\255\350\275\254\346\234\200\345\260\221", nullptr));
        label_chengdu->setText(QApplication::translate("MyWidget", "\346\210\220\351\203\275", nullptr));
        label_xian->setText(QApplication::translate("MyWidget", "\350\245\277\345\256\211", nullptr));
        label_zhengzhou->setText(QApplication::translate("MyWidget", "\351\203\221\345\267\236", nullptr));
        label_guangzhou->setText(QApplication::translate("MyWidget", "\345\271\277\345\267\236", nullptr));
        label_xuzhou->setText(QApplication::translate("MyWidget", "\345\276\220\345\267\236", nullptr));
        label_shanghai->setText(QApplication::translate("MyWidget", "\344\270\212\346\265\267", nullptr));
        label_5->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        label_9->setText(QString());
        label_10->setText(QString());
        label_11->setText(QString());
        label_12->setText(QString());
        label_13->setText(QString());
        pushButton_2->setText(QApplication::translate("MyWidget", "\346\237\245\347\234\213\350\257\246\345\233\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
