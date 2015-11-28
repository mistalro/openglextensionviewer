/********************************************************************************
** Form generated from reading UI file 'generateprogressbasedlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERATEPROGRESSBASEDLG_H
#define UI_GENERATEPROGRESSBASEDLG_H

#include <Qt3Support/Q3GroupBox>
#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CGenerateProgressBaseDialog
{
public:
    QVBoxLayout *vboxLayout;
    Q3GroupBox *m_groupboxheader;
    QVBoxLayout *vboxLayout1;
    QLineEdit *m_editheader;
    QProgressBar *m_progressheader;
    Q3GroupBox *m_groupboxsource;
    QVBoxLayout *vboxLayout2;
    QLineEdit *m_editsource;
    QProgressBar *m_progresssource;

    void setupUi(QDialog *CGenerateProgressBaseDialog)
    {
        if (CGenerateProgressBaseDialog->objectName().isEmpty())
            CGenerateProgressBaseDialog->setObjectName(QString::fromUtf8("CGenerateProgressBaseDialog"));
        CGenerateProgressBaseDialog->resize(361, 220);
        vboxLayout = new QVBoxLayout(CGenerateProgressBaseDialog);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        m_groupboxheader = new Q3GroupBox(CGenerateProgressBaseDialog);
        m_groupboxheader->setObjectName(QString::fromUtf8("m_groupboxheader"));
        m_groupboxheader->setColumnLayout(0, Qt::Vertical);
        m_groupboxheader->layout()->setSpacing(6);
        m_groupboxheader->layout()->setContentsMargins(11, 11, 11, 11);
        vboxLayout1 = new QVBoxLayout();
        QBoxLayout *boxlayout = qobject_cast<QBoxLayout *>(m_groupboxheader->layout());
        if (boxlayout)
            boxlayout->addLayout(vboxLayout1);
        vboxLayout1->setAlignment(Qt::AlignTop);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        m_editheader = new QLineEdit(m_groupboxheader);
        m_editheader->setObjectName(QString::fromUtf8("m_editheader"));
        m_editheader->setReadOnly(true);

        vboxLayout1->addWidget(m_editheader);

        m_progressheader = new QProgressBar(m_groupboxheader);
        m_progressheader->setObjectName(QString::fromUtf8("m_progressheader"));

        vboxLayout1->addWidget(m_progressheader);


        vboxLayout->addWidget(m_groupboxheader);

        m_groupboxsource = new Q3GroupBox(CGenerateProgressBaseDialog);
        m_groupboxsource->setObjectName(QString::fromUtf8("m_groupboxsource"));
        m_groupboxsource->setColumnLayout(0, Qt::Vertical);
        m_groupboxsource->layout()->setSpacing(6);
        m_groupboxsource->layout()->setContentsMargins(11, 11, 11, 11);
        vboxLayout2 = new QVBoxLayout();
        QBoxLayout *boxlayout1 = qobject_cast<QBoxLayout *>(m_groupboxsource->layout());
        if (boxlayout1)
            boxlayout1->addLayout(vboxLayout2);
        vboxLayout2->setAlignment(Qt::AlignTop);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        m_editsource = new QLineEdit(m_groupboxsource);
        m_editsource->setObjectName(QString::fromUtf8("m_editsource"));
        m_editsource->setReadOnly(true);

        vboxLayout2->addWidget(m_editsource);

        m_progresssource = new QProgressBar(m_groupboxsource);
        m_progresssource->setObjectName(QString::fromUtf8("m_progresssource"));

        vboxLayout2->addWidget(m_progresssource);


        vboxLayout->addWidget(m_groupboxsource);


        retranslateUi(CGenerateProgressBaseDialog);

        QMetaObject::connectSlotsByName(CGenerateProgressBaseDialog);
    } // setupUi

    void retranslateUi(QDialog *CGenerateProgressBaseDialog)
    {
        CGenerateProgressBaseDialog->setWindowTitle(QApplication::translate("CGenerateProgressBaseDialog", "Generate Files", 0, QApplication::UnicodeUTF8));
        m_groupboxheader->setTitle(QString());
        m_groupboxsource->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class CGenerateProgressBaseDialog: public Ui_CGenerateProgressBaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATEPROGRESSBASEDLG_H
