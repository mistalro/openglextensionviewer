/********************************************************************************
** Form generated from reading UI file 'headerdownloadprogressbasedlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEADERDOWNLOADPROGRESSBASEDLG_H
#define UI_HEADERDOWNLOADPROGRESSBASEDLG_H

#include <Qt3Support/Q3Frame>
#include <Qt3Support/Q3ListBox>
#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CHeaderDownloadProgressBaseDialog
{
public:
    QVBoxLayout *vboxLayout;
    Q3ListBox *m_listboxlog;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacer1;
    QPushButton *m_pushbuttoncancel;
    QPushButton *m_pushbuttonpause;
    QPushButton *m_pushbuttonok;

    void setupUi(QDialog *CHeaderDownloadProgressBaseDialog)
    {
        if (CHeaderDownloadProgressBaseDialog->objectName().isEmpty())
            CHeaderDownloadProgressBaseDialog->setObjectName(QString::fromUtf8("CHeaderDownloadProgressBaseDialog"));
        CHeaderDownloadProgressBaseDialog->resize(365, 274);
        vboxLayout = new QVBoxLayout(CHeaderDownloadProgressBaseDialog);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        m_listboxlog = new Q3ListBox(CHeaderDownloadProgressBaseDialog);
        m_listboxlog->setObjectName(QString::fromUtf8("m_listboxlog"));
        m_listboxlog->setCurrentItem(-1);

        vboxLayout->addWidget(m_listboxlog);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        spacer1 = new QSpacerItem(314, 30, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer1);

        m_pushbuttoncancel = new QPushButton(CHeaderDownloadProgressBaseDialog);
        m_pushbuttoncancel->setObjectName(QString::fromUtf8("m_pushbuttoncancel"));
        m_pushbuttoncancel->setDefault(false);

        hboxLayout->addWidget(m_pushbuttoncancel);

        m_pushbuttonpause = new QPushButton(CHeaderDownloadProgressBaseDialog);
        m_pushbuttonpause->setObjectName(QString::fromUtf8("m_pushbuttonpause"));
        m_pushbuttonpause->setDefault(false);

        hboxLayout->addWidget(m_pushbuttonpause);

        m_pushbuttonok = new QPushButton(CHeaderDownloadProgressBaseDialog);
        m_pushbuttonok->setObjectName(QString::fromUtf8("m_pushbuttonok"));
        m_pushbuttonok->setDefault(true);

        hboxLayout->addWidget(m_pushbuttonok);


        vboxLayout->addLayout(hboxLayout);


        retranslateUi(CHeaderDownloadProgressBaseDialog);
        QObject::connect(m_pushbuttoncancel, SIGNAL(clicked()), CHeaderDownloadProgressBaseDialog, SLOT(pushbuttoncancel_clicked()));
        QObject::connect(m_pushbuttonpause, SIGNAL(clicked()), CHeaderDownloadProgressBaseDialog, SLOT(pushbuttonpause_clicked()));
        QObject::connect(m_pushbuttonok, SIGNAL(clicked()), CHeaderDownloadProgressBaseDialog, SLOT(pushbuttonok_clicked()));

        QMetaObject::connectSlotsByName(CHeaderDownloadProgressBaseDialog);
    } // setupUi

    void retranslateUi(QDialog *CHeaderDownloadProgressBaseDialog)
    {
        CHeaderDownloadProgressBaseDialog->setWindowTitle(QApplication::translate("CHeaderDownloadProgressBaseDialog", "Download Header Files Log", 0, QApplication::UnicodeUTF8));
        m_pushbuttoncancel->setText(QApplication::translate("CHeaderDownloadProgressBaseDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        m_pushbuttonpause->setText(QApplication::translate("CHeaderDownloadProgressBaseDialog", "Pause", 0, QApplication::UnicodeUTF8));
        m_pushbuttonok->setText(QApplication::translate("CHeaderDownloadProgressBaseDialog", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CHeaderDownloadProgressBaseDialog: public Ui_CHeaderDownloadProgressBaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEADERDOWNLOADPROGRESSBASEDLG_H
