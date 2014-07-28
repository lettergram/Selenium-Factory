/*
 * Author: Austin Walters
 * Last Modified: July 28, 2014
 * Project: Selenium Factory
 */

#ifndef JAVASCRIPTHANDLER_H
#define JAVASCRIPTHANDLER_H

#include <QWebFrame>
#include <QString>

#include "generate.h"

class javaScriptHandler : public QObject {
    Q_OBJECT

public slots:

    Q_INVOKABLE void webElement(QString);

public:

    javaScriptHandler(Generate *);
    void injectJavaScript(QWebFrame *);
    Generate * outPutUserActions();
    void turnOn();
    void turnOff();

private:

    QString * webElementIdentification;
    Generate * userActionList;
    bool collect;

};

#endif // JAVASCRIPTHANDLER_H
