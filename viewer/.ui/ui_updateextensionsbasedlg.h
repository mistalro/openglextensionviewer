/********************************************************************************
** Form generated from reading UI file 'updateextensionsbasedlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATEEXTENSIONSBASEDLG_H
#define UI_UPDATEEXTENSIONSBASEDLG_H

#include <Qt3Support/Q3Frame>
#include <Qt3Support/Q3GroupBox>
#include <Qt3Support/Q3ListBox>
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
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CUpdateExtensionsBaseDialog
{
public:
    QVBoxLayout *vboxLayout;
    Q3GroupBox *groupBox16;
    QVBoxLayout *vboxLayout1;
    QLabel *m_textextensionsnotfound;
    Q3ListBox *m_listboxextensionsnotfound;
    QLabel *m_textwhattodo;
    QCheckBox *m_checkboxdownloadheaders;
    QCheckBox *m_checkboxreadheaders;
    QCheckBox *m_checkboxdownloadregistry;
    QCheckBox *m_checkboxreadregistry;
    QCheckBox *m_checkboxignoreextensions;
    QHBoxLayout *hboxLayout;
    QPushButton *m_pushbuttonreset;
    QSpacerItem *spacer1;
    QPushButton *m_pushbuttoncancel;
    QPushButton *m_pushbuttonapply;
    QPushButton *m_pushbuttonok;

    void setupUi(QDialog *CUpdateExtensionsBaseDialog)
    {
        if (CUpdateExtensionsBaseDialog->objectName().isEmpty())
            CUpdateExtensionsBaseDialog->setObjectName(QString::fromUtf8("CUpdateExtensionsBaseDialog"));
        CUpdateExtensionsBaseDialog->resize(447, 492);
        vboxLayout = new QVBoxLayout(CUpdateExtensionsBaseDialog);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        groupBox16 = new Q3GroupBox(CUpdateExtensionsBaseDialog);
        groupBox16->setObjectName(QString::fromUtf8("groupBox16"));
        groupBox16->setColumnLayout(0, Qt::Vertical);
        groupBox16->layout()->setSpacing(6);
        groupBox16->layout()->setContentsMargins(11, 11, 11, 11);
        vboxLayout1 = new QVBoxLayout();
        QBoxLayout *boxlayout = qobject_cast<QBoxLayout *>(groupBox16->layout());
        if (boxlayout)
            boxlayout->addLayout(vboxLayout1);
        vboxLayout1->setAlignment(Qt::AlignTop);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        m_textextensionsnotfound = new QLabel(groupBox16);
        m_textextensionsnotfound->setObjectName(QString::fromUtf8("m_textextensionsnotfound"));
        m_textextensionsnotfound->setWordWrap(false);

        vboxLayout1->addWidget(m_textextensionsnotfound);

        m_listboxextensionsnotfound = new Q3ListBox(groupBox16);
        m_listboxextensionsnotfound->setObjectName(QString::fromUtf8("m_listboxextensionsnotfound"));
        QFont font;
        font.setFamily(QString::fromUtf8("Monospace"));
        m_listboxextensionsnotfound->setFont(font);
        m_listboxextensionsnotfound->setSelectionMode(Q3ListBox::Single);

        vboxLayout1->addWidget(m_listboxextensionsnotfound);

        m_textwhattodo = new QLabel(groupBox16);
        m_textwhattodo->setObjectName(QString::fromUtf8("m_textwhattodo"));
        m_textwhattodo->setWordWrap(false);

        vboxLayout1->addWidget(m_textwhattodo);

        m_checkboxdownloadheaders = new QCheckBox(groupBox16);
        m_checkboxdownloadheaders->setObjectName(QString::fromUtf8("m_checkboxdownloadheaders"));
        m_checkboxdownloadheaders->setChecked(false);

        vboxLayout1->addWidget(m_checkboxdownloadheaders);

        m_checkboxreadheaders = new QCheckBox(groupBox16);
        m_checkboxreadheaders->setObjectName(QString::fromUtf8("m_checkboxreadheaders"));
        m_checkboxreadheaders->setChecked(false);

        vboxLayout1->addWidget(m_checkboxreadheaders);

        m_checkboxdownloadregistry = new QCheckBox(groupBox16);
        m_checkboxdownloadregistry->setObjectName(QString::fromUtf8("m_checkboxdownloadregistry"));
        m_checkboxdownloadregistry->setChecked(false);

        vboxLayout1->addWidget(m_checkboxdownloadregistry);

        m_checkboxreadregistry = new QCheckBox(groupBox16);
        m_checkboxreadregistry->setObjectName(QString::fromUtf8("m_checkboxreadregistry"));
        m_checkboxreadregistry->setChecked(false);

        vboxLayout1->addWidget(m_checkboxreadregistry);

        m_checkboxignoreextensions = new QCheckBox(groupBox16);
        m_checkboxignoreextensions->setObjectName(QString::fromUtf8("m_checkboxignoreextensions"));

        vboxLayout1->addWidget(m_checkboxignoreextensions);


        vboxLayout->addWidget(groupBox16);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        m_pushbuttonreset = new QPushButton(CUpdateExtensionsBaseDialog);
        m_pushbuttonreset->setObjectName(QString::fromUtf8("m_pushbuttonreset"));

        hboxLayout->addWidget(m_pushbuttonreset);

        spacer1 = new QSpacerItem(240, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer1);

        m_pushbuttoncancel = new QPushButton(CUpdateExtensionsBaseDialog);
        m_pushbuttoncancel->setObjectName(QString::fromUtf8("m_pushbuttoncancel"));

        hboxLayout->addWidget(m_pushbuttoncancel);

        m_pushbuttonapply = new QPushButton(CUpdateExtensionsBaseDialog);
        m_pushbuttonapply->setObjectName(QString::fromUtf8("m_pushbuttonapply"));

        hboxLayout->addWidget(m_pushbuttonapply);

        m_pushbuttonok = new QPushButton(CUpdateExtensionsBaseDialog);
        m_pushbuttonok->setObjectName(QString::fromUtf8("m_pushbuttonok"));
        m_pushbuttonok->setDefault(true);

        hboxLayout->addWidget(m_pushbuttonok);


        vboxLayout->addLayout(hboxLayout);


        retranslateUi(CUpdateExtensionsBaseDialog);
        QObject::connect(m_checkboxreadheaders, SIGNAL(toggled(bool)), CUpdateExtensionsBaseDialog, SLOT(checkboxreadheaders_toggled(bool)));
        QObject::connect(m_checkboxdownloadheaders, SIGNAL(toggled(bool)), CUpdateExtensionsBaseDialog, SLOT(checkboxdownloadheaders_toggled(bool)));
        QObject::connect(m_checkboxreadregistry, SIGNAL(toggled(bool)), CUpdateExtensionsBaseDialog, SLOT(checkboxreadregistry_toggled(bool)));
        QObject::connect(m_checkboxdownloadregistry, SIGNAL(toggled(bool)), CUpdateExtensionsBaseDialog, SLOT(checkboxdownloadregistry_toggled(bool)));
        QObject::connect(m_checkboxignoreextensions, SIGNAL(toggled(bool)), CUpdateExtensionsBaseDialog, SLOT(checkboxignoreextensions_toggled(bool)));
        QObject::connect(m_listboxextensionsnotfound, SIGNAL(doubleClicked(Q3ListBoxItem*)), CUpdateExtensionsBaseDialog, SLOT(listboxextensionsnotfound_doubleClicked(Q3ListBoxItem*)));
        QObject::connect(m_pushbuttonreset, SIGNAL(clicked()), CUpdateExtensionsBaseDialog, SLOT(pushbuttonreset_clicked()));
        QObject::connect(m_pushbuttoncancel, SIGNAL(clicked()), CUpdateExtensionsBaseDialog, SLOT(pushbuttoncancel_clicked()));
        QObject::connect(m_pushbuttonapply, SIGNAL(clicked()), CUpdateExtensionsBaseDialog, SLOT(pushbuttonapply_clicked()));
        QObject::connect(m_pushbuttonok, SIGNAL(clicked()), CUpdateExtensionsBaseDialog, SLOT(pushbuttonok_clicked()));

        QMetaObject::connectSlotsByName(CUpdateExtensionsBaseDialog);
    } // setupUi

    void retranslateUi(QDialog *CUpdateExtensionsBaseDialog)
    {
        CUpdateExtensionsBaseDialog->setWindowTitle(QApplication::translate("CUpdateExtensionsBaseDialog", "Update Extensions", 0, QApplication::UnicodeUTF8));
        groupBox16->setTitle(QString());
        m_textextensionsnotfound->setText(QApplication::translate("CUpdateExtensionsBaseDialog", "The following extensions have been found, \n"
"but are not defined in any of the extension lists:", 0, QApplication::UnicodeUTF8));
        m_textwhattodo->setText(QApplication::translate("CUpdateExtensionsBaseDialog", "Which of the following actions should be taken?", 0, QApplication::UnicodeUTF8));
        m_checkboxdownloadheaders->setText(QApplication::translate("CUpdateExtensionsBaseDialog", "Download the latest extension header files", 0, QApplication::UnicodeUTF8));
        m_checkboxreadheaders->setText(QApplication::translate("CUpdateExtensionsBaseDialog", "Read the extension header files", 0, QApplication::UnicodeUTF8));
        m_checkboxdownloadregistry->setText(QApplication::translate("CUpdateExtensionsBaseDialog", "Download the latest registry specification files", 0, QApplication::UnicodeUTF8));
        m_checkboxreadregistry->setText(QApplication::translate("CUpdateExtensionsBaseDialog", "Read the registry specification files", 0, QApplication::UnicodeUTF8));
        m_checkboxignoreextensions->setText(QApplication::translate("CUpdateExtensionsBaseDialog", "Add these extensions to the ignored list", 0, QApplication::UnicodeUTF8));
        m_pushbuttonreset->setText(QApplication::translate("CUpdateExtensionsBaseDialog", "Reset", 0, QApplication::UnicodeUTF8));
        m_pushbuttoncancel->setText(QApplication::translate("CUpdateExtensionsBaseDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        m_pushbuttonapply->setText(QApplication::translate("CUpdateExtensionsBaseDialog", "Apply", 0, QApplication::UnicodeUTF8));
        m_pushbuttonok->setText(QApplication::translate("CUpdateExtensionsBaseDialog", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CUpdateExtensionsBaseDialog: public Ui_CUpdateExtensionsBaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATEEXTENSIONSBASEDLG_H
