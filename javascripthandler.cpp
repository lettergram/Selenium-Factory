#include "javascripthandler.h"
#include <QDebug>

javaScriptHandler::javaScriptHandler(QObject *parent) :
    QObject(parent){

}

void javaScriptHandler::os_foo(){
        qDebug() << "foo called, it want's it's bar back";
};

/**
 * @brief javaScriptHandler::injectJavaScript - Returns string of java script
 *          to inject into the web page. Used for callback functions.
 * @return string of java script to inject
 */
const QString javaScriptHandler::injectJavaScript(){

    QString javaScript;

    javaScript =  "'<br>Testing<br> <script>alert('a');</script>'";
    //javaScript += "function tester (str) { alert(str); return 'function call'; }\n";

/*
    javaScript += "function clickHandler(e){\n";
    javaScript += "\t'use strict';\n";
    javaScript += "\tvar alertString, elem, evt = e ? e:event;\n";
    javaScript += "\tif (evt.srcElement) {\n";
    javaScript += "\t\telem = evt.srcElement;\n";
    javaScript += "\t}else if (evt.target) {\n";
    javaScript += "\t\telem = evt.target;\n";
    javaScript += "\t}\n\n";
    javaScript += "\talertString = 'Tag=<'+ elem.tagName + '>';\n";
    javaScript += "\tif(elem.hasAttribute('id;)) {\n";
    javaScript += "\t\talertString += '\nId=' + elem.getAttribute('id');\n";
    javaScript += "\t}\n";
    javaScript += "\tif(elem.hasAttribute('class')) {\n";
    javaScript += "\t\talertString += '\nClass=' + elem.getAttribute('class');\n";
    javaScript += "\t}\n";
    javaScript += "\tif(elem.hasAttribute('name')) {\n";
    javaScript += "\t\talertString += '\nName='' + elem.getAttribute('name');\n";
    javaScript += "\t}\n";
    javaScript += "\talert(alertString);\n";
    javaScript += "\t\treturn true;\n";
    javaScript += "}\n\n";
    javaScript += "function init() {\n'use strict';\n";
    javaScript += "\tdocument.onclick = clickHandler;\n";
    javaScript += "}\n";
*/
    return javaScript;
}
