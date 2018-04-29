#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <QJsonObject>
#include <QJsonArray>

class Serializer
{
public:
    static void jsonToFile(QJsonObject jsonObject);
    static void jsonToFile(QJsonArray  jsonArray);
};

#endif // SERIALIZER_H
