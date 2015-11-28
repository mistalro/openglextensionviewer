/********************************************************************************
** Form generated from reading UI file 'registryfileprogressbasedlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRYFILEPROGRESSBASEDLG_H
#define UI_REGISTRYFILEPROGRESSBASEDLG_H

#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CRegistryFileProgressBaseDialog
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QLabel *textLabel9;
    QLineEdit *m_editregistryfile;
    QLineEdit *m_editextensionstring;
    QProgressBar *m_progressbar;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacer2;
    QPushButton *m_pushbuttoncancel;
    QSpacerItem *spacer1;

    void setupUi(QDialog *CRegistryFileProgressBaseDialog)
    {
        if (CRegistryFileProgressBaseDialog->objectName().isEmpty())
            CRegistryFileProgressBaseDialog->setObjectName(QString::fromUtf8("CRegistryFileProgressBaseDialog"));
        CRegistryFileProgressBaseDialog->resize(289, 173);
        vboxLayout = new QVBoxLayout(CRegistryFileProgressBaseDialog);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        textLabel9 = new QLabel(CRegistryFileProgressBaseDialog);
        textLabel9->setObjectName(QString::fromUtf8("textLabel9"));
        textLabel9->setWordWrap(false);

        hboxLayout->addWidget(textLabel9);

        m_editregistryfile = new QLineEdit(CRegistryFileProgressBaseDialog);
        m_editregistryfile->setObjectName(QString::fromUtf8("m_editregistryfile"));

        hboxLayout->addWidget(m_editregistryfile);


        vboxLayout->addLayout(hboxLayout);

        m_editextensionstring = new QLineEdit(CRegistryFileProgressBaseDialog);
        m_editextensionstring->setObjectName(QString::fromUtf8("m_editextensionstring"));

        vboxLayout->addWidget(m_editextensionstring);

        m_progressbar = new QProgressBar(CRegistryFileProgressBaseDialog);
        m_progressbar->setObjectName(QString::fromUtf8("m_progressbar"));

        vboxLayout->addWidget(m_progressbar);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        spacer2 = new QSpacerItem(80, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacer2);

        m_pushbuttoncancel = new QPushButton(CRegistryFileProgressBaseDialog);
        m_pushbuttoncancel->setObjectName(QString::fromUtf8("m_pushbuttoncancel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_pushbuttoncancel->sizePolicy().hasHeightForWidth());
        m_pushbuttoncancel->setSizePolicy(sizePolicy);

        hboxLayout1->addWidget(m_pushbuttoncancel);

        spacer1 = new QSpacerItem(70, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacer1);


        vboxLayout->addLayout(hboxLayout1);


        retranslateUi(CRegistryFileProgressBaseDialog);

        QMetaObject::connectSlotsByName(CRegistryFileProgressBaseDialog);
    } // setupUi

    void retranslateUi(QDialog *CRegistryFileProgressBaseDialog)
    {
        CRegistryFileProgressBaseDialog->setWindowTitle(QApplication::translate("CRegistryFileProgressBaseDialog", "Registry File Progress", 0, QApplication::UnicodeUTF8));
        textLabel9->setText(QApplication::translate("CRegistryFileProgressBaseDialog", "Reading registry file", 0, QApplication::UnicodeUTF8));
        m_pushbuttoncancel->setText(QApplication::translate("CRegistryFileProgressBaseDialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CRegistryFileProgressBaseDialog: public Ui_CRegistryFileProgressBaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRYFILEPROGRESSBASEDLG_H
