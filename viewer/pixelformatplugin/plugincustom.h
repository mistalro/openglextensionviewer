// --------------------------------------------------------------------------
// Modify these according to the name of the widget
// --------------------------------------------------------------------------

#include <Qt3Support>
#include "../pixelformatwidget/pixelformatwidget.h"

#define CONSTRUCTOR CPixelFormatListView

#define CLASS_NAME  "CPixelFormatListView"

static char m_headerfile[] = "pixelformatwidget/pixelformatwidget.h";
static char m_tooltip[] = "Pixel Format Widget";
static char m_description[] = "A widget to view pixel formats";
static char m_group[] = "Input";
static char m_name[]  = CLASS_NAME;
static QIcon m_icon;

static const char m_domxml[] = 
        "<widget class=\""
        CLASS_NAME
        "\" name=\"pixel format widget\">\n"
        " <property name=\"geometry\">\n"
        "  <rect>\n"
        "   <x>0</x>\n"
        "   <y>0</y>\n"
        "   <width>100</width>\n"
        "   <height>100</height>\n"
        "  </rect>\n"
        " </property>\n"
        " <property name=\"toolTip\" >\n"
        "  <string>Pixel Format Widget</string>\n"
        " </property>\n"
        " <property name=\"whatsThis\" >\n"
        "  <string>Pixel Format</string>\n"
        " </property>\n"
        "</widget>\n";
