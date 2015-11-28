/********************************************************************************
** Form generated from reading UI file 'aboutbasedlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTBASEDLG_H
#define UI_ABOUTBASEDLG_H

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
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CAboutBaseDialog
{
public:
    QGridLayout *gridLayout;
    Q3GroupBox *m_groupbox;
    QGridLayout *gridLayout_2;
    QLabel *textLabel1;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *spacer1;
    QPushButton *m_pushbuttonok;
    QSpacerItem *spacer1_2;

    void setupUi(QDialog *CAboutBaseDialog)
    {
        if (CAboutBaseDialog->objectName().isEmpty())
            CAboutBaseDialog->setObjectName(QString::fromUtf8("CAboutBaseDialog"));
        CAboutBaseDialog->resize(305, 177);
        gridLayout = new QGridLayout(CAboutBaseDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_groupbox = new Q3GroupBox(CAboutBaseDialog);
        m_groupbox->setObjectName(QString::fromUtf8("m_groupbox"));
        m_groupbox->setColumnLayout(0, Qt::Vertical);
        m_groupbox->layout()->setSpacing(6);
        m_groupbox->layout()->setContentsMargins(11, 11, 11, 11);
        gridLayout_2 = new QGridLayout();
        QBoxLayout *boxlayout = qobject_cast<QBoxLayout *>(m_groupbox->layout());
        if (boxlayout)
            boxlayout->addLayout(gridLayout_2);
        gridLayout_2->setAlignment(Qt::AlignTop);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        textLabel1 = new QLabel(m_groupbox);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textLabel1->sizePolicy().hasHeightForWidth());
        textLabel1->setSizePolicy(sizePolicy);
        textLabel1->setAlignment(Qt::AlignCenter);
        textLabel1->setWordWrap(false);

        gridLayout_2->addWidget(textLabel1, 0, 0, 1, 1);


        gridLayout->addWidget(m_groupbox, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        spacer1 = new QSpacerItem(68, 30, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacer1);

        m_pushbuttonok = new QPushButton(CAboutBaseDialog);
        m_pushbuttonok->setObjectName(QString::fromUtf8("m_pushbuttonok"));
        m_pushbuttonok->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_pushbuttonok->sizePolicy().hasHeightForWidth());
        m_pushbuttonok->setSizePolicy(sizePolicy1);
        m_pushbuttonok->setMinimumSize(QSize(80, 30));
        m_pushbuttonok->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(m_pushbuttonok);

        spacer1_2 = new QSpacerItem(68, 30, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacer1_2);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(CAboutBaseDialog);
        QObject::connect(m_pushbuttonok, SIGNAL(clicked()), CAboutBaseDialog, SLOT(pushbuttonok_clicked()));

        QMetaObject::connectSlotsByName(CAboutBaseDialog);
    } // setupUi

    void retranslateUi(QDialog *CAboutBaseDialog)
    {
        CAboutBaseDialog->setWindowTitle(QApplication::translate("CAboutBaseDialog", "About this application", 0, QApplication::UnicodeUTF8));
        m_groupbox->setTitle(QString());
        textLabel1->setText(QApplication::translate("CAboutBaseDialog", "OpenGL Extension Editor\n"
"(C) VFX Research 2002-2014\n"
"All Rights Reserved.\n"
"Author: Dr.  Michael S. A. Robb\n"
"E-mail: msar@vfxresearch.com	", 0, QApplication::UnicodeUTF8));
        m_pushbuttonok->setText(QApplication::translate("CAboutBaseDialog", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CAboutBaseDialog: public Ui_CAboutBaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTBASEDLG_H
