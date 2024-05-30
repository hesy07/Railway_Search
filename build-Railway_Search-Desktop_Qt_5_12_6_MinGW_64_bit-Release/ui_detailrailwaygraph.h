/********************************************************************************
** Form generated from reading UI file 'detailrailwaygraph.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILRAILWAYGRAPH_H
#define UI_DETAILRAILWAYGRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DetailRailwayGraph
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QLabel *label;

    void setupUi(QDialog *DetailRailwayGraph)
    {
        if (DetailRailwayGraph->objectName().isEmpty())
            DetailRailwayGraph->setObjectName(QString::fromUtf8("DetailRailwayGraph"));
        DetailRailwayGraph->resize(559, 450);
        DetailRailwayGraph->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(DetailRailwayGraph);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(DetailRailwayGraph);
        widget->setObjectName(QString::fromUtf8("widget"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(8, 0, 541, 421));
        label->setStyleSheet(QString::fromUtf8("\n"
"border-image: url(:/res/railwayDetailGraph.png);"));

        horizontalLayout->addWidget(widget);


        retranslateUi(DetailRailwayGraph);

        QMetaObject::connectSlotsByName(DetailRailwayGraph);
    } // setupUi

    void retranslateUi(QDialog *DetailRailwayGraph)
    {
        DetailRailwayGraph->setWindowTitle(QApplication::translate("DetailRailwayGraph", "Dialog", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DetailRailwayGraph: public Ui_DetailRailwayGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILRAILWAYGRAPH_H
