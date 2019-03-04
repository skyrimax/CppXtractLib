/********************************************************************************
** Form generated from reading UI file 'qtplaintextdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTPLAINTEXTDIALOG_H
#define UI_QTPLAINTEXTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_QtPlainTextDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPlainTextEdit *resultOutput;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;

    void setupUi(QDialog *QtPlainTextDialog)
    {
        if (QtPlainTextDialog->objectName().isEmpty())
            QtPlainTextDialog->setObjectName(QString::fromUtf8("QtPlainTextDialog"));
        QtPlainTextDialog->resize(400, 391);
        gridLayout_2 = new QGridLayout(QtPlainTextDialog);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        resultOutput = new QPlainTextEdit(QtPlainTextDialog);
        resultOutput->setObjectName(QString::fromUtf8("resultOutput"));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        resultOutput->setFont(font);

        gridLayout->addWidget(resultOutput, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okButton = new QPushButton(QtPlainTextDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout->addWidget(okButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


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
