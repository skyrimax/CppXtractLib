/********************************************************************************
** Form generated from reading UI file 'CppXtractLibGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CPPXTRACTLIBGUI_H
#define UI_CPPXTRACTLIBGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CppXtractLibGUIClass
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *mAboutCppXtractButton;
    QPushButton *mAboutCppButton;
    QPushButton *mAboutQtButton;

    void setupUi(QMainWindow *CppXtractLibGUIClass)
    {
        if (CppXtractLibGUIClass->objectName().isEmpty())
            CppXtractLibGUIClass->setObjectName(QString::fromUtf8("CppXtractLibGUIClass"));
        CppXtractLibGUIClass->resize(917, 580);
        centralWidget = new QWidget(CppXtractLibGUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 450, 791, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        mAboutCppXtractButton = new QPushButton(widget);
        mAboutCppXtractButton->setObjectName(QString::fromUtf8("mAboutCppXtractButton"));

        horizontalLayout->addWidget(mAboutCppXtractButton);

        mAboutCppButton = new QPushButton(widget);
        mAboutCppButton->setObjectName(QString::fromUtf8("mAboutCppButton"));

        horizontalLayout->addWidget(mAboutCppButton);

        mAboutQtButton = new QPushButton(widget);
        mAboutQtButton->setObjectName(QString::fromUtf8("mAboutQtButton"));

        horizontalLayout->addWidget(mAboutQtButton);

        CppXtractLibGUIClass->setCentralWidget(centralWidget);

        retranslateUi(CppXtractLibGUIClass);
        QObject::connect(mAboutCppXtractButton, SIGNAL(clicked()), CppXtractLibGUIClass, SLOT(showAboutCppXtract()));
        QObject::connect(mAboutCppButton, SIGNAL(clicked()), CppXtractLibGUIClass, SLOT(showAboutCpp()));
        QObject::connect(mAboutQtButton, SIGNAL(clicked()), CppXtractLibGUIClass, SLOT(showAboutQt()));

        QMetaObject::connectSlotsByName(CppXtractLibGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *CppXtractLibGUIClass)
    {
        CppXtractLibGUIClass->setWindowTitle(QApplication::translate("CppXtractLibGUIClass", "CppXtractLibGUI", nullptr));
        mAboutCppXtractButton->setText(QApplication::translate("CppXtractLibGUIClass", "\303\200 propos de CppXtractLib...", nullptr));
        mAboutCppButton->setText(QApplication::translate("CppXtractLibGUIClass", "\303\200 propos du langage C++...", nullptr));
        mAboutQtButton->setText(QApplication::translate("CppXtractLibGUIClass", "\303\200 propos de Qt...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CppXtractLibGUIClass: public Ui_CppXtractLibGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CPPXTRACTLIBGUI_H
