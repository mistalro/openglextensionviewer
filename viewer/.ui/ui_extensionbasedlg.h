/********************************************************************************
** Form generated from reading UI file 'extensionbasedlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXTENSIONBASEDLG_H
#define UI_EXTENSIONBASEDLG_H

#include <Qt3Support/Q3Frame>
#include <Qt3Support/Q3GroupBox>
#include <Qt3Support/Q3MimeSourceFactory>
#include <Qt3Support/Q3TextEdit>
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
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "extconstantlistwidget/extconstantlistwidget.h"
#include "extfunctionlistwidget/extfunctionlistwidget.h"

QT_BEGIN_NAMESPACE

class Ui_CExtensionBaseDialog
{
public:
    QVBoxLayout *vboxLayout;
    Q3GroupBox *m_groupboxextensionheader;
    QGridLayout *gridLayout;
    QHBoxLayout *hboxLayout;
    QLabel *m_textfunctioncount;
    QLineEdit *m_editfunctioncount;
    QSpacerItem *spacer2_2;
    QLabel *m_textconstantcount;
    QLineEdit *m_editconstantcount;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacer2;
    QLabel *m_textselected;
    QRadioButton *m_radioselected;
    QGridLayout *gridLayout1;
    QLabel *m_textextensionname_2;
    QLineEdit *m_editextensionname;
    QLabel *m_textextensionname;
    QComboBox *m_combobox;
    Q3GroupBox *groupBox2;
    QGridLayout *gridLayout2;
    QLabel *m_textextensionname_3;
    QRadioButton *m_radiosearchforwards;
    QLineEdit *m_editfindtext;
    QPushButton *m_pushbuttonfind;
    QRadioButton *m_radiocasesensitive;
    QRadioButton *m_radiowholewords;
    QTabWidget *m_tabwidget;
    QWidget *TabPage;
    QGridLayout *gridLayout3;
    QTextEdit *m_textedit;
    QWidget *tab;
    QGridLayout *gridLayout4;
    CExtensionFunctionListView *m_listfunction;
    QWidget *tab1;
    QGridLayout *gridLayout5;
    CExtensionConstantListView *m_listconstant;
    QHBoxLayout *hboxLayout2;
    QPushButton *m_pushbuttonprevious;
    QPushButton *m_pushbuttonnext;
    QPushButton *m_pushbuttonremove;
    QPushButton *m_pushbuttonadd;
    QPushButton *m_pushbuttonok;

    void setupUi(QDialog *CExtensionBaseDialog)
    {
        if (CExtensionBaseDialog->objectName().isEmpty())
            CExtensionBaseDialog->setObjectName(QString::fromUtf8("CExtensionBaseDialog"));
        CExtensionBaseDialog->resize(981, 621);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CExtensionBaseDialog->sizePolicy().hasHeightForWidth());
        CExtensionBaseDialog->setSizePolicy(sizePolicy);
        CExtensionBaseDialog->setSizeGripEnabled(true);
        vboxLayout = new QVBoxLayout(CExtensionBaseDialog);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        m_groupboxextensionheader = new Q3GroupBox(CExtensionBaseDialog);
        m_groupboxextensionheader->setObjectName(QString::fromUtf8("m_groupboxextensionheader"));
        m_groupboxextensionheader->setColumnLayout(0, Qt::Vertical);
        m_groupboxextensionheader->layout()->setSpacing(6);
        m_groupboxextensionheader->layout()->setContentsMargins(11, 11, 11, 11);
        gridLayout = new QGridLayout();
        QBoxLayout *boxlayout = qobject_cast<QBoxLayout *>(m_groupboxextensionheader->layout());
        if (boxlayout)
            boxlayout->addLayout(gridLayout);
        gridLayout->setAlignment(Qt::AlignTop);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        m_textfunctioncount = new QLabel(m_groupboxextensionheader);
        m_textfunctioncount->setObjectName(QString::fromUtf8("m_textfunctioncount"));
        m_textfunctioncount->setWordWrap(false);

        hboxLayout->addWidget(m_textfunctioncount);

        m_editfunctioncount = new QLineEdit(m_groupboxextensionheader);
        m_editfunctioncount->setObjectName(QString::fromUtf8("m_editfunctioncount"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_editfunctioncount->sizePolicy().hasHeightForWidth());
        m_editfunctioncount->setSizePolicy(sizePolicy1);
        m_editfunctioncount->setMaximumSize(QSize(80, 32767));
        m_editfunctioncount->setReadOnly(true);

        hboxLayout->addWidget(m_editfunctioncount);

        spacer2_2 = new QSpacerItem(110, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer2_2);

        m_textconstantcount = new QLabel(m_groupboxextensionheader);
        m_textconstantcount->setObjectName(QString::fromUtf8("m_textconstantcount"));
        m_textconstantcount->setWordWrap(false);

        hboxLayout->addWidget(m_textconstantcount);

        m_editconstantcount = new QLineEdit(m_groupboxextensionheader);
        m_editconstantcount->setObjectName(QString::fromUtf8("m_editconstantcount"));
        sizePolicy1.setHeightForWidth(m_editconstantcount->sizePolicy().hasHeightForWidth());
        m_editconstantcount->setSizePolicy(sizePolicy1);
        m_editconstantcount->setMaximumSize(QSize(80, 32767));
        m_editconstantcount->setReadOnly(true);

        hboxLayout->addWidget(m_editconstantcount);


        gridLayout->addLayout(hboxLayout, 1, 1, 1, 1);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        spacer2 = new QSpacerItem(463, 30, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacer2);

        m_textselected = new QLabel(m_groupboxextensionheader);
        m_textselected->setObjectName(QString::fromUtf8("m_textselected"));
        m_textselected->setWordWrap(false);

        hboxLayout1->addWidget(m_textselected);

        m_radioselected = new QRadioButton(m_groupboxextensionheader);
        m_radioselected->setObjectName(QString::fromUtf8("m_radioselected"));
        sizePolicy1.setHeightForWidth(m_radioselected->sizePolicy().hasHeightForWidth());
        m_radioselected->setSizePolicy(sizePolicy1);

        hboxLayout1->addWidget(m_radioselected);


        gridLayout->addLayout(hboxLayout1, 0, 1, 1, 1);

        gridLayout1 = new QGridLayout();
        gridLayout1->setSpacing(6);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        m_textextensionname_2 = new QLabel(m_groupboxextensionheader);
        m_textextensionname_2->setObjectName(QString::fromUtf8("m_textextensionname_2"));
        m_textextensionname_2->setWordWrap(false);

        gridLayout1->addWidget(m_textextensionname_2, 1, 0, 1, 1);

        m_editextensionname = new QLineEdit(m_groupboxextensionheader);
        m_editextensionname->setObjectName(QString::fromUtf8("m_editextensionname"));
        m_editextensionname->setReadOnly(false);

        gridLayout1->addWidget(m_editextensionname, 1, 1, 1, 1);

        m_textextensionname = new QLabel(m_groupboxextensionheader);
        m_textextensionname->setObjectName(QString::fromUtf8("m_textextensionname"));
        m_textextensionname->setWordWrap(false);

        gridLayout1->addWidget(m_textextensionname, 0, 0, 1, 1);

        m_combobox = new QComboBox(m_groupboxextensionheader);
        m_combobox->setObjectName(QString::fromUtf8("m_combobox"));
        m_combobox->setAutoCompletion(true);

        gridLayout1->addWidget(m_combobox, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout1, 0, 0, 2, 1);


        vboxLayout->addWidget(m_groupboxextensionheader);

        groupBox2 = new Q3GroupBox(CExtensionBaseDialog);
        groupBox2->setObjectName(QString::fromUtf8("groupBox2"));
        groupBox2->setColumnLayout(0, Qt::Vertical);
        groupBox2->layout()->setSpacing(6);
        groupBox2->layout()->setContentsMargins(11, 11, 11, 11);
        gridLayout2 = new QGridLayout();
        QBoxLayout *boxlayout1 = qobject_cast<QBoxLayout *>(groupBox2->layout());
        if (boxlayout1)
            boxlayout1->addLayout(gridLayout2);
        gridLayout2->setAlignment(Qt::AlignTop);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        m_textextensionname_3 = new QLabel(groupBox2);
        m_textextensionname_3->setObjectName(QString::fromUtf8("m_textextensionname_3"));
        m_textextensionname_3->setWordWrap(false);

        gridLayout2->addWidget(m_textextensionname_3, 0, 0, 1, 1);

        m_radiosearchforwards = new QRadioButton(groupBox2);
        m_radiosearchforwards->setObjectName(QString::fromUtf8("m_radiosearchforwards"));

        gridLayout2->addWidget(m_radiosearchforwards, 0, 5, 1, 1);

        m_editfindtext = new QLineEdit(groupBox2);
        m_editfindtext->setObjectName(QString::fromUtf8("m_editfindtext"));
        m_editfindtext->setReadOnly(false);

        gridLayout2->addWidget(m_editfindtext, 0, 1, 1, 1);

        m_pushbuttonfind = new QPushButton(groupBox2);
        m_pushbuttonfind->setObjectName(QString::fromUtf8("m_pushbuttonfind"));

        gridLayout2->addWidget(m_pushbuttonfind, 0, 2, 1, 1);

        m_radiocasesensitive = new QRadioButton(groupBox2);
        m_radiocasesensitive->setObjectName(QString::fromUtf8("m_radiocasesensitive"));

        gridLayout2->addWidget(m_radiocasesensitive, 0, 3, 1, 1);

        m_radiowholewords = new QRadioButton(groupBox2);
        m_radiowholewords->setObjectName(QString::fromUtf8("m_radiowholewords"));

        gridLayout2->addWidget(m_radiowholewords, 0, 4, 1, 1);


        vboxLayout->addWidget(groupBox2);

        m_tabwidget = new QTabWidget(CExtensionBaseDialog);
        m_tabwidget->setObjectName(QString::fromUtf8("m_tabwidget"));
        TabPage = new QWidget();
        TabPage->setObjectName(QString::fromUtf8("TabPage"));
        gridLayout3 = new QGridLayout(TabPage);
        gridLayout3->setSpacing(6);
        gridLayout3->setContentsMargins(11, 11, 11, 11);
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        m_textedit = new QTextEdit(TabPage);
        m_textedit->setObjectName(QString::fromUtf8("m_textedit"));
        QFont font;
        font.setFamily(QString::fromUtf8("Monospace"));
        font.setPointSize(11);
        m_textedit->setFont(font);
        m_textedit->setReadOnly(true);

        gridLayout3->addWidget(m_textedit, 0, 0, 1, 1);

        m_tabwidget->addTab(TabPage, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout4 = new QGridLayout(tab);
        gridLayout4->setSpacing(6);
        gridLayout4->setContentsMargins(11, 11, 11, 11);
        gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
        m_listfunction = new CExtensionFunctionListView(tab);
        m_listfunction->setObjectName(QString::fromUtf8("m_listfunction"));

        gridLayout4->addWidget(m_listfunction, 0, 0, 1, 1);

        m_tabwidget->addTab(tab, QString());
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        gridLayout5 = new QGridLayout(tab1);
        gridLayout5->setSpacing(6);
        gridLayout5->setContentsMargins(11, 11, 11, 11);
        gridLayout5->setObjectName(QString::fromUtf8("gridLayout5"));
        m_listconstant = new CExtensionConstantListView(tab1);
        m_listconstant->setObjectName(QString::fromUtf8("m_listconstant"));

        gridLayout5->addWidget(m_listconstant, 0, 0, 1, 1);

        m_tabwidget->addTab(tab1, QString());

        vboxLayout->addWidget(m_tabwidget);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        m_pushbuttonprevious = new QPushButton(CExtensionBaseDialog);
        m_pushbuttonprevious->setObjectName(QString::fromUtf8("m_pushbuttonprevious"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(m_pushbuttonprevious->sizePolicy().hasHeightForWidth());
        m_pushbuttonprevious->setSizePolicy(sizePolicy2);

        hboxLayout2->addWidget(m_pushbuttonprevious);

        m_pushbuttonnext = new QPushButton(CExtensionBaseDialog);
        m_pushbuttonnext->setObjectName(QString::fromUtf8("m_pushbuttonnext"));
        sizePolicy2.setHeightForWidth(m_pushbuttonnext->sizePolicy().hasHeightForWidth());
        m_pushbuttonnext->setSizePolicy(sizePolicy2);

        hboxLayout2->addWidget(m_pushbuttonnext);

        m_pushbuttonremove = new QPushButton(CExtensionBaseDialog);
        m_pushbuttonremove->setObjectName(QString::fromUtf8("m_pushbuttonremove"));
        sizePolicy2.setHeightForWidth(m_pushbuttonremove->sizePolicy().hasHeightForWidth());
        m_pushbuttonremove->setSizePolicy(sizePolicy2);

        hboxLayout2->addWidget(m_pushbuttonremove);

        m_pushbuttonadd = new QPushButton(CExtensionBaseDialog);
        m_pushbuttonadd->setObjectName(QString::fromUtf8("m_pushbuttonadd"));
        sizePolicy2.setHeightForWidth(m_pushbuttonadd->sizePolicy().hasHeightForWidth());
        m_pushbuttonadd->setSizePolicy(sizePolicy2);

        hboxLayout2->addWidget(m_pushbuttonadd);

        m_pushbuttonok = new QPushButton(CExtensionBaseDialog);
        m_pushbuttonok->setObjectName(QString::fromUtf8("m_pushbuttonok"));
        sizePolicy2.setHeightForWidth(m_pushbuttonok->sizePolicy().hasHeightForWidth());
        m_pushbuttonok->setSizePolicy(sizePolicy2);
        m_pushbuttonok->setDefault(true);

        hboxLayout2->addWidget(m_pushbuttonok);


        vboxLayout->addLayout(hboxLayout2);


        retranslateUi(CExtensionBaseDialog);
        QObject::connect(m_pushbuttonprevious, SIGNAL(clicked()), CExtensionBaseDialog, SLOT(pushbuttonprevious_clicked()));
        QObject::connect(m_pushbuttonnext, SIGNAL(clicked()), CExtensionBaseDialog, SLOT(pushbuttonnext_clicked()));
        QObject::connect(m_pushbuttonremove, SIGNAL(clicked()), CExtensionBaseDialog, SLOT(pushbuttonremove_clicked()));
        QObject::connect(m_pushbuttonadd, SIGNAL(clicked()), CExtensionBaseDialog, SLOT(pushbuttonadd_clicked()));
        QObject::connect(m_pushbuttonok, SIGNAL(clicked()), CExtensionBaseDialog, SLOT(pushbuttonok_clicked()));
        QObject::connect(m_editextensionname, SIGNAL(textChanged(QString)), CExtensionBaseDialog, SLOT(editextensionname_textChanged(QString)));
        QObject::connect(m_combobox, SIGNAL(activated(QString)), CExtensionBaseDialog, SLOT(combobox_activated(QString)));
        QObject::connect(m_editfindtext, SIGNAL(textChanged(QString)), CExtensionBaseDialog, SLOT(editfindtext_textChanged(QString)));
        QObject::connect(m_pushbuttonfind, SIGNAL(clicked()), CExtensionBaseDialog, SLOT(pushbuttonfind_clicked()));
        QObject::connect(m_radioselected, SIGNAL(toggled(bool)), CExtensionBaseDialog, SLOT(radioselected_toggled(bool)));
        QObject::connect(m_radiocasesensitive, SIGNAL(toggled(bool)), CExtensionBaseDialog, SLOT(radiocasesensitive_toggled(bool)));
        QObject::connect(m_radiowholewords, SIGNAL(toggled(bool)), CExtensionBaseDialog, SLOT(radiowholewords_toggled(bool)));
        QObject::connect(m_radiosearchforwards, SIGNAL(toggled(bool)), CExtensionBaseDialog, SLOT(radiosearchforwards_toggled(bool)));

        QMetaObject::connectSlotsByName(CExtensionBaseDialog);
    } // setupUi

    void retranslateUi(QDialog *CExtensionBaseDialog)
    {
        CExtensionBaseDialog->setWindowTitle(QApplication::translate("CExtensionBaseDialog", "Extension Description", 0, QApplication::UnicodeUTF8));
        m_groupboxextensionheader->setTitle(QString());
        m_textfunctioncount->setText(QApplication::translate("CExtensionBaseDialog", "Number of Functions", 0, QApplication::UnicodeUTF8));
        m_textconstantcount->setText(QApplication::translate("CExtensionBaseDialog", "Number of Constants", 0, QApplication::UnicodeUTF8));
        m_textselected->setText(QApplication::translate("CExtensionBaseDialog", "Selected", 0, QApplication::UnicodeUTF8));
        m_radioselected->setText(QString());
        m_textextensionname_2->setText(QApplication::translate("CExtensionBaseDialog", "String to search for:", 0, QApplication::UnicodeUTF8));
        m_textextensionname->setText(QApplication::translate("CExtensionBaseDialog", "Extension Name", 0, QApplication::UnicodeUTF8));
        groupBox2->setTitle(QString());
        m_textextensionname_3->setText(QApplication::translate("CExtensionBaseDialog", "Text to find:", 0, QApplication::UnicodeUTF8));
        m_radiosearchforwards->setText(QApplication::translate("CExtensionBaseDialog", "Search Forwards", 0, QApplication::UnicodeUTF8));
        m_pushbuttonfind->setText(QApplication::translate("CExtensionBaseDialog", "Find again", 0, QApplication::UnicodeUTF8));
        m_radiocasesensitive->setText(QApplication::translate("CExtensionBaseDialog", "Case Sensitive", 0, QApplication::UnicodeUTF8));
        m_radiowholewords->setText(QApplication::translate("CExtensionBaseDialog", "Whole words only", 0, QApplication::UnicodeUTF8));
        m_tabwidget->setTabText(m_tabwidget->indexOf(TabPage), QApplication::translate("CExtensionBaseDialog", "Extension Specification", 0, QApplication::UnicodeUTF8));
        m_tabwidget->setTabText(m_tabwidget->indexOf(tab), QApplication::translate("CExtensionBaseDialog", "Extension Functions", 0, QApplication::UnicodeUTF8));
        m_tabwidget->setTabText(m_tabwidget->indexOf(tab1), QApplication::translate("CExtensionBaseDialog", "Extension Constants", 0, QApplication::UnicodeUTF8));
        m_pushbuttonprevious->setText(QApplication::translate("CExtensionBaseDialog", "Previous", 0, QApplication::UnicodeUTF8));
        m_pushbuttonnext->setText(QApplication::translate("CExtensionBaseDialog", "Next", 0, QApplication::UnicodeUTF8));
        m_pushbuttonremove->setText(QApplication::translate("CExtensionBaseDialog", "Remove", 0, QApplication::UnicodeUTF8));
        m_pushbuttonadd->setText(QApplication::translate("CExtensionBaseDialog", "Add", 0, QApplication::UnicodeUTF8));
        m_pushbuttonok->setText(QApplication::translate("CExtensionBaseDialog", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CExtensionBaseDialog: public Ui_CExtensionBaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXTENSIONBASEDLG_H
