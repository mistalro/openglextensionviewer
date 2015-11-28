/********************************************************************************
** Form generated from reading UI file 'exitapplicationbasedlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXITAPPLICATIONBASEDLG_H
#define UI_EXITAPPLICATIONBASEDLG_H

#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CExitApplicationBaseDialog
{
public:
    QLabel *m_textsaveconfiguration;
    QPushButton *m_pushbuttonno;
    QPushButton *m_pushbuttoncancel;
    QPushButton *m_pushbuttonyes;

    void setupUi(QDialog *CExitApplicationBaseDialog)
    {
        if (CExitApplicationBaseDialog->objectName().isEmpty())
            CExitApplicationBaseDialog->setObjectName(QString::fromUtf8("CExitApplicationBaseDialog"));
        CExitApplicationBaseDialog->resize(334, 97);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CExitApplicationBaseDialog->sizePolicy().hasHeightForWidth());
        CExitApplicationBaseDialog->setSizePolicy(sizePolicy);
        m_textsaveconfiguration = new QLabel(CExitApplicationBaseDialog);
        m_textsaveconfiguration->setObjectName(QString::fromUtf8("m_textsaveconfiguration"));
        m_textsaveconfiguration->setGeometry(QRect(40, 20, 260, 20));
        m_textsaveconfiguration->setWordWrap(false);
        m_pushbuttonno = new QPushButton(CExitApplicationBaseDialog);
        m_pushbuttonno->setObjectName(QString::fromUtf8("m_pushbuttonno"));
        m_pushbuttonno->setGeometry(QRect(130, 50, 91, 31));
        m_pushbuttoncancel = new QPushButton(CExitApplicationBaseDialog);
        m_pushbuttoncancel->setObjectName(QString::fromUtf8("m_pushbuttoncancel"));
        m_pushbuttoncancel->setGeometry(QRect(230, 50, 91, 31));
        m_pushbuttonyes = new QPushButton(CExitApplicationBaseDialog);
        m_pushbuttonyes->setObjectName(QString::fromUtf8("m_pushbuttonyes"));
        m_pushbuttonyes->setGeometry(QRect(20, 50, 97, 32));

        retranslateUi(CExitApplicationBaseDialog);
        QObject::connect(m_pushbuttonyes, SIGNAL(clicked()), CExitApplicationBaseDialog, SLOT(pushbuttonyes_clicked()));
        QObject::connect(m_pushbuttonno, SIGNAL(clicked()), CExitApplicationBaseDialog, SLOT(pushbuttonno_clicked()));
        QObject::connect(m_pushbuttoncancel, SIGNAL(clicked()), CExitApplicationBaseDialog, SLOT(pushbuttoncancel_clicked()));

        QMetaObject::connectSlotsByName(CExitApplicationBaseDialog);
    } // setupUi

    void retranslateUi(QDialog *CExitApplicationBaseDialog)
    {
        CExitApplicationBaseDialog->setWindowTitle(QApplication::translate("CExitApplicationBaseDialog", "Exit Application", 0, QApplication::UnicodeUTF8));
        m_textsaveconfiguration->setText(QApplication::translate("CExitApplicationBaseDialog", "Save current configuration before leaving?", 0, QApplication::UnicodeUTF8));
        m_pushbuttonno->setText(QApplication::translate("CExitApplicationBaseDialog", "No", 0, QApplication::UnicodeUTF8));
        m_pushbuttoncancel->setText(QApplication::translate("CExitApplicationBaseDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        m_pushbuttonyes->setText(QApplication::translate("CExitApplicationBaseDialog", "Yes", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CExitApplicationBaseDialog: public Ui_CExitApplicationBaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXITAPPLICATIONBASEDLG_H
