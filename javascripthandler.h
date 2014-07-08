#ifndef JAVASCRIPTHANDLER_H
#define JAVASCRIPTHANDLER_H

#include <QWebFrame>
#include <QString>

#include "generate.h"

class javaScriptHandler : public QObject {
    Q_OBJECT

public slots:
    Q_INVOKABLE void webElement(QString str);

public:
    javaScriptHandler();
    void injectJavaScript(QWebFrame *);

private:
    QString * webElementIdentification;
    Generate * userActionList;

};

#endif // JAVASCRIPTHANDLER_H
