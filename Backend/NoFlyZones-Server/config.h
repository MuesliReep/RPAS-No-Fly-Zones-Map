#ifndef CONFIG_H
#define CONFIG_H

#include <QString>

class Config
{
public:
    Config();

    QString getOutputDir()   const;
    QString getXmlSource()   const;
    int     getRefreshRate() const;

private:
    QString outputDir;
    QString xmlSource;
    int     refreshRate;
};

#endif // CONFIG_H
