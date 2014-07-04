#ifndef JAVASCRIPTHANDLER_H
#define JAVASCRIPTHANDLER_H

#include <QObject>

class javaScriptHandler : public QObject
{
        Q_OBJECT

public:
        javaScriptHandler(QObject *parent);

public slots:
        void os_foo();

signals:
        void win_bar();

public:
        const QString injectJavaScript();

};

#endif // JAVASCRIPTHANDLER_H
