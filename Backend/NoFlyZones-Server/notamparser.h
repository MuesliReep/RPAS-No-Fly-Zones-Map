#ifndef NOTAMPARSER_H
#define NOTAMPARSER_H

#include <QString>
#include <QJsonArray>
#include <QByteArray>

class NotamParser
{
public:

    static QJsonArray notamXmlToJson(QByteArray xmlData);

    static double DMStoDDConverter(QString DMSValue);
};

#endif // NOTAMPARSER_H
