#include "program.h"

#include "notamparser.h"
#include "serializer.h"

#include <QJsonObject>
#include <QJsonArray>

Program::Program(QObject *parent) : QObject(parent)
{
    // Load config
    //config = new Config();

    // Setup downloader
    connect(&downloader, SIGNAL(sendNewData(QByteArray)), this, SLOT(receiveNewData(QByteArray)));

    // Setup timer
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
    timer->setSingleShot(true);
    timer->start(1000);
}

Program::~Program()
{

}

void Program::tick()
{
    // Request new XML data
    downloader.doDownload(config.getXmlSource());
}

void Program::receiveNewData(QByteArray xmlData)
{
    // Parse the new xml data
    QJsonArray notamArray = NotamParser::notamXmlToJson(xmlData);

    // Output the parsed data to file
    Serializer::jsonToFile(notamArray);

    // Reset timer
    timer->start(config.getRefreshRate() * 1000);
}
