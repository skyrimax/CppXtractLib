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
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QWidget *layoutWidget1;
    QVBoxLayout *selectFileLayout1;
    QPushButton *mSelectFileButton1;
    QLabel *mSelectedFilename1;
    QGroupBox *mOutputGroupBox;
    QRadioButton *mOutputScreenRadioButton;
    QRadioButton *mOutputClipboardRadioButton;
    QRadioButton *mOutputFileRadioButton;
    QWidget *layoutWidget_2;
    QVBoxLayout *selectFileLayout2;
    QPushButton *mSelectFileButton2;
    QLabel *mSelectedFilename2;
    QCheckBox *mIncludeStatInfoCheckBox;
    QPushButton *mProcessButton;
    QButtonGroup *mButtonGroup;

    void setupUi(QMainWindow *CppXtractLibGUIClass)
    {
        if (CppXtractLibGUIClass->objectName().isEmpty())
            CppXtractLibGUIClass->setObjectName(QString::fromUtf8("CppXtractLibGUIClass"));
        CppXtractLibGUIClass->resize(917, 580);
        centralWidget = new QWidget(CppXtractLibGUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 450, 801, 25));
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

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(40, 60, 801, 44));
        selectFileLayout1 = new QVBoxLayout(layoutWidget1);
        selectFileLayout1->setSpacing(6);
        selectFileLayout1->setContentsMargins(11, 11, 11, 11);
        selectFileLayout1->setObjectName(QString::fromUtf8("selectFileLayout1"));
        selectFileLayout1->setContentsMargins(0, 0, 0, 0);
        mSelectFileButton1 = new QPushButton(layoutWidget1);
        mSelectFileButton1->setObjectName(QString::fromUtf8("mSelectFileButton1"));

        selectFileLayout1->addWidget(mSelectFileButton1);

        mSelectedFilename1 = new QLabel(layoutWidget1);
        mSelectedFilename1->setObjectName(QString::fromUtf8("mSelectedFilename1"));
        mSelectedFilename1->setAlignment(Qt::AlignCenter);

        selectFileLayout1->addWidget(mSelectedFilename1);

        mOutputGroupBox = new QGroupBox(centralWidget);
        mOutputGroupBox->setObjectName(QString::fromUtf8("mOutputGroupBox"));
        mOutputGroupBox->setGeometry(QRect(40, 140, 801, 181));
        mOutputScreenRadioButton = new QRadioButton(mOutputGroupBox);
        mButtonGroup = new QButtonGroup(CppXtractLibGUIClass);
        mButtonGroup->setObjectName(QString::fromUtf8("mButtonGroup"));
        mButtonGroup->addButton(mOutputScreenRadioButton);
        mOutputScreenRadioButton->setObjectName(QString::fromUtf8("mOutputScreenRadioButton"));
        mOutputScreenRadioButton->setGeometry(QRect(10, 30, 191, 17));
        mOutputClipboardRadioButton = new QRadioButton(mOutputGroupBox);
        mButtonGroup->addButton(mOutputClipboardRadioButton);
        mOutputClipboardRadioButton->setObjectName(QString::fromUtf8("mOutputClipboardRadioButton"));
        mOutputClipboardRadioButton->setGeometry(QRect(10, 50, 191, 17));
        mOutputFileRadioButton = new QRadioButton(mOutputGroupBox);
        mButtonGroup->addButton(mOutputFileRadioButton);
        mOutputFileRadioButton->setObjectName(QString::fromUtf8("mOutputFileRadioButton"));
        mOutputFileRadioButton->setGeometry(QRect(10, 70, 191, 17));
        layoutWidget_2 = new QWidget(mOutputGroupBox);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 100, 761, 44));
        selectFileLayout2 = new QVBoxLayout(layoutWidget_2);
        selectFileLayout2->setSpacing(6);
        selectFileLayout2->setContentsMargins(11, 11, 11, 11);
        selectFileLayout2->setObjectName(QString::fromUtf8("selectFileLayout2"));
        selectFileLayout2->setContentsMargins(0, 0, 0, 0);
        mSelectFileButton2 = new QPushButton(layoutWidget_2);
        mSelectFileButton2->setObjectName(QString::fromUtf8("mSelectFileButton2"));

        selectFileLayout2->addWidget(mSelectFileButton2);

        mSelectedFilename2 = new QLabel(layoutWidget_2);
        mSelectedFilename2->setObjectName(QString::fromUtf8("mSelectedFilename2"));
        mSelectedFilename2->setAlignment(Qt::AlignCenter);

        selectFileLayout2->addWidget(mSelectedFilename2);

        mIncludeStatInfoCheckBox = new QCheckBox(mOutputGroupBox);
        mIncludeStatInfoCheckBox->setObjectName(QString::fromUtf8("mIncludeStatInfoCheckBox"));
        mIncludeStatInfoCheckBox->setGeometry(QRect(10, 150, 261, 17));
        mProcessButton = new QPushButton(centralWidget);
        mProcessButton->setObjectName(QString::fromUtf8("mProcessButton"));
        mProcessButton->setGeometry(QRect(680, 380, 161, 23));
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
        mOutputGroupBox->setTitle(QApplication::translate("CppXtractLibGUIClass", "Options de sortie", nullptr));
        mOutputScreenRadioButton->setText(QApplication::translate("CppXtractLibGUIClass", "\303\200 l'\303\251cran", nullptr));
        mOutputClipboardRadioButton->setText(QApplication::translate("CppXtractLibGUIClass", "Vers le presse papier", nullptr));
        mOutputFileRadioButton->setText(QApplication::translate("CppXtractLibGUIClass", "Vers un fichier de sortie", nullptr));
        mSelectFileButton2->setText(QApplication::translate("CppXtractLibGUIClass", "S\303\251lectionner un fichier...", nullptr));
        mSelectedFilename2->setText(QApplication::translate("CppXtractLibGUIClass", "TextLabel", nullptr));
        mIncludeStatInfoCheckBox->setText(QApplication::translate("CppXtractLibGUIClass", "Ins\303\251rer les statistiques de comptage", nullptr));
        mProcessButton->setText(QApplication::translate("CppXtractLibGUIClass", "Extraire les commentaires", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CppXtractLibGUIClass: public Ui_CppXtractLibGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CPPXTRACTLIBGUI_H
