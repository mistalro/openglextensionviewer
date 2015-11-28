// --------------------------------------------------------------------------
// Modify these according to the name of the widget
// --------------------------------------------------------------------------

#include <Qt3Support>
#include "../extfunctionlistwidget/extfunctionlistwidget.h"

#define CONSTRUCTOR CExtensionFunctionListView

#define CLASS_NAME "CExtensionFunctionListView"

static char m_headerfile[] = "extfunctionlistwidget/extfunctionlistwidget.h";
static char m_tooltip[] = "Extension functions list view widget";
static char m_description[] = "A widget to view function constant lists";
static char m_group[] = "Input";
static char m_name[] = CLASS_NAME;
static QIcon m_icon;

static const char m_domxml[] =
        "<widget class=\""
        CLASS_NAME
        "\" name=\"function list widget\">\n"
        " <property name=\"geometry\">\n"
        "  <rect>\n"
        "   <x>0</x>\n"
        "   <y>0</y>\n"
        "   <width>100</width>\n"
        "   <height>100</height>\n"
        "  </rect>\n"
        " </property>\n"
        " <property name=\"toolTip\" >\n"
        "  <string>Function List Widget</string>\n"
        " </property>\n"
        " <property name=\"whatsThis\" >\n"
        "  <string>Function List Widget</string>\n"
        " </property>\n"
        "</widget>\n";
