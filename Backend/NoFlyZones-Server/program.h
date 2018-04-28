#ifndef PROGRAM_H
#define PROGRAM_H

#include <QObject>
#include <QTimer>

#include "config.h"

class Program : public QObject
{
    Q_OBJECT
public:
    explicit Program(QObject *parent = nullptr);
    ~Program();

private:
    Config *config;
    QTimer *timer;

signals:

public slots:

private slots:
    void tick();
};

#endif // PROGRAM_H
