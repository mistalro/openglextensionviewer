/********************************************************************************
** Form generated from reading UI file 'extensionviewbasedlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXTENSIONVIEWBASEDLG_H
#define UI_EXTENSIONVIEWBASEDLG_H

#include <Qt3Support/Q3Frame>
#include <Qt3Support/Q3MimeSourceFactory>
#include <Qt3Support/Q3TextEdit>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CExtensionViewBaseDialog
{
public:
    QGridLayout *gridLayout;
    Q3TextEdit *m_textedit;
    QHBoxLayout *hboxLayout;
    QSpacerItem *m_spacer;
    QPushButton *m_pushbuttonok;

    void setupUi(QDialog *CExtensionViewBaseDialog)
    {
        if (CExtensionViewBaseDialog->objectName().isEmpty())
            CExtensionViewBaseDialog->setObjectName(QString::fromUtf8("CExtensionViewBaseDialog"));
        CExtensionViewBaseDialog->resize(622, 602);
        gridLayout = new QGridLayout(CExtensionViewBaseDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_textedit = new Q3TextEdit(CExtensionViewBaseDialog);
        m_textedit->setObjectName(QString::fromUtf8("m_textedit"));
        QFont font;
        font.setFamily(QString::fromUtf8("Monospace"));
        font.setPointSize(11);
        m_textedit->setFont(font);
        m_textedit->setWordWrap(Q3TextEdit::WidgetWidth);
        m_textedit->setReadOnly(true);

        gridLayout->addWidget(m_textedit, 0, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        m_spacer = new QSpacerItem(490, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(m_spacer);

        m_pushbuttonok = new QPushButton(CExtensionViewBaseDialog);
        m_pushbuttonok->setObjectName(QString::fromUtf8("m_pushbuttonok"));

        hboxLayout->addWidget(m_pushbuttonok);


        gridLayout->addLayout(hboxLayout, 1, 0, 1, 1);


        retranslateUi(CExtensionViewBaseDialog);
        QObject::connect(m_pushbuttonok, SIGNAL(clicked()), CExtensionViewBaseDialog, SLOT(pushbuttonok_clicked()));

        QMetaObject::connectSlotsByName(CExtensionViewBaseDialog);
    } // setupUi

    void retranslateUi(QDialog *CExtensionViewBaseDialog)
    {
        CExtensionViewBaseDialog->setWindowTitle(QApplication::translate("CExtensionViewBaseDialog", "Extension Specification", 0, QApplication::UnicodeUTF8));
        m_textedit->setText(QString());
        m_pushbuttonok->setText(QApplication::translate("CExtensionViewBaseDialog", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CExtensionViewBaseDialog: public Ui_CExtensionViewBaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXTENSIONVIEWBASEDLG_H
