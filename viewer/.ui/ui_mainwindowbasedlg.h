/********************************************************************************
** Form generated from reading UI file 'mainwindowbasedlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWBASEDLG_H
#define UI_MAINWINDOWBASEDLG_H

#include <Qt3Support/Q3Frame>
#include <Qt3Support/Q3ListBox>
#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <Qt3Support/Q3ListBoxPixmap>
#include "extensionlistwidget/extensionlistwidget.h"

QT_BEGIN_NAMESPACE

class Ui_CMainWindowBaseDialog
{
public:
    QAction *fileNewAction;
    QAction *fileOpenAction;
    QAction *fileOpenAndMergeAction;
    QAction *fileSaveAction;
    QAction *fileSaveAsAction;
    QAction *unnamed;
    QAction *fileExitAction;
    QAction *editUndoAction;
    QAction *editRedoAction;
    QAction *editCutAction;
    QAction *editCopyAction;
    QAction *editPasteAction;
    QAction *editFindAction;
    QAction *helpContentsAction;
    QAction *helpIndexAction;
    QAction *helpAboutAction;
    QAction *optionsOptionsAction;
    QAction *optionsScript_FilesAction;
    QAction *header_filesDownload_OpenGL_Header_FilesAction;
    QAction *header_filesRead_OpenGL_Header_FilesAction;
    QAction *Action;
    QAction *registryDownload_all_extension_specificationsAction;
    QAction *registryDownload_selected_extension_specificationsAction;
    QAction *registryDownload_new_extension_specificationsAction;
    QAction *registryRead_OpenGL_registryAction;
    QAction *registryRead_selected_extensionsAction;
    QAction *viewAction;
    QAction *viewExamine_pixel_formatsAction;
    QAction *viewExamine_video_card_resolutionsAction;
    QAction *menunew_itemAction;
    QAction *Action_2;
    QAction *optionsFiles_and_Directory_settingsAction;
    QAction *Action_3;
    QAction *registryRead_New_ExtensionsAction;
    QAction *editClear_AllAction;
    QAction *editRemoveAction;
    QAction *editAddAction;
    QAction *editSelect_AllAction;
    QAction *editUndoAction_2;
    QAction *editnew_itemAction;
    QAction *editGenerate_Output_FilesAction;
    QAction *editAction;
    QAction *optionsOutput_FilesAction;
    QAction *optionsConfiguration_FilesAction;
    QAction *searchFindFuncConstAction;
    QAction *searchExtension_SpecificationsAction;
    QAction *registryDownload_all_registry_pagesAction;
    QWidget *widget;
    QVBoxLayout *vboxLayout;
    QTabWidget *m_tabcontrol;
    QWidget *m_pagegl;
    QVBoxLayout *vboxLayout1;
    QGridLayout *gridLayout;
    QLabel *m_textlabelglselected;
    CExtensionListBox *m_listglselected;
    CExtensionListBox *m_listglavailable;
    QLabel *m_textlabelglavailable;
    QWidget *m_pagewgl;
    QGridLayout *gridLayout1;
    QGridLayout *gridLayout2;
    CExtensionListBox *m_listwglselected;
    CExtensionListBox *m_listwglavailable;
    QLabel *m_textlabelwglavailable;
    QLabel *m_textlabelwglselected;
    QWidget *m_pageglx;
    QGridLayout *gridLayout3;
    QGridLayout *gridLayout4;
    CExtensionListBox *m_listglxselected;
    CExtensionListBox *m_listglxavailable;
    QLabel *m_textlabelavailableglx;
    QLabel *m_textlabelselectedglx;
    QWidget *m_pagevendor;
    QGridLayout *gridLayout5;
    QGridLayout *gridLayout6;
    QLabel *m_textlabelvendoravailable;
    CExtensionListBox *m_listvendoravailable;
    CExtensionListBox *m_listvendorselected;
    QLabel *m_textlabelvendorselected;
    QWidget *m_pagenew;
    QGridLayout *gridLayout7;
    QVBoxLayout *vboxLayout2;
    QLabel *m_textlabelavailablenew_2;
    CExtensionListBox *m_listignore;
    QVBoxLayout *vboxLayout3;
    QLabel *m_textlabelavailablenew;
    CExtensionListBox *m_listnew;
    QWidget *TabPage;
    QGridLayout *gridLayout8;
    CExtensionListBox *m_listsystem;
    QHBoxLayout *hboxLayout;
    QLabel *textLabel1;
    QSpacerItem *spacer1;
    QHBoxLayout *hboxLayout1;
    QPushButton *m_pushbuttonclearall;
    QPushButton *m_pushbuttonremove;
    QPushButton *m_pushbuttonadd;
    QPushButton *m_pushbuttonselectall;
    QPushButton *m_pushbuttonundo;
    QPushButton *m_pushbuttonredo;
    QHBoxLayout *hboxLayout2;
    QPushButton *m_pushbuttonchecksystem;
    QPushButton *m_pushbuttongenerate;
    QPushButton *m_pushbuttonexit;
    QMenuBar *MenuBar;
    QMenu *File;
    QMenu *Edit;
    QMenu *Options;
    QMenu *Header_Files;
    QMenu *Registry;
    QMenu *View;
    QMenu *Search;
    QMenu *Help;

    void setupUi(QMainWindow *CMainWindowBaseDialog)
    {
        if (CMainWindowBaseDialog->objectName().isEmpty())
            CMainWindowBaseDialog->setObjectName(QString::fromUtf8("CMainWindowBaseDialog"));
        CMainWindowBaseDialog->setEnabled(true);
        CMainWindowBaseDialog->resize(826, 581);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CMainWindowBaseDialog->sizePolicy().hasHeightForWidth());
        CMainWindowBaseDialog->setSizePolicy(sizePolicy);
        CMainWindowBaseDialog->setMinimumSize(QSize(564, 291));
        CMainWindowBaseDialog->setSizeIncrement(QSize(1, 1));
        fileNewAction = new QAction(CMainWindowBaseDialog);
        fileNewAction->setObjectName(QString::fromUtf8("fileNewAction"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../FORMS-3"), QSize(), QIcon::Normal, QIcon::Off);
        fileNewAction->setIcon(icon);
        fileNewAction->setProperty("name", QVariant(QByteArray("fileNewAction")));
        fileOpenAction = new QAction(CMainWindowBaseDialog);
        fileOpenAction->setObjectName(QString::fromUtf8("fileOpenAction"));
        fileOpenAction->setIcon(icon);
        fileOpenAction->setProperty("name", QVariant(QByteArray("fileOpenAction")));
        fileOpenAndMergeAction = new QAction(CMainWindowBaseDialog);
        fileOpenAndMergeAction->setObjectName(QString::fromUtf8("fileOpenAndMergeAction"));
        fileOpenAndMergeAction->setIcon(icon);
        fileOpenAndMergeAction->setProperty("name", QVariant(QByteArray("fileOpenAndMergeAction")));
        fileSaveAction = new QAction(CMainWindowBaseDialog);
        fileSaveAction->setObjectName(QString::fromUtf8("fileSaveAction"));
        fileSaveAction->setIcon(icon);
        fileSaveAction->setProperty("name", QVariant(QByteArray("fileSaveAction")));
        fileSaveAsAction = new QAction(CMainWindowBaseDialog);
        fileSaveAsAction->setObjectName(QString::fromUtf8("fileSaveAsAction"));
        fileSaveAsAction->setProperty("name", QVariant(QByteArray("fileSaveAsAction")));
        unnamed = new QAction(CMainWindowBaseDialog);
        unnamed->setObjectName(QString::fromUtf8("unnamed"));
        unnamed->setIcon(icon);
        unnamed->setProperty("name", QVariant(QByteArray("unnamed")));
        fileExitAction = new QAction(CMainWindowBaseDialog);
        fileExitAction->setObjectName(QString::fromUtf8("fileExitAction"));
        fileExitAction->setProperty("name", QVariant(QByteArray("fileExitAction")));
        editUndoAction = new QAction(CMainWindowBaseDialog);
        editUndoAction->setObjectName(QString::fromUtf8("editUndoAction"));
        editUndoAction->setIcon(icon);
        editUndoAction->setProperty("name", QVariant(QByteArray("editUndoAction")));
        editRedoAction = new QAction(CMainWindowBaseDialog);
        editRedoAction->setObjectName(QString::fromUtf8("editRedoAction"));
        editRedoAction->setIcon(icon);
        editRedoAction->setProperty("name", QVariant(QByteArray("editRedoAction")));
        editCutAction = new QAction(CMainWindowBaseDialog);
        editCutAction->setObjectName(QString::fromUtf8("editCutAction"));
        editCutAction->setIcon(icon);
        editCutAction->setProperty("name", QVariant(QByteArray("editCutAction")));
        editCopyAction = new QAction(CMainWindowBaseDialog);
        editCopyAction->setObjectName(QString::fromUtf8("editCopyAction"));
        editCopyAction->setIcon(icon);
        editCopyAction->setProperty("name", QVariant(QByteArray("editCopyAction")));
        editPasteAction = new QAction(CMainWindowBaseDialog);
        editPasteAction->setObjectName(QString::fromUtf8("editPasteAction"));
        editPasteAction->setIcon(icon);
        editPasteAction->setProperty("name", QVariant(QByteArray("editPasteAction")));
        editFindAction = new QAction(CMainWindowBaseDialog);
        editFindAction->setObjectName(QString::fromUtf8("editFindAction"));
        editFindAction->setIcon(icon);
        editFindAction->setProperty("name", QVariant(QByteArray("editFindAction")));
        helpContentsAction = new QAction(CMainWindowBaseDialog);
        helpContentsAction->setObjectName(QString::fromUtf8("helpContentsAction"));
        helpContentsAction->setProperty("name", QVariant(QByteArray("helpContentsAction")));
        helpIndexAction = new QAction(CMainWindowBaseDialog);
        helpIndexAction->setObjectName(QString::fromUtf8("helpIndexAction"));
        helpIndexAction->setProperty("name", QVariant(QByteArray("helpIndexAction")));
        helpAboutAction = new QAction(CMainWindowBaseDialog);
        helpAboutAction->setObjectName(QString::fromUtf8("helpAboutAction"));
        helpAboutAction->setProperty("name", QVariant(QByteArray("helpAboutAction")));
        optionsOptionsAction = new QAction(CMainWindowBaseDialog);
        optionsOptionsAction->setObjectName(QString::fromUtf8("optionsOptionsAction"));
        optionsOptionsAction->setProperty("name", QVariant(QByteArray("optionsOptionsAction")));
        optionsScript_FilesAction = new QAction(CMainWindowBaseDialog);
        optionsScript_FilesAction->setObjectName(QString::fromUtf8("optionsScript_FilesAction"));
        optionsScript_FilesAction->setProperty("name", QVariant(QByteArray("optionsScript_FilesAction")));
        header_filesDownload_OpenGL_Header_FilesAction = new QAction(CMainWindowBaseDialog);
        header_filesDownload_OpenGL_Header_FilesAction->setObjectName(QString::fromUtf8("header_filesDownload_OpenGL_Header_FilesAction"));
        header_filesDownload_OpenGL_Header_FilesAction->setProperty("name", QVariant(QByteArray("header_filesDownload_OpenGL_Header_FilesAction")));
        header_filesRead_OpenGL_Header_FilesAction = new QAction(CMainWindowBaseDialog);
        header_filesRead_OpenGL_Header_FilesAction->setObjectName(QString::fromUtf8("header_filesRead_OpenGL_Header_FilesAction"));
        header_filesRead_OpenGL_Header_FilesAction->setProperty("name", QVariant(QByteArray("header_filesRead_OpenGL_Header_FilesAction")));
        Action = new QAction(CMainWindowBaseDialog);
        Action->setObjectName(QString::fromUtf8("Action"));
        Action->setProperty("name", QVariant(QByteArray("Action")));
        registryDownload_all_extension_specificationsAction = new QAction(CMainWindowBaseDialog);
        registryDownload_all_extension_specificationsAction->setObjectName(QString::fromUtf8("registryDownload_all_extension_specificationsAction"));
        registryDownload_all_extension_specificationsAction->setProperty("name", QVariant(QByteArray("registryDownload_all_extension_specificationsAction")));
        registryDownload_selected_extension_specificationsAction = new QAction(CMainWindowBaseDialog);
        registryDownload_selected_extension_specificationsAction->setObjectName(QString::fromUtf8("registryDownload_selected_extension_specificationsAction"));
        registryDownload_selected_extension_specificationsAction->setProperty("name", QVariant(QByteArray("registryDownload_selected_extension_specificationsAction")));
        registryDownload_new_extension_specificationsAction = new QAction(CMainWindowBaseDialog);
        registryDownload_new_extension_specificationsAction->setObjectName(QString::fromUtf8("registryDownload_new_extension_specificationsAction"));
        registryDownload_new_extension_specificationsAction->setProperty("name", QVariant(QByteArray("registryDownload_new_extension_specificationsAction")));
        registryRead_OpenGL_registryAction = new QAction(CMainWindowBaseDialog);
        registryRead_OpenGL_registryAction->setObjectName(QString::fromUtf8("registryRead_OpenGL_registryAction"));
        registryRead_OpenGL_registryAction->setProperty("name", QVariant(QByteArray("registryRead_OpenGL_registryAction")));
        registryRead_selected_extensionsAction = new QAction(CMainWindowBaseDialog);
        registryRead_selected_extensionsAction->setObjectName(QString::fromUtf8("registryRead_selected_extensionsAction"));
        registryRead_selected_extensionsAction->setProperty("name", QVariant(QByteArray("registryRead_selected_extensionsAction")));
        viewAction = new QAction(CMainWindowBaseDialog);
        viewAction->setObjectName(QString::fromUtf8("viewAction"));
        viewAction->setProperty("name", QVariant(QByteArray("viewAction")));
        viewExamine_pixel_formatsAction = new QAction(CMainWindowBaseDialog);
        viewExamine_pixel_formatsAction->setObjectName(QString::fromUtf8("viewExamine_pixel_formatsAction"));
        viewExamine_pixel_formatsAction->setProperty("name", QVariant(QByteArray("viewExamine_pixel_formatsAction")));
        viewExamine_video_card_resolutionsAction = new QAction(CMainWindowBaseDialog);
        viewExamine_video_card_resolutionsAction->setObjectName(QString::fromUtf8("viewExamine_video_card_resolutionsAction"));
        viewExamine_video_card_resolutionsAction->setProperty("name", QVariant(QByteArray("viewExamine_video_card_resolutionsAction")));
        menunew_itemAction = new QAction(CMainWindowBaseDialog);
        menunew_itemAction->setObjectName(QString::fromUtf8("menunew_itemAction"));
        menunew_itemAction->setProperty("name", QVariant(QByteArray("menunew_itemAction")));
        Action_2 = new QAction(CMainWindowBaseDialog);
        Action_2->setObjectName(QString::fromUtf8("Action_2"));
        Action_2->setProperty("name", QVariant(QByteArray("Action_2")));
        optionsFiles_and_Directory_settingsAction = new QAction(CMainWindowBaseDialog);
        optionsFiles_and_Directory_settingsAction->setObjectName(QString::fromUtf8("optionsFiles_and_Directory_settingsAction"));
        optionsFiles_and_Directory_settingsAction->setProperty("name", QVariant(QByteArray("optionsFiles_and_Directory_settingsAction")));
        Action_3 = new QAction(CMainWindowBaseDialog);
        Action_3->setObjectName(QString::fromUtf8("Action_3"));
        Action_3->setProperty("name", QVariant(QByteArray("Action_3")));
        registryRead_New_ExtensionsAction = new QAction(CMainWindowBaseDialog);
        registryRead_New_ExtensionsAction->setObjectName(QString::fromUtf8("registryRead_New_ExtensionsAction"));
        registryRead_New_ExtensionsAction->setProperty("name", QVariant(QByteArray("registryRead_New_ExtensionsAction")));
        editClear_AllAction = new QAction(CMainWindowBaseDialog);
        editClear_AllAction->setObjectName(QString::fromUtf8("editClear_AllAction"));
        editClear_AllAction->setProperty("name", QVariant(QByteArray("editClear_AllAction")));
        editRemoveAction = new QAction(CMainWindowBaseDialog);
        editRemoveAction->setObjectName(QString::fromUtf8("editRemoveAction"));
        editRemoveAction->setProperty("name", QVariant(QByteArray("editRemoveAction")));
        editAddAction = new QAction(CMainWindowBaseDialog);
        editAddAction->setObjectName(QString::fromUtf8("editAddAction"));
        editAddAction->setProperty("name", QVariant(QByteArray("editAddAction")));
        editSelect_AllAction = new QAction(CMainWindowBaseDialog);
        editSelect_AllAction->setObjectName(QString::fromUtf8("editSelect_AllAction"));
        editSelect_AllAction->setProperty("name", QVariant(QByteArray("editSelect_AllAction")));
        editUndoAction_2 = new QAction(CMainWindowBaseDialog);
        editUndoAction_2->setObjectName(QString::fromUtf8("editUndoAction_2"));
        editUndoAction_2->setProperty("name", QVariant(QByteArray("editUndoAction_2")));
        editnew_itemAction = new QAction(CMainWindowBaseDialog);
        editnew_itemAction->setObjectName(QString::fromUtf8("editnew_itemAction"));
        editnew_itemAction->setProperty("name", QVariant(QByteArray("editnew_itemAction")));
        editGenerate_Output_FilesAction = new QAction(CMainWindowBaseDialog);
        editGenerate_Output_FilesAction->setObjectName(QString::fromUtf8("editGenerate_Output_FilesAction"));
        editGenerate_Output_FilesAction->setProperty("name", QVariant(QByteArray("editGenerate_Output_FilesAction")));
        editAction = new QAction(CMainWindowBaseDialog);
        editAction->setObjectName(QString::fromUtf8("editAction"));
        editAction->setProperty("name", QVariant(QByteArray("editAction")));
        optionsOutput_FilesAction = new QAction(CMainWindowBaseDialog);
        optionsOutput_FilesAction->setObjectName(QString::fromUtf8("optionsOutput_FilesAction"));
        optionsOutput_FilesAction->setProperty("name", QVariant(QByteArray("optionsOutput_FilesAction")));
        optionsConfiguration_FilesAction = new QAction(CMainWindowBaseDialog);
        optionsConfiguration_FilesAction->setObjectName(QString::fromUtf8("optionsConfiguration_FilesAction"));
        optionsConfiguration_FilesAction->setProperty("name", QVariant(QByteArray("optionsConfiguration_FilesAction")));
        searchFindFuncConstAction = new QAction(CMainWindowBaseDialog);
        searchFindFuncConstAction->setObjectName(QString::fromUtf8("searchFindFuncConstAction"));
        searchFindFuncConstAction->setProperty("name", QVariant(QByteArray("searchFindFuncConstAction")));
        searchExtension_SpecificationsAction = new QAction(CMainWindowBaseDialog);
        searchExtension_SpecificationsAction->setObjectName(QString::fromUtf8("searchExtension_SpecificationsAction"));
        searchExtension_SpecificationsAction->setProperty("name", QVariant(QByteArray("searchExtension_SpecificationsAction")));
        registryDownload_all_registry_pagesAction = new QAction(CMainWindowBaseDialog);
        registryDownload_all_registry_pagesAction->setObjectName(QString::fromUtf8("registryDownload_all_registry_pagesAction"));
        registryDownload_all_registry_pagesAction->setProperty("name", QVariant(QByteArray("XXXX")));
        widget = new QWidget(CMainWindowBaseDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        vboxLayout = new QVBoxLayout(widget);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        m_tabcontrol = new QTabWidget(widget);
        m_tabcontrol->setObjectName(QString::fromUtf8("m_tabcontrol"));
        m_tabcontrol->setAcceptDrops(true);
        m_tabcontrol->setTabShape(QTabWidget::Rounded);
        m_pagegl = new QWidget();
        m_pagegl->setObjectName(QString::fromUtf8("m_pagegl"));
        vboxLayout1 = new QVBoxLayout(m_pagegl);
        vboxLayout1->setSpacing(6);
        vboxLayout1->setContentsMargins(11, 11, 11, 11);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_textlabelglselected = new QLabel(m_pagegl);
        m_textlabelglselected->setObjectName(QString::fromUtf8("m_textlabelglselected"));
        m_textlabelglselected->setWordWrap(false);

        gridLayout->addWidget(m_textlabelglselected, 0, 1, 1, 1);

        m_listglselected = new CExtensionListBox(m_pagegl);
        m_listglselected->setObjectName(QString::fromUtf8("m_listglselected"));
        QFont font;
        font.setFamily(QString::fromUtf8("Monospace"));
        m_listglselected->setFont(font);
        m_listglselected->setAcceptDrops(true);
        m_listglselected->setSelectionMode(Q3ListBox::Extended);

        gridLayout->addWidget(m_listglselected, 1, 1, 1, 1);

        m_listglavailable = new CExtensionListBox(m_pagegl);
        m_listglavailable->setObjectName(QString::fromUtf8("m_listglavailable"));
        m_listglavailable->setFont(font);
        m_listglavailable->setAcceptDrops(true);
        m_listglavailable->setSelectionMode(Q3ListBox::Extended);

        gridLayout->addWidget(m_listglavailable, 1, 0, 1, 1);

        m_textlabelglavailable = new QLabel(m_pagegl);
        m_textlabelglavailable->setObjectName(QString::fromUtf8("m_textlabelglavailable"));
        m_textlabelglavailable->setWordWrap(false);

        gridLayout->addWidget(m_textlabelglavailable, 0, 0, 1, 1);


        vboxLayout1->addLayout(gridLayout);

        m_tabcontrol->addTab(m_pagegl, QString());
        m_pagewgl = new QWidget();
        m_pagewgl->setObjectName(QString::fromUtf8("m_pagewgl"));
        gridLayout1 = new QGridLayout(m_pagewgl);
        gridLayout1->setSpacing(6);
        gridLayout1->setContentsMargins(11, 11, 11, 11);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        gridLayout2 = new QGridLayout();
        gridLayout2->setSpacing(6);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        m_listwglselected = new CExtensionListBox(m_pagewgl);
        m_listwglselected->setObjectName(QString::fromUtf8("m_listwglselected"));
        m_listwglselected->setFont(font);
        m_listwglselected->setAcceptDrops(true);
        m_listwglselected->setSelectionMode(Q3ListBox::Extended);

        gridLayout2->addWidget(m_listwglselected, 1, 1, 1, 1);

        m_listwglavailable = new CExtensionListBox(m_pagewgl);
        m_listwglavailable->setObjectName(QString::fromUtf8("m_listwglavailable"));
        m_listwglavailable->setFont(font);
        m_listwglavailable->setAcceptDrops(true);
        m_listwglavailable->setSelectionMode(Q3ListBox::Extended);

        gridLayout2->addWidget(m_listwglavailable, 1, 0, 1, 1);

        m_textlabelwglavailable = new QLabel(m_pagewgl);
        m_textlabelwglavailable->setObjectName(QString::fromUtf8("m_textlabelwglavailable"));
        m_textlabelwglavailable->setWordWrap(false);

        gridLayout2->addWidget(m_textlabelwglavailable, 0, 0, 1, 1);

        m_textlabelwglselected = new QLabel(m_pagewgl);
        m_textlabelwglselected->setObjectName(QString::fromUtf8("m_textlabelwglselected"));
        m_textlabelwglselected->setWordWrap(false);

        gridLayout2->addWidget(m_textlabelwglselected, 0, 1, 1, 1);


        gridLayout1->addLayout(gridLayout2, 0, 0, 1, 1);

        m_tabcontrol->addTab(m_pagewgl, QString());
        m_pageglx = new QWidget();
        m_pageglx->setObjectName(QString::fromUtf8("m_pageglx"));
        gridLayout3 = new QGridLayout(m_pageglx);
        gridLayout3->setSpacing(6);
        gridLayout3->setContentsMargins(11, 11, 11, 11);
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        gridLayout4 = new QGridLayout();
        gridLayout4->setSpacing(6);
        gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
        m_listglxselected = new CExtensionListBox(m_pageglx);
        m_listglxselected->setObjectName(QString::fromUtf8("m_listglxselected"));
        m_listglxselected->setFont(font);
        m_listglxselected->setAcceptDrops(true);
        m_listglxselected->setSelectionMode(Q3ListBox::Extended);

        gridLayout4->addWidget(m_listglxselected, 1, 1, 1, 1);

        m_listglxavailable = new CExtensionListBox(m_pageglx);
        m_listglxavailable->setObjectName(QString::fromUtf8("m_listglxavailable"));
        m_listglxavailable->setFont(font);
        m_listglxavailable->setAcceptDrops(true);
        m_listglxavailable->setSelectionMode(Q3ListBox::Extended);

        gridLayout4->addWidget(m_listglxavailable, 1, 0, 1, 1);

        m_textlabelavailableglx = new QLabel(m_pageglx);
        m_textlabelavailableglx->setObjectName(QString::fromUtf8("m_textlabelavailableglx"));
        m_textlabelavailableglx->setAcceptDrops(false);
        m_textlabelavailableglx->setWordWrap(false);

        gridLayout4->addWidget(m_textlabelavailableglx, 0, 0, 1, 1);

        m_textlabelselectedglx = new QLabel(m_pageglx);
        m_textlabelselectedglx->setObjectName(QString::fromUtf8("m_textlabelselectedglx"));
        m_textlabelselectedglx->setWordWrap(false);

        gridLayout4->addWidget(m_textlabelselectedglx, 0, 1, 1, 1);


        gridLayout3->addLayout(gridLayout4, 0, 0, 1, 1);

        m_tabcontrol->addTab(m_pageglx, QString());
        m_pagevendor = new QWidget();
        m_pagevendor->setObjectName(QString::fromUtf8("m_pagevendor"));
        gridLayout5 = new QGridLayout(m_pagevendor);
        gridLayout5->setSpacing(6);
        gridLayout5->setContentsMargins(11, 11, 11, 11);
        gridLayout5->setObjectName(QString::fromUtf8("gridLayout5"));
        gridLayout6 = new QGridLayout();
        gridLayout6->setSpacing(6);
        gridLayout6->setObjectName(QString::fromUtf8("gridLayout6"));
        m_textlabelvendoravailable = new QLabel(m_pagevendor);
        m_textlabelvendoravailable->setObjectName(QString::fromUtf8("m_textlabelvendoravailable"));
        m_textlabelvendoravailable->setWordWrap(false);

        gridLayout6->addWidget(m_textlabelvendoravailable, 0, 0, 1, 1);

        m_listvendoravailable = new CExtensionListBox(m_pagevendor);
        m_listvendoravailable->setObjectName(QString::fromUtf8("m_listvendoravailable"));
        m_listvendoravailable->setFont(font);
        m_listvendoravailable->setAcceptDrops(true);
        m_listvendoravailable->setSelectionMode(Q3ListBox::Extended);

        gridLayout6->addWidget(m_listvendoravailable, 1, 0, 1, 1);

        m_listvendorselected = new CExtensionListBox(m_pagevendor);
        m_listvendorselected->setObjectName(QString::fromUtf8("m_listvendorselected"));
        m_listvendorselected->setFont(font);
        m_listvendorselected->setAcceptDrops(true);
        m_listvendorselected->setFrameShape(QFrame::StyledPanel);
        m_listvendorselected->setSelectionMode(Q3ListBox::Extended);

        gridLayout6->addWidget(m_listvendorselected, 1, 1, 1, 1);

        m_textlabelvendorselected = new QLabel(m_pagevendor);
        m_textlabelvendorselected->setObjectName(QString::fromUtf8("m_textlabelvendorselected"));
        m_textlabelvendorselected->setEnabled(true);
        m_textlabelvendorselected->setAcceptDrops(false);
        m_textlabelvendorselected->setWordWrap(false);

        gridLayout6->addWidget(m_textlabelvendorselected, 0, 1, 1, 1);


        gridLayout5->addLayout(gridLayout6, 0, 0, 1, 1);

        m_tabcontrol->addTab(m_pagevendor, QString());
        m_pagenew = new QWidget();
        m_pagenew->setObjectName(QString::fromUtf8("m_pagenew"));
        gridLayout7 = new QGridLayout(m_pagenew);
        gridLayout7->setSpacing(6);
        gridLayout7->setContentsMargins(11, 11, 11, 11);
        gridLayout7->setObjectName(QString::fromUtf8("gridLayout7"));
        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setSpacing(6);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        m_textlabelavailablenew_2 = new QLabel(m_pagenew);
        m_textlabelavailablenew_2->setObjectName(QString::fromUtf8("m_textlabelavailablenew_2"));
        m_textlabelavailablenew_2->setAcceptDrops(false);
        m_textlabelavailablenew_2->setWordWrap(false);

        vboxLayout2->addWidget(m_textlabelavailablenew_2);

        m_listignore = new CExtensionListBox(m_pagenew);
        m_listignore->setObjectName(QString::fromUtf8("m_listignore"));
        m_listignore->setFont(font);
        m_listignore->setAcceptDrops(true);
        m_listignore->setSelectionMode(Q3ListBox::Extended);

        vboxLayout2->addWidget(m_listignore);


        gridLayout7->addLayout(vboxLayout2, 0, 1, 1, 1);

        vboxLayout3 = new QVBoxLayout();
        vboxLayout3->setSpacing(6);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        m_textlabelavailablenew = new QLabel(m_pagenew);
        m_textlabelavailablenew->setObjectName(QString::fromUtf8("m_textlabelavailablenew"));
        m_textlabelavailablenew->setAcceptDrops(false);
        m_textlabelavailablenew->setWordWrap(false);

        vboxLayout3->addWidget(m_textlabelavailablenew);

        m_listnew = new CExtensionListBox(m_pagenew);
        m_listnew->setObjectName(QString::fromUtf8("m_listnew"));
        m_listnew->setFont(font);
        m_listnew->setAcceptDrops(true);
        m_listnew->setSelectionMode(Q3ListBox::Extended);

        vboxLayout3->addWidget(m_listnew);


        gridLayout7->addLayout(vboxLayout3, 0, 0, 1, 1);

        m_tabcontrol->addTab(m_pagenew, QString());
        TabPage = new QWidget();
        TabPage->setObjectName(QString::fromUtf8("TabPage"));
        gridLayout8 = new QGridLayout(TabPage);
        gridLayout8->setSpacing(6);
        gridLayout8->setContentsMargins(11, 11, 11, 11);
        gridLayout8->setObjectName(QString::fromUtf8("gridLayout8"));
        m_listsystem = new CExtensionListBox(TabPage);
        m_listsystem->setObjectName(QString::fromUtf8("m_listsystem"));
        m_listsystem->setFont(font);
        m_listsystem->setSelectionMode(Q3ListBox::Extended);

        gridLayout8->addWidget(m_listsystem, 1, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        textLabel1 = new QLabel(TabPage);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        textLabel1->setWordWrap(false);

        hboxLayout->addWidget(textLabel1);

        spacer1 = new QSpacerItem(541, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer1);


        gridLayout8->addLayout(hboxLayout, 0, 0, 1, 1);

        m_tabcontrol->addTab(TabPage, QString());

        vboxLayout->addWidget(m_tabcontrol);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        m_pushbuttonclearall = new QPushButton(widget);
        m_pushbuttonclearall->setObjectName(QString::fromUtf8("m_pushbuttonclearall"));

        hboxLayout1->addWidget(m_pushbuttonclearall);

        m_pushbuttonremove = new QPushButton(widget);
        m_pushbuttonremove->setObjectName(QString::fromUtf8("m_pushbuttonremove"));

        hboxLayout1->addWidget(m_pushbuttonremove);

        m_pushbuttonadd = new QPushButton(widget);
        m_pushbuttonadd->setObjectName(QString::fromUtf8("m_pushbuttonadd"));

        hboxLayout1->addWidget(m_pushbuttonadd);

        m_pushbuttonselectall = new QPushButton(widget);
        m_pushbuttonselectall->setObjectName(QString::fromUtf8("m_pushbuttonselectall"));

        hboxLayout1->addWidget(m_pushbuttonselectall);

        m_pushbuttonundo = new QPushButton(widget);
        m_pushbuttonundo->setObjectName(QString::fromUtf8("m_pushbuttonundo"));

        hboxLayout1->addWidget(m_pushbuttonundo);

        m_pushbuttonredo = new QPushButton(widget);
        m_pushbuttonredo->setObjectName(QString::fromUtf8("m_pushbuttonredo"));

        hboxLayout1->addWidget(m_pushbuttonredo);


        vboxLayout->addLayout(hboxLayout1);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        m_pushbuttonchecksystem = new QPushButton(widget);
        m_pushbuttonchecksystem->setObjectName(QString::fromUtf8("m_pushbuttonchecksystem"));

        hboxLayout2->addWidget(m_pushbuttonchecksystem);

        m_pushbuttongenerate = new QPushButton(widget);
        m_pushbuttongenerate->setObjectName(QString::fromUtf8("m_pushbuttongenerate"));

        hboxLayout2->addWidget(m_pushbuttongenerate);

        m_pushbuttonexit = new QPushButton(widget);
        m_pushbuttonexit->setObjectName(QString::fromUtf8("m_pushbuttonexit"));

        hboxLayout2->addWidget(m_pushbuttonexit);


        vboxLayout->addLayout(hboxLayout2);

        CMainWindowBaseDialog->setCentralWidget(widget);
        MenuBar = new QMenuBar(CMainWindowBaseDialog);
        MenuBar->setObjectName(QString::fromUtf8("MenuBar"));
        MenuBar->setGeometry(QRect(0, 0, 826, 23));
        File = new QMenu(MenuBar);
        File->setObjectName(QString::fromUtf8("File"));
        Edit = new QMenu(MenuBar);
        Edit->setObjectName(QString::fromUtf8("Edit"));
        Options = new QMenu(MenuBar);
        Options->setObjectName(QString::fromUtf8("Options"));
        Header_Files = new QMenu(MenuBar);
        Header_Files->setObjectName(QString::fromUtf8("Header_Files"));
        Registry = new QMenu(MenuBar);
        Registry->setObjectName(QString::fromUtf8("Registry"));
        View = new QMenu(MenuBar);
        View->setObjectName(QString::fromUtf8("View"));
        Search = new QMenu(MenuBar);
        Search->setObjectName(QString::fromUtf8("Search"));
        Help = new QMenu(MenuBar);
        Help->setObjectName(QString::fromUtf8("Help"));
        CMainWindowBaseDialog->setMenuBar(MenuBar);

        MenuBar->addAction(File->menuAction());
        MenuBar->addAction(Edit->menuAction());
        MenuBar->addAction(Options->menuAction());
        MenuBar->addAction(Header_Files->menuAction());
        MenuBar->addAction(Registry->menuAction());
        MenuBar->addAction(View->menuAction());
        MenuBar->addAction(Search->menuAction());
        MenuBar->addAction(Help->menuAction());
        File->addAction(fileNewAction);
        File->addAction(fileOpenAction);
        File->addAction(fileOpenAndMergeAction);
        File->addSeparator();
        File->addAction(fileSaveAction);
        File->addAction(fileSaveAsAction);
        File->addSeparator();
        File->addAction(fileExitAction);
        Edit->addAction(editUndoAction);
        Edit->addAction(editRedoAction);
        Edit->addSeparator();
        Edit->addAction(editClear_AllAction);
        Edit->addAction(editRemoveAction);
        Edit->addAction(editAddAction);
        Edit->addAction(editSelect_AllAction);
        Edit->addSeparator();
        Edit->addAction(editnew_itemAction);
        Edit->addAction(editGenerate_Output_FilesAction);
        Edit->addSeparator();
        Edit->addAction(editAction);
        Options->addAction(optionsFiles_and_Directory_settingsAction);
        Options->addAction(optionsScript_FilesAction);
        Options->addAction(optionsOutput_FilesAction);
        Options->addAction(optionsConfiguration_FilesAction);
        Header_Files->addAction(header_filesDownload_OpenGL_Header_FilesAction);
        Header_Files->addSeparator();
        Header_Files->addAction(header_filesRead_OpenGL_Header_FilesAction);
        Registry->addAction(registryDownload_all_registry_pagesAction);
        Registry->addAction(registryDownload_all_extension_specificationsAction);
        Registry->addAction(registryDownload_selected_extension_specificationsAction);
        Registry->addAction(registryDownload_new_extension_specificationsAction);
        Registry->addSeparator();
        Registry->addAction(registryRead_OpenGL_registryAction);
        Registry->addAction(registryRead_selected_extensionsAction);
        Registry->addAction(registryRead_New_ExtensionsAction);
        View->addAction(viewExamine_pixel_formatsAction);
        View->addAction(viewExamine_video_card_resolutionsAction);
        Search->addAction(searchFindFuncConstAction);
        Search->addAction(searchExtension_SpecificationsAction);
        Help->addAction(helpContentsAction);
        Help->addAction(helpIndexAction);
        Help->addSeparator();
        Help->addAction(helpAboutAction);

        retranslateUi(CMainWindowBaseDialog);
        QObject::connect(searchFindFuncConstAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(menubar_searchfindfuncconst_activated()));
        QObject::connect(viewExamine_video_card_resolutionsAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(menubar_viewvideoresolutions_activated()));
        QObject::connect(viewExamine_pixel_formatsAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(menubar_viewpixelformats_activated()));
        QObject::connect(registryRead_selected_extensionsAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(menubar_registryreadselected_activated()));
        QObject::connect(registryRead_OpenGL_registryAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(menubar_registryreadall_activated()));
        QObject::connect(registryDownload_selected_extension_specificationsAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(menubar_registrydownloadselected_activated()));
        QObject::connect(registryDownload_new_extension_specificationsAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(menubar_registrydownloadnew_activated()));
        QObject::connect(registryDownload_all_extension_specificationsAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(menubar_registrydownloadall_activated()));
        QObject::connect(optionsFiles_and_Directory_settingsAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(menubar_optionsfilesdirectorysettings_activated()));
        QObject::connect(optionsScript_FilesAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(menubar_optionsscriptsettings_activated()));
        QObject::connect(m_pushbuttonundo, SIGNAL(clicked()), CMainWindowBaseDialog, SLOT(pushbuttonundo_clicked()));
        QObject::connect(m_pushbuttonselectall, SIGNAL(clicked()), CMainWindowBaseDialog, SLOT(pushbuttonselectall_clicked()));
        QObject::connect(m_pushbuttonremove, SIGNAL(clicked()), CMainWindowBaseDialog, SLOT(pushbuttonremove_clicked()));
        QObject::connect(m_pushbuttonredo, SIGNAL(clicked()), CMainWindowBaseDialog, SLOT(pushbuttonredo_clicked()));
        QObject::connect(m_pushbuttongenerate, SIGNAL(clicked()), CMainWindowBaseDialog, SLOT(pushbuttongenerate_clicked()));
        QObject::connect(m_pushbuttonexit, SIGNAL(clicked()), CMainWindowBaseDialog, SLOT(pushbuttonexit_clicked()));
        QObject::connect(m_pushbuttonclearall, SIGNAL(clicked()), CMainWindowBaseDialog, SLOT(pushbuttonclearall_clicked()));
        QObject::connect(m_pushbuttonchecksystem, SIGNAL(clicked()), CMainWindowBaseDialog, SLOT(pushbuttonchecksystem_clicked()));
        QObject::connect(m_pushbuttonadd, SIGNAL(clicked()), CMainWindowBaseDialog, SLOT(pushbuttonadd_clicked()));
        QObject::connect(helpIndexAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(helpIndex()));
        QObject::connect(helpContentsAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(helpContents()));
        QObject::connect(helpAboutAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(helpAbout()));
        QObject::connect(header_filesRead_OpenGL_Header_FilesAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(menubar_headerfilesreadfiles_activated()));
        QObject::connect(header_filesDownload_OpenGL_Header_FilesAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(menubar_headerfilesdownloadfiles_activated()));
        QObject::connect(fileSaveAsAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(fileSaveAs()));
        QObject::connect(fileSaveAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(fileSave()));
        QObject::connect(fileOpenAndMergeAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(fileOpenAndMerge()));
        QObject::connect(editUndoAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(menubar_editundo_activated()));
        QObject::connect(editRedoAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(menubar_editredo_activated()));
        QObject::connect(registryRead_New_ExtensionsAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(menubar_registryreadnew_activated()));
        QObject::connect(editAddAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(menubar_editadd_activated()));
        QObject::connect(editClear_AllAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(menubar_editclearall_activated()));
        QObject::connect(editRemoveAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(menubar_editremove_activated()));
        QObject::connect(editSelect_AllAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(menubar_editselectall_activated()));
        QObject::connect(editnew_itemAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(menubar_editchecksystem_activated()));
        QObject::connect(editGenerate_Output_FilesAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(menubar_editgenerateoutputfiles_activated()));
        QObject::connect(m_listnew, SIGNAL(doubleClicked(Q3ListBoxItem*)), CMainWindowBaseDialog, SLOT(listnew_doubleClicked(Q3ListBoxItem*)));
        QObject::connect(m_listnew, SIGNAL(itemsDropped(QString&)), CMainWindowBaseDialog, SLOT(listnew_itemsDropped(QString&)));
        QObject::connect(m_listignore, SIGNAL(doubleClicked(Q3ListBoxItem*)), CMainWindowBaseDialog, SLOT(listignore_doubleClicked(Q3ListBoxItem*)));
        QObject::connect(m_listignore, SIGNAL(itemsDropped(QString&)), CMainWindowBaseDialog, SLOT(listignore_itemsDropped(QString&)));
        QObject::connect(m_listsystem, SIGNAL(doubleClicked(Q3ListBoxItem*)), CMainWindowBaseDialog, SLOT(listsystem_doubleClicked(Q3ListBoxItem*)));
        QObject::connect(m_listsystem, SIGNAL(itemsDropped(QString&)), CMainWindowBaseDialog, SLOT(listsystem_itemsDropped(QString&)));
        QObject::connect(m_listvendorselected, SIGNAL(doubleClicked(Q3ListBoxItem*)), CMainWindowBaseDialog, SLOT(listvendorselected_doubleClicked(Q3ListBoxItem*)));
        QObject::connect(m_listvendorselected, SIGNAL(itemsDropped(QString&)), CMainWindowBaseDialog, SLOT(listvendorselected_itemsDropped(QString&)));
        QObject::connect(m_listvendoravailable, SIGNAL(doubleClicked(Q3ListBoxItem*)), CMainWindowBaseDialog, SLOT(listvendoravailable_doubleClicked(Q3ListBoxItem*)));
        QObject::connect(m_listvendoravailable, SIGNAL(itemsDropped(QString&)), CMainWindowBaseDialog, SLOT(listvendoravailable_itemsDropped(QString&)));
        QObject::connect(m_listglxavailable, SIGNAL(doubleClicked(Q3ListBoxItem*)), CMainWindowBaseDialog, SLOT(listglxavailable_doubleClicked(Q3ListBoxItem*)));
        QObject::connect(m_listglxavailable, SIGNAL(itemsDropped(QString&)), CMainWindowBaseDialog, SLOT(listglxavailable_itemsDropped(QString&)));
        QObject::connect(m_listglxselected, SIGNAL(doubleClicked(Q3ListBoxItem*)), CMainWindowBaseDialog, SLOT(listglxselected_doubleClicked(Q3ListBoxItem*)));
        QObject::connect(m_listglxselected, SIGNAL(itemsDropped(QString&)), CMainWindowBaseDialog, SLOT(listglxselected_itemsDropped(QString&)));
        QObject::connect(m_listwglavailable, SIGNAL(doubleClicked(Q3ListBoxItem*)), CMainWindowBaseDialog, SLOT(listwglavailable_doubleClicked(Q3ListBoxItem*)));
        QObject::connect(m_listwglavailable, SIGNAL(itemsDropped(QString&)), CMainWindowBaseDialog, SLOT(listwglavailable_itemsDropped(QString&)));
        QObject::connect(m_listwglselected, SIGNAL(doubleClicked(Q3ListBoxItem*)), CMainWindowBaseDialog, SLOT(listwglselected_doubleClicked(Q3ListBoxItem*)));
        QObject::connect(m_listwglselected, SIGNAL(itemsDropped(QString&)), CMainWindowBaseDialog, SLOT(listwglselected_itemsDropped(QString&)));
        QObject::connect(m_listglavailable, SIGNAL(doubleClicked(Q3ListBoxItem*)), CMainWindowBaseDialog, SLOT(listglavailable_doubleClicked(Q3ListBoxItem*)));
        QObject::connect(m_listglavailable, SIGNAL(itemsDropped(QString&)), CMainWindowBaseDialog, SLOT(listglavailable_itemsDropped(QString&)));
        QObject::connect(m_listglselected, SIGNAL(doubleClicked(Q3ListBoxItem*)), CMainWindowBaseDialog, SLOT(listglselected_doubleClicked(Q3ListBoxItem*)));
        QObject::connect(m_listglselected, SIGNAL(itemsDropped(QString&)), CMainWindowBaseDialog, SLOT(listglselected_itemsDropped(QString&)));
        QObject::connect(optionsOutput_FilesAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(menubar_optionsoutputsettings_activated()));
        QObject::connect(fileNewAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(fileNew()));
        QObject::connect(fileOpenAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(fileOpen()));
        QObject::connect(fileExitAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(fileExit()));
        QObject::connect(optionsConfiguration_FilesAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(menubar_optionsconfigurationfiles_activated()));
        QObject::connect(searchExtension_SpecificationsAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(menubar_searchfindextensionspecs_activated()));
        QObject::connect(registryDownload_all_registry_pagesAction, SIGNAL(activated()), CMainWindowBaseDialog, SLOT(menubar_registrydownloadpages_activated()));

        QMetaObject::connectSlotsByName(CMainWindowBaseDialog);
    } // setupUi

    void retranslateUi(QMainWindow *CMainWindowBaseDialog)
    {
        CMainWindowBaseDialog->setWindowTitle(QApplication::translate("CMainWindowBaseDialog", "OpenGL Extension Class Viewer", 0, QApplication::UnicodeUTF8));
        fileNewAction->setText(QApplication::translate("CMainWindowBaseDialog", "New Configuration", 0, QApplication::UnicodeUTF8));
        fileNewAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "New Configuration", 0, QApplication::UnicodeUTF8));
        fileNewAction->setShortcut(QApplication::translate("CMainWindowBaseDialog", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        fileOpenAction->setText(QApplication::translate("CMainWindowBaseDialog", "Load Configuration", 0, QApplication::UnicodeUTF8));
        fileOpenAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Load Configuration", 0, QApplication::UnicodeUTF8));
        fileOpenAction->setShortcut(QApplication::translate("CMainWindowBaseDialog", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        fileOpenAndMergeAction->setText(QApplication::translate("CMainWindowBaseDialog", "Load and Merge Configuration", 0, QApplication::UnicodeUTF8));
        fileOpenAndMergeAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Load and Merge Configuration", 0, QApplication::UnicodeUTF8));
        fileOpenAndMergeAction->setShortcut(QApplication::translate("CMainWindowBaseDialog", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        fileSaveAction->setText(QApplication::translate("CMainWindowBaseDialog", "Save Configuration", 0, QApplication::UnicodeUTF8));
        fileSaveAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Save", 0, QApplication::UnicodeUTF8));
        fileSaveAction->setShortcut(QApplication::translate("CMainWindowBaseDialog", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        fileSaveAsAction->setText(QApplication::translate("CMainWindowBaseDialog", "Save Configuration As...", 0, QApplication::UnicodeUTF8));
        fileSaveAsAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Save As", 0, QApplication::UnicodeUTF8));
        fileSaveAsAction->setShortcut(QApplication::translate("CMainWindowBaseDialog", "Ctrl+A", 0, QApplication::UnicodeUTF8));
        unnamed->setText(QString());
        unnamed->setIconText(QString());
        fileExitAction->setText(QApplication::translate("CMainWindowBaseDialog", "Exit", 0, QApplication::UnicodeUTF8));
        fileExitAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Exit", 0, QApplication::UnicodeUTF8));
        editUndoAction->setText(QApplication::translate("CMainWindowBaseDialog", "Undo", 0, QApplication::UnicodeUTF8));
        editUndoAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Undo", 0, QApplication::UnicodeUTF8));
        editUndoAction->setShortcut(QApplication::translate("CMainWindowBaseDialog", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        editRedoAction->setText(QApplication::translate("CMainWindowBaseDialog", "Redo", 0, QApplication::UnicodeUTF8));
        editRedoAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Redo", 0, QApplication::UnicodeUTF8));
        editRedoAction->setShortcut(QApplication::translate("CMainWindowBaseDialog", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        editCutAction->setText(QApplication::translate("CMainWindowBaseDialog", "Cut", 0, QApplication::UnicodeUTF8));
        editCutAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Cut", 0, QApplication::UnicodeUTF8));
        editCutAction->setShortcut(QApplication::translate("CMainWindowBaseDialog", "Ctrl+X", 0, QApplication::UnicodeUTF8));
        editCopyAction->setText(QApplication::translate("CMainWindowBaseDialog", "Copy", 0, QApplication::UnicodeUTF8));
        editCopyAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Copy", 0, QApplication::UnicodeUTF8));
        editCopyAction->setShortcut(QApplication::translate("CMainWindowBaseDialog", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        editPasteAction->setText(QApplication::translate("CMainWindowBaseDialog", "Paste", 0, QApplication::UnicodeUTF8));
        editPasteAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Paste", 0, QApplication::UnicodeUTF8));
        editPasteAction->setShortcut(QApplication::translate("CMainWindowBaseDialog", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        editFindAction->setText(QApplication::translate("CMainWindowBaseDialog", "Find...", 0, QApplication::UnicodeUTF8));
        editFindAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Find", 0, QApplication::UnicodeUTF8));
        editFindAction->setShortcut(QApplication::translate("CMainWindowBaseDialog", "Ctrl+F", 0, QApplication::UnicodeUTF8));
        helpContentsAction->setText(QApplication::translate("CMainWindowBaseDialog", "Contents...", 0, QApplication::UnicodeUTF8));
        helpContentsAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Contents", 0, QApplication::UnicodeUTF8));
        helpContentsAction->setShortcut(QString());
        helpIndexAction->setText(QApplication::translate("CMainWindowBaseDialog", "Index...", 0, QApplication::UnicodeUTF8));
        helpIndexAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Index", 0, QApplication::UnicodeUTF8));
        helpIndexAction->setShortcut(QString());
        helpAboutAction->setText(QApplication::translate("CMainWindowBaseDialog", "About", 0, QApplication::UnicodeUTF8));
        helpAboutAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "About", 0, QApplication::UnicodeUTF8));
        helpAboutAction->setShortcut(QString());
        optionsOptionsAction->setText(QString());
        optionsOptionsAction->setIconText(QString());
        optionsScript_FilesAction->setText(QApplication::translate("CMainWindowBaseDialog", "Script Files", 0, QApplication::UnicodeUTF8));
        optionsScript_FilesAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Script Files", 0, QApplication::UnicodeUTF8));
        header_filesDownload_OpenGL_Header_FilesAction->setText(QApplication::translate("CMainWindowBaseDialog", "Download OpenGL Header Files", 0, QApplication::UnicodeUTF8));
        header_filesDownload_OpenGL_Header_FilesAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Download OpenGL Header Files", 0, QApplication::UnicodeUTF8));
        header_filesRead_OpenGL_Header_FilesAction->setText(QApplication::translate("CMainWindowBaseDialog", "Read OpenGL Header Files", 0, QApplication::UnicodeUTF8));
        header_filesRead_OpenGL_Header_FilesAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Read OpenGL Header Files", 0, QApplication::UnicodeUTF8));
        Action->setIconText(QApplication::translate("CMainWindowBaseDialog", "Unnamed", 0, QApplication::UnicodeUTF8));
        Action->setShortcut(QApplication::translate("CMainWindowBaseDialog", "Alt+F, Alt+S", 0, QApplication::UnicodeUTF8));
        registryDownload_all_extension_specificationsAction->setText(QApplication::translate("CMainWindowBaseDialog", "Download All Extension Specifications", 0, QApplication::UnicodeUTF8));
        registryDownload_all_extension_specificationsAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Download all", 0, QApplication::UnicodeUTF8));
        registryDownload_selected_extension_specificationsAction->setText(QApplication::translate("CMainWindowBaseDialog", "Download Selected Extension specifications", 0, QApplication::UnicodeUTF8));
        registryDownload_selected_extension_specificationsAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "download selected", 0, QApplication::UnicodeUTF8));
        registryDownload_new_extension_specificationsAction->setText(QApplication::translate("CMainWindowBaseDialog", "Download New Extension Specifications", 0, QApplication::UnicodeUTF8));
        registryDownload_new_extension_specificationsAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Download New Extension Specifications", 0, QApplication::UnicodeUTF8));
        registryRead_OpenGL_registryAction->setText(QApplication::translate("CMainWindowBaseDialog", "Read All Extension Specifications", 0, QApplication::UnicodeUTF8));
        registryRead_OpenGL_registryAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Read All Extension Specifications", 0, QApplication::UnicodeUTF8));
        registryRead_selected_extensionsAction->setText(QApplication::translate("CMainWindowBaseDialog", "Read Selected Extension Specifications", 0, QApplication::UnicodeUTF8));
        registryRead_selected_extensionsAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Read Selected Extension Specifications", 0, QApplication::UnicodeUTF8));
        viewAction->setText(QApplication::translate("CMainWindowBaseDialog", "OneTwoThree", 0, QApplication::UnicodeUTF8));
        viewAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "OneTwoThree", 0, QApplication::UnicodeUTF8));
        viewExamine_pixel_formatsAction->setText(QApplication::translate("CMainWindowBaseDialog", "Examine Pixel Formats", 0, QApplication::UnicodeUTF8));
        viewExamine_pixel_formatsAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Examine Pixel Formats", 0, QApplication::UnicodeUTF8));
        viewExamine_video_card_resolutionsAction->setText(QApplication::translate("CMainWindowBaseDialog", "Examine Video Card Resolutions", 0, QApplication::UnicodeUTF8));
        viewExamine_video_card_resolutionsAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Examine Video Card Resolutions", 0, QApplication::UnicodeUTF8));
        menunew_itemAction->setText(QApplication::translate("CMainWindowBaseDialog", "new item", 0, QApplication::UnicodeUTF8));
        menunew_itemAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "new item", 0, QApplication::UnicodeUTF8));
        Action_2->setIconText(QApplication::translate("CMainWindowBaseDialog", "Unnamed", 0, QApplication::UnicodeUTF8));
        optionsFiles_and_Directory_settingsAction->setText(QApplication::translate("CMainWindowBaseDialog", "Internet Files and Local Directory settings", 0, QApplication::UnicodeUTF8));
        optionsFiles_and_Directory_settingsAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Internet Files and Local Directory settings", 0, QApplication::UnicodeUTF8));
        Action_3->setIconText(QApplication::translate("CMainWindowBaseDialog", "Examine Pixel Formats", 0, QApplication::UnicodeUTF8));
        registryRead_New_ExtensionsAction->setText(QApplication::translate("CMainWindowBaseDialog", "Read New Extension Specifications", 0, QApplication::UnicodeUTF8));
        registryRead_New_ExtensionsAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Read New Extension Specifications", 0, QApplication::UnicodeUTF8));
        editClear_AllAction->setText(QApplication::translate("CMainWindowBaseDialog", "Clear All", 0, QApplication::UnicodeUTF8));
        editClear_AllAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Clear All", 0, QApplication::UnicodeUTF8));
        editRemoveAction->setText(QApplication::translate("CMainWindowBaseDialog", "Remove", 0, QApplication::UnicodeUTF8));
        editRemoveAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Remove", 0, QApplication::UnicodeUTF8));
        editAddAction->setText(QApplication::translate("CMainWindowBaseDialog", "Add", 0, QApplication::UnicodeUTF8));
        editAddAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Add", 0, QApplication::UnicodeUTF8));
        editSelect_AllAction->setText(QApplication::translate("CMainWindowBaseDialog", "Select All", 0, QApplication::UnicodeUTF8));
        editSelect_AllAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Select All", 0, QApplication::UnicodeUTF8));
        editUndoAction_2->setText(QApplication::translate("CMainWindowBaseDialog", "Undo", 0, QApplication::UnicodeUTF8));
        editUndoAction_2->setIconText(QApplication::translate("CMainWindowBaseDialog", "Undo", 0, QApplication::UnicodeUTF8));
        editnew_itemAction->setText(QApplication::translate("CMainWindowBaseDialog", "Check System", 0, QApplication::UnicodeUTF8));
        editnew_itemAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Check System", 0, QApplication::UnicodeUTF8));
        editGenerate_Output_FilesAction->setText(QApplication::translate("CMainWindowBaseDialog", "Generate Output Files", 0, QApplication::UnicodeUTF8));
        editGenerate_Output_FilesAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Generate Output Files", 0, QApplication::UnicodeUTF8));
        editAction->setText(QString());
        editAction->setIconText(QString());
        optionsOutput_FilesAction->setText(QApplication::translate("CMainWindowBaseDialog", "Output Files", 0, QApplication::UnicodeUTF8));
        optionsOutput_FilesAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Output Files", 0, QApplication::UnicodeUTF8));
        optionsConfiguration_FilesAction->setText(QApplication::translate("CMainWindowBaseDialog", "Configuration Files", 0, QApplication::UnicodeUTF8));
        optionsConfiguration_FilesAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Configuration Files", 0, QApplication::UnicodeUTF8));
        searchFindFuncConstAction->setText(QApplication::translate("CMainWindowBaseDialog", "Constants and Functions", 0, QApplication::UnicodeUTF8));
        searchFindFuncConstAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Constants and Functions", 0, QApplication::UnicodeUTF8));
        searchExtension_SpecificationsAction->setText(QApplication::translate("CMainWindowBaseDialog", "Extension Specifications", 0, QApplication::UnicodeUTF8));
        searchExtension_SpecificationsAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Extension Specifications", 0, QApplication::UnicodeUTF8));
        registryDownload_all_registry_pagesAction->setText(QApplication::translate("CMainWindowBaseDialog", "Download Registry Index Pages", 0, QApplication::UnicodeUTF8));
        registryDownload_all_registry_pagesAction->setIconText(QApplication::translate("CMainWindowBaseDialog", "Download Registry Index Pages", 0, QApplication::UnicodeUTF8));
        m_textlabelglselected->setText(QApplication::translate("CMainWindowBaseDialog", "GL extensions selected", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_listglavailable->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        m_textlabelglavailable->setText(QApplication::translate("CMainWindowBaseDialog", "GL extensions defined in header files", 0, QApplication::UnicodeUTF8));
        m_tabcontrol->setTabText(m_tabcontrol->indexOf(m_pagegl), QApplication::translate("CMainWindowBaseDialog", "GL Extensions", 0, QApplication::UnicodeUTF8));
        m_textlabelwglavailable->setText(QApplication::translate("CMainWindowBaseDialog", "WGL extensions defined in header files", 0, QApplication::UnicodeUTF8));
        m_textlabelwglselected->setText(QApplication::translate("CMainWindowBaseDialog", "WGL extensions selected", 0, QApplication::UnicodeUTF8));
        m_tabcontrol->setTabText(m_tabcontrol->indexOf(m_pagewgl), QApplication::translate("CMainWindowBaseDialog", "WGL Extensions", 0, QApplication::UnicodeUTF8));
        m_textlabelavailableglx->setText(QApplication::translate("CMainWindowBaseDialog", "GLX extensions defined in header files", 0, QApplication::UnicodeUTF8));
        m_textlabelselectedglx->setText(QApplication::translate("CMainWindowBaseDialog", "GLX extensions selected", 0, QApplication::UnicodeUTF8));
        m_tabcontrol->setTabText(m_tabcontrol->indexOf(m_pageglx), QApplication::translate("CMainWindowBaseDialog", "GLX Extensions", 0, QApplication::UnicodeUTF8));
        m_textlabelvendoravailable->setText(QApplication::translate("CMainWindowBaseDialog", "Vendor Extension Prefixes defined in header files", 0, QApplication::UnicodeUTF8));
        m_textlabelvendorselected->setText(QApplication::translate("CMainWindowBaseDialog", "Vendor Extension Prefixes selected", 0, QApplication::UnicodeUTF8));
        m_tabcontrol->setTabText(m_tabcontrol->indexOf(m_pagevendor), QApplication::translate("CMainWindowBaseDialog", "Vendor Prefixes", 0, QApplication::UnicodeUTF8));
        m_textlabelavailablenew_2->setText(QApplication::translate("CMainWindowBaseDialog", "<p align=\"center\"></p>Ignored extensions", 0, QApplication::UnicodeUTF8));
        m_textlabelavailablenew->setText(QApplication::translate("CMainWindowBaseDialog", "<p align=\"center\"></p>New extensions", 0, QApplication::UnicodeUTF8));
        m_tabcontrol->setTabText(m_tabcontrol->indexOf(m_pagenew), QApplication::translate("CMainWindowBaseDialog", "New/Ignored Extensions", 0, QApplication::UnicodeUTF8));
        textLabel1->setText(QApplication::translate("CMainWindowBaseDialog", "Extensions found on system", 0, QApplication::UnicodeUTF8));
        m_tabcontrol->setTabText(m_tabcontrol->indexOf(TabPage), QApplication::translate("CMainWindowBaseDialog", "System Extension List", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_pushbuttonclearall->setToolTip(QApplication::translate("CMainWindowBaseDialog", "Remove all selected items", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_pushbuttonclearall->setText(QApplication::translate("CMainWindowBaseDialog", "Clear All", 0, QApplication::UnicodeUTF8));
        m_pushbuttonclearall->setShortcut(QString());
#ifndef QT_NO_TOOLTIP
        m_pushbuttonremove->setToolTip(QApplication::translate("CMainWindowBaseDialog", "Remove selected items", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_pushbuttonremove->setText(QApplication::translate("CMainWindowBaseDialog", "Remove", 0, QApplication::UnicodeUTF8));
        m_pushbuttonremove->setShortcut(QString());
#ifndef QT_NO_TOOLTIP
        m_pushbuttonadd->setToolTip(QApplication::translate("CMainWindowBaseDialog", "Add selected items", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_pushbuttonadd->setText(QApplication::translate("CMainWindowBaseDialog", "Add", 0, QApplication::UnicodeUTF8));
        m_pushbuttonadd->setShortcut(QString());
#ifndef QT_NO_TOOLTIP
        m_pushbuttonselectall->setToolTip(QApplication::translate("CMainWindowBaseDialog", "Select all items", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_pushbuttonselectall->setText(QApplication::translate("CMainWindowBaseDialog", "Select All", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_pushbuttonundo->setToolTip(QApplication::translate("CMainWindowBaseDialog", "Undo operations", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_pushbuttonundo->setText(QApplication::translate("CMainWindowBaseDialog", "Undo", 0, QApplication::UnicodeUTF8));
        m_pushbuttonundo->setShortcut(QString());
#ifndef QT_NO_TOOLTIP
        m_pushbuttonredo->setToolTip(QApplication::translate("CMainWindowBaseDialog", "Reapply operations", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_pushbuttonredo->setText(QApplication::translate("CMainWindowBaseDialog", "Redo", 0, QApplication::UnicodeUTF8));
        m_pushbuttonredo->setShortcut(QString());
#ifndef QT_NO_TOOLTIP
        m_pushbuttonchecksystem->setToolTip(QApplication::translate("CMainWindowBaseDialog", "Check available OpenGL extensions", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_pushbuttonchecksystem->setText(QApplication::translate("CMainWindowBaseDialog", "Check System", 0, QApplication::UnicodeUTF8));
        m_pushbuttonchecksystem->setShortcut(QString());
#ifndef QT_NO_TOOLTIP
        m_pushbuttongenerate->setToolTip(QApplication::translate("CMainWindowBaseDialog", "Generate source and header files", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_pushbuttongenerate->setText(QApplication::translate("CMainWindowBaseDialog", "Generate Output Files", 0, QApplication::UnicodeUTF8));
        m_pushbuttongenerate->setShortcut(QString());
#ifndef QT_NO_TOOLTIP
        m_pushbuttonexit->setToolTip(QApplication::translate("CMainWindowBaseDialog", "Exit application", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_pushbuttonexit->setText(QApplication::translate("CMainWindowBaseDialog", "Exit", 0, QApplication::UnicodeUTF8));
        m_pushbuttonexit->setShortcut(QString());
        File->setTitle(QApplication::translate("CMainWindowBaseDialog", "File", 0, QApplication::UnicodeUTF8));
        Edit->setTitle(QApplication::translate("CMainWindowBaseDialog", "Edit", 0, QApplication::UnicodeUTF8));
        Options->setTitle(QApplication::translate("CMainWindowBaseDialog", "Options", 0, QApplication::UnicodeUTF8));
        Header_Files->setTitle(QApplication::translate("CMainWindowBaseDialog", "Header Files", 0, QApplication::UnicodeUTF8));
        Registry->setTitle(QApplication::translate("CMainWindowBaseDialog", "Registry", 0, QApplication::UnicodeUTF8));
        View->setTitle(QApplication::translate("CMainWindowBaseDialog", "View", 0, QApplication::UnicodeUTF8));
        Search->setTitle(QApplication::translate("CMainWindowBaseDialog", "Search", 0, QApplication::UnicodeUTF8));
        Help->setTitle(QApplication::translate("CMainWindowBaseDialog", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CMainWindowBaseDialog: public Ui_CMainWindowBaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWBASEDLG_H
