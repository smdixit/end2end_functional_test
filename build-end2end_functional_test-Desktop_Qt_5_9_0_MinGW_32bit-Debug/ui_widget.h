/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLineEdit *RunFor;
    QLCDNumber *MS_Elapsed;
    QPushButton *MS;
    QLabel *label_2;
    QLabel *label;
    QPushButton *test;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(485, 307);
        RunFor = new QLineEdit(Widget);
        RunFor->setObjectName(QStringLiteral("RunFor"));
        RunFor->setGeometry(QRect(160, 200, 81, 20));
        MS_Elapsed = new QLCDNumber(Widget);
        MS_Elapsed->setObjectName(QStringLiteral("MS_Elapsed"));
        MS_Elapsed->setGeometry(QRect(140, 260, 161, 23));
        MS_Elapsed->setStyleSheet(QLatin1String(" color: white; background-color: black;\n"
"font: 85 10pt \"MS Shell Dlg 2\";"));
        MS_Elapsed->setSmallDecimalPoint(true);
        MS_Elapsed->setDigitCount(10);
        MS_Elapsed->setSegmentStyle(QLCDNumber::Outline);
        MS = new QPushButton(Widget);
        MS->setObjectName(QStringLiteral("MS"));
        MS->setGeometry(QRect(14, 200, 131, 23));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 260, 91, 20));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 200, 151, 21));
        test = new QPushButton(Widget);
        test->setObjectName(QStringLiteral("test"));
        test->setGeometry(QRect(60, 40, 75, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        MS->setText(QApplication::translate("Widget", "Run For so many millisec from now", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "Current Time in MS", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "Will be defaulted to1 after run", Q_NULLPTR));
        test->setText(QApplication::translate("Widget", "test", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
