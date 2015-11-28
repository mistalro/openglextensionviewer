/********************************************************************************
** Form generated from reading UI file 'outputfilesettingsbasedlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTPUTFILESETTINGSBASEDLG_H
#define UI_OUTPUTFILESETTINGSBASEDLG_H

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
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_COutputFileSettingsBaseDialog
{
public:
    QGridLayout *gridLayout;
    Q3GroupBox *m_groupboxscriptfiletype;
    QGridLayout *gridLayout1;
    QLabel *m_textscriptfiletype;
    QLabel *m_textexternalscript;
    QPushButton *m_pushbuttonexternalbrowse;
    QSpacerItem *spacer2_2;
    QHBoxLayout *hboxLayout;
    QRadioButton *m_radiointernal;
    QRadioButton *m_radioexternal;
    QSpacerItem *spacer15_2;
    QLineEdit *m_editexternalscript;
    Q3GroupBox *m_groupboxoutputfiles;
    QGridLayout *gridLayout2;
    QPushButton *m_pushbuttonheaderbrowse;
    QHBoxLayout *hboxLayout1;
    QRadioButton *m_radioc;
    QRadioButton *m_radiocpp;
    QSpacerItem *spacer14_2;
    QLabel *m_textoutputheader;
    QSpacerItem *spacer12;
    QSpacerItem *spacer10;
    QPushButton *m_pushbuttonsourcebrowse;
    QLineEdit *m_editoutputsourcefile;
    QLineEdit *m_editoutputclassname;
    QLineEdit *m_editoutputheaderfile;
    QLabel *m_textoutputlanguage;
    QLabel *m_textoutputclass;
    QLabel *m_textoutputsource;
    QHBoxLayout *hboxLayout2;
    QPushButton *m_pushbuttonreset;
    QSpacerItem *spacer48;
    QPushButton *m_pushbuttoncancel;
    QPushButton *m_pushbuttonapply;
    QPushButton *m_pushbuttonok;

    void setupUi(QDialog *COutputFileSettingsBaseDialog)
    {
        if (COutputFileSettingsBaseDialog->objectName().isEmpty())
            COutputFileSettingsBaseDialog->setObjectName(QString::fromUtf8("COutputFileSettingsBaseDialog"));
        COutputFileSettingsBaseDialog->resize(714, 341);
        gridLayout = new QGridLayout(COutputFileSettingsBaseDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_groupboxscriptfiletype = new Q3GroupBox(COutputFileSettingsBaseDialog);
        m_groupboxscriptfiletype->setObjectName(QString::fromUtf8("m_groupboxscriptfiletype"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_groupboxscriptfiletype->sizePolicy().hasHeightForWidth());
        m_groupboxscriptfiletype->setSizePolicy(sizePolicy);
        m_groupboxscriptfiletype->setColumnLayout(0, Qt::Vertical);
        m_groupboxscriptfiletype->layout()->setSpacing(6);
        m_groupboxscriptfiletype->layout()->setContentsMargins(11, 11, 11, 11);
        gridLayout1 = new QGridLayout();
        QBoxLayout *boxlayout = qobject_cast<QBoxLayout *>(m_groupboxscriptfiletype->layout());
        if (boxlayout)
            boxlayout->addLayout(gridLayout1);
        gridLayout1->setAlignment(Qt::AlignTop);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        m_textscriptfiletype = new QLabel(m_groupboxscriptfiletype);
        m_textscriptfiletype->setObjectName(QString::fromUtf8("m_textscriptfiletype"));
        m_textscriptfiletype->setWordWrap(false);

        gridLayout1->addWidget(m_textscriptfiletype, 0, 0, 1, 1);

        m_textexternalscript = new QLabel(m_groupboxscriptfiletype);
        m_textexternalscript->setObjectName(QString::fromUtf8("m_textexternalscript"));
        m_textexternalscript->setWordWrap(false);

        gridLayout1->addWidget(m_textexternalscript, 1, 0, 1, 1);

        m_pushbuttonexternalbrowse = new QPushButton(m_groupboxscriptfiletype);
        m_pushbuttonexternalbrowse->setObjectName(QString::fromUtf8("m_pushbuttonexternalbrowse"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_pushbuttonexternalbrowse->sizePolicy().hasHeightForWidth());
        m_pushbuttonexternalbrowse->setSizePolicy(sizePolicy1);
        m_pushbuttonexternalbrowse->setAutoDefault(false);

        gridLayout1->addWidget(m_pushbuttonexternalbrowse, 1, 2, 1, 1);

        spacer2_2 = new QSpacerItem(80, 31, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout1->addItem(spacer2_2, 0, 2, 1, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        m_radiointernal = new QRadioButton(m_groupboxscriptfiletype);
        m_radiointernal->setObjectName(QString::fromUtf8("m_radiointernal"));

        hboxLayout->addWidget(m_radiointernal);

        m_radioexternal = new QRadioButton(m_groupboxscriptfiletype);
        m_radioexternal->setObjectName(QString::fromUtf8("m_radioexternal"));

        hboxLayout->addWidget(m_radioexternal);

        spacer15_2 = new QSpacerItem(210, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer15_2);


        gridLayout1->addLayout(hboxLayout, 0, 1, 1, 1);

        m_editexternalscript = new QLineEdit(m_groupboxscriptfiletype);
        m_editexternalscript->setObjectName(QString::fromUtf8("m_editexternalscript"));

        gridLayout1->addWidget(m_editexternalscript, 1, 1, 1, 1);


        gridLayout->addWidget(m_groupboxscriptfiletype, 0, 0, 1, 1);

        m_groupboxoutputfiles = new Q3GroupBox(COutputFileSettingsBaseDialog);
        m_groupboxoutputfiles->setObjectName(QString::fromUtf8("m_groupboxoutputfiles"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(m_groupboxoutputfiles->sizePolicy().hasHeightForWidth());
        m_groupboxoutputfiles->setSizePolicy(sizePolicy2);
        m_groupboxoutputfiles->setColumnLayout(0, Qt::Vertical);
        m_groupboxoutputfiles->layout()->setSpacing(6);
        m_groupboxoutputfiles->layout()->setContentsMargins(11, 11, 11, 11);
        gridLayout2 = new QGridLayout();
        QBoxLayout *boxlayout1 = qobject_cast<QBoxLayout *>(m_groupboxoutputfiles->layout());
        if (boxlayout1)
            boxlayout1->addLayout(gridLayout2);
        gridLayout2->setAlignment(Qt::AlignTop);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        m_pushbuttonheaderbrowse = new QPushButton(m_groupboxoutputfiles);
        m_pushbuttonheaderbrowse->setObjectName(QString::fromUtf8("m_pushbuttonheaderbrowse"));
        sizePolicy1.setHeightForWidth(m_pushbuttonheaderbrowse->sizePolicy().hasHeightForWidth());
        m_pushbuttonheaderbrowse->setSizePolicy(sizePolicy1);
        m_pushbuttonheaderbrowse->setAutoDefault(false);

        gridLayout2->addWidget(m_pushbuttonheaderbrowse, 0, 2, 1, 1);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        m_radioc = new QRadioButton(m_groupboxoutputfiles);
        m_radioc->setObjectName(QString::fromUtf8("m_radioc"));

        hboxLayout1->addWidget(m_radioc);

        m_radiocpp = new QRadioButton(m_groupboxoutputfiles);
        m_radiocpp->setObjectName(QString::fromUtf8("m_radiocpp"));

        hboxLayout1->addWidget(m_radiocpp);

        spacer14_2 = new QSpacerItem(301, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacer14_2);


        gridLayout2->addLayout(hboxLayout1, 3, 1, 1, 1);

        m_textoutputheader = new QLabel(m_groupboxoutputfiles);
        m_textoutputheader->setObjectName(QString::fromUtf8("m_textoutputheader"));
        m_textoutputheader->setWordWrap(false);

        gridLayout2->addWidget(m_textoutputheader, 0, 0, 1, 1);

        spacer12 = new QSpacerItem(82, 31, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout2->addItem(spacer12, 2, 2, 1, 1);

        spacer10 = new QSpacerItem(82, 31, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout2->addItem(spacer10, 3, 2, 1, 1);

        m_pushbuttonsourcebrowse = new QPushButton(m_groupboxoutputfiles);
        m_pushbuttonsourcebrowse->setObjectName(QString::fromUtf8("m_pushbuttonsourcebrowse"));
        sizePolicy1.setHeightForWidth(m_pushbuttonsourcebrowse->sizePolicy().hasHeightForWidth());
        m_pushbuttonsourcebrowse->setSizePolicy(sizePolicy1);
        m_pushbuttonsourcebrowse->setAutoDefault(false);

        gridLayout2->addWidget(m_pushbuttonsourcebrowse, 1, 2, 1, 1);

        m_editoutputsourcefile = new QLineEdit(m_groupboxoutputfiles);
        m_editoutputsourcefile->setObjectName(QString::fromUtf8("m_editoutputsourcefile"));

        gridLayout2->addWidget(m_editoutputsourcefile, 1, 1, 1, 1);

        m_editoutputclassname = new QLineEdit(m_groupboxoutputfiles);
        m_editoutputclassname->setObjectName(QString::fromUtf8("m_editoutputclassname"));

        gridLayout2->addWidget(m_editoutputclassname, 2, 1, 1, 1);

        m_editoutputheaderfile = new QLineEdit(m_groupboxoutputfiles);
        m_editoutputheaderfile->setObjectName(QString::fromUtf8("m_editoutputheaderfile"));

        gridLayout2->addWidget(m_editoutputheaderfile, 0, 1, 1, 1);

        m_textoutputlanguage = new QLabel(m_groupboxoutputfiles);
        m_textoutputlanguage->setObjectName(QString::fromUtf8("m_textoutputlanguage"));
        m_textoutputlanguage->setWordWrap(false);

        gridLayout2->addWidget(m_textoutputlanguage, 3, 0, 1, 1);

        m_textoutputclass = new QLabel(m_groupboxoutputfiles);
        m_textoutputclass->setObjectName(QString::fromUtf8("m_textoutputclass"));
        m_textoutputclass->setWordWrap(false);

        gridLayout2->addWidget(m_textoutputclass, 2, 0, 1, 1);

        m_textoutputsource = new QLabel(m_groupboxoutputfiles);
        m_textoutputsource->setObjectName(QString::fromUtf8("m_textoutputsource"));
        m_textoutputsource->setWordWrap(false);

        gridLayout2->addWidget(m_textoutputsource, 1, 0, 1, 1);


        gridLayout->addWidget(m_groupboxoutputfiles, 1, 0, 1, 1);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        m_pushbuttonreset = new QPushButton(COutputFileSettingsBaseDialog);
        m_pushbuttonreset->setObjectName(QString::fromUtf8("m_pushbuttonreset"));
        m_pushbuttonreset->setAutoDefault(false);

        hboxLayout2->addWidget(m_pushbuttonreset);

        spacer48 = new QSpacerItem(80, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacer48);

        m_pushbuttoncancel = new QPushButton(COutputFileSettingsBaseDialog);
        m_pushbuttoncancel->setObjectName(QString::fromUtf8("m_pushbuttoncancel"));
        m_pushbuttoncancel->setAutoDefault(false);

        hboxLayout2->addWidget(m_pushbuttoncancel);

        m_pushbuttonapply = new QPushButton(COutputFileSettingsBaseDialog);
        m_pushbuttonapply->setObjectName(QString::fromUtf8("m_pushbuttonapply"));
        m_pushbuttonapply->setAutoDefault(false);

        hboxLayout2->addWidget(m_pushbuttonapply);

        m_pushbuttonok = new QPushButton(COutputFileSettingsBaseDialog);
        m_pushbuttonok->setObjectName(QString::fromUtf8("m_pushbuttonok"));

        hboxLayout2->addWidget(m_pushbuttonok);


        gridLayout->addLayout(hboxLayout2, 2, 0, 1, 1);


        retranslateUi(COutputFileSettingsBaseDialog);
        QObject::connect(m_radiointernal, SIGNAL(clicked()), COutputFileSettingsBaseDialog, SLOT(radiointernal_clicked()));
        QObject::connect(m_radioexternal, SIGNAL(clicked()), COutputFileSettingsBaseDialog, SLOT(radioexternal_clicked()));
        QObject::connect(m_editexternalscript, SIGNAL(textEdited(QString)), COutputFileSettingsBaseDialog, SLOT(editexternalscript_textChanged(QString)));
        QObject::connect(m_pushbuttonexternalbrowse, SIGNAL(clicked()), COutputFileSettingsBaseDialog, SLOT(pushbuttonexternalbrowse_clicked()));
        QObject::connect(m_pushbuttonreset, SIGNAL(clicked()), COutputFileSettingsBaseDialog, SLOT(pushbuttonreset_clicked()));
        QObject::connect(m_pushbuttoncancel, SIGNAL(clicked()), COutputFileSettingsBaseDialog, SLOT(pushbuttonreset_clicked()));
        QObject::connect(m_pushbuttonapply, SIGNAL(clicked()), COutputFileSettingsBaseDialog, SLOT(pushbuttonapply_clicked()));
        QObject::connect(m_pushbuttonok, SIGNAL(clicked()), COutputFileSettingsBaseDialog, SLOT(pushbuttonok_clicked()));
        QObject::connect(m_radioc, SIGNAL(clicked()), COutputFileSettingsBaseDialog, SLOT(radioc_clicked()));
        QObject::connect(m_radiocpp, SIGNAL(clicked()), COutputFileSettingsBaseDialog, SLOT(radiocpp_clicked()));
        QObject::connect(m_editoutputheaderfile, SIGNAL(textEdited(QString)), COutputFileSettingsBaseDialog, SLOT(editoutputheaderfile_textChanged(QString)));
        QObject::connect(m_editoutputsourcefile, SIGNAL(textChanged(QString)), COutputFileSettingsBaseDialog, SLOT(editoutputsourcefile_textChanged(QString)));
        QObject::connect(m_editoutputclassname, SIGNAL(textChanged(QString)), COutputFileSettingsBaseDialog, SLOT(editoutputclassname_textChanged(QString)));
        QObject::connect(m_pushbuttonheaderbrowse, SIGNAL(clicked()), COutputFileSettingsBaseDialog, SLOT(pushbuttonheaderbrowse_clicked()));
        QObject::connect(m_pushbuttonsourcebrowse, SIGNAL(clicked()), COutputFileSettingsBaseDialog, SLOT(pushbuttonsourcebrowse_clicked()));
        QObject::connect(m_editexternalscript, SIGNAL(textChanged(QString)), COutputFileSettingsBaseDialog, SLOT(editexternalscript_textChanged(QString)));
        QObject::connect(m_editoutputheaderfile, SIGNAL(textChanged(QString)), COutputFileSettingsBaseDialog, SLOT(editoutputheaderfile_textChanged(QString)));
        QObject::connect(m_editoutputsourcefile, SIGNAL(textChanged(QString)), COutputFileSettingsBaseDialog, SLOT(editoutputsourcefile_textChanged(QString)));
        QObject::connect(m_pushbuttoncancel, SIGNAL(clicked()), COutputFileSettingsBaseDialog, SLOT(pushbuttoncancel_clicked()));
        QObject::connect(m_pushbuttonapply, SIGNAL(clicked()), COutputFileSettingsBaseDialog, SLOT(pushbuttonapply_clicked()));
        QObject::connect(m_pushbuttonok, SIGNAL(clicked()), COutputFileSettingsBaseDialog, SLOT(pushbuttonok_clicked()));

        QMetaObject::connectSlotsByName(COutputFileSettingsBaseDialog);
    } // setupUi

    void retranslateUi(QDialog *COutputFileSettingsBaseDialog)
    {
        COutputFileSettingsBaseDialog->setWindowTitle(QApplication::translate("COutputFileSettingsBaseDialog", "Output File Settings", 0, QApplication::UnicodeUTF8));
        m_groupboxscriptfiletype->setTitle(QString());
        m_textscriptfiletype->setText(QApplication::translate("COutputFileSettingsBaseDialog", "Script file type", 0, QApplication::UnicodeUTF8));
        m_textexternalscript->setText(QApplication::translate("COutputFileSettingsBaseDialog", "External script file", 0, QApplication::UnicodeUTF8));
        m_pushbuttonexternalbrowse->setText(QApplication::translate("COutputFileSettingsBaseDialog", "Browse", 0, QApplication::UnicodeUTF8));
        m_radiointernal->setText(QApplication::translate("COutputFileSettingsBaseDialog", "Internal", 0, QApplication::UnicodeUTF8));
        m_radioexternal->setText(QApplication::translate("COutputFileSettingsBaseDialog", "External", 0, QApplication::UnicodeUTF8));
        m_groupboxoutputfiles->setTitle(QString());
        m_pushbuttonheaderbrowse->setText(QApplication::translate("COutputFileSettingsBaseDialog", "Browse", 0, QApplication::UnicodeUTF8));
        m_radioc->setText(QApplication::translate("COutputFileSettingsBaseDialog", "C", 0, QApplication::UnicodeUTF8));
        m_radiocpp->setText(QApplication::translate("COutputFileSettingsBaseDialog", "C++", 0, QApplication::UnicodeUTF8));
        m_textoutputheader->setText(QApplication::translate("COutputFileSettingsBaseDialog", "Output header file", 0, QApplication::UnicodeUTF8));
        m_pushbuttonsourcebrowse->setText(QApplication::translate("COutputFileSettingsBaseDialog", "Browse", 0, QApplication::UnicodeUTF8));
        m_textoutputlanguage->setText(QApplication::translate("COutputFileSettingsBaseDialog", "Output language", 0, QApplication::UnicodeUTF8));
        m_textoutputclass->setText(QApplication::translate("COutputFileSettingsBaseDialog", "Output class name", 0, QApplication::UnicodeUTF8));
        m_textoutputsource->setText(QApplication::translate("COutputFileSettingsBaseDialog", "Output source file", 0, QApplication::UnicodeUTF8));
        m_pushbuttonreset->setText(QApplication::translate("COutputFileSettingsBaseDialog", "Reset", 0, QApplication::UnicodeUTF8));
        m_pushbuttoncancel->setText(QApplication::translate("COutputFileSettingsBaseDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        m_pushbuttonapply->setText(QApplication::translate("COutputFileSettingsBaseDialog", "Apply", 0, QApplication::UnicodeUTF8));
        m_pushbuttonok->setText(QApplication::translate("COutputFileSettingsBaseDialog", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class COutputFileSettingsBaseDialog: public Ui_COutputFileSettingsBaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTPUTFILESETTINGSBASEDLG_H
