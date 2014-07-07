#ifndef JAVASCRIPTHANDLER_H
#define JAVASCRIPTHANDLER_H

#include <QWebFrame>
#include <QString>

class javaScriptHandler {

public:
        javaScriptHandler();
        void injectJavaScript(QWebFrame *);

private:

        QString * webElementIdentification;

};

#endif // JAVASCRIPTHANDLER_H
