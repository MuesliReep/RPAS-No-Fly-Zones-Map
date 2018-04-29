#include "downloader.h"

#include <iostream>
#include <QUrl>

Downloader::Downloader(QObject *parent) : QObject(parent)
{

}

void Downloader::doDownload(QString url)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(downloadComplete(QNetworkReply*)));

    QNetworkRequest request;
    request.setUrl(QUrl(url));
    request.setRawHeader("User-Agent", "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2272.76 Safari/537.36");

    manager->get(request);
}

void Downloader::downloadComplete(QNetworkReply *reply)
{
    QByteArray data;

    if(reply->error() == QNetworkReply::NoError) {
        data = reply->readAll();
    } else {
        QString error = reply->errorString();
        std::cout << error.toStdString() << std::endl;
    }

    emit sendNewData(data);
}
