#ifndef COOKIEHANDLER_H
#define COOKIEHANDLER_H

/**
 * Repurposed from: http://developer.nokia.com/community/wiki/How_to_use_http_cookies_with_Qt
 *
 * TODO - research:
 * 1. http://stackoverflow.com/questions/4509441/qt-http-post-issue-when-server-requires-cookies
 **/

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkCookieJar>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QDebug>

class cookiehandler : public QObject{
    Q_OBJECT

    public:

        cookiehandler();

        void sendPostRequest(QUrl, QByteArray);

        virtual ~cookiehandler();

    private slots:

        void replyFinished(QNetworkReply *reply);

    private:

        QNetworkAccessManager *mManager;
        QUrl mUrl;

};

#endif // COOKIEHANDLER_H
