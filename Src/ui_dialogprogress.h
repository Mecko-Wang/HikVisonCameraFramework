/********************************************************************************
** Form generated from reading UI file 'dialogprogress.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPROGRESS_H
#define UI_DIALOGPROGRESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DialogProgress
{
public:
    QLabel *label;

    void setupUi(QDialog *DialogProgress)
    {
        if (DialogProgress->objectName().isEmpty())
            DialogProgress->setObjectName(QStringLiteral("DialogProgress"));
        DialogProgress->resize(400, 127);
        label = new QLabel(DialogProgress);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 40, 331, 41));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setTextFormat(Qt::PlainText);

        retranslateUi(DialogProgress);

        QMetaObject::connectSlotsByName(DialogProgress);
    } // setupUi

    void retranslateUi(QDialog *DialogProgress)
    {
        DialogProgress->setWindowTitle(QApplication::translate("DialogProgress", "\346\217\220\347\244\272", Q_NULLPTR));
        label->setText(QApplication::translate("DialogProgress", "\350\257\267\347\250\215\347\255\211\357\274\214\347\250\213\345\272\217\346\255\243\345\234\250\345\220\257\345\212\250..........", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogProgress: public Ui_DialogProgress {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPROGRESS_H
