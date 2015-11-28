/********************************************************************************
** Form generated from reading UI file 'findextensionspecbasedlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDEXTENSIONSPECBASEDLG_H
#define UI_FINDEXTENSIONSPECBASEDLG_H

#include <Qt3Support/Q3Frame>
#include <Qt3Support/Q3GroupBox>
#include <Qt3Support/Q3Header>
#include <Qt3Support/Q3ListView>
#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
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

class Ui_CFindExtensionSpecBaseDialog
{
public:
    QVBoxLayout *vboxLayout;
    Q3GroupBox *m_groupboxstring;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout;
    QLineEdit *m_lineeditstring;
    QPushButton *m_pushbuttonfindstring;
    QHBoxLayout *hboxLayout1;
    QCheckBox *m_checkboxmatchcase;
    QCheckBox *m_checkboxfirstmatch;
    QCheckBox *m_checkboxfullpaths;
    QCheckBox *m_checkboxonematchperfile;
    QSpacerItem *spacer2;
    Q3ListView *m_listviewresults;
    QHBoxLayout *hboxLayout2;
    QLabel *textLabel1_2;
    QLineEdit *m_lineeditsite;
    QLabel *textLabel1;
    QProgressBar *m_progressbarsearch;
    QSpacerItem *spacer1;
    QLabel *label;
    QLineEdit *m_lineeditsearchstatus;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pushbuttoncancel;
    QSpacerItem *spacer3;
    QPushButton *pushButton;
    QPushButton *m_pushbuttonok;

    void setupUi(QDialog *CFindExtensionSpecBaseDialog)
    {
        if (CFindExtensionSpecBaseDialog->objectName().isEmpty())
            CFindExtensionSpecBaseDialog->setObjectName(QString::fromUtf8("CFindExtensionSpecBaseDialog"));
        CFindExtensionSpecBaseDialog->resize(796, 652);
        vboxLayout = new QVBoxLayout(CFindExtensionSpecBaseDialog);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        m_groupboxstring = new Q3GroupBox(CFindExtensionSpecBaseDialog);
        m_groupboxstring->setObjectName(QString::fromUtf8("m_groupboxstring"));
        m_groupboxstring->setColumnLayout(0, Qt::Vertical);
        m_groupboxstring->layout()->setSpacing(6);
        m_groupboxstring->layout()->setContentsMargins(11, 11, 11, 11);
        vboxLayout1 = new QVBoxLayout();
        QBoxLayout *boxlayout = qobject_cast<QBoxLayout *>(m_groupboxstring->layout());
        if (boxlayout)
            boxlayout->addLayout(vboxLayout1);
        vboxLayout1->setAlignment(Qt::AlignTop);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        m_lineeditstring = new QLineEdit(m_groupboxstring);
        m_lineeditstring->setObjectName(QString::fromUtf8("m_lineeditstring"));

        hboxLayout->addWidget(m_lineeditstring);

        m_pushbuttonfindstring = new QPushButton(m_groupboxstring);
        m_pushbuttonfindstring->setObjectName(QString::fromUtf8("m_pushbuttonfindstring"));

        hboxLayout->addWidget(m_pushbuttonfindstring);


        vboxLayout1->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        m_checkboxmatchcase = new QCheckBox(m_groupboxstring);
        m_checkboxmatchcase->setObjectName(QString::fromUtf8("m_checkboxmatchcase"));

        hboxLayout1->addWidget(m_checkboxmatchcase);

        m_checkboxfirstmatch = new QCheckBox(m_groupboxstring);
        m_checkboxfirstmatch->setObjectName(QString::fromUtf8("m_checkboxfirstmatch"));

        hboxLayout1->addWidget(m_checkboxfirstmatch);

        m_checkboxfullpaths = new QCheckBox(m_groupboxstring);
        m_checkboxfullpaths->setObjectName(QString::fromUtf8("m_checkboxfullpaths"));

        hboxLayout1->addWidget(m_checkboxfullpaths);

        m_checkboxonematchperfile = new QCheckBox(m_groupboxstring);
        m_checkboxonematchperfile->setObjectName(QString::fromUtf8("m_checkboxonematchperfile"));

        hboxLayout1->addWidget(m_checkboxonematchperfile);

        spacer2 = new QSpacerItem(300, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacer2);


        vboxLayout1->addLayout(hboxLayout1);


        vboxLayout->addWidget(m_groupboxstring);

        m_listviewresults = new Q3ListView(CFindExtensionSpecBaseDialog);
        m_listviewresults->addColumn(QApplication::translate("CFindExtensionSpecBaseDialog", "File", 0, QApplication::UnicodeUTF8));
        m_listviewresults->header()->setClickEnabled(true, m_listviewresults->header()->count() - 1);
        m_listviewresults->header()->setResizeEnabled(true, m_listviewresults->header()->count() - 1);
        m_listviewresults->addColumn(QApplication::translate("CFindExtensionSpecBaseDialog", "Line number", 0, QApplication::UnicodeUTF8));
        m_listviewresults->header()->setClickEnabled(true, m_listviewresults->header()->count() - 1);
        m_listviewresults->header()->setResizeEnabled(true, m_listviewresults->header()->count() - 1);
        m_listviewresults->addColumn(QApplication::translate("CFindExtensionSpecBaseDialog", "Text", 0, QApplication::UnicodeUTF8));
        m_listviewresults->header()->setClickEnabled(true, m_listviewresults->header()->count() - 1);
        m_listviewresults->header()->setResizeEnabled(true, m_listviewresults->header()->count() - 1);
        m_listviewresults->setObjectName(QString::fromUtf8("m_listviewresults"));
        m_listviewresults->setAllColumnsShowFocus(true);
        m_listviewresults->setResizeMode(Q3ListView::NoColumn);

        vboxLayout->addWidget(m_listviewresults);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        textLabel1_2 = new QLabel(CFindExtensionSpecBaseDialog);
        textLabel1_2->setObjectName(QString::fromUtf8("textLabel1_2"));
        textLabel1_2->setWordWrap(false);

        hboxLayout2->addWidget(textLabel1_2);

        m_lineeditsite = new QLineEdit(CFindExtensionSpecBaseDialog);
        m_lineeditsite->setObjectName(QString::fromUtf8("m_lineeditsite"));
        m_lineeditsite->setReadOnly(true);

        hboxLayout2->addWidget(m_lineeditsite);

        textLabel1 = new QLabel(CFindExtensionSpecBaseDialog);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        textLabel1->setWordWrap(false);

        hboxLayout2->addWidget(textLabel1);

        m_progressbarsearch = new QProgressBar(CFindExtensionSpecBaseDialog);
        m_progressbarsearch->setObjectName(QString::fromUtf8("m_progressbarsearch"));

        hboxLayout2->addWidget(m_progressbarsearch);

        spacer1 = new QSpacerItem(90, 30, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacer1);

        label = new QLabel(CFindExtensionSpecBaseDialog);
        label->setObjectName(QString::fromUtf8("label"));

        hboxLayout2->addWidget(label);

        m_lineeditsearchstatus = new QLineEdit(CFindExtensionSpecBaseDialog);
        m_lineeditsearchstatus->setObjectName(QString::fromUtf8("m_lineeditsearchstatus"));
        m_lineeditsearchstatus->setReadOnly(true);

        hboxLayout2->addWidget(m_lineeditsearchstatus);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(horizontalSpacer);

        m_pushbuttoncancel = new QPushButton(CFindExtensionSpecBaseDialog);
        m_pushbuttoncancel->setObjectName(QString::fromUtf8("m_pushbuttoncancel"));

        hboxLayout2->addWidget(m_pushbuttoncancel);

        spacer3 = new QSpacerItem(90, 30, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacer3);

        pushButton = new QPushButton(CFindExtensionSpecBaseDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        hboxLayout2->addWidget(pushButton);

        m_pushbuttonok = new QPushButton(CFindExtensionSpecBaseDialog);
        m_pushbuttonok->setObjectName(QString::fromUtf8("m_pushbuttonok"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_pushbuttonok->sizePolicy().hasHeightForWidth());
        m_pushbuttonok->setSizePolicy(sizePolicy);

        hboxLayout2->addWidget(m_pushbuttonok);


        vboxLayout->addLayout(hboxLayout2);


        retranslateUi(CFindExtensionSpecBaseDialog);
        QObject::connect(m_pushbuttoncancel, SIGNAL(clicked()), CFindExtensionSpecBaseDialog, SLOT(pushbuttoncancelsearch_clicked()));
        QObject::connect(m_lineeditstring, SIGNAL(textChanged(QString)), CFindExtensionSpecBaseDialog, SLOT(lineeditsearchstring_textChanged(QString)));
        QObject::connect(m_checkboxmatchcase, SIGNAL(clicked(bool)), CFindExtensionSpecBaseDialog, SLOT(radiobuttonmatchcase_toggled(bool)));
        QObject::connect(m_checkboxfirstmatch, SIGNAL(clicked(bool)), CFindExtensionSpecBaseDialog, SLOT(radiobuttonfindfirst_toggled(bool)));
        QObject::connect(m_checkboxfullpaths, SIGNAL(clicked(bool)), CFindExtensionSpecBaseDialog, SLOT(radiobuttondisplayfullpaths_toggled(bool)));
        QObject::connect(m_pushbuttonok, SIGNAL(clicked()), CFindExtensionSpecBaseDialog, SLOT(pushbuttonok_clicked()));
        QObject::connect(m_pushbuttonfindstring, SIGNAL(clicked()), CFindExtensionSpecBaseDialog, SLOT(pushbuttonfind_clicked()));
        QObject::connect(m_listviewresults, SIGNAL(clicked(Q3ListViewItem*)), CFindExtensionSpecBaseDialog, SLOT(listview_clicked(Q3ListViewItem*)));
        QObject::connect(m_checkboxonematchperfile, SIGNAL(clicked(bool)), CFindExtensionSpecBaseDialog, SLOT(radiobuttononematchperfile_toggled(bool)));
        QObject::connect(pushButton, SIGNAL(clicked()), CFindExtensionSpecBaseDialog, SLOT(pushbuttonclear_clicked()));

        QMetaObject::connectSlotsByName(CFindExtensionSpecBaseDialog);
    } // setupUi

    void retranslateUi(QDialog *CFindExtensionSpecBaseDialog)
    {
        CFindExtensionSpecBaseDialog->setWindowTitle(QApplication::translate("CFindExtensionSpecBaseDialog", "Find String in OpenGL Specifications", 0, QApplication::UnicodeUTF8));
        m_groupboxstring->setTitle(QApplication::translate("CFindExtensionSpecBaseDialog", "Find String", 0, QApplication::UnicodeUTF8));
        m_pushbuttonfindstring->setText(QApplication::translate("CFindExtensionSpecBaseDialog", "Find", 0, QApplication::UnicodeUTF8));
        m_checkboxmatchcase->setText(QApplication::translate("CFindExtensionSpecBaseDialog", "Match case", 0, QApplication::UnicodeUTF8));
        m_checkboxfirstmatch->setText(QApplication::translate("CFindExtensionSpecBaseDialog", "Find first match only", 0, QApplication::UnicodeUTF8));
        m_checkboxfullpaths->setText(QApplication::translate("CFindExtensionSpecBaseDialog", "Display full paths only", 0, QApplication::UnicodeUTF8));
        m_checkboxonematchperfile->setText(QApplication::translate("CFindExtensionSpecBaseDialog", "Find one match per file", 0, QApplication::UnicodeUTF8));
        m_listviewresults->header()->setLabel(0, QApplication::translate("CFindExtensionSpecBaseDialog", "File", 0, QApplication::UnicodeUTF8));
        m_listviewresults->header()->setLabel(1, QApplication::translate("CFindExtensionSpecBaseDialog", "Line number", 0, QApplication::UnicodeUTF8));
        m_listviewresults->header()->setLabel(2, QApplication::translate("CFindExtensionSpecBaseDialog", "Text", 0, QApplication::UnicodeUTF8));
        textLabel1_2->setText(QApplication::translate("CFindExtensionSpecBaseDialog", "Site", 0, QApplication::UnicodeUTF8));
        textLabel1->setText(QApplication::translate("CFindExtensionSpecBaseDialog", "Progress", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CFindExtensionSpecBaseDialog", "Search Status", 0, QApplication::UnicodeUTF8));
        m_pushbuttoncancel->setText(QApplication::translate("CFindExtensionSpecBaseDialog", "Cancel Search", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("CFindExtensionSpecBaseDialog", "Clear", 0, QApplication::UnicodeUTF8));
        m_pushbuttonok->setText(QApplication::translate("CFindExtensionSpecBaseDialog", "&OK", 0, QApplication::UnicodeUTF8));
        m_pushbuttonok->setShortcut(QApplication::translate("CFindExtensionSpecBaseDialog", "Alt+O", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CFindExtensionSpecBaseDialog: public Ui_CFindExtensionSpecBaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDEXTENSIONSPECBASEDLG_H
