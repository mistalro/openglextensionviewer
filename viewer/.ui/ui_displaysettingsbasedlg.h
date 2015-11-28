/********************************************************************************
** Form generated from reading UI file 'displaysettingsbasedlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYSETTINGSBASEDLG_H
#define UI_DISPLAYSETTINGSBASEDLG_H

#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include "displaysettingswidget/displaysettingswidget.h"

QT_BEGIN_NAMESPACE

class Ui_CDisplaySettingsBaseDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *hboxLayout;
    QLabel *m_textdisplaymodecount;
    QLineEdit *m_editdisplaymodecount;
    QSpacerItem *spacer2;
    QLabel *m_textsortby;
    QComboBox *m_combodisplaysettings;
    QRadioButton *m_radioreversed;
    QHBoxLayout *hboxLayout1;
    QPushButton *m_pushbuttonprint;
    QPushButton *m_pushbuttonsave;
    QSpacerItem *spacer1;
    QPushButton *m_pushbuttonok;
    CDisplaySettingsListView *m_displaysettingslist;

    void setupUi(QDialog *CDisplaySettingsBaseDialog)
    {
        if (CDisplaySettingsBaseDialog->objectName().isEmpty())
            CDisplaySettingsBaseDialog->setObjectName(QString::fromUtf8("CDisplaySettingsBaseDialog"));
        CDisplaySettingsBaseDialog->resize(628, 392);
        gridLayout = new QGridLayout(CDisplaySettingsBaseDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        m_textdisplaymodecount = new QLabel(CDisplaySettingsBaseDialog);
        m_textdisplaymodecount->setObjectName(QString::fromUtf8("m_textdisplaymodecount"));
        m_textdisplaymodecount->setWordWrap(false);

        hboxLayout->addWidget(m_textdisplaymodecount);

        m_editdisplaymodecount = new QLineEdit(CDisplaySettingsBaseDialog);
        m_editdisplaymodecount->setObjectName(QString::fromUtf8("m_editdisplaymodecount"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_editdisplaymodecount->sizePolicy().hasHeightForWidth());
        m_editdisplaymodecount->setSizePolicy(sizePolicy);
        m_editdisplaymodecount->setReadOnly(true);

        hboxLayout->addWidget(m_editdisplaymodecount);

        spacer2 = new QSpacerItem(71, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer2);

        m_textsortby = new QLabel(CDisplaySettingsBaseDialog);
        m_textsortby->setObjectName(QString::fromUtf8("m_textsortby"));
        m_textsortby->setWordWrap(false);

        hboxLayout->addWidget(m_textsortby);

        m_combodisplaysettings = new QComboBox(CDisplaySettingsBaseDialog);
        m_combodisplaysettings->setObjectName(QString::fromUtf8("m_combodisplaysettings"));

        hboxLayout->addWidget(m_combodisplaysettings);

        m_radioreversed = new QRadioButton(CDisplaySettingsBaseDialog);
        m_radioreversed->setObjectName(QString::fromUtf8("m_radioreversed"));

        hboxLayout->addWidget(m_radioreversed);


        gridLayout->addLayout(hboxLayout, 0, 0, 1, 1);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        m_pushbuttonprint = new QPushButton(CDisplaySettingsBaseDialog);
        m_pushbuttonprint->setObjectName(QString::fromUtf8("m_pushbuttonprint"));
        sizePolicy.setHeightForWidth(m_pushbuttonprint->sizePolicy().hasHeightForWidth());
        m_pushbuttonprint->setSizePolicy(sizePolicy);
        m_pushbuttonprint->setMinimumSize(QSize(80, 30));

        hboxLayout1->addWidget(m_pushbuttonprint);

        m_pushbuttonsave = new QPushButton(CDisplaySettingsBaseDialog);
        m_pushbuttonsave->setObjectName(QString::fromUtf8("m_pushbuttonsave"));
        sizePolicy.setHeightForWidth(m_pushbuttonsave->sizePolicy().hasHeightForWidth());
        m_pushbuttonsave->setSizePolicy(sizePolicy);
        m_pushbuttonsave->setMinimumSize(QSize(80, 30));

        hboxLayout1->addWidget(m_pushbuttonsave);

        spacer1 = new QSpacerItem(365, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacer1);

        m_pushbuttonok = new QPushButton(CDisplaySettingsBaseDialog);
        m_pushbuttonok->setObjectName(QString::fromUtf8("m_pushbuttonok"));
        sizePolicy.setHeightForWidth(m_pushbuttonok->sizePolicy().hasHeightForWidth());
        m_pushbuttonok->setSizePolicy(sizePolicy);
        m_pushbuttonok->setMinimumSize(QSize(80, 30));
        m_pushbuttonok->setDefault(true);

        hboxLayout1->addWidget(m_pushbuttonok);


        gridLayout->addLayout(hboxLayout1, 2, 0, 1, 1);

        m_displaysettingslist = new CDisplaySettingsListView(CDisplaySettingsBaseDialog);
        m_displaysettingslist->setObjectName(QString::fromUtf8("m_displaysettingslist"));

        gridLayout->addWidget(m_displaysettingslist, 1, 0, 1, 1);


        retranslateUi(CDisplaySettingsBaseDialog);
        QObject::connect(m_radioreversed, SIGNAL(toggled(bool)), CDisplaySettingsBaseDialog, SLOT(radioreversed_toggled(bool)));
        QObject::connect(m_combodisplaysettings, SIGNAL(highlighted(int)), CDisplaySettingsBaseDialog, SLOT(combodisplaysettings_highlighted(int)));
        QObject::connect(m_combodisplaysettings, SIGNAL(activated(int)), CDisplaySettingsBaseDialog, SLOT(combodisplaysettings_activated(int)));
        QObject::connect(m_displaysettingslist, SIGNAL(sortingChanged(int,bool)), CDisplaySettingsBaseDialog, SLOT(listviewdisplaysettings_sortingChanged(int,bool)));
        QObject::connect(m_pushbuttonok, SIGNAL(clicked()), CDisplaySettingsBaseDialog, SLOT(pushbuttonok_clicked()));
        QObject::connect(m_pushbuttonsave, SIGNAL(clicked()), CDisplaySettingsBaseDialog, SLOT(pushbuttonsave_clicked()));
        QObject::connect(m_pushbuttonprint, SIGNAL(clicked()), CDisplaySettingsBaseDialog, SLOT(pushbuttonprint_clicked()));

        QMetaObject::connectSlotsByName(CDisplaySettingsBaseDialog);
    } // setupUi

    void retranslateUi(QDialog *CDisplaySettingsBaseDialog)
    {
        CDisplaySettingsBaseDialog->setWindowTitle(QApplication::translate("CDisplaySettingsBaseDialog", "Display Settings", 0, QApplication::UnicodeUTF8));
        m_textdisplaymodecount->setText(QApplication::translate("CDisplaySettingsBaseDialog", "Number of Display Modes", 0, QApplication::UnicodeUTF8));
        m_textsortby->setText(QApplication::translate("CDisplaySettingsBaseDialog", "Sort by", 0, QApplication::UnicodeUTF8));
        m_combodisplaysettings->clear();
        m_combodisplaysettings->insertItems(0, QStringList()
         << QApplication::translate("CDisplaySettingsBaseDialog", "Index", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CDisplaySettingsBaseDialog", "Depth", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CDisplaySettingsBaseDialog", "Width", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CDisplaySettingsBaseDialog", "Height", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CDisplaySettingsBaseDialog", "Vertical Refresh", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CDisplaySettingsBaseDialog", "Horizontal Refresh", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CDisplaySettingsBaseDialog", "Bandwidth", 0, QApplication::UnicodeUTF8)
        );
        m_radioreversed->setText(QApplication::translate("CDisplaySettingsBaseDialog", "Reversed", 0, QApplication::UnicodeUTF8));
        m_pushbuttonprint->setText(QApplication::translate("CDisplaySettingsBaseDialog", "Print", 0, QApplication::UnicodeUTF8));
        m_pushbuttonsave->setText(QApplication::translate("CDisplaySettingsBaseDialog", "Save", 0, QApplication::UnicodeUTF8));
        m_pushbuttonok->setText(QApplication::translate("CDisplaySettingsBaseDialog", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CDisplaySettingsBaseDialog: public Ui_CDisplaySettingsBaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYSETTINGSBASEDLG_H
