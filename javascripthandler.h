#ifndef JAVASCRIPTHANDLER_H
#define JAVASCRIPTHANDLER_H

#include <QWebFrame>

class javaScriptHandler {

public:
        javaScriptHandler();
        void injectJavaScript(QWebFrame *);

};

#endif // JAVASCRIPTHANDLER_H
