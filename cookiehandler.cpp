#include "cookiehandler.h"

cookiehandler::cookiehandler(){
       mManager = new QNetworkAccessManager(this);
       mManager->setCookieJar(new QNetworkCookieJar(this));
       connect(mManager, SIGNAL(finished(QNetworkReply*)), SLOT(replyFinished(QNetworkReply*)));
}

void cookiehandler::sendPostRequest(QUrl url, QByteArray data){
        mUrl = url;
        QNetworkRequest r(mUrl);
        mManager->post(r, data);
}

void cookiehandler::replyFinished(QNetworkReply *reply){
        if (reply->error() != QNetworkReply::NoError){
            qWarning() << "ERROR:" << reply->errorString();
            return;
        }

        QList<QNetworkCookie>  cookies = mManager->cookieJar()->cookiesForUrl(mUrl);
        qDebug() << "COOKIES for" << mUrl.host() << cookies;
}
