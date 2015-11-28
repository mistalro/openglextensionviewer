/********************************************************************************
** Form generated from reading UI file 'registryprogressbasedlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRYPROGRESSBASEDLG_H
#define UI_REGISTRYPROGRESSBASEDLG_H

#include <Qt3Support/Q3Frame>
#include <Qt3Support/Q3ListBox>
#include <Qt3Support/Q3MimeSourceFactory>
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

class Ui_CRegistryProgressBaseDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *hboxLayout;
    QPushButton *m_pushbuttonsave;
    QSpacerItem *spacer1;
    QPushButton *m_pushbuttoncancel;
    QPushButton *m_pushbuttonpause;
    QPushButton *m_pushbuttonok;
    Q3ListBox *m_listboxregistrylog;

    void setupUi(QDialog *CRegistryProgressBaseDialog)
    {
        if (CRegistryProgressBaseDialog->objectName().isEmpty())
            CRegistryProgressBaseDialog->setObjectName(QString::fromUtf8("CRegistryProgressBaseDialog"));
        CRegistryProgressBaseDialog->resize(561, 452);
        gridLayout = new QGridLayout(CRegistryProgressBaseDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        m_pushbuttonsave = new QPushButton(CRegistryProgressBaseDialog);
        m_pushbuttonsave->setObjectName(QString::fromUtf8("m_pushbuttonsave"));

        hboxLayout->addWidget(m_pushbuttonsave);

        spacer1 = new QSpacerItem(180, 30, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer1);

        m_pushbuttoncancel = new QPushButton(CRegistryProgressBaseDialog);
        m_pushbuttoncancel->setObjectName(QString::fromUtf8("m_pushbuttoncancel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_pushbuttoncancel->sizePolicy().hasHeightForWidth());
        m_pushbuttoncancel->setSizePolicy(sizePolicy);
        m_pushbuttoncancel->setDefault(false);

        hboxLayout->addWidget(m_pushbuttoncancel);

        m_pushbuttonpause = new QPushButton(CRegistryProgressBaseDialog);
        m_pushbuttonpause->setObjectName(QString::fromUtf8("m_pushbuttonpause"));
        sizePolicy.setHeightForWidth(m_pushbuttonpause->sizePolicy().hasHeightForWidth());
        m_pushbuttonpause->setSizePolicy(sizePolicy);
        m_pushbuttonpause->setDefault(false);

        hboxLayout->addWidget(m_pushbuttonpause);

        m_pushbuttonok = new QPushButton(CRegistryProgressBaseDialog);
        m_pushbuttonok->setObjectName(QString::fromUtf8("m_pushbuttonok"));
        sizePolicy.setHeightForWidth(m_pushbuttonok->sizePolicy().hasHeightForWidth());
        m_pushbuttonok->setSizePolicy(sizePolicy);
        m_pushbuttonok->setDefault(true);

        hboxLayout->addWidget(m_pushbuttonok);


        gridLayout->addLayout(hboxLayout, 1, 0, 1, 1);

        m_listboxregistrylog = new Q3ListBox(CRegistryProgressBaseDialog);
        m_listboxregistrylog->setObjectName(QString::fromUtf8("m_listboxregistrylog"));
        m_listboxregistrylog->setCurrentItem(-1);
        m_listboxregistrylog->setSelectionMode(Q3ListBox::NoSelection);

        gridLayout->addWidget(m_listboxregistrylog, 0, 0, 1, 1);


        retranslateUi(CRegistryProgressBaseDialog);
        QObject::connect(m_pushbuttonok, SIGNAL(clicked()), CRegistryProgressBaseDialog, SLOT(pushbuttonok_clicked()));
        QObject::connect(m_pushbuttonpause, SIGNAL(clicked()), CRegistryProgressBaseDialog, SLOT(pushbuttonpause_clicked()));
        QObject::connect(m_pushbuttoncancel, SIGNAL(clicked()), CRegistryProgressBaseDialog, SLOT(pushbuttoncancel_clicked()));
        QObject::connect(m_pushbuttonsave, SIGNAL(clicked()), CRegistryProgressBaseDialog, SLOT(pushbuttonsave_clicked()));

        QMetaObject::connectSlotsByName(CRegistryProgressBaseDialog);
    } // setupUi

    void retranslateUi(QDialog *CRegistryProgressBaseDialog)
    {
        CRegistryProgressBaseDialog->setWindowTitle(QApplication::translate("CRegistryProgressBaseDialog", "Download Registry Log", 0, QApplication::UnicodeUTF8));
        m_pushbuttonsave->setText(QApplication::translate("CRegistryProgressBaseDialog", "Save", 0, QApplication::UnicodeUTF8));
        m_pushbuttoncancel->setText(QApplication::translate("CRegistryProgressBaseDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        m_pushbuttonpause->setText(QApplication::translate("CRegistryProgressBaseDialog", "Pause", 0, QApplication::UnicodeUTF8));
        m_pushbuttonok->setText(QApplication::translate("CRegistryProgressBaseDialog", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CRegistryProgressBaseDialog: public Ui_CRegistryProgressBaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRYPROGRESSBASEDLG_H
