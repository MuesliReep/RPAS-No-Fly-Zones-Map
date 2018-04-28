#ifndef CONFIG_H
#define CONFIG_H

#include <QString>

class Config
{
public:
    Config();

    QString getOutputDir()   const;
    int     getRefreshRate() const;

private:
    QString outputDir;
    int     refreshRate;
};

#endif // CONFIG_H
