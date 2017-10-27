/********************************************************************************
** Form generated from reading UI file 'common_inputs.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMON_INPUTS_H
#define UI_COMMON_INPUTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Common_Inputs
{
public:
    QWidget *IgnWidget;
    QRadioButton *IGN_ACC;
    QRadioButton *IGN_OFF;
    QRadioButton *IGN_ON;
    QRadioButton *IGN_CRANK;

    void setupUi(QWidget *Common_Inputs)
    {
        if (Common_Inputs->objectName().isEmpty())
            Common_Inputs->setObjectName(QStringLiteral("Common_Inputs"));
        Common_Inputs->resize(400, 300);
        IgnWidget = new QWidget(Common_Inputs);
        IgnWidget->setObjectName(QStringLiteral("IgnWidget"));
        IgnWidget->setGeometry(QRect(10, 40, 151, 111));
        IgnWidget->setAutoFillBackground(true);
        IGN_ACC = new QRadioButton(IgnWidget);
        IGN_ACC->setObjectName(QStringLiteral("IGN_ACC"));
        IGN_ACC->setGeometry(QRect(0, 20, 82, 17));
        IGN_OFF = new QRadioButton(IgnWidget);
        IGN_OFF->setObjectName(QStringLiteral("IGN_OFF"));
        IGN_OFF->setGeometry(QRect(0, 0, 81, 20));
        IGN_ON = new QRadioButton(IgnWidget);
        IGN_ON->setObjectName(QStringLiteral("IGN_ON"));
        IGN_ON->setGeometry(QRect(0, 40, 82, 17));
        IGN_CRANK = new QRadioButton(IgnWidget);
        IGN_CRANK->setObjectName(QStringLiteral("IGN_CRANK"));
        IGN_CRANK->setGeometry(QRect(0, 60, 82, 17));

        retranslateUi(Common_Inputs);

        QMetaObject::connectSlotsByName(Common_Inputs);
    } // setupUi

    void retranslateUi(QWidget *Common_Inputs)
    {
        Common_Inputs->setWindowTitle(QApplication::translate("Common_Inputs", "Form", Q_NULLPTR));
        IGN_ACC->setText(QApplication::translate("Common_Inputs", "IGN_ACC", Q_NULLPTR));
        IGN_OFF->setText(QApplication::translate("Common_Inputs", "IGN_OFF", Q_NULLPTR));
        IGN_ON->setText(QApplication::translate("Common_Inputs", "IGN_ON", Q_NULLPTR));
        IGN_CRANK->setText(QApplication::translate("Common_Inputs", "IGN_CRANK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Common_Inputs: public Ui_Common_Inputs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMON_INPUTS_H
