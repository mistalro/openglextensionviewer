/********************************************************************************
** Form generated from reading UI file 'pixelformatbasedlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIXELFORMATBASEDLG_H
#define UI_PIXELFORMATBASEDLG_H

#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include "pixelformatwidget/pixelformatwidget.h"

QT_BEGIN_NAMESPACE

class Ui_CPixelFormatBaseDialog
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QLabel *m_textpixelformatcount;
    QLineEdit *m_pixelformatcount;
    QSpacerItem *spacer2;
    QLabel *m_textsort;
    QComboBox *m_combopixelformat;
    QRadioButton *m_radiopixelformat;
    CPixelFormatListView *m_listviewpixelformat;
    QHBoxLayout *hboxLayout1;
    QPushButton *m_pushbuttonprint;
    QPushButton *m_pushbuttonsave;
    QSpacerItem *spacer1;
    QPushButton *m_pushbuttonok;

    void setupUi(QDialog *CPixelFormatBaseDialog)
    {
        if (CPixelFormatBaseDialog->objectName().isEmpty())
            CPixelFormatBaseDialog->setObjectName(QString::fromUtf8("CPixelFormatBaseDialog"));
        CPixelFormatBaseDialog->resize(1345, 515);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CPixelFormatBaseDialog->sizePolicy().hasHeightForWidth());
        CPixelFormatBaseDialog->setSizePolicy(sizePolicy);
        vboxLayout = new QVBoxLayout(CPixelFormatBaseDialog);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        m_textpixelformatcount = new QLabel(CPixelFormatBaseDialog);
        m_textpixelformatcount->setObjectName(QString::fromUtf8("m_textpixelformatcount"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_textpixelformatcount->sizePolicy().hasHeightForWidth());
        m_textpixelformatcount->setSizePolicy(sizePolicy1);
        m_textpixelformatcount->setWordWrap(false);

        hboxLayout->addWidget(m_textpixelformatcount);

        m_pixelformatcount = new QLineEdit(CPixelFormatBaseDialog);
        m_pixelformatcount->setObjectName(QString::fromUtf8("m_pixelformatcount"));
        sizePolicy1.setHeightForWidth(m_pixelformatcount->sizePolicy().hasHeightForWidth());
        m_pixelformatcount->setSizePolicy(sizePolicy1);
        m_pixelformatcount->setMaximumSize(QSize(60, 32767));
        m_pixelformatcount->setAlignment(Qt::AlignRight);
        m_pixelformatcount->setReadOnly(true);

        hboxLayout->addWidget(m_pixelformatcount);

        spacer2 = new QSpacerItem(180, 21, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer2);

        m_textsort = new QLabel(CPixelFormatBaseDialog);
        m_textsort->setObjectName(QString::fromUtf8("m_textsort"));
        sizePolicy1.setHeightForWidth(m_textsort->sizePolicy().hasHeightForWidth());
        m_textsort->setSizePolicy(sizePolicy1);
        m_textsort->setWordWrap(false);

        hboxLayout->addWidget(m_textsort);

        m_combopixelformat = new QComboBox(CPixelFormatBaseDialog);
        m_combopixelformat->setObjectName(QString::fromUtf8("m_combopixelformat"));
        sizePolicy1.setHeightForWidth(m_combopixelformat->sizePolicy().hasHeightForWidth());
        m_combopixelformat->setSizePolicy(sizePolicy1);

        hboxLayout->addWidget(m_combopixelformat);

        m_radiopixelformat = new QRadioButton(CPixelFormatBaseDialog);
        m_radiopixelformat->setObjectName(QString::fromUtf8("m_radiopixelformat"));
        sizePolicy1.setHeightForWidth(m_radiopixelformat->sizePolicy().hasHeightForWidth());
        m_radiopixelformat->setSizePolicy(sizePolicy1);

        hboxLayout->addWidget(m_radiopixelformat);


        vboxLayout->addLayout(hboxLayout);

        m_listviewpixelformat = new CPixelFormatListView(CPixelFormatBaseDialog);
        m_listviewpixelformat->setObjectName(QString::fromUtf8("m_listviewpixelformat"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(m_listviewpixelformat->sizePolicy().hasHeightForWidth());
        m_listviewpixelformat->setSizePolicy(sizePolicy2);
        m_listviewpixelformat->setMinimumSize(QSize(100, 60));

        vboxLayout->addWidget(m_listviewpixelformat);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        m_pushbuttonprint = new QPushButton(CPixelFormatBaseDialog);
        m_pushbuttonprint->setObjectName(QString::fromUtf8("m_pushbuttonprint"));
        sizePolicy1.setHeightForWidth(m_pushbuttonprint->sizePolicy().hasHeightForWidth());
        m_pushbuttonprint->setSizePolicy(sizePolicy1);

        hboxLayout1->addWidget(m_pushbuttonprint);

        m_pushbuttonsave = new QPushButton(CPixelFormatBaseDialog);
        m_pushbuttonsave->setObjectName(QString::fromUtf8("m_pushbuttonsave"));
        sizePolicy1.setHeightForWidth(m_pushbuttonsave->sizePolicy().hasHeightForWidth());
        m_pushbuttonsave->setSizePolicy(sizePolicy1);

        hboxLayout1->addWidget(m_pushbuttonsave);

        spacer1 = new QSpacerItem(416, 30, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacer1);

        m_pushbuttonok = new QPushButton(CPixelFormatBaseDialog);
        m_pushbuttonok->setObjectName(QString::fromUtf8("m_pushbuttonok"));
        sizePolicy1.setHeightForWidth(m_pushbuttonok->sizePolicy().hasHeightForWidth());
        m_pushbuttonok->setSizePolicy(sizePolicy1);
        m_pushbuttonok->setDefault(true);

        hboxLayout1->addWidget(m_pushbuttonok);


        vboxLayout->addLayout(hboxLayout1);


        retranslateUi(CPixelFormatBaseDialog);
        QObject::connect(m_pushbuttonok, SIGNAL(clicked()), CPixelFormatBaseDialog, SLOT(pushbuttonok_clicked()));
        QObject::connect(m_pushbuttonprint, SIGNAL(clicked()), CPixelFormatBaseDialog, SLOT(pushbuttonprint_clicked()));
        QObject::connect(m_pushbuttonsave, SIGNAL(clicked()), CPixelFormatBaseDialog, SLOT(pushbuttonsave_clicked()));
        QObject::connect(m_combopixelformat, SIGNAL(activated(int)), CPixelFormatBaseDialog, SLOT(combopixelformat_activated(int)));
        QObject::connect(m_radiopixelformat, SIGNAL(toggled(bool)), CPixelFormatBaseDialog, SLOT(radiopixelformat_toggled(bool)));

        QMetaObject::connectSlotsByName(CPixelFormatBaseDialog);
    } // setupUi

    void retranslateUi(QDialog *CPixelFormatBaseDialog)
    {
        CPixelFormatBaseDialog->setWindowTitle(QApplication::translate("CPixelFormatBaseDialog", "List of available Pixel Formats", 0, QApplication::UnicodeUTF8));
        m_textpixelformatcount->setText(QApplication::translate("CPixelFormatBaseDialog", "Number of Pixel Formats:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_pixelformatcount->setToolTip(QApplication::translate("CPixelFormatBaseDialog", "Number of pixel formats available", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_textsort->setText(QApplication::translate("CPixelFormatBaseDialog", "Sort by:", 0, QApplication::UnicodeUTF8));
        m_combopixelformat->clear();
        m_combopixelformat->insertItems(0, QStringList()
         << QApplication::translate("CPixelFormatBaseDialog", "Index", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CPixelFormatBaseDialog", "Pixel type", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CPixelFormatBaseDialog", "Color bits", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CPixelFormatBaseDialog", "Red bits/shift", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CPixelFormatBaseDialog", "Green bits/shift", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CPixelFormatBaseDialog", "Blue bits/shift", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CPixelFormatBaseDialog", "Alpha bits/shift", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CPixelFormatBaseDialog", "Accumulation bits", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CPixelFormatBaseDialog", "Depth Bits", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CPixelFormatBaseDialog", "Stencil bits", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CPixelFormatBaseDialog", "Flags", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CPixelFormatBaseDialog", "Plane level", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        m_combopixelformat->setToolTip(QApplication::translate("CPixelFormatBaseDialog", "Click to select sorting order of data", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_radiopixelformat->setToolTip(QApplication::translate("CPixelFormatBaseDialog", "Click to reverse sorting order", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_radiopixelformat->setText(QApplication::translate("CPixelFormatBaseDialog", "&Reversed", 0, QApplication::UnicodeUTF8));
        m_radiopixelformat->setShortcut(QApplication::translate("CPixelFormatBaseDialog", "Alt+R", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_pushbuttonprint->setToolTip(QApplication::translate("CPixelFormatBaseDialog", "Print out this list", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_pushbuttonprint->setText(QApplication::translate("CPixelFormatBaseDialog", "&Print", 0, QApplication::UnicodeUTF8));
        m_pushbuttonprint->setShortcut(QApplication::translate("CPixelFormatBaseDialog", "Alt+P", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_pushbuttonsave->setToolTip(QApplication::translate("CPixelFormatBaseDialog", "Save this list to a file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_pushbuttonsave->setText(QApplication::translate("CPixelFormatBaseDialog", "&Save", 0, QApplication::UnicodeUTF8));
        m_pushbuttonsave->setShortcut(QApplication::translate("CPixelFormatBaseDialog", "Alt+S", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_pushbuttonok->setToolTip(QApplication::translate("CPixelFormatBaseDialog", "Click here to close window", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_pushbuttonok->setText(QApplication::translate("CPixelFormatBaseDialog", "&OK", 0, QApplication::UnicodeUTF8));
        m_pushbuttonok->setShortcut(QApplication::translate("CPixelFormatBaseDialog", "Alt+O", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CPixelFormatBaseDialog: public Ui_CPixelFormatBaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIXELFORMATBASEDLG_H
