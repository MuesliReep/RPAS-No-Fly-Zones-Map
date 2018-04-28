#include "program.h"

#include "notamparser.h"

Program::Program(QObject *parent) : QObject(parent)
{
    // Load config
    config = new Config();

    // Setup timer
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
    timer->setSingleShot(true);
    timer->start(1000);
}

Program::~Program()
{
    delete config;
}

void Program::tick()
{
    // Get latest xml data

    // Parse the new xml data
    QJSonArray notamArray = NotamParser::notamXmlToJson();

    // Output the parsed data to file

    // Reset timer
    timer->start(config->getRefreshRate());
}
