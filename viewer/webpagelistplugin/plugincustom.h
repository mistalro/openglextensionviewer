// --------------------------------------------------------------------------
// Modify these according to the name of the widget
// --------------------------------------------------------------------------

#include <Qt3Support>
#include "../webpagelistwidget/webpagelistwidget.h"

#define CONSTRUCTOR CWebPageListView

#define CLASS_NAME "CWebPageListView"

static char m_headerfile[]  = "webpagelistwidget/webpagelistwidget.h";
static char m_tooltip[]     = "Web Page List Widget";
static char m_description[] = "A widget to view web page details";
static char m_group[]       = "Input";
static char m_name[]        = CLASS_NAME;
static QIcon m_icon;

static const char m_domxml[] = 
        "<widget class=\""
        CLASS_NAME
        "\" name=\"web page list view widget\">\n"
        " <property name=\"geometry\">\n"
        "  <rect>\n"
        "   <x>0</x>\n"
        "   <y>0</y>\n"
        "   <width>100</width>\n"
        "   <height>100</height>\n"
        "  </rect>\n"
        " </property>\n"
        " <property name=\"toolTip\" >\n"
        "  <string>Web Page List View Widget</string>\n"
        " </property>\n"
        " <property name=\"whatsThis\" >\n"
        "  <string>Web Page List View Widget</string>\n"
        " </property>\n"
        "</widget>\n";
