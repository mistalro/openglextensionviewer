/********************************************************************************
** Form generated from reading UI file 'headerfileprogressbasedlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEADERFILEPROGRESSBASEDLG_H
#define UI_HEADERFILEPROGRESSBASEDLG_H

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
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CHeaderFileProgressBaseDialog
{
public:
    QVBoxLayout *vboxLayout;
    QGridLayout *gridLayout;
    QLineEdit *m_editextensionstring;
    QLabel *m_textreadingheaderfile;
    QLineEdit *m_editheaderfile;
    QLabel *m_textreadingextension;
    QProgressBar *m_progressheaderfile;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacer1;
    QPushButton *m_pushbuttoncancel;
    QSpacerItem *spacer2;

    void setupUi(QDialog *CHeaderFileProgressBaseDialog)
    {
        if (CHeaderFileProgressBaseDialog->objectName().isEmpty())
            CHeaderFileProgressBaseDialog->setObjectName(QString::fromUtf8("CHeaderFileProgressBaseDialog"));
        CHeaderFileProgressBaseDialog->resize(496, 154);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CHeaderFileProgressBaseDialog->sizePolicy().hasHeightForWidth());
        CHeaderFileProgressBaseDialog->setSizePolicy(sizePolicy);
        CHeaderFileProgressBaseDialog->setMaximumSize(QSize(32767, 32767));
        vboxLayout = new QVBoxLayout(CHeaderFileProgressBaseDialog);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_editextensionstring = new QLineEdit(CHeaderFileProgressBaseDialog);
        m_editextensionstring->setObjectName(QString::fromUtf8("m_editextensionstring"));
        m_editextensionstring->setReadOnly(true);

        gridLayout->addWidget(m_editextensionstring, 1, 1, 1, 1);

        m_textreadingheaderfile = new QLabel(CHeaderFileProgressBaseDialog);
        m_textreadingheaderfile->setObjectName(QString::fromUtf8("m_textreadingheaderfile"));
        m_textreadingheaderfile->setWordWrap(false);

        gridLayout->addWidget(m_textreadingheaderfile, 0, 0, 1, 1);

        m_editheaderfile = new QLineEdit(CHeaderFileProgressBaseDialog);
        m_editheaderfile->setObjectName(QString::fromUtf8("m_editheaderfile"));
        m_editheaderfile->setReadOnly(true);

        gridLayout->addWidget(m_editheaderfile, 0, 1, 1, 1);

        m_textreadingextension = new QLabel(CHeaderFileProgressBaseDialog);
        m_textreadingextension->setObjectName(QString::fromUtf8("m_textreadingextension"));
        m_textreadingextension->setWordWrap(false);

        gridLayout->addWidget(m_textreadingextension, 1, 0, 1, 1);


        vboxLayout->addLayout(gridLayout);

        m_progressheaderfile = new QProgressBar(CHeaderFileProgressBaseDialog);
        m_progressheaderfile->setObjectName(QString::fromUtf8("m_progressheaderfile"));

        vboxLayout->addWidget(m_progressheaderfile);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        spacer1 = new QSpacerItem(190, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer1);

        m_pushbuttoncancel = new QPushButton(CHeaderFileProgressBaseDialog);
        m_pushbuttoncancel->setObjectName(QString::fromUtf8("m_pushbuttoncancel"));

        hboxLayout->addWidget(m_pushbuttoncancel);

        spacer2 = new QSpacerItem(189, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer2);


        vboxLayout->addLayout(hboxLayout);


        retranslateUi(CHeaderFileProgressBaseDialog);
        QObject::connect(m_pushbuttoncancel, SIGNAL(clicked()), CHeaderFileProgressBaseDialog, SLOT(pushbuttoncancel_clicked()));

        QMetaObject::connectSlotsByName(CHeaderFileProgressBaseDialog);
    } // setupUi

    void retranslateUi(QDialog *CHeaderFileProgressBaseDialog)
    {
        CHeaderFileProgressBaseDialog->setWindowTitle(QApplication::translate("CHeaderFileProgressBaseDialog", "Reading Header Files", 0, QApplication::UnicodeUTF8));
        m_textreadingheaderfile->setText(QApplication::translate("CHeaderFileProgressBaseDialog", "Current header file", 0, QApplication::UnicodeUTF8));
        m_textreadingextension->setText(QApplication::translate("CHeaderFileProgressBaseDialog", "Current extension", 0, QApplication::UnicodeUTF8));
        m_pushbuttoncancel->setText(QApplication::translate("CHeaderFileProgressBaseDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        m_pushbuttoncancel->setShortcut(QString());
    } // retranslateUi

};

namespace Ui {
    class CHeaderFileProgressBaseDialog: public Ui_CHeaderFileProgressBaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEADERFILEPROGRESSBASEDLG_H
