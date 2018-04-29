#include "config.h"

#include <QSettings>
#include <QFile>

static const QString DEFAULT_OUTPUT_DIR   = "/var/www/map/";
static const QString DEFAULT_XML_SOURCE   = "http://notaminfo.com/feed?u=Muesli_Reep";
static const int     DEFAULT_REFRESH_RATE = 60*60*8; // 8 hours in seconds

static const QString FILE_NAME = "config.ini";

Config::Config()
{
    if(!QFile::exists(FILE_NAME)) {
        QSettings settings(FILE_NAME, QSettings::IniFormat);

        settings.setValue("Output/Directory",   DEFAULT_OUTPUT_DIR);
        settings.setValue("Source/url",         DEFAULT_XML_SOURCE);
        settings.setValue("Source/RefreshRate", DEFAULT_REFRESH_RATE);
    }

    QSettings settings(FILE_NAME, QSettings::IniFormat);

    outputDir   = settings.value("Output/Directory",   DEFAULT_OUTPUT_DIR)   .toString();
    xmlSource   = settings.value("Source/url",         DEFAULT_XML_SOURCE)   .toString();
    refreshRate = settings.value("Source/RefreshRate", DEFAULT_REFRESH_RATE) .toInt();
}

QString Config::getOutputDir() const
{
    return outputDir;
}

QString Config::getXmlSource() const
{
    return xmlSource;
}

int Config::getRefreshRate() const
{
    return refreshRate;
}
