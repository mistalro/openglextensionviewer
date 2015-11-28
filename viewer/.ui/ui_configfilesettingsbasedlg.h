/********************************************************************************
** Form generated from reading UI file 'configfilesettingsbasedlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGFILESETTINGSBASEDLG_H
#define UI_CONFIGFILESETTINGSBASEDLG_H

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

class Ui_CConfigFileSettingsBaseDialog
{
public:
    QGridLayout *gridLayout;
    Q3GroupBox *groupBox11;
    QGridLayout *gridLayout1;
    QLineEdit *m_lineeditconfigfile;
    QLabel *textLabel1;
    QPushButton *m_pushbuttonbrowse;
    Q3GroupBox *groupBox12;
    QGridLayout *gridLayout2;
    QRadioButton *m_radiobuttonloadauto;
    QRadioButton *m_radiobuttonloadprompt;
    QRadioButton *m_radiobuttonloadnoaction;
    Q3GroupBox *m_radiobuttonnoaction;
    QGridLayout *gridLayout3;
    QRadioButton *m_radiobuttonsaveprompt;
    QRadioButton *m_radiobuttonsavenoaction;
    QRadioButton *m_radiobuttonsaveauto;
    QHBoxLayout *hboxLayout;
    QPushButton *m_pushbuttonreset;
    QSpacerItem *spacer1;
    QPushButton *m_pushbuttoncancel;
    QPushButton *m_pushbuttonapply;
    QPushButton *m_pushbuttonok;

    void setupUi(QDialog *CConfigFileSettingsBaseDialog)
    {
        if (CConfigFileSettingsBaseDialog->objectName().isEmpty())
            CConfigFileSettingsBaseDialog->setObjectName(QString::fromUtf8("CConfigFileSettingsBaseDialog"));
        CConfigFileSettingsBaseDialog->resize(541, 373);
        gridLayout = new QGridLayout(CConfigFileSettingsBaseDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox11 = new Q3GroupBox(CConfigFileSettingsBaseDialog);
        groupBox11->setObjectName(QString::fromUtf8("groupBox11"));
        groupBox11->setColumnLayout(0, Qt::Vertical);
        groupBox11->layout()->setSpacing(6);
        groupBox11->layout()->setContentsMargins(11, 11, 11, 11);
        gridLayout1 = new QGridLayout();
        QBoxLayout *boxlayout = qobject_cast<QBoxLayout *>(groupBox11->layout());
        if (boxlayout)
            boxlayout->addLayout(gridLayout1);
        gridLayout1->setAlignment(Qt::AlignTop);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        m_lineeditconfigfile = new QLineEdit(groupBox11);
        m_lineeditconfigfile->setObjectName(QString::fromUtf8("m_lineeditconfigfile"));

        gridLayout1->addWidget(m_lineeditconfigfile, 0, 1, 1, 1);

        textLabel1 = new QLabel(groupBox11);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        textLabel1->setWordWrap(false);

        gridLayout1->addWidget(textLabel1, 0, 0, 1, 1);

        m_pushbuttonbrowse = new QPushButton(groupBox11);
        m_pushbuttonbrowse->setObjectName(QString::fromUtf8("m_pushbuttonbrowse"));

        gridLayout1->addWidget(m_pushbuttonbrowse, 0, 2, 1, 1);


        gridLayout->addWidget(groupBox11, 0, 0, 1, 1);

        groupBox12 = new Q3GroupBox(CConfigFileSettingsBaseDialog);
        groupBox12->setObjectName(QString::fromUtf8("groupBox12"));
        groupBox12->setColumnLayout(0, Qt::Vertical);
        groupBox12->layout()->setSpacing(6);
        groupBox12->layout()->setContentsMargins(11, 11, 11, 11);
        gridLayout2 = new QGridLayout();
        QBoxLayout *boxlayout1 = qobject_cast<QBoxLayout *>(groupBox12->layout());
        if (boxlayout1)
            boxlayout1->addLayout(gridLayout2);
        gridLayout2->setAlignment(Qt::AlignTop);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        m_radiobuttonloadauto = new QRadioButton(groupBox12);
        m_radiobuttonloadauto->setObjectName(QString::fromUtf8("m_radiobuttonloadauto"));

        gridLayout2->addWidget(m_radiobuttonloadauto, 0, 0, 1, 1);

        m_radiobuttonloadprompt = new QRadioButton(groupBox12);
        m_radiobuttonloadprompt->setObjectName(QString::fromUtf8("m_radiobuttonloadprompt"));

        gridLayout2->addWidget(m_radiobuttonloadprompt, 1, 0, 1, 1);

        m_radiobuttonloadnoaction = new QRadioButton(groupBox12);
        m_radiobuttonloadnoaction->setObjectName(QString::fromUtf8("m_radiobuttonloadnoaction"));

        gridLayout2->addWidget(m_radiobuttonloadnoaction, 2, 0, 1, 1);


        gridLayout->addWidget(groupBox12, 1, 0, 1, 1);

        m_radiobuttonnoaction = new Q3GroupBox(CConfigFileSettingsBaseDialog);
        m_radiobuttonnoaction->setObjectName(QString::fromUtf8("m_radiobuttonnoaction"));
        m_radiobuttonnoaction->setColumnLayout(0, Qt::Vertical);
        m_radiobuttonnoaction->layout()->setSpacing(6);
        m_radiobuttonnoaction->layout()->setContentsMargins(11, 11, 11, 11);
        gridLayout3 = new QGridLayout();
        QBoxLayout *boxlayout2 = qobject_cast<QBoxLayout *>(m_radiobuttonnoaction->layout());
        if (boxlayout2)
            boxlayout2->addLayout(gridLayout3);
        gridLayout3->setAlignment(Qt::AlignTop);
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        m_radiobuttonsaveprompt = new QRadioButton(m_radiobuttonnoaction);
        m_radiobuttonsaveprompt->setObjectName(QString::fromUtf8("m_radiobuttonsaveprompt"));

        gridLayout3->addWidget(m_radiobuttonsaveprompt, 1, 0, 1, 1);

        m_radiobuttonsavenoaction = new QRadioButton(m_radiobuttonnoaction);
        m_radiobuttonsavenoaction->setObjectName(QString::fromUtf8("m_radiobuttonsavenoaction"));

        gridLayout3->addWidget(m_radiobuttonsavenoaction, 2, 0, 1, 1);

        m_radiobuttonsaveauto = new QRadioButton(m_radiobuttonnoaction);
        m_radiobuttonsaveauto->setObjectName(QString::fromUtf8("m_radiobuttonsaveauto"));

        gridLayout3->addWidget(m_radiobuttonsaveauto, 0, 0, 1, 1);


        gridLayout->addWidget(m_radiobuttonnoaction, 2, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        m_pushbuttonreset = new QPushButton(CConfigFileSettingsBaseDialog);
        m_pushbuttonreset->setObjectName(QString::fromUtf8("m_pushbuttonreset"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_pushbuttonreset->sizePolicy().hasHeightForWidth());
        m_pushbuttonreset->setSizePolicy(sizePolicy);
        m_pushbuttonreset->setMinimumSize(QSize(80, 30));
        m_pushbuttonreset->setAutoDefault(false);

        hboxLayout->addWidget(m_pushbuttonreset);

        spacer1 = new QSpacerItem(160, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer1);

        m_pushbuttoncancel = new QPushButton(CConfigFileSettingsBaseDialog);
        m_pushbuttoncancel->setObjectName(QString::fromUtf8("m_pushbuttoncancel"));
        sizePolicy.setHeightForWidth(m_pushbuttoncancel->sizePolicy().hasHeightForWidth());
        m_pushbuttoncancel->setSizePolicy(sizePolicy);
        m_pushbuttoncancel->setMinimumSize(QSize(80, 30));
        m_pushbuttoncancel->setAutoDefault(false);

        hboxLayout->addWidget(m_pushbuttoncancel);

        m_pushbuttonapply = new QPushButton(CConfigFileSettingsBaseDialog);
        m_pushbuttonapply->setObjectName(QString::fromUtf8("m_pushbuttonapply"));
        sizePolicy.setHeightForWidth(m_pushbuttonapply->sizePolicy().hasHeightForWidth());
        m_pushbuttonapply->setSizePolicy(sizePolicy);
        m_pushbuttonapply->setMinimumSize(QSize(80, 30));
        m_pushbuttonapply->setAutoDefault(false);

        hboxLayout->addWidget(m_pushbuttonapply);

        m_pushbuttonok = new QPushButton(CConfigFileSettingsBaseDialog);
        m_pushbuttonok->setObjectName(QString::fromUtf8("m_pushbuttonok"));
        sizePolicy.setHeightForWidth(m_pushbuttonok->sizePolicy().hasHeightForWidth());
        m_pushbuttonok->setSizePolicy(sizePolicy);
        m_pushbuttonok->setMinimumSize(QSize(80, 30));

        hboxLayout->addWidget(m_pushbuttonok);


        gridLayout->addLayout(hboxLayout, 3, 0, 1, 1);


        retranslateUi(CConfigFileSettingsBaseDialog);
        QObject::connect(m_lineeditconfigfile, SIGNAL(textChanged(QString)), CConfigFileSettingsBaseDialog, SLOT(lineeditconfigfile_textChanged(QString)));
        QObject::connect(m_pushbuttonbrowse, SIGNAL(clicked()), CConfigFileSettingsBaseDialog, SLOT(pushbuttonbrowse_clicked()));
        QObject::connect(m_radiobuttonloadauto, SIGNAL(clicked()), CConfigFileSettingsBaseDialog, SLOT(radiobuttonloadauto_clicked()));
        QObject::connect(m_radiobuttonloadprompt, SIGNAL(clicked()), CConfigFileSettingsBaseDialog, SLOT(radiobuttonloadprompt_clicked()));
        QObject::connect(m_radiobuttonloadnoaction, SIGNAL(clicked()), CConfigFileSettingsBaseDialog, SLOT(radiobuttonloadnoaction_clicked()));
        QObject::connect(m_radiobuttonsaveauto, SIGNAL(clicked()), CConfigFileSettingsBaseDialog, SLOT(radiobuttonsaveauto_clicked()));
        QObject::connect(m_radiobuttonsaveprompt, SIGNAL(clicked()), CConfigFileSettingsBaseDialog, SLOT(radiobuttonsaveprompt_clicked()));
        QObject::connect(m_radiobuttonsavenoaction, SIGNAL(clicked()), CConfigFileSettingsBaseDialog, SLOT(radiobuttonsavenoaction_clicked()));
        QObject::connect(m_pushbuttoncancel, SIGNAL(clicked()), CConfigFileSettingsBaseDialog, SLOT(pushbuttoncancel_clicked()));
        QObject::connect(m_pushbuttonapply, SIGNAL(clicked()), CConfigFileSettingsBaseDialog, SLOT(pushbuttonapply_clicked()));
        QObject::connect(m_pushbuttonok, SIGNAL(clicked()), CConfigFileSettingsBaseDialog, SLOT(pushbuttonok_clicked()));
        QObject::connect(m_pushbuttonreset, SIGNAL(clicked()), CConfigFileSettingsBaseDialog, SLOT(pushbuttonreset_clicked()));

        QMetaObject::connectSlotsByName(CConfigFileSettingsBaseDialog);
    } // setupUi

    void retranslateUi(QDialog *CConfigFileSettingsBaseDialog)
    {
        CConfigFileSettingsBaseDialog->setWindowTitle(QApplication::translate("CConfigFileSettingsBaseDialog", "Configuration File Settings", 0, QApplication::UnicodeUTF8));
        groupBox11->setTitle(QString());
        textLabel1->setText(QApplication::translate("CConfigFileSettingsBaseDialog", "Default configuration file", 0, QApplication::UnicodeUTF8));
        m_pushbuttonbrowse->setText(QApplication::translate("CConfigFileSettingsBaseDialog", "Browse", 0, QApplication::UnicodeUTF8));
        groupBox12->setTitle(QApplication::translate("CConfigFileSettingsBaseDialog", "Configuration File loading", 0, QApplication::UnicodeUTF8));
        m_radiobuttonloadauto->setText(QApplication::translate("CConfigFileSettingsBaseDialog", "Automatically load configuration file upon start", 0, QApplication::UnicodeUTF8));
        m_radiobuttonloadprompt->setText(QApplication::translate("CConfigFileSettingsBaseDialog", "Prompt for configuration file to load upon start", 0, QApplication::UnicodeUTF8));
        m_radiobuttonloadnoaction->setText(QApplication::translate("CConfigFileSettingsBaseDialog", "Take no action", 0, QApplication::UnicodeUTF8));
        m_radiobuttonnoaction->setTitle(QApplication::translate("CConfigFileSettingsBaseDialog", "Configuration File saving", 0, QApplication::UnicodeUTF8));
        m_radiobuttonsaveprompt->setText(QApplication::translate("CConfigFileSettingsBaseDialog", "Prompt for configuration file to save upon exit", 0, QApplication::UnicodeUTF8));
        m_radiobuttonsavenoaction->setText(QApplication::translate("CConfigFileSettingsBaseDialog", "Take no action", 0, QApplication::UnicodeUTF8));
        m_radiobuttonsaveauto->setText(QApplication::translate("CConfigFileSettingsBaseDialog", "Automatically save configuration file upon exit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_pushbuttonreset->setWhatsThis(QApplication::translate("CConfigFileSettingsBaseDialog", "Abandon all changes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_pushbuttonreset->setText(QApplication::translate("CConfigFileSettingsBaseDialog", "Reset", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_pushbuttoncancel->setWhatsThis(QApplication::translate("CConfigFileSettingsBaseDialog", "Abandon all changes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_pushbuttoncancel->setText(QApplication::translate("CConfigFileSettingsBaseDialog", "Cancel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        m_pushbuttonapply->setWhatsThis(QApplication::translate("CConfigFileSettingsBaseDialog", "Apply changes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        m_pushbuttonapply->setText(QApplication::translate("CConfigFileSettingsBaseDialog", "Apply", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_pushbuttonok->setToolTip(QApplication::translate("CConfigFileSettingsBaseDialog", "Apply changes and close window", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_pushbuttonok->setText(QApplication::translate("CConfigFileSettingsBaseDialog", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CConfigFileSettingsBaseDialog: public Ui_CConfigFileSettingsBaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGFILESETTINGSBASEDLG_H
