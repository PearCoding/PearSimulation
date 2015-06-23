#include "pluginmanager.h"
#include <QDebug>

PluginManager* PluginManager::sInstance = 0;

PluginManager::PluginManager(QObject *parent) :
	QObject(parent)
{
	if(sInstance)
	{
		qWarning() << "There is already a pluginmanager";
	}
	else
	{
		sInstance = this;
	}
}

PluginManager::~PluginManager()
{
	if (sInstance == this)
	{
		sInstance = 0;
	}

	qDeleteAll(mPlugins);
}
