/********************************************************************************
** Form generated from reading UI file 'checksystemprogressbasedlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKSYSTEMPROGRESSBASEDLG_H
#define UI_CHECKSYSTEMPROGRESSBASEDLG_H

#include <Qt3Support/Q3GroupBox>
#include <Qt3Support/Q3MimeSourceFactory>
#include <Qt3Support/Q3ProgressBar>
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
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CCheckSystemProgressBaseDialog
{
public:
    QGridLayout *gridLayout;
    Q3GroupBox *m_groupbox;
    QGridLayout *gridLayout1;
    QHBoxLayout *hboxLayout;
    QLabel *m_textlabelprogress;
    QSpacerItem *spacer1;
    QLineEdit *m_lineeditcount;
    Q3ProgressBar *m_progressbar;

    void setupUi(QDialog *CCheckSystemProgressBaseDialog)
    {
        if (CCheckSystemProgressBaseDialog->objectName().isEmpty())
            CCheckSystemProgressBaseDialog->setObjectName(QString::fromUtf8("CCheckSystemProgressBaseDialog"));
        CCheckSystemProgressBaseDialog->resize(266, 120);
        gridLayout = new QGridLayout(CCheckSystemProgressBaseDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_groupbox = new Q3GroupBox(CCheckSystemProgressBaseDialog);
        m_groupbox->setObjectName(QString::fromUtf8("m_groupbox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_groupbox->sizePolicy().hasHeightForWidth());
        m_groupbox->setSizePolicy(sizePolicy);
        m_groupbox->setColumnLayout(0, Qt::Vertical);
        m_groupbox->layout()->setSpacing(6);
        m_groupbox->layout()->setContentsMargins(11, 11, 11, 11);
        gridLayout1 = new QGridLayout();
        QBoxLayout *boxlayout = qobject_cast<QBoxLayout *>(m_groupbox->layout());
        if (boxlayout)
            boxlayout->addLayout(gridLayout1);
        gridLayout1->setAlignment(Qt::AlignTop);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        m_textlabelprogress = new QLabel(m_groupbox);
        m_textlabelprogress->setObjectName(QString::fromUtf8("m_textlabelprogress"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_textlabelprogress->sizePolicy().hasHeightForWidth());
        m_textlabelprogress->setSizePolicy(sizePolicy1);
        m_textlabelprogress->setWordWrap(false);

        hboxLayout->addWidget(m_textlabelprogress);

        spacer1 = new QSpacerItem(40, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer1);

        m_lineeditcount = new QLineEdit(m_groupbox);
        m_lineeditcount->setObjectName(QString::fromUtf8("m_lineeditcount"));
        sizePolicy.setHeightForWidth(m_lineeditcount->sizePolicy().hasHeightForWidth());
        m_lineeditcount->setSizePolicy(sizePolicy);
        m_lineeditcount->setAlignment(Qt::AlignHCenter);

        hboxLayout->addWidget(m_lineeditcount);


        gridLayout1->addLayout(hboxLayout, 0, 0, 1, 1);

        m_progressbar = new Q3ProgressBar(m_groupbox);
        m_progressbar->setObjectName(QString::fromUtf8("m_progressbar"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(m_progressbar->sizePolicy().hasHeightForWidth());
        m_progressbar->setSizePolicy(sizePolicy2);

        gridLayout1->addWidget(m_progressbar, 1, 0, 1, 1);


        gridLayout->addWidget(m_groupbox, 0, 0, 1, 1);


        retranslateUi(CCheckSystemProgressBaseDialog);

        QMetaObject::connectSlotsByName(CCheckSystemProgressBaseDialog);
    } // setupUi

    void retranslateUi(QDialog *CCheckSystemProgressBaseDialog)
    {
        CCheckSystemProgressBaseDialog->setWindowTitle(QApplication::translate("CCheckSystemProgressBaseDialog", "Examining Pixel Format List", 0, QApplication::UnicodeUTF8));
        m_groupbox->setTitle(QString());
        m_textlabelprogress->setText(QApplication::translate("CCheckSystemProgressBaseDialog", "Checking pixel format", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CCheckSystemProgressBaseDialog: public Ui_CCheckSystemProgressBaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKSYSTEMPROGRESSBASEDLG_H
