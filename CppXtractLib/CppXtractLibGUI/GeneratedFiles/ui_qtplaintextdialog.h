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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_QtPlainTextDialog
{
public:
    QPlainTextEdit *resultOutput;
    QPushButton *okButton;

    void setupUi(QDialog *QtPlainTextDialog)
    {
        if (QtPlainTextDialog->objectName().isEmpty())
            QtPlainTextDialog->setObjectName(QString::fromUtf8("QtPlainTextDialog"));
        QtPlainTextDialog->resize(375, 286);
        resultOutput = new QPlainTextEdit(QtPlainTextDialog);
        resultOutput->setObjectName(QString::fromUtf8("resultOutput"));
        resultOutput->setGeometry(QRect(10, 20, 331, 201));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        resultOutput->setFont(font);
        okButton = new QPushButton(QtPlainTextDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(270, 230, 75, 23));

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
