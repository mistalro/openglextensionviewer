// --------------------------------------------------------------------------
// Modify these according to the name of the widget
// --------------------------------------------------------------------------

#include <Qt3Support>
#include "../displaysettingswidget/displaysettingswidget.h"

#define CONSTRUCTOR CDisplaySettingsListView

#define CLASS_NAME  "CDisplaySettingsListView"

static char m_headerfile[]  = "displaysettingswidget/displaysettingswidget.h";
static char m_tooltip[]     = "Display Settings Widget";
static char m_description[] = "A widget to view display settings details";
static char m_group[]       = "Input";
static char m_name[]        = CLASS_NAME;
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
	"  <string>Display Settings Widget</string>\n"
	" </property>\n"
	" <property name=\"whatsThis\" >\n"
	"  <string>Display Settings </string>\n"
	" </property>\n"
	"</widget>\n";
