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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CppXtractLibGUIClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *aboutButtonLayout;
    QPushButton *mAboutCppXtractButton;
    QPushButton *mAboutCppButton;
    QPushButton *mAboutQtButton;
    QWidget *widget;
    QVBoxLayout *selectFileLayout1;
    QPushButton *mSelectFileButton1;
    QLabel *mSelectedFilename1;

    void setupUi(QMainWindow *CppXtractLibGUIClass)
    {
        if (CppXtractLibGUIClass->objectName().isEmpty())
            CppXtractLibGUIClass->setObjectName(QString::fromUtf8("CppXtractLibGUIClass"));
        CppXtractLibGUIClass->resize(917, 580);
        centralWidget = new QWidget(CppXtractLibGUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 450, 791, 25));
        aboutButtonLayout = new QHBoxLayout(layoutWidget);
        aboutButtonLayout->setSpacing(6);
        aboutButtonLayout->setContentsMargins(11, 11, 11, 11);
        aboutButtonLayout->setObjectName(QString::fromUtf8("aboutButtonLayout"));
        aboutButtonLayout->setContentsMargins(0, 0, 0, 0);
        mAboutCppXtractButton = new QPushButton(layoutWidget);
        mAboutCppXtractButton->setObjectName(QString::fromUtf8("mAboutCppXtractButton"));

        aboutButtonLayout->addWidget(mAboutCppXtractButton);

        mAboutCppButton = new QPushButton(layoutWidget);
        mAboutCppButton->setObjectName(QString::fromUtf8("mAboutCppButton"));

        aboutButtonLayout->addWidget(mAboutCppButton);

        mAboutQtButton = new QPushButton(layoutWidget);
        mAboutQtButton->setObjectName(QString::fromUtf8("mAboutQtButton"));

        aboutButtonLayout->addWidget(mAboutQtButton);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 60, 781, 44));
        selectFileLayout1 = new QVBoxLayout(widget);
        selectFileLayout1->setSpacing(6);
        selectFileLayout1->setContentsMargins(11, 11, 11, 11);
        selectFileLayout1->setObjectName(QString::fromUtf8("selectFileLayout1"));
        selectFileLayout1->setContentsMargins(0, 0, 0, 0);
        mSelectFileButton1 = new QPushButton(widget);
        mSelectFileButton1->setObjectName(QString::fromUtf8("mSelectFileButton1"));

        selectFileLayout1->addWidget(mSelectFileButton1);

        mSelectedFilename1 = new QLabel(widget);
        mSelectedFilename1->setObjectName(QString::fromUtf8("mSelectedFilename1"));
        mSelectedFilename1->setAlignment(Qt::AlignCenter);

        selectFileLayout1->addWidget(mSelectedFilename1);

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
        mSelectFileButton1->setText(QApplication::translate("CppXtractLibGUIClass", "S\303\251lectionner un fichier...", nullptr));
        mSelectedFilename1->setText(QApplication::translate("CppXtractLibGUIClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CppXtractLibGUIClass: public Ui_CppXtractLibGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CPPXTRACTLIBGUI_H
