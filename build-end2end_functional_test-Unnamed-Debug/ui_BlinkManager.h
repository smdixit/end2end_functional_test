/********************************************************************************
** Form generated from reading UI file 'BlinkManager.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLINKMANAGER_H
#define UI_BLINKMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BlinkManager
{
public:
    QLabel *label;

    void setupUi(QWidget *BlinkManager)
    {
        if (BlinkManager->objectName().isEmpty())
            BlinkManager->setObjectName(QStringLiteral("BlinkManager"));
        BlinkManager->resize(400, 300);
        label = new QLabel(BlinkManager);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 10, 81, 31));

        retranslateUi(BlinkManager);

        QMetaObject::connectSlotsByName(BlinkManager);
    } // setupUi

    void retranslateUi(QWidget *BlinkManager)
    {
        BlinkManager->setWindowTitle(QApplication::translate("BlinkManager", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("BlinkManager", "BlinkManager", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BlinkManager: public Ui_BlinkManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLINKMANAGER_H
