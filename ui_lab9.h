/********************************************************************************
** Form generated from reading UI file 'lab9.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB9_H
#define UI_LAB9_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lab9Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *lab9Class)
    {
        if (lab9Class->objectName().isEmpty())
            lab9Class->setObjectName(QString::fromUtf8("lab9Class"));
        lab9Class->resize(600, 400);
        menuBar = new QMenuBar(lab9Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        lab9Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(lab9Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        lab9Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(lab9Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lab9Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(lab9Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        lab9Class->setStatusBar(statusBar);

        retranslateUi(lab9Class);

        QMetaObject::connectSlotsByName(lab9Class);
    } // setupUi

    void retranslateUi(QMainWindow *lab9Class)
    {
        lab9Class->setWindowTitle(QApplication::translate("lab9Class", "lab9", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lab9Class: public Ui_lab9Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB9_H
