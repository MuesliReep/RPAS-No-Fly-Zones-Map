#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class Downloader : public QObject
{
    Q_OBJECT
public:
    explicit Downloader(QObject *parent = nullptr);

    void doDownload(QString url);

signals:
    void sendNewData(QByteArray data);

public slots:

private slots:
    void downloadComplete(QNetworkReply*reply);
};

#endif // DOWNLOADER_H
