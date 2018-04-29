#include "serializer.h"

#include <QJsonDocument>

void Serializer::jsonToFile(QJsonObject jsonObject)
{
    QJsonDocument jsonDocument(jsonObject);
}

void Serializer::jsonToFile(QJsonArray jsonArray)
{
    QJsonDocument jsonDocument(jsonArray);
}
