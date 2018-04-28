#include "config.h"

static const QString DEFAULT_OUTPUT_DIR   = "/var/www/map/";
static const int     DEFAULT_REFRESH_RATE = 60*60*8; // 8 hours in seconds

Config::Config()
{

}

QString Config::getOutputDir() const
{
    return outputDir;
}

int Config::getRefreshRate() const
{
    return refreshRate;
}
