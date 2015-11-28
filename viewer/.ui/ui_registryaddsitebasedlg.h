/********************************************************************************
** Form generated from reading UI file 'registryaddsitebasedlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRYADDSITEBASEDLG_H
#define UI_REGISTRYADDSITEBASEDLG_H

#include <Qt3Support/Q3GroupBox>
#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CRegistryAddSiteBaseDialog
{
public:
    QGridLayout *gridLayout;
    Q3GroupBox *m_groupbox;
    QGridLayout *gridLayout1;
    QLineEdit *m_lineeditdescription;
    QLabel *m_textlabel;
    QSpacerItem *spacer1;
    QHBoxLayout *hboxLayout;
    QPushButton *m_pushbuttoncancel;
    QPushButton *m_pushbuttonapply;
    QPushButton *m_pushbuttonok;

    void setupUi(QDialog *CRegistryAddSiteBaseDialog)
    {
        if (CRegistryAddSiteBaseDialog->objectName().isEmpty())
            CRegistryAddSiteBaseDialog->setObjectName(QString::fromUtf8("CRegistryAddSiteBaseDialog"));
        CRegistryAddSiteBaseDialog->resize(508, 122);
        gridLayout = new QGridLayout(CRegistryAddSiteBaseDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_groupbox = new Q3GroupBox(CRegistryAddSiteBaseDialog);
        m_groupbox->setObjectName(QString::fromUtf8("m_groupbox"));
        m_groupbox->setColumnLayout(0, Qt::Vertical);
        m_groupbox->layout()->setSpacing(6);
        m_groupbox->layout()->setContentsMargins(11, 11, 11, 11);
        gridLayout1 = new QGridLayout();
        QBoxLayout *boxlayout = qobject_cast<QBoxLayout *>(m_groupbox->layout());
        if (boxlayout)
            boxlayout->addLayout(gridLayout1);
        gridLayout1->setAlignment(Qt::AlignTop);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        m_lineeditdescription = new QLineEdit(m_groupbox);
        m_lineeditdescription->setObjectName(QString::fromUtf8("m_lineeditdescription"));

        gridLayout1->addWidget(m_lineeditdescription, 0, 1, 1, 1);

        m_textlabel = new QLabel(m_groupbox);
        m_textlabel->setObjectName(QString::fromUtf8("m_textlabel"));
        m_textlabel->setWordWrap(false);

        gridLayout1->addWidget(m_textlabel, 0, 0, 1, 1);


        gridLayout->addWidget(m_groupbox, 0, 0, 1, 1);

        spacer1 = new QSpacerItem(41, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer1, 1, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        m_pushbuttoncancel = new QPushButton(CRegistryAddSiteBaseDialog);
        m_pushbuttoncancel->setObjectName(QString::fromUtf8("m_pushbuttoncancel"));

        hboxLayout->addWidget(m_pushbuttoncancel);

        m_pushbuttonapply = new QPushButton(CRegistryAddSiteBaseDialog);
        m_pushbuttonapply->setObjectName(QString::fromUtf8("m_pushbuttonapply"));

        hboxLayout->addWidget(m_pushbuttonapply);

        m_pushbuttonok = new QPushButton(CRegistryAddSiteBaseDialog);
        m_pushbuttonok->setObjectName(QString::fromUtf8("m_pushbuttonok"));

        hboxLayout->addWidget(m_pushbuttonok);


        gridLayout->addLayout(hboxLayout, 2, 0, 1, 1);


        retranslateUi(CRegistryAddSiteBaseDialog);
        QObject::connect(m_pushbuttonok, SIGNAL(clicked()), CRegistryAddSiteBaseDialog, SLOT(pushbuttonok_clicked()));
        QObject::connect(m_pushbuttonapply, SIGNAL(clicked()), CRegistryAddSiteBaseDialog, SLOT(pushbuttonapply_clicked()));
        QObject::connect(m_lineeditdescription, SIGNAL(textChanged(QString)), CRegistryAddSiteBaseDialog, SLOT(lineeditdescription_textChanged(QString)));
        QObject::connect(m_pushbuttoncancel, SIGNAL(clicked()), CRegistryAddSiteBaseDialog, SLOT(pushbuttoncancel_clicked()));

        QMetaObject::connectSlotsByName(CRegistryAddSiteBaseDialog);
    } // setupUi

    void retranslateUi(QDialog *CRegistryAddSiteBaseDialog)
    {
        CRegistryAddSiteBaseDialog->setWindowTitle(QApplication::translate("CRegistryAddSiteBaseDialog", "Add new registry site", 0, QApplication::UnicodeUTF8));
        m_groupbox->setTitle(QString());
        m_textlabel->setText(QApplication::translate("CRegistryAddSiteBaseDialog", "Enter site description:", 0, QApplication::UnicodeUTF8));
        m_pushbuttoncancel->setText(QApplication::translate("CRegistryAddSiteBaseDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        m_pushbuttonapply->setText(QApplication::translate("CRegistryAddSiteBaseDialog", "Apply", 0, QApplication::UnicodeUTF8));
        m_pushbuttonok->setText(QApplication::translate("CRegistryAddSiteBaseDialog", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CRegistryAddSiteBaseDialog: public Ui_CRegistryAddSiteBaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRYADDSITEBASEDLG_H
