/********************************************************************************
** Form generated from reading UI file 'registrysettingsbasedlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRYSETTINGSBASEDLG_H
#define UI_REGISTRYSETTINGSBASEDLG_H

#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <Qt3Support/Q3ListViewItemIterator>
#include "webpagelistwidget/webpagelistwidget.h"

QT_BEGIN_NAMESPACE

class Ui_CRegistrySettingsBaseDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    CWebPageListView *m_webpagelistview;
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout;
    QCheckBox *m_checkboxdownloadregistry;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLineEdit *m_lineeditfileextensionfilter;
    QCheckBox *m_checkboxdownloadheaderfiles;
    QCheckBox *m_checkboxreadheaderfiles;
    QCheckBox *m_checkboxreadextensionspec;
    QWidget *tab_4;
    QGridLayout *gridLayout;
    QLabel *m_textregistry;
    QLineEdit *m_editregistry;
    QSpacerItem *spacer16;
    QLabel *m_textregistrylocalcopy;
    QLineEdit *m_editregistrylocaldir;
    QPushButton *m_pushbuttonregistrylocaldirbrowse;
    QLabel *m_textgllocalcopy_2;
    QLineEdit *m_editregistrylocalcopy;
    QPushButton *m_pushbuttonregistrywebpagebrowse;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QLabel *m_textglheader;
    QLineEdit *m_editgl;
    QSpacerItem *spacer172;
    QLabel *m_textgllocalcopy;
    QLineEdit *m_editgllocalcopy;
    QPushButton *m_pushbuttonglbrowse;
    QLabel *m_textglversion;
    QHBoxLayout *hboxLayout;
    QLineEdit *m_editglversion;
    QSpacerItem *spacer3;
    QLabel *textLabel11;
    QLineEdit *m_editglcount;
    QSpacerItem *spacer4;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QLabel *textLabel9;
    QLineEdit *m_editglx;
    QSpacerItem *spacer19;
    QLabel *m_textglxlocalcopy;
    QLineEdit *m_editglxlocalcopy;
    QPushButton *m_pushbuttonglxbrowse;
    QLabel *m_textglxversion;
    QHBoxLayout *hboxLayout1;
    QLineEdit *m_editglxversion;
    QSpacerItem *spacer7;
    QLabel *textLabel11_13;
    QLineEdit *m_editglxcount;
    QSpacerItem *spacer8;
    QWidget *tab_3;
    QGridLayout *gridLayout_3;
    QLabel *textLabel10;
    QLineEdit *m_editwgl;
    QSpacerItem *spacer18;
    QLabel *m_textwgllocalcopy;
    QLineEdit *m_editwgllocalcopy;
    QPushButton *m_pushbuttonwglbrowse;
    QLabel *m_textwglversion;
    QHBoxLayout *hboxLayout2;
    QLineEdit *m_editwglversion;
    QSpacerItem *spacer5;
    QLabel *textLabel11_8;
    QLineEdit *m_editwglcount;
    QSpacerItem *spacer6;
    QWidget *tab_6;
    QGridLayout *gridLayout_13;
    QLabel *textLabel10_3;
    QLineEdit *m_editcorearb;
    QSpacerItem *spacer18_3;
    QLabel *m_textwgllocalcopy_3;
    QLineEdit *m_editcorearblocalcopy;
    QLabel *m_textwglversion_3;
    QHBoxLayout *_8;
    QLineEdit *m_editcorearbversion;
    QSpacerItem *spacer5_4;
    QLabel *textLabel11_11;
    QLineEdit *m_editcorearbcount;
    QSpacerItem *spacer6_4;
    QPushButton *m_pushbuttonwglbrowse_3;
    QHBoxLayout *hboxLayout3;
    QPushButton *m_pushbuttonreset;
    QSpacerItem *spacer39;
    QPushButton *m_pushbuttonremove;
    QPushButton *m_pushbuttonadd;
    QSpacerItem *spacer39_1;
    QPushButton *m_pushbuttoncancel;
    QPushButton *m_pushbuttonapply;
    QPushButton *m_pushbuttonok;

    void setupUi(QDialog *CRegistrySettingsBaseDialog)
    {
        if (CRegistrySettingsBaseDialog->objectName().isEmpty())
            CRegistrySettingsBaseDialog->setObjectName(QString::fromUtf8("CRegistrySettingsBaseDialog"));
        CRegistrySettingsBaseDialog->resize(754, 390);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CRegistrySettingsBaseDialog->sizePolicy().hasHeightForWidth());
        CRegistrySettingsBaseDialog->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(CRegistrySettingsBaseDialog);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        m_webpagelistview = new CWebPageListView(CRegistrySettingsBaseDialog);
        m_webpagelistview->setObjectName(QString::fromUtf8("m_webpagelistview"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(100);
        sizePolicy1.setVerticalStretch(100);
        sizePolicy1.setHeightForWidth(m_webpagelistview->sizePolicy().hasHeightForWidth());
        m_webpagelistview->setSizePolicy(sizePolicy1);
        m_webpagelistview->setMinimumSize(QSize(100, 100));
        m_webpagelistview->setAutoFillBackground(true);

        verticalLayout_2->addWidget(m_webpagelistview);

        tabWidget = new QTabWidget(CRegistrySettingsBaseDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        verticalLayout = new QVBoxLayout(tab_5);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_checkboxdownloadregistry = new QCheckBox(tab_5);
        m_checkboxdownloadregistry->setObjectName(QString::fromUtf8("m_checkboxdownloadregistry"));

        verticalLayout->addWidget(m_checkboxdownloadregistry);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(16, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(tab_5);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        m_lineeditfileextensionfilter = new QLineEdit(tab_5);
        m_lineeditfileextensionfilter->setObjectName(QString::fromUtf8("m_lineeditfileextensionfilter"));

        horizontalLayout->addWidget(m_lineeditfileextensionfilter);


        verticalLayout->addLayout(horizontalLayout);

        m_checkboxdownloadheaderfiles = new QCheckBox(tab_5);
        m_checkboxdownloadheaderfiles->setObjectName(QString::fromUtf8("m_checkboxdownloadheaderfiles"));

        verticalLayout->addWidget(m_checkboxdownloadheaderfiles);

        m_checkboxreadheaderfiles = new QCheckBox(tab_5);
        m_checkboxreadheaderfiles->setObjectName(QString::fromUtf8("m_checkboxreadheaderfiles"));

        verticalLayout->addWidget(m_checkboxreadheaderfiles);

        m_checkboxreadextensionspec = new QCheckBox(tab_5);
        m_checkboxreadextensionspec->setObjectName(QString::fromUtf8("m_checkboxreadextensionspec"));

        verticalLayout->addWidget(m_checkboxreadextensionspec);

        tabWidget->addTab(tab_5, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout = new QGridLayout(tab_4);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_textregistry = new QLabel(tab_4);
        m_textregistry->setObjectName(QString::fromUtf8("m_textregistry"));
        m_textregistry->setWordWrap(false);

        gridLayout->addWidget(m_textregistry, 0, 0, 1, 1);

        m_editregistry = new QLineEdit(tab_4);
        m_editregistry->setObjectName(QString::fromUtf8("m_editregistry"));

        gridLayout->addWidget(m_editregistry, 0, 1, 1, 1);

        spacer16 = new QSpacerItem(82, 22, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(spacer16, 0, 2, 1, 1);

        m_textregistrylocalcopy = new QLabel(tab_4);
        m_textregistrylocalcopy->setObjectName(QString::fromUtf8("m_textregistrylocalcopy"));
        m_textregistrylocalcopy->setWordWrap(false);

        gridLayout->addWidget(m_textregistrylocalcopy, 1, 0, 1, 1);

        m_editregistrylocaldir = new QLineEdit(tab_4);
        m_editregistrylocaldir->setObjectName(QString::fromUtf8("m_editregistrylocaldir"));

        gridLayout->addWidget(m_editregistrylocaldir, 1, 1, 1, 1);

        m_pushbuttonregistrylocaldirbrowse = new QPushButton(tab_4);
        m_pushbuttonregistrylocaldirbrowse->setObjectName(QString::fromUtf8("m_pushbuttonregistrylocaldirbrowse"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(m_pushbuttonregistrylocaldirbrowse->sizePolicy().hasHeightForWidth());
        m_pushbuttonregistrylocaldirbrowse->setSizePolicy(sizePolicy2);
        m_pushbuttonregistrylocaldirbrowse->setAutoDefault(false);

        gridLayout->addWidget(m_pushbuttonregistrylocaldirbrowse, 1, 2, 1, 1);

        m_textgllocalcopy_2 = new QLabel(tab_4);
        m_textgllocalcopy_2->setObjectName(QString::fromUtf8("m_textgllocalcopy_2"));
        m_textgllocalcopy_2->setWordWrap(false);

        gridLayout->addWidget(m_textgllocalcopy_2, 2, 0, 1, 1);

        m_editregistrylocalcopy = new QLineEdit(tab_4);
        m_editregistrylocalcopy->setObjectName(QString::fromUtf8("m_editregistrylocalcopy"));

        gridLayout->addWidget(m_editregistrylocalcopy, 2, 1, 1, 1);

        m_pushbuttonregistrywebpagebrowse = new QPushButton(tab_4);
        m_pushbuttonregistrywebpagebrowse->setObjectName(QString::fromUtf8("m_pushbuttonregistrywebpagebrowse"));
        sizePolicy2.setHeightForWidth(m_pushbuttonregistrywebpagebrowse->sizePolicy().hasHeightForWidth());
        m_pushbuttonregistrywebpagebrowse->setSizePolicy(sizePolicy2);
        m_pushbuttonregistrywebpagebrowse->setAutoDefault(false);

        gridLayout->addWidget(m_pushbuttonregistrywebpagebrowse, 2, 2, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        m_textglheader = new QLabel(tab);
        m_textglheader->setObjectName(QString::fromUtf8("m_textglheader"));
        m_textglheader->setWordWrap(false);

        gridLayout_2->addWidget(m_textglheader, 0, 0, 1, 1);

        m_editgl = new QLineEdit(tab);
        m_editgl->setObjectName(QString::fromUtf8("m_editgl"));

        gridLayout_2->addWidget(m_editgl, 0, 1, 1, 1);

        spacer172 = new QSpacerItem(82, 18, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_2->addItem(spacer172, 0, 2, 1, 1);

        m_textgllocalcopy = new QLabel(tab);
        m_textgllocalcopy->setObjectName(QString::fromUtf8("m_textgllocalcopy"));
        m_textgllocalcopy->setWordWrap(false);

        gridLayout_2->addWidget(m_textgllocalcopy, 1, 0, 1, 1);

        m_editgllocalcopy = new QLineEdit(tab);
        m_editgllocalcopy->setObjectName(QString::fromUtf8("m_editgllocalcopy"));

        gridLayout_2->addWidget(m_editgllocalcopy, 1, 1, 1, 1);

        m_pushbuttonglbrowse = new QPushButton(tab);
        m_pushbuttonglbrowse->setObjectName(QString::fromUtf8("m_pushbuttonglbrowse"));
        sizePolicy2.setHeightForWidth(m_pushbuttonglbrowse->sizePolicy().hasHeightForWidth());
        m_pushbuttonglbrowse->setSizePolicy(sizePolicy2);
        m_pushbuttonglbrowse->setAutoDefault(false);

        gridLayout_2->addWidget(m_pushbuttonglbrowse, 1, 2, 1, 1);

        m_textglversion = new QLabel(tab);
        m_textglversion->setObjectName(QString::fromUtf8("m_textglversion"));
        m_textglversion->setWordWrap(false);

        gridLayout_2->addWidget(m_textglversion, 2, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        m_editglversion = new QLineEdit(tab);
        m_editglversion->setObjectName(QString::fromUtf8("m_editglversion"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(m_editglversion->sizePolicy().hasHeightForWidth());
        m_editglversion->setSizePolicy(sizePolicy3);
        m_editglversion->setAcceptDrops(false);
        m_editglversion->setAutoFillBackground(false);
        m_editglversion->setReadOnly(true);

        hboxLayout->addWidget(m_editglversion);

        spacer3 = new QSpacerItem(60, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer3);

        textLabel11 = new QLabel(tab);
        textLabel11->setObjectName(QString::fromUtf8("textLabel11"));
        textLabel11->setWordWrap(false);

        hboxLayout->addWidget(textLabel11);

        m_editglcount = new QLineEdit(tab);
        m_editglcount->setObjectName(QString::fromUtf8("m_editglcount"));
        sizePolicy3.setHeightForWidth(m_editglcount->sizePolicy().hasHeightForWidth());
        m_editglcount->setSizePolicy(sizePolicy3);
        m_editglcount->setReadOnly(true);

        hboxLayout->addWidget(m_editglcount);


        gridLayout_2->addLayout(hboxLayout, 2, 1, 1, 1);

        spacer4 = new QSpacerItem(82, 18, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_2->addItem(spacer4, 2, 2, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        textLabel9 = new QLabel(tab_2);
        textLabel9->setObjectName(QString::fromUtf8("textLabel9"));
        textLabel9->setWordWrap(false);

        gridLayout_4->addWidget(textLabel9, 0, 0, 1, 1);

        m_editglx = new QLineEdit(tab_2);
        m_editglx->setObjectName(QString::fromUtf8("m_editglx"));

        gridLayout_4->addWidget(m_editglx, 0, 1, 1, 1);

        spacer19 = new QSpacerItem(82, 31, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_4->addItem(spacer19, 0, 2, 1, 1);

        m_textglxlocalcopy = new QLabel(tab_2);
        m_textglxlocalcopy->setObjectName(QString::fromUtf8("m_textglxlocalcopy"));
        m_textglxlocalcopy->setWordWrap(false);

        gridLayout_4->addWidget(m_textglxlocalcopy, 1, 0, 1, 1);

        m_editglxlocalcopy = new QLineEdit(tab_2);
        m_editglxlocalcopy->setObjectName(QString::fromUtf8("m_editglxlocalcopy"));

        gridLayout_4->addWidget(m_editglxlocalcopy, 1, 1, 1, 1);

        m_pushbuttonglxbrowse = new QPushButton(tab_2);
        m_pushbuttonglxbrowse->setObjectName(QString::fromUtf8("m_pushbuttonglxbrowse"));
        sizePolicy2.setHeightForWidth(m_pushbuttonglxbrowse->sizePolicy().hasHeightForWidth());
        m_pushbuttonglxbrowse->setSizePolicy(sizePolicy2);
        m_pushbuttonglxbrowse->setAutoDefault(false);

        gridLayout_4->addWidget(m_pushbuttonglxbrowse, 1, 2, 1, 1);

        m_textglxversion = new QLabel(tab_2);
        m_textglxversion->setObjectName(QString::fromUtf8("m_textglxversion"));
        m_textglxversion->setWordWrap(false);

        gridLayout_4->addWidget(m_textglxversion, 2, 0, 1, 1);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        m_editglxversion = new QLineEdit(tab_2);
        m_editglxversion->setObjectName(QString::fromUtf8("m_editglxversion"));
        sizePolicy3.setHeightForWidth(m_editglxversion->sizePolicy().hasHeightForWidth());
        m_editglxversion->setSizePolicy(sizePolicy3);
        m_editglxversion->setReadOnly(true);

        hboxLayout1->addWidget(m_editglxversion);

        spacer7 = new QSpacerItem(70, 30, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacer7);

        textLabel11_13 = new QLabel(tab_2);
        textLabel11_13->setObjectName(QString::fromUtf8("textLabel11_13"));
        textLabel11_13->setWordWrap(false);

        hboxLayout1->addWidget(textLabel11_13);

        m_editglxcount = new QLineEdit(tab_2);
        m_editglxcount->setObjectName(QString::fromUtf8("m_editglxcount"));
        sizePolicy3.setHeightForWidth(m_editglxcount->sizePolicy().hasHeightForWidth());
        m_editglxcount->setSizePolicy(sizePolicy3);
        m_editglxcount->setReadOnly(true);

        hboxLayout1->addWidget(m_editglxcount);


        gridLayout_4->addLayout(hboxLayout1, 2, 1, 1, 1);

        spacer8 = new QSpacerItem(82, 30, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_4->addItem(spacer8, 2, 2, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_3 = new QGridLayout(tab_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        textLabel10 = new QLabel(tab_3);
        textLabel10->setObjectName(QString::fromUtf8("textLabel10"));
        textLabel10->setWordWrap(false);

        gridLayout_3->addWidget(textLabel10, 0, 0, 1, 1);

        m_editwgl = new QLineEdit(tab_3);
        m_editwgl->setObjectName(QString::fromUtf8("m_editwgl"));

        gridLayout_3->addWidget(m_editwgl, 0, 1, 1, 1);

        spacer18 = new QSpacerItem(82, 25, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_3->addItem(spacer18, 0, 2, 1, 1);

        m_textwgllocalcopy = new QLabel(tab_3);
        m_textwgllocalcopy->setObjectName(QString::fromUtf8("m_textwgllocalcopy"));
        m_textwgllocalcopy->setWordWrap(false);

        gridLayout_3->addWidget(m_textwgllocalcopy, 1, 0, 1, 1);

        m_editwgllocalcopy = new QLineEdit(tab_3);
        m_editwgllocalcopy->setObjectName(QString::fromUtf8("m_editwgllocalcopy"));

        gridLayout_3->addWidget(m_editwgllocalcopy, 1, 1, 1, 1);

        m_pushbuttonwglbrowse = new QPushButton(tab_3);
        m_pushbuttonwglbrowse->setObjectName(QString::fromUtf8("m_pushbuttonwglbrowse"));
        sizePolicy2.setHeightForWidth(m_pushbuttonwglbrowse->sizePolicy().hasHeightForWidth());
        m_pushbuttonwglbrowse->setSizePolicy(sizePolicy2);
        m_pushbuttonwglbrowse->setAutoDefault(false);

        gridLayout_3->addWidget(m_pushbuttonwglbrowse, 1, 2, 1, 1);

        m_textwglversion = new QLabel(tab_3);
        m_textwglversion->setObjectName(QString::fromUtf8("m_textwglversion"));
        m_textwglversion->setWordWrap(false);

        gridLayout_3->addWidget(m_textwglversion, 2, 0, 1, 1);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        m_editwglversion = new QLineEdit(tab_3);
        m_editwglversion->setObjectName(QString::fromUtf8("m_editwglversion"));
        sizePolicy3.setHeightForWidth(m_editwglversion->sizePolicy().hasHeightForWidth());
        m_editwglversion->setSizePolicy(sizePolicy3);
        m_editwglversion->setReadOnly(true);

        hboxLayout2->addWidget(m_editwglversion);

        spacer5 = new QSpacerItem(60, 30, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacer5);

        textLabel11_8 = new QLabel(tab_3);
        textLabel11_8->setObjectName(QString::fromUtf8("textLabel11_8"));
        textLabel11_8->setWordWrap(false);

        hboxLayout2->addWidget(textLabel11_8);

        m_editwglcount = new QLineEdit(tab_3);
        m_editwglcount->setObjectName(QString::fromUtf8("m_editwglcount"));
        sizePolicy3.setHeightForWidth(m_editwglcount->sizePolicy().hasHeightForWidth());
        m_editwglcount->setSizePolicy(sizePolicy3);
        m_editwglcount->setReadOnly(true);

        hboxLayout2->addWidget(m_editwglcount);


        gridLayout_3->addLayout(hboxLayout2, 2, 1, 1, 1);

        spacer6 = new QSpacerItem(82, 25, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_3->addItem(spacer6, 2, 2, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        gridLayout_13 = new QGridLayout(tab_6);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        textLabel10_3 = new QLabel(tab_6);
        textLabel10_3->setObjectName(QString::fromUtf8("textLabel10_3"));
        textLabel10_3->setWordWrap(false);

        gridLayout_13->addWidget(textLabel10_3, 0, 0, 1, 1);

        m_editcorearb = new QLineEdit(tab_6);
        m_editcorearb->setObjectName(QString::fromUtf8("m_editcorearb"));

        gridLayout_13->addWidget(m_editcorearb, 0, 1, 1, 1);

        spacer18_3 = new QSpacerItem(82, 25, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_13->addItem(spacer18_3, 0, 2, 1, 1);

        m_textwgllocalcopy_3 = new QLabel(tab_6);
        m_textwgllocalcopy_3->setObjectName(QString::fromUtf8("m_textwgllocalcopy_3"));
        m_textwgllocalcopy_3->setWordWrap(false);

        gridLayout_13->addWidget(m_textwgllocalcopy_3, 1, 0, 1, 1);

        m_editcorearblocalcopy = new QLineEdit(tab_6);
        m_editcorearblocalcopy->setObjectName(QString::fromUtf8("m_editcorearblocalcopy"));

        gridLayout_13->addWidget(m_editcorearblocalcopy, 1, 1, 1, 1);

        m_textwglversion_3 = new QLabel(tab_6);
        m_textwglversion_3->setObjectName(QString::fromUtf8("m_textwglversion_3"));
        m_textwglversion_3->setWordWrap(false);

        gridLayout_13->addWidget(m_textwglversion_3, 2, 0, 1, 1);

        _8 = new QHBoxLayout();
        _8->setSpacing(6);
        _8->setObjectName(QString::fromUtf8("_8"));
        m_editcorearbversion = new QLineEdit(tab_6);
        m_editcorearbversion->setObjectName(QString::fromUtf8("m_editcorearbversion"));
        sizePolicy3.setHeightForWidth(m_editcorearbversion->sizePolicy().hasHeightForWidth());
        m_editcorearbversion->setSizePolicy(sizePolicy3);
        m_editcorearbversion->setReadOnly(true);

        _8->addWidget(m_editcorearbversion);

        spacer5_4 = new QSpacerItem(60, 30, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _8->addItem(spacer5_4);

        textLabel11_11 = new QLabel(tab_6);
        textLabel11_11->setObjectName(QString::fromUtf8("textLabel11_11"));
        textLabel11_11->setWordWrap(false);

        _8->addWidget(textLabel11_11);

        m_editcorearbcount = new QLineEdit(tab_6);
        m_editcorearbcount->setObjectName(QString::fromUtf8("m_editcorearbcount"));
        sizePolicy3.setHeightForWidth(m_editcorearbcount->sizePolicy().hasHeightForWidth());
        m_editcorearbcount->setSizePolicy(sizePolicy3);
        m_editcorearbcount->setReadOnly(true);

        _8->addWidget(m_editcorearbcount);


        gridLayout_13->addLayout(_8, 2, 1, 1, 1);

        spacer6_4 = new QSpacerItem(82, 37, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_13->addItem(spacer6_4, 2, 2, 1, 1);

        m_pushbuttonwglbrowse_3 = new QPushButton(tab_6);
        m_pushbuttonwglbrowse_3->setObjectName(QString::fromUtf8("m_pushbuttonwglbrowse_3"));
        sizePolicy2.setHeightForWidth(m_pushbuttonwglbrowse_3->sizePolicy().hasHeightForWidth());
        m_pushbuttonwglbrowse_3->setSizePolicy(sizePolicy2);
        m_pushbuttonwglbrowse_3->setAutoDefault(false);

        gridLayout_13->addWidget(m_pushbuttonwglbrowse_3, 1, 2, 1, 1);

        tabWidget->addTab(tab_6, QString());

        verticalLayout_2->addWidget(tabWidget);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setSpacing(6);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        m_pushbuttonreset = new QPushButton(CRegistrySettingsBaseDialog);
        m_pushbuttonreset->setObjectName(QString::fromUtf8("m_pushbuttonreset"));
        sizePolicy3.setHeightForWidth(m_pushbuttonreset->sizePolicy().hasHeightForWidth());
        m_pushbuttonreset->setSizePolicy(sizePolicy3);
        m_pushbuttonreset->setMinimumSize(QSize(80, 30));
        m_pushbuttonreset->setAutoDefault(false);

        hboxLayout3->addWidget(m_pushbuttonreset);

        spacer39 = new QSpacerItem(50, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout3->addItem(spacer39);

        m_pushbuttonremove = new QPushButton(CRegistrySettingsBaseDialog);
        m_pushbuttonremove->setObjectName(QString::fromUtf8("m_pushbuttonremove"));
        sizePolicy3.setHeightForWidth(m_pushbuttonremove->sizePolicy().hasHeightForWidth());
        m_pushbuttonremove->setSizePolicy(sizePolicy3);
        m_pushbuttonremove->setMinimumSize(QSize(80, 30));
        m_pushbuttonremove->setAutoDefault(false);

        hboxLayout3->addWidget(m_pushbuttonremove);

        m_pushbuttonadd = new QPushButton(CRegistrySettingsBaseDialog);
        m_pushbuttonadd->setObjectName(QString::fromUtf8("m_pushbuttonadd"));
        sizePolicy3.setHeightForWidth(m_pushbuttonadd->sizePolicy().hasHeightForWidth());
        m_pushbuttonadd->setSizePolicy(sizePolicy3);
        m_pushbuttonadd->setMinimumSize(QSize(80, 30));
        m_pushbuttonadd->setAutoDefault(false);

        hboxLayout3->addWidget(m_pushbuttonadd);

        spacer39_1 = new QSpacerItem(100, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout3->addItem(spacer39_1);

        m_pushbuttoncancel = new QPushButton(CRegistrySettingsBaseDialog);
        m_pushbuttoncancel->setObjectName(QString::fromUtf8("m_pushbuttoncancel"));
        sizePolicy3.setHeightForWidth(m_pushbuttoncancel->sizePolicy().hasHeightForWidth());
        m_pushbuttoncancel->setSizePolicy(sizePolicy3);
        m_pushbuttoncancel->setMinimumSize(QSize(80, 30));
        m_pushbuttoncancel->setAutoDefault(false);

        hboxLayout3->addWidget(m_pushbuttoncancel);

        m_pushbuttonapply = new QPushButton(CRegistrySettingsBaseDialog);
        m_pushbuttonapply->setObjectName(QString::fromUtf8("m_pushbuttonapply"));
        sizePolicy3.setHeightForWidth(m_pushbuttonapply->sizePolicy().hasHeightForWidth());
        m_pushbuttonapply->setSizePolicy(sizePolicy3);
        m_pushbuttonapply->setMinimumSize(QSize(80, 30));
        m_pushbuttonapply->setAutoDefault(false);

        hboxLayout3->addWidget(m_pushbuttonapply);

        m_pushbuttonok = new QPushButton(CRegistrySettingsBaseDialog);
        m_pushbuttonok->setObjectName(QString::fromUtf8("m_pushbuttonok"));
        sizePolicy3.setHeightForWidth(m_pushbuttonok->sizePolicy().hasHeightForWidth());
        m_pushbuttonok->setSizePolicy(sizePolicy3);
        m_pushbuttonok->setMinimumSize(QSize(80, 30));

        hboxLayout3->addWidget(m_pushbuttonok);


        verticalLayout_2->addLayout(hboxLayout3);


        retranslateUi(CRegistrySettingsBaseDialog);
        QObject::connect(m_pushbuttonreset, SIGNAL(clicked()), CRegistrySettingsBaseDialog, SLOT(pushbuttonreset_clicked()));
        QObject::connect(m_pushbuttonremove, SIGNAL(clicked()), CRegistrySettingsBaseDialog, SLOT(pushbuttonremove_clicked()));
        QObject::connect(m_pushbuttoncancel, SIGNAL(clicked()), CRegistrySettingsBaseDialog, SLOT(pushbuttoncancel_clicked()));
        QObject::connect(m_pushbuttonapply, SIGNAL(clicked()), CRegistrySettingsBaseDialog, SLOT(pushbuttonapply_clicked()));
        QObject::connect(m_pushbuttonok, SIGNAL(clicked()), CRegistrySettingsBaseDialog, SLOT(pushbuttonok_clicked()));
        QObject::connect(m_pushbuttonadd, SIGNAL(clicked()), CRegistrySettingsBaseDialog, SLOT(pushbuttonadd_clicked()));
        QObject::connect(m_webpagelistview, SIGNAL(mouseDoubleClicked(int)), CRegistrySettingsBaseDialog, SLOT(webpagelistview_mouseDoubleClicked(int)));
        QObject::connect(m_webpagelistview, SIGNAL(mouseMoved(int)), CRegistrySettingsBaseDialog, SLOT(webpagelistview_mouseMoved(int)));
        QObject::connect(m_webpagelistview, SIGNAL(mouseReleased(int)), CRegistrySettingsBaseDialog, SLOT(webpagelistview_mouseReleased(int)));
        QObject::connect(m_webpagelistview, SIGNAL(mousePressed(int)), CRegistrySettingsBaseDialog, SLOT(webpagelistview_mousePressed(int)));
        QObject::connect(m_pushbuttonglbrowse, SIGNAL(clicked()), CRegistrySettingsBaseDialog, SLOT(pushbuttonglbrowse_clicked()));
        QObject::connect(m_checkboxreadheaderfiles, SIGNAL(toggled(bool)), CRegistrySettingsBaseDialog, SLOT(checkboxreadheaderfiles_toggled(bool)));
        QObject::connect(m_pushbuttonglxbrowse, SIGNAL(clicked()), CRegistrySettingsBaseDialog, SLOT(pushbuttonglxbrowse_clicked()));
        QObject::connect(m_pushbuttonwglbrowse, SIGNAL(clicked()), CRegistrySettingsBaseDialog, SLOT(pushbuttonwglbrowse_clicked()));
        QObject::connect(m_editgl, SIGNAL(textChanged(QString)), CRegistrySettingsBaseDialog, SLOT(editgl_textChanged(QString)));
        QObject::connect(m_editgllocalcopy, SIGNAL(textChanged(QString)), CRegistrySettingsBaseDialog, SLOT(editgllocalcopy_textChanged(QString)));
        QObject::connect(m_editwgl, SIGNAL(textChanged(QString)), CRegistrySettingsBaseDialog, SLOT(editwgl_textChanged(QString)));
        QObject::connect(m_editglx, SIGNAL(textChanged(QString)), CRegistrySettingsBaseDialog, SLOT(editglx_textChanged(QString)));
        QObject::connect(m_editwgllocalcopy, SIGNAL(textChanged(QString)), CRegistrySettingsBaseDialog, SLOT(editwgllocalcopy_textChanged(QString)));
        QObject::connect(m_editglxlocalcopy, SIGNAL(textChanged(QString)), CRegistrySettingsBaseDialog, SLOT(editglxlocalcopy_textChanged(QString)));
        QObject::connect(m_checkboxreadextensionspec, SIGNAL(toggled(bool)), CRegistrySettingsBaseDialog, SLOT(checkboxreadextensionspec_toggled(bool)));
        QObject::connect(m_checkboxdownloadheaderfiles, SIGNAL(toggled(bool)), CRegistrySettingsBaseDialog, SLOT(checkboxdownloadheaderfiles_toggled(bool)));
        QObject::connect(m_checkboxdownloadregistry, SIGNAL(toggled(bool)), CRegistrySettingsBaseDialog, SLOT(checkboxdownloadregistry_toggled(bool)));
        QObject::connect(m_editregistrylocaldir, SIGNAL(textChanged(QString)), CRegistrySettingsBaseDialog, SLOT(editregistrylocaldir_textChanged(QString)));
        QObject::connect(m_pushbuttonregistrywebpagebrowse, SIGNAL(clicked()), CRegistrySettingsBaseDialog, SLOT(pushbuttonregistrywebpagebrowse_clicked()));
        QObject::connect(m_pushbuttonregistrylocaldirbrowse, SIGNAL(clicked()), CRegistrySettingsBaseDialog, SLOT(pushbuttonregistrylocaldirbrowse_clicked()));
        QObject::connect(m_editregistrylocalcopy, SIGNAL(textChanged(QString)), CRegistrySettingsBaseDialog, SLOT(editregistrylocalcopy_textChanged(QString)));
        QObject::connect(m_editcorearblocalcopy, SIGNAL(textChanged(QString)), CRegistrySettingsBaseDialog, SLOT(editcorearblocalcopy_textChanged(QString)));
        QObject::connect(m_editcorearb, SIGNAL(textChanged(QString)), CRegistrySettingsBaseDialog, SLOT(editcorearb_textChanged(QString)));
        QObject::connect(m_pushbuttonwglbrowse_3, SIGNAL(clicked()), CRegistrySettingsBaseDialog, SLOT(pushbuttoncorearb_clicked()));
        QObject::connect(m_lineeditfileextensionfilter, SIGNAL(textChanged(QString)), CRegistrySettingsBaseDialog, SLOT(editfileextensionfilter_textChanged(QString)));
        QObject::connect(m_editregistry, SIGNAL(textChanged(QString)), CRegistrySettingsBaseDialog, SLOT(editregistry_textChanged(QString)));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(CRegistrySettingsBaseDialog);
    } // setupUi

    void retranslateUi(QDialog *CRegistrySettingsBaseDialog)
    {
        CRegistrySettingsBaseDialog->setWindowTitle(QApplication::translate("CRegistrySettingsBaseDialog", "Registry Settings", 0, QApplication::UnicodeUTF8));
        m_checkboxdownloadregistry->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Download this web page and all associated hyperlinked files", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Download file extension filter", 0, QApplication::UnicodeUTF8));
        m_checkboxdownloadheaderfiles->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Download header files from this site", 0, QApplication::UnicodeUTF8));
        m_checkboxreadheaderfiles->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Read extension header files from this directory", 0, QApplication::UnicodeUTF8));
        m_checkboxreadextensionspec->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Search the local copy of this site when looking for extension specifications", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("CRegistrySettingsBaseDialog", "Downloading and File reading", 0, QApplication::UnicodeUTF8));
        m_textregistry->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Registry webpage ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_editregistry->setWhatsThis(QApplication::translate("CRegistrySettingsBaseDialog", "Web page to download", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_textregistrylocalcopy->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Local directory      ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_editregistrylocaldir->setWhatsThis(QApplication::translate("CRegistrySettingsBaseDialog", "Where to store downloaded files", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        m_pushbuttonregistrylocaldirbrowse->setWhatsThis(QApplication::translate("CRegistrySettingsBaseDialog", "Browse local file system", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_pushbuttonregistrylocaldirbrowse->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Browse", 0, QApplication::UnicodeUTF8));
        m_textgllocalcopy_2->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Local copy", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_editregistrylocalcopy->setWhatsThis(QApplication::translate("CRegistrySettingsBaseDialog", "Web page to download", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        m_pushbuttonregistrywebpagebrowse->setWhatsThis(QApplication::translate("CRegistrySettingsBaseDialog", "Browse local file system", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_pushbuttonregistrywebpagebrowse->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Browse", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("CRegistrySettingsBaseDialog", "Local Directories", 0, QApplication::UnicodeUTF8));
        m_textglheader->setText(QApplication::translate("CRegistrySettingsBaseDialog", "GL header file", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_editgl->setWhatsThis(QApplication::translate("CRegistrySettingsBaseDialog", "GL header file to download", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_textgllocalcopy->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Local copy", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_editgllocalcopy->setWhatsThis(QApplication::translate("CRegistrySettingsBaseDialog", "File path to local copy", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        m_pushbuttonglbrowse->setWhatsThis(QApplication::translate("CRegistrySettingsBaseDialog", "Browse local file system", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_pushbuttonglbrowse->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Browse", 0, QApplication::UnicodeUTF8));
        m_textglversion->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Header file version", 0, QApplication::UnicodeUTF8));
        textLabel11->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Number of extensions", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("CRegistrySettingsBaseDialog", "GL Settings", 0, QApplication::UnicodeUTF8));
        textLabel9->setText(QApplication::translate("CRegistrySettingsBaseDialog", "GLX header file", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_editglx->setWhatsThis(QApplication::translate("CRegistrySettingsBaseDialog", "GLX header file to download", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_textglxlocalcopy->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Local copy", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_editglxlocalcopy->setWhatsThis(QApplication::translate("CRegistrySettingsBaseDialog", "File path to local copy", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        m_pushbuttonglxbrowse->setWhatsThis(QApplication::translate("CRegistrySettingsBaseDialog", "Browse local file system", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_pushbuttonglxbrowse->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Browse", 0, QApplication::UnicodeUTF8));
        m_textglxversion->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Header file version", 0, QApplication::UnicodeUTF8));
        textLabel11_13->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Number of extensions", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("CRegistrySettingsBaseDialog", "GLX Settings", 0, QApplication::UnicodeUTF8));
        textLabel10->setText(QApplication::translate("CRegistrySettingsBaseDialog", "WGL header file", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_editwgl->setWhatsThis(QApplication::translate("CRegistrySettingsBaseDialog", "WGL header file to download", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_textwgllocalcopy->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Local copy", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_editwgllocalcopy->setWhatsThis(QApplication::translate("CRegistrySettingsBaseDialog", "File path to local copy", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        m_pushbuttonwglbrowse->setWhatsThis(QApplication::translate("CRegistrySettingsBaseDialog", "Browse local file system", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_pushbuttonwglbrowse->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Browse", 0, QApplication::UnicodeUTF8));
        m_textwglversion->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Header file version", 0, QApplication::UnicodeUTF8));
        textLabel11_8->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Number of extensions", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("CRegistrySettingsBaseDialog", "WGL Settings", 0, QApplication::UnicodeUTF8));
        textLabel10_3->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Core ARB header", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_editcorearb->setWhatsThis(QApplication::translate("CRegistrySettingsBaseDialog", "WGL header file to download", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_textwgllocalcopy_3->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Local copy", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_editcorearblocalcopy->setWhatsThis(QApplication::translate("CRegistrySettingsBaseDialog", "File path to local copy", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_textwglversion_3->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Header file version", 0, QApplication::UnicodeUTF8));
        textLabel11_11->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Number of extensions", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_pushbuttonwglbrowse_3->setWhatsThis(QApplication::translate("CRegistrySettingsBaseDialog", "Browse local file system", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_pushbuttonwglbrowse_3->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Browse", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("CRegistrySettingsBaseDialog", " CoreARB Settings", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_pushbuttonreset->setWhatsThis(QApplication::translate("CRegistrySettingsBaseDialog", "Reset settings to default values", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_pushbuttonreset->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Reset", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_pushbuttonremove->setWhatsThis(QApplication::translate("CRegistrySettingsBaseDialog", "Remove entry from list", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_pushbuttonremove->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Remove", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_pushbuttonadd->setWhatsThis(QApplication::translate("CRegistrySettingsBaseDialog", "Add new entry to list", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_pushbuttonadd->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Add", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_pushbuttoncancel->setWhatsThis(QApplication::translate("CRegistrySettingsBaseDialog", "Abandon all changes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_pushbuttoncancel->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Cancel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_pushbuttonapply->setWhatsThis(QApplication::translate("CRegistrySettingsBaseDialog", "Apply changes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_pushbuttonapply->setText(QApplication::translate("CRegistrySettingsBaseDialog", "Apply", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_pushbuttonok->setToolTip(QApplication::translate("CRegistrySettingsBaseDialog", "Apply changes and close window", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_pushbuttonok->setText(QApplication::translate("CRegistrySettingsBaseDialog", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CRegistrySettingsBaseDialog: public Ui_CRegistrySettingsBaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRYSETTINGSBASEDLG_H
