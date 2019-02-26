/********************************************************************************
** Form generated from reading UI file 'qtplaintextdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTPLAINTEXTDIALOG_H
#define UI_QTPLAINTEXTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtPlainTextDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QPlainTextEdit *resultOutput;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *QtPlainTextDialog)
    {
        if (QtPlainTextDialog->objectName().isEmpty())
            QtPlainTextDialog->setObjectName(QString::fromUtf8("QtPlainTextDialog"));
        QtPlainTextDialog->resize(659, 475);
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        QtPlainTextDialog->setFont(font);
        layoutWidget = new QWidget(QtPlainTextDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 0, 519, 363));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        resultOutput = new QPlainTextEdit(layoutWidget);
        resultOutput->setObjectName(QString::fromUtf8("resultOutput"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Comic Sans MS"));
        resultOutput->setFont(font1);

        verticalLayout->addWidget(resultOutput);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(388, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout->addWidget(okButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        retranslateUi(QtPlainTextDialog);
        QObject::connect(okButton, SIGNAL(clicked()), QtPlainTextDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(QtPlainTextDialog);
    } // setupUi

    void retranslateUi(QDialog *QtPlainTextDialog)
    {
        QtPlainTextDialog->setWindowTitle(QApplication::translate("QtPlainTextDialog", "QtPlainTextDialog", nullptr));
        okButton->setText(QApplication::translate("QtPlainTextDialog", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtPlainTextDialog: public Ui_QtPlainTextDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTPLAINTEXTDIALOG_H
