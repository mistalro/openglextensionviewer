// --------------------------------------------------------------------------
// Modify these according to the name of the widget
// --------------------------------------------------------------------------

#include <Qt3Support>
#include "../extensionlistwidget/extensionlistwidget.h"

#define CONSTRUCTOR CExtensionListBox

#define CLASS_NAME  "CExtensionListBox"

static char m_headerfile[] = "extensionlistwidget/extensionlistwidget.h";
static char m_tooltip[] = "Extension List Box Dialog";
static char m_description[] = "A widget to view extension lists";
static char m_group[] = "Input";
static char m_name[] = CLASS_NAME;
static QIcon m_icon;

static const char m_domxml[] = 
        "<widget class=\""
        CLASS_NAME
        "\" name=\"display settings widget\">\n"
        " <property name=\"geometry\">\n"
        "  <rect>\n"
        "   <x>0</x>\n"
        "   <y>0</y>\n"
        "   <width>100</width>\n"
        "   <height>100</height>\n"
        "  </rect>\n"
        " </property>\n"
        " <property name=\"toolTip\" >\n"
        "  <string>Extension List Widget</string>\n"
        " </property>\n"
        " <property name=\"whatsThis\" >\n"
        "  <string>Extension List Widget</string>\n"
        " </property>\n"
        "</widget>\n";

