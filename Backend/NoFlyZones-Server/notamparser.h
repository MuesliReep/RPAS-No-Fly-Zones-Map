#ifndef NOTAMPARSER_H
#define NOTAMPARSER_H

#include <QString>
#include <QJsonArray>

class NotamParser
{
public:

    static QJsonArray notamXmlToJson(QString xmlNotamList);

    static double DMStoDDConverter(QString DMSValue);
};

#endif // NOTAMPARSER_H
