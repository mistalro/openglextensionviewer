/********************************************************************************
** Form generated from reading UI file 'scripteditorbasedlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCRIPTEDITORBASEDLG_H
#define UI_SCRIPTEDITORBASEDLG_H

#include <Qt3Support/Q3Frame>
#include <Qt3Support/Q3MimeSourceFactory>
#include <Qt3Support/Q3TextEdit>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CScriptEditorBaseDialog
{
public:
    QVBoxLayout *vboxLayout;
    QTabWidget *m_tabscript;
    QWidget *tab;
    QGridLayout *gridLayout;
    Q3TextEdit *m_texteditinternal;
    QWidget *tab_2;
    QGridLayout *gridLayout1;
    Q3TextEdit *m_texteditexternal;
    QHBoxLayout *hboxLayout;
    QPushButton *m_pushbuttoncopy;
    QSpacerItem *spacer1;
    QPushButton *m_pushbuttonsave;
    QPushButton *m_pushbuttonclear;
    QPushButton *m_pushbuttonrestore;
    QPushButton *m_pushbuttoncancel;
    QPushButton *m_pushbuttonapply;
    QPushButton *m_pushbuttonok;

    void setupUi(QDialog *CScriptEditorBaseDialog)
    {
        if (CScriptEditorBaseDialog->objectName().isEmpty())
            CScriptEditorBaseDialog->setObjectName(QString::fromUtf8("CScriptEditorBaseDialog"));
        CScriptEditorBaseDialog->resize(749, 506);
        vboxLayout = new QVBoxLayout(CScriptEditorBaseDialog);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        m_tabscript = new QTabWidget(CScriptEditorBaseDialog);
        m_tabscript->setObjectName(QString::fromUtf8("m_tabscript"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_texteditinternal = new Q3TextEdit(tab);
        m_texteditinternal->setObjectName(QString::fromUtf8("m_texteditinternal"));
        QFont font;
        font.setFamily(QString::fromUtf8("Monospace"));
        m_texteditinternal->setFont(font);
        m_texteditinternal->setReadOnly(true);

        gridLayout->addWidget(m_texteditinternal, 0, 0, 1, 1);

        m_tabscript->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout1 = new QGridLayout(tab_2);
        gridLayout1->setSpacing(6);
        gridLayout1->setContentsMargins(11, 11, 11, 11);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        m_texteditexternal = new Q3TextEdit(tab_2);
        m_texteditexternal->setObjectName(QString::fromUtf8("m_texteditexternal"));
        m_texteditexternal->setFont(font);

        gridLayout1->addWidget(m_texteditexternal, 0, 0, 1, 1);

        m_tabscript->addTab(tab_2, QString());

        vboxLayout->addWidget(m_tabscript);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        m_pushbuttoncopy = new QPushButton(CScriptEditorBaseDialog);
        m_pushbuttoncopy->setObjectName(QString::fromUtf8("m_pushbuttoncopy"));

        hboxLayout->addWidget(m_pushbuttoncopy);

        spacer1 = new QSpacerItem(40, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer1);

        m_pushbuttonsave = new QPushButton(CScriptEditorBaseDialog);
        m_pushbuttonsave->setObjectName(QString::fromUtf8("m_pushbuttonsave"));

        hboxLayout->addWidget(m_pushbuttonsave);

        m_pushbuttonclear = new QPushButton(CScriptEditorBaseDialog);
        m_pushbuttonclear->setObjectName(QString::fromUtf8("m_pushbuttonclear"));

        hboxLayout->addWidget(m_pushbuttonclear);

        m_pushbuttonrestore = new QPushButton(CScriptEditorBaseDialog);
        m_pushbuttonrestore->setObjectName(QString::fromUtf8("m_pushbuttonrestore"));

        hboxLayout->addWidget(m_pushbuttonrestore);

        m_pushbuttoncancel = new QPushButton(CScriptEditorBaseDialog);
        m_pushbuttoncancel->setObjectName(QString::fromUtf8("m_pushbuttoncancel"));

        hboxLayout->addWidget(m_pushbuttoncancel);

        m_pushbuttonapply = new QPushButton(CScriptEditorBaseDialog);
        m_pushbuttonapply->setObjectName(QString::fromUtf8("m_pushbuttonapply"));

        hboxLayout->addWidget(m_pushbuttonapply);

        m_pushbuttonok = new QPushButton(CScriptEditorBaseDialog);
        m_pushbuttonok->setObjectName(QString::fromUtf8("m_pushbuttonok"));
        m_pushbuttonok->setDefault(true);

        hboxLayout->addWidget(m_pushbuttonok);


        vboxLayout->addLayout(hboxLayout);


        retranslateUi(CScriptEditorBaseDialog);
        QObject::connect(m_pushbuttoncopy, SIGNAL(clicked()), CScriptEditorBaseDialog, SLOT(pushbuttoncopy_clicked()));
        QObject::connect(m_pushbuttonsave, SIGNAL(clicked()), CScriptEditorBaseDialog, SLOT(pushbuttonsave_clicked()));
        QObject::connect(m_pushbuttonclear, SIGNAL(clicked()), CScriptEditorBaseDialog, SLOT(pushbuttonclear_clicked()));
        QObject::connect(m_pushbuttonrestore, SIGNAL(clicked()), CScriptEditorBaseDialog, SLOT(pushbuttonrestore_clicked()));
        QObject::connect(m_pushbuttoncancel, SIGNAL(clicked()), CScriptEditorBaseDialog, SLOT(pushbuttoncancel_clicked()));
        QObject::connect(m_pushbuttonapply, SIGNAL(clicked()), CScriptEditorBaseDialog, SLOT(pushbuttonapply_clicked()));
        QObject::connect(m_pushbuttonok, SIGNAL(clicked()), CScriptEditorBaseDialog, SLOT(pushbuttonok_clicked()));

        QMetaObject::connectSlotsByName(CScriptEditorBaseDialog);
    } // setupUi

    void retranslateUi(QDialog *CScriptEditorBaseDialog)
    {
        CScriptEditorBaseDialog->setWindowTitle(QApplication::translate("CScriptEditorBaseDialog", "Script Editor", 0, QApplication::UnicodeUTF8));
        m_tabscript->setTabText(m_tabscript->indexOf(tab), QApplication::translate("CScriptEditorBaseDialog", "Internal Script File", 0, QApplication::UnicodeUTF8));
        m_tabscript->setTabText(m_tabscript->indexOf(tab_2), QApplication::translate("CScriptEditorBaseDialog", "External Script File", 0, QApplication::UnicodeUTF8));
        m_pushbuttoncopy->setText(QApplication::translate("CScriptEditorBaseDialog", "Copy Internal Script", 0, QApplication::UnicodeUTF8));
        m_pushbuttoncopy->setShortcut(QString());
        m_pushbuttonsave->setText(QApplication::translate("CScriptEditorBaseDialog", "Save", 0, QApplication::UnicodeUTF8));
        m_pushbuttonclear->setText(QApplication::translate("CScriptEditorBaseDialog", "Clear", 0, QApplication::UnicodeUTF8));
        m_pushbuttonrestore->setText(QApplication::translate("CScriptEditorBaseDialog", "Restore", 0, QApplication::UnicodeUTF8));
        m_pushbuttoncancel->setText(QApplication::translate("CScriptEditorBaseDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        m_pushbuttonapply->setText(QApplication::translate("CScriptEditorBaseDialog", "Apply", 0, QApplication::UnicodeUTF8));
        m_pushbuttonok->setText(QApplication::translate("CScriptEditorBaseDialog", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CScriptEditorBaseDialog: public Ui_CScriptEditorBaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCRIPTEDITORBASEDLG_H
