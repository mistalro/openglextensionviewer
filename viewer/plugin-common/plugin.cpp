// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include "plugincustom.h"
#include "plugin.h"

// --------------------------------------------------------------------------
// Nothing below this comment needs to be changed
// --------------------------------------------------------------------------

CustomWidgetPlugin::CustomWidgetPlugin( QObject *parent ) : QObject( parent)
{
	initialized = false;
}

void CustomWidgetPlugin::initialize( QDesignerFormEditorInterface * /*core */)
{
	if ( initialized )
		return;

	initialized = true;
}

bool CustomWidgetPlugin::isInitialized() const
	{
	return initialized;
	}

QWidget *CustomWidgetPlugin::createWidget( QWidget *parent )
{
	return new CONSTRUCTOR(parent);
}

QString CustomWidgetPlugin::name() const
{
	return m_name;
}

QString CustomWidgetPlugin::group() const
{
	return m_group;
}

QIcon CustomWidgetPlugin::icon() const
{
	return m_icon;
}

QString CustomWidgetPlugin::toolTip() const
{
	return m_tooltip;
}

QString CustomWidgetPlugin::whatsThis() const
{
	return m_description;
}

bool CustomWidgetPlugin::isContainer() const
{
	return FALSE;
}

QString CustomWidgetPlugin::domXml() const
{
	return m_domxml;
}

QString CustomWidgetPlugin::includeFile() const
{
	return m_headerfile;
}

Q_EXPORT_PLUGIN( CustomWidgetPlugin )
