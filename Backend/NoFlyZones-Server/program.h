#ifndef PROGRAM_H
#define PROGRAM_H

#include <QObject>
#include <QTimer>

#include "config.h"
#include "downloader.h"

class Program : public QObject
{
    Q_OBJECT
public:
    explicit Program(QObject *parent = nullptr);
    ~Program();

private:
    Config      config;
    Downloader  downloader;
    QTimer     *timer;

signals:

public slots:
    void receiveNewData(QByteArray xmlData);

private slots:
    void tick();
};

#endif // PROGRAM_H
