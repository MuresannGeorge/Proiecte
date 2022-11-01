/********************************************************************************
** Form generated from reading UI file 'ForyoureyesonlyGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORYOUREYESONLYGUI_H
#define UI_FORYOUREYESONLYGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ForyoureyesonlyGUIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ForyoureyesonlyGUIClass)
    {
        if (ForyoureyesonlyGUIClass->objectName().isEmpty())
            ForyoureyesonlyGUIClass->setObjectName(QString::fromUtf8("ForyoureyesonlyGUIClass"));
        ForyoureyesonlyGUIClass->resize(600, 400);
        menuBar = new QMenuBar(ForyoureyesonlyGUIClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        ForyoureyesonlyGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ForyoureyesonlyGUIClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ForyoureyesonlyGUIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ForyoureyesonlyGUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ForyoureyesonlyGUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ForyoureyesonlyGUIClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ForyoureyesonlyGUIClass->setStatusBar(statusBar);

        retranslateUi(ForyoureyesonlyGUIClass);

        QMetaObject::connectSlotsByName(ForyoureyesonlyGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *ForyoureyesonlyGUIClass)
    {
        ForyoureyesonlyGUIClass->setWindowTitle(QCoreApplication::translate("ForyoureyesonlyGUIClass", "ForyoureyesonlyGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ForyoureyesonlyGUIClass: public Ui_ForyoureyesonlyGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORYOUREYESONLYGUI_H
