/********************************************************************************
** Form generated from reading UI file 'cppxtract.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CPPXTRACT_H
#define UI_CPPXTRACT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CppXtractClass
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QWidget *cppXtractParameters;
    QVBoxLayout *verticalLayout_4;
    QWidget *fileSelectorInput;
    QVBoxLayout *verticalLayout;
    QPushButton *fileSelectorButtonImput;
    QLabel *inputFilePathLabel;
    QGroupBox *outputOptions;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *screenRadioButton;
    QRadioButton *clipboardRadioButton;
    QRadioButton *fileRadioButton;
    QWidget *fileSelectorOutput;
    QVBoxLayout *verticalLayout_2;
    QPushButton *fileSlectorButtonOutput;
    QLabel *outputFilePathLabel;
    QCheckBox *statisticsCheckBox;
    QSpacerItem *horizontalSpacer_3;
    QWidget *cppXtractButton;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *extractButton;
    QWidget *aboutBar;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *aboutCppXtractButton;
    QPushButton *aboutCPlusPlusButton;
    QPushButton *aboutQtButton;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *CppXtractClass)
    {
        if (CppXtractClass->objectName().isEmpty())
            CppXtractClass->setObjectName(QString::fromUtf8("CppXtractClass"));
        CppXtractClass->resize(600, 445);
        gridLayout_2 = new QGridLayout(CppXtractClass);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(28, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        cppXtractParameters = new QWidget(CppXtractClass);
        cppXtractParameters->setObjectName(QString::fromUtf8("cppXtractParameters"));
        verticalLayout_4 = new QVBoxLayout(cppXtractParameters);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        fileSelectorInput = new QWidget(cppXtractParameters);
        fileSelectorInput->setObjectName(QString::fromUtf8("fileSelectorInput"));
        verticalLayout = new QVBoxLayout(fileSelectorInput);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        fileSelectorButtonImput = new QPushButton(fileSelectorInput);
        fileSelectorButtonImput->setObjectName(QString::fromUtf8("fileSelectorButtonImput"));

        verticalLayout->addWidget(fileSelectorButtonImput);

        inputFilePathLabel = new QLabel(fileSelectorInput);
        inputFilePathLabel->setObjectName(QString::fromUtf8("inputFilePathLabel"));
        inputFilePathLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(inputFilePathLabel);


        verticalLayout_4->addWidget(fileSelectorInput);

        outputOptions = new QGroupBox(cppXtractParameters);
        outputOptions->setObjectName(QString::fromUtf8("outputOptions"));
        outputOptions->setAutoFillBackground(false);
        verticalLayout_3 = new QVBoxLayout(outputOptions);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        screenRadioButton = new QRadioButton(outputOptions);
        screenRadioButton->setObjectName(QString::fromUtf8("screenRadioButton"));

        verticalLayout_3->addWidget(screenRadioButton);

        clipboardRadioButton = new QRadioButton(outputOptions);
        clipboardRadioButton->setObjectName(QString::fromUtf8("clipboardRadioButton"));

        verticalLayout_3->addWidget(clipboardRadioButton);

        fileRadioButton = new QRadioButton(outputOptions);
        fileRadioButton->setObjectName(QString::fromUtf8("fileRadioButton"));

        verticalLayout_3->addWidget(fileRadioButton);

        fileSelectorOutput = new QWidget(outputOptions);
        fileSelectorOutput->setObjectName(QString::fromUtf8("fileSelectorOutput"));
        verticalLayout_2 = new QVBoxLayout(fileSelectorOutput);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        fileSlectorButtonOutput = new QPushButton(fileSelectorOutput);
        fileSlectorButtonOutput->setObjectName(QString::fromUtf8("fileSlectorButtonOutput"));

        verticalLayout_2->addWidget(fileSlectorButtonOutput);

        outputFilePathLabel = new QLabel(fileSelectorOutput);
        outputFilePathLabel->setObjectName(QString::fromUtf8("outputFilePathLabel"));
        outputFilePathLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(outputFilePathLabel);


        verticalLayout_3->addWidget(fileSelectorOutput);

        statisticsCheckBox = new QCheckBox(outputOptions);
        statisticsCheckBox->setObjectName(QString::fromUtf8("statisticsCheckBox"));

        verticalLayout_3->addWidget(statisticsCheckBox);


        verticalLayout_4->addWidget(outputOptions);


        gridLayout->addWidget(cppXtractParameters, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(28, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        cppXtractButton = new QWidget(CppXtractClass);
        cppXtractButton->setObjectName(QString::fromUtf8("cppXtractButton"));
        horizontalLayout = new QHBoxLayout(cppXtractButton);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        extractButton = new QPushButton(cppXtractButton);
        extractButton->setObjectName(QString::fromUtf8("extractButton"));

        horizontalLayout->addWidget(extractButton);


        gridLayout->addWidget(cppXtractButton, 2, 1, 1, 1);

        aboutBar = new QWidget(CppXtractClass);
        aboutBar->setObjectName(QString::fromUtf8("aboutBar"));
        horizontalLayout_2 = new QHBoxLayout(aboutBar);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        aboutCppXtractButton = new QPushButton(aboutBar);
        aboutCppXtractButton->setObjectName(QString::fromUtf8("aboutCppXtractButton"));

        horizontalLayout_2->addWidget(aboutCppXtractButton);

        aboutCPlusPlusButton = new QPushButton(aboutBar);
        aboutCPlusPlusButton->setObjectName(QString::fromUtf8("aboutCPlusPlusButton"));

        horizontalLayout_2->addWidget(aboutCPlusPlusButton);

        aboutQtButton = new QPushButton(aboutBar);
        aboutQtButton->setObjectName(QString::fromUtf8("aboutQtButton"));

        horizontalLayout_2->addWidget(aboutQtButton);


        gridLayout->addWidget(aboutBar, 3, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 4, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(CppXtractClass);
        QObject::connect(aboutQtButton, SIGNAL(clicked()), CppXtractClass, SLOT(showAboutQt()));
        QObject::connect(aboutCPlusPlusButton, SIGNAL(clicked()), CppXtractClass, SLOT(showAboutCpp()));
        QObject::connect(aboutCppXtractButton, SIGNAL(clicked()), CppXtractClass, SLOT(showAboutCppXtract()));

        QMetaObject::connectSlotsByName(CppXtractClass);
    } // setupUi

    void retranslateUi(QWidget *CppXtractClass)
    {
        CppXtractClass->setWindowTitle(QApplication::translate("CppXtractClass", "CppXtract", nullptr));
        fileSelectorButtonImput->setText(QApplication::translate("CppXtractClass", "S\303\251lectionner un fichier d'entr\303\251", nullptr));
        inputFilePathLabel->setText(QApplication::translate("CppXtractClass", "-", nullptr));
        outputOptions->setTitle(QApplication::translate("CppXtractClass", "Option de sortie", nullptr));
        screenRadioButton->setText(QApplication::translate("CppXtractClass", "\303\200 l'\303\251cran", nullptr));
        clipboardRadioButton->setText(QApplication::translate("CppXtractClass", "Vers le presse papier", nullptr));
        fileRadioButton->setText(QApplication::translate("CppXtractClass", "Vers un fichier de sortie", nullptr));
        fileSlectorButtonOutput->setText(QApplication::translate("CppXtractClass", "S\303\251lectionner un fichier d'entr\303\251", nullptr));
        outputFilePathLabel->setText(QApplication::translate("CppXtractClass", "-", nullptr));
        statisticsCheckBox->setText(QApplication::translate("CppXtractClass", "Ins\303\251rer les statistiques", nullptr));
        extractButton->setText(QApplication::translate("CppXtractClass", "Extraire les commentaires...", nullptr));
        aboutCppXtractButton->setText(QApplication::translate("CppXtractClass", "\303\200 propos de CppXtract...", nullptr));
        aboutCPlusPlusButton->setText(QApplication::translate("CppXtractClass", "\303\200 propos du langage C++...", nullptr));
        aboutQtButton->setText(QApplication::translate("CppXtractClass", "\303\200 propos de QT...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CppXtractClass: public Ui_CppXtractClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CPPXTRACT_H
