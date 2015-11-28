/********************************************************************************
** Form generated from reading UI file 'findfuncconstbasedlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDFUNCCONSTBASEDLG_H
#define UI_FINDFUNCCONSTBASEDLG_H

#include <Qt3Support/Q3Frame>
#include <Qt3Support/Q3GroupBox>
#include <Qt3Support/Q3Header>
#include <Qt3Support/Q3ListView>
#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CFindFuncConstBaseDialog
{
public:
    QVBoxLayout *vboxLayout;
    Q3GroupBox *m_groupboxconstant;
    QHBoxLayout *hboxLayout;
    QLineEdit *m_lineeditconstant;
    QPushButton *m_pushbuttonfindconstant;
    Q3GroupBox *m_groupboxfunction;
    QHBoxLayout *hboxLayout1;
    QLineEdit *m_lineeditfunction;
    QPushButton *m_pushbuttonfindfunction;
    Q3ListView *m_listviewresults;
    QHBoxLayout *hboxLayout2;
    QSpacerItem *spacer1;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *m_pushbuttonok;

    void setupUi(QDialog *CFindFuncConstBaseDialog)
    {
        if (CFindFuncConstBaseDialog->objectName().isEmpty())
            CFindFuncConstBaseDialog->setObjectName(QString::fromUtf8("CFindFuncConstBaseDialog"));
        CFindFuncConstBaseDialog->resize(600, 598);
        vboxLayout = new QVBoxLayout(CFindFuncConstBaseDialog);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        m_groupboxconstant = new Q3GroupBox(CFindFuncConstBaseDialog);
        m_groupboxconstant->setObjectName(QString::fromUtf8("m_groupboxconstant"));
        m_groupboxconstant->setColumnLayout(0, Qt::Vertical);
        m_groupboxconstant->layout()->setSpacing(6);
        m_groupboxconstant->layout()->setContentsMargins(11, 11, 11, 11);
        hboxLayout = new QHBoxLayout();
        QBoxLayout *boxlayout = qobject_cast<QBoxLayout *>(m_groupboxconstant->layout());
        if (boxlayout)
            boxlayout->addLayout(hboxLayout);
        hboxLayout->setAlignment(Qt::AlignTop);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        m_lineeditconstant = new QLineEdit(m_groupboxconstant);
        m_lineeditconstant->setObjectName(QString::fromUtf8("m_lineeditconstant"));

        hboxLayout->addWidget(m_lineeditconstant);

        m_pushbuttonfindconstant = new QPushButton(m_groupboxconstant);
        m_pushbuttonfindconstant->setObjectName(QString::fromUtf8("m_pushbuttonfindconstant"));

        hboxLayout->addWidget(m_pushbuttonfindconstant);


        vboxLayout->addWidget(m_groupboxconstant);

        m_groupboxfunction = new Q3GroupBox(CFindFuncConstBaseDialog);
        m_groupboxfunction->setObjectName(QString::fromUtf8("m_groupboxfunction"));
        m_groupboxfunction->setColumnLayout(0, Qt::Vertical);
        m_groupboxfunction->layout()->setSpacing(6);
        m_groupboxfunction->layout()->setContentsMargins(11, 11, 11, 11);
        hboxLayout1 = new QHBoxLayout();
        QBoxLayout *boxlayout1 = qobject_cast<QBoxLayout *>(m_groupboxfunction->layout());
        if (boxlayout1)
            boxlayout1->addLayout(hboxLayout1);
        hboxLayout1->setAlignment(Qt::AlignTop);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        m_lineeditfunction = new QLineEdit(m_groupboxfunction);
        m_lineeditfunction->setObjectName(QString::fromUtf8("m_lineeditfunction"));

        hboxLayout1->addWidget(m_lineeditfunction);

        m_pushbuttonfindfunction = new QPushButton(m_groupboxfunction);
        m_pushbuttonfindfunction->setObjectName(QString::fromUtf8("m_pushbuttonfindfunction"));

        hboxLayout1->addWidget(m_pushbuttonfindfunction);


        vboxLayout->addWidget(m_groupboxfunction);

        m_listviewresults = new Q3ListView(CFindFuncConstBaseDialog);
        m_listviewresults->addColumn(QApplication::translate("CFindFuncConstBaseDialog", "Name", 0, QApplication::UnicodeUTF8));
        m_listviewresults->header()->setClickEnabled(true, m_listviewresults->header()->count() - 1);
        m_listviewresults->header()->setResizeEnabled(true, m_listviewresults->header()->count() - 1);
        m_listviewresults->addColumn(QApplication::translate("CFindFuncConstBaseDialog", "Value", 0, QApplication::UnicodeUTF8));
        m_listviewresults->header()->setClickEnabled(true, m_listviewresults->header()->count() - 1);
        m_listviewresults->header()->setResizeEnabled(true, m_listviewresults->header()->count() - 1);
        m_listviewresults->setObjectName(QString::fromUtf8("m_listviewresults"));

        vboxLayout->addWidget(m_listviewresults);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        spacer1 = new QSpacerItem(470, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacer1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(horizontalSpacer);

        pushButton = new QPushButton(CFindFuncConstBaseDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        hboxLayout2->addWidget(pushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(horizontalSpacer_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(horizontalSpacer_2);

        m_pushbuttonok = new QPushButton(CFindFuncConstBaseDialog);
        m_pushbuttonok->setObjectName(QString::fromUtf8("m_pushbuttonok"));

        hboxLayout2->addWidget(m_pushbuttonok);


        vboxLayout->addLayout(hboxLayout2);


        retranslateUi(CFindFuncConstBaseDialog);
        QObject::connect(m_pushbuttonfindconstant, SIGNAL(clicked()), CFindFuncConstBaseDialog, SLOT(pushbuttonfindconstant_clicked()));
        QObject::connect(m_pushbuttonfindfunction, SIGNAL(clicked()), CFindFuncConstBaseDialog, SLOT(pushbuttonfindfunction_clicked()));
        QObject::connect(pushButton, SIGNAL(clicked()), CFindFuncConstBaseDialog, SLOT(pushbuttonclear_clicked()));
        QObject::connect(m_pushbuttonok, SIGNAL(clicked()), CFindFuncConstBaseDialog, SLOT(pushbuttonok_clicked()));
        QObject::connect(m_lineeditconstant, SIGNAL(textChanged(QString)), CFindFuncConstBaseDialog, SLOT(lineeditconstant_textChanged(QString)));
        QObject::connect(m_lineeditfunction, SIGNAL(textChanged(QString)), CFindFuncConstBaseDialog, SLOT(pushbuttonfindfunction_clicked()));

        QMetaObject::connectSlotsByName(CFindFuncConstBaseDialog);
    } // setupUi

    void retranslateUi(QDialog *CFindFuncConstBaseDialog)
    {
        CFindFuncConstBaseDialog->setWindowTitle(QApplication::translate("CFindFuncConstBaseDialog", "Find OpenGL Function or Constant", 0, QApplication::UnicodeUTF8));
        m_groupboxconstant->setTitle(QApplication::translate("CFindFuncConstBaseDialog", "Find Constant", 0, QApplication::UnicodeUTF8));
        m_pushbuttonfindconstant->setText(QApplication::translate("CFindFuncConstBaseDialog", "Find", 0, QApplication::UnicodeUTF8));
        m_groupboxfunction->setTitle(QApplication::translate("CFindFuncConstBaseDialog", "Find Function", 0, QApplication::UnicodeUTF8));
        m_pushbuttonfindfunction->setText(QApplication::translate("CFindFuncConstBaseDialog", "Find", 0, QApplication::UnicodeUTF8));
        m_listviewresults->header()->setLabel(0, QApplication::translate("CFindFuncConstBaseDialog", "Name", 0, QApplication::UnicodeUTF8));
        m_listviewresults->header()->setLabel(1, QApplication::translate("CFindFuncConstBaseDialog", "Value", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("CFindFuncConstBaseDialog", "Clear", 0, QApplication::UnicodeUTF8));
        m_pushbuttonok->setText(QApplication::translate("CFindFuncConstBaseDialog", "&OK", 0, QApplication::UnicodeUTF8));
        m_pushbuttonok->setShortcut(QApplication::translate("CFindFuncConstBaseDialog", "Alt+O", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CFindFuncConstBaseDialog: public Ui_CFindFuncConstBaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDFUNCCONSTBASEDLG_H
