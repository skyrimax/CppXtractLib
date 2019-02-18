/********************************************************************************
** Form generated from reading UI file 'cppxtract.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CPPXTRACT_H
#define UI_CPPXTRACT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CppXtractClass
{
public:
    QWidget *centralWidget;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QPushButton *SelecFichierEntreeButton;
    QLabel *FichierEntreeLabel;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *ScreenButton;
    QRadioButton *PressPapierButton;
    QRadioButton *FichierSortieButton;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QPushButton *SelecFichierSortieButton;
    QLabel *FichierSortieLabel;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *InsertStatsBox;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_4;
    QWidget *PushButton;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *XtractCommentButton;
    QSpacerItem *verticalSpacer;
    QWidget *aboutButtonLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *mAboutCppXtractButton;
    QPushButton *mAboutCppButton;
    QPushButton *mAboutQtButton;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QMainWindow *CppXtractClass)
    {
        if (CppXtractClass->objectName().isEmpty())
            CppXtractClass->setObjectName(QString::fromUtf8("CppXtractClass"));
        CppXtractClass->resize(540, 521);
        CppXtractClass->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8("TonyIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        CppXtractClass->setWindowIcon(icon);
        CppXtractClass->setToolButtonStyle(Qt::ToolButtonIconOnly);
        CppXtractClass->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(CppXtractClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        formLayout = new QFormLayout(centralWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_3);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        SelecFichierEntreeButton = new QPushButton(widget_2);
        SelecFichierEntreeButton->setObjectName(QString::fromUtf8("SelecFichierEntreeButton"));
        SelecFichierEntreeButton->setIconSize(QSize(16, 16));

        verticalLayout->addWidget(SelecFichierEntreeButton);

        FichierEntreeLabel = new QLabel(widget_2);
        FichierEntreeLabel->setObjectName(QString::fromUtf8("FichierEntreeLabel"));

        verticalLayout->addWidget(FichierEntreeLabel);


        horizontalLayout_4->addLayout(verticalLayout);


        gridLayout->addWidget(widget_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        widget_3 = new QWidget(groupBox);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_8 = new QHBoxLayout(widget_3);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        ScreenButton = new QRadioButton(widget_3);
        ScreenButton->setObjectName(QString::fromUtf8("ScreenButton"));
        ScreenButton->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_3->addWidget(ScreenButton);

        PressPapierButton = new QRadioButton(widget_3);
        PressPapierButton->setObjectName(QString::fromUtf8("PressPapierButton"));
        PressPapierButton->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_3->addWidget(PressPapierButton);

        FichierSortieButton = new QRadioButton(widget_3);
        FichierSortieButton->setObjectName(QString::fromUtf8("FichierSortieButton"));
        FichierSortieButton->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_3->addWidget(FichierSortieButton);


        horizontalLayout_8->addLayout(verticalLayout_3);


        verticalLayout_5->addWidget(widget_3);

        widget_4 = new QWidget(groupBox);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_7 = new QHBoxLayout(widget_4);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        SelecFichierSortieButton = new QPushButton(widget_4);
        SelecFichierSortieButton->setObjectName(QString::fromUtf8("SelecFichierSortieButton"));

        verticalLayout_2->addWidget(SelecFichierSortieButton);

        FichierSortieLabel = new QLabel(widget_4);
        FichierSortieLabel->setObjectName(QString::fromUtf8("FichierSortieLabel"));

        verticalLayout_2->addWidget(FichierSortieLabel);


        horizontalLayout_7->addLayout(verticalLayout_2);


        verticalLayout_5->addWidget(widget_4);

        widget_5 = new QWidget(groupBox);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_6 = new QHBoxLayout(widget_5);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        InsertStatsBox = new QCheckBox(widget_5);
        InsertStatsBox->setObjectName(QString::fromUtf8("InsertStatsBox"));
        InsertStatsBox->setCursor(QCursor(Qt::CrossCursor));

        horizontalLayout_3->addWidget(InsertStatsBox);


        horizontalLayout_6->addLayout(horizontalLayout_3);


        verticalLayout_5->addWidget(widget_5);


        gridLayout->addWidget(groupBox, 1, 0, 1, 1);


        horizontalLayout_9->addWidget(widget);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);


        verticalLayout_6->addLayout(horizontalLayout_9);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        PushButton = new QWidget(centralWidget);
        PushButton->setObjectName(QString::fromUtf8("PushButton"));
        horizontalLayout_5 = new QHBoxLayout(PushButton);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        XtractCommentButton = new QPushButton(PushButton);
        XtractCommentButton->setObjectName(QString::fromUtf8("XtractCommentButton"));

        horizontalLayout_2->addWidget(XtractCommentButton);


        horizontalLayout_5->addLayout(horizontalLayout_2);


        verticalLayout_4->addWidget(PushButton);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer);

        aboutButtonLayout = new QWidget(centralWidget);
        aboutButtonLayout->setObjectName(QString::fromUtf8("aboutButtonLayout"));
        horizontalLayout = new QHBoxLayout(aboutButtonLayout);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mAboutCppXtractButton = new QPushButton(aboutButtonLayout);
        mAboutCppXtractButton->setObjectName(QString::fromUtf8("mAboutCppXtractButton"));

        horizontalLayout->addWidget(mAboutCppXtractButton);

        mAboutCppButton = new QPushButton(aboutButtonLayout);
        mAboutCppButton->setObjectName(QString::fromUtf8("mAboutCppButton"));

        horizontalLayout->addWidget(mAboutCppButton);

        mAboutQtButton = new QPushButton(aboutButtonLayout);
        mAboutQtButton->setObjectName(QString::fromUtf8("mAboutQtButton"));

        horizontalLayout->addWidget(mAboutQtButton);


        verticalLayout_4->addWidget(aboutButtonLayout);


        verticalLayout_6->addLayout(verticalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);


        formLayout->setLayout(0, QFormLayout::FieldRole, verticalLayout_6);

        CppXtractClass->setCentralWidget(centralWidget);

        retranslateUi(CppXtractClass);
        QObject::connect(mAboutCppXtractButton, SIGNAL(clicked()), CppXtractClass, SLOT(showAboutCppXtract()));
        QObject::connect(mAboutCppButton, SIGNAL(clicked()), CppXtractClass, SLOT(showAboutCpp()));
        QObject::connect(mAboutQtButton, SIGNAL(clicked()), CppXtractClass, SLOT(showAboutQt()));

        QMetaObject::connectSlotsByName(CppXtractClass);
    } // setupUi

    void retranslateUi(QMainWindow *CppXtractClass)
    {
        CppXtractClass->setWindowTitle(QApplication::translate("CppXtractClass", "CppXtract", nullptr));
        SelecFichierEntreeButton->setText(QApplication::translate("CppXtractClass", "S\303\251lectionnez un fichier d'entr\303\251e...", nullptr));
        FichierEntreeLabel->setText(QApplication::translate("CppXtractClass", "<html><head/><body><p align=\"center\">&lt;Aucun fichier de s\303\251lectionn\303\251&gt;</p></body></html>", nullptr));
        groupBox->setTitle(QApplication::translate("CppXtractClass", "Option de sortie", nullptr));
        ScreenButton->setText(QApplication::translate("CppXtractClass", "\303\200 l'\303\251cran", nullptr));
        PressPapierButton->setText(QApplication::translate("CppXtractClass", "Vers le presse papier", nullptr));
        FichierSortieButton->setText(QApplication::translate("CppXtractClass", "Vers un fichier de sortie", nullptr));
        SelecFichierSortieButton->setText(QApplication::translate("CppXtractClass", "S\303\251lectionnez les fichiers de sortie...", nullptr));
        FichierSortieLabel->setText(QApplication::translate("CppXtractClass", "<html><head/><body><p align=\"center\">&lt;Aucun fichier s\303\251lectionn\303\251&gt;</p></body></html>", nullptr));
        InsertStatsBox->setText(QApplication::translate("CppXtractClass", "Ins\303\251rer les statistiques", nullptr));
        XtractCommentButton->setText(QApplication::translate("CppXtractClass", "Extraire les commentaires...", nullptr));
        mAboutCppXtractButton->setText(QApplication::translate("CppXtractClass", "\303\200 propos de CppXtract...", nullptr));
        mAboutCppButton->setText(QApplication::translate("CppXtractClass", "\303\200 propos du langage C++...", nullptr));
        mAboutQtButton->setText(QApplication::translate("CppXtractClass", "\303\200 propos de Qt...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CppXtractClass: public Ui_CppXtractClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CPPXTRACT_H
