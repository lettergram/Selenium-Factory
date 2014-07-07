#include "javascripthandler.h"
#include <QDebug>

/**
 * @brief javaScriptHandler::javaScriptHandler - generic consctructor for
 *          the javaScriptHandler class
 */
javaScriptHandler::javaScriptHandler(){
    // Nothing
}

/**
 * @brief javaScriptHandler::injectJavaScript - Returns string of java script
 *          to inject into the web page. Used for callback functions.
 * @return string of java script to inject
 */
void javaScriptHandler::injectJavaScript(QWebFrame *frame){

    QString javaScript;

    javaScript = "function clickHandler(e){";
    javaScript += "var alertString, elem, evt = e ? e:event;";
    javaScript += "if (evt.srcElement) {";
    javaScript += "elem = evt.srcElement;";
    javaScript += "}else if (evt.target) {";
    javaScript += "elem = evt.target;";
    javaScript += "}";
    javaScript += "alertString = 'Tag=<'+ elem.tagName + '>';";
    javaScript += "if(elem.hasAttribute('id')) {";
    javaScript += "alertString += '\\nId=' + elem.getAttribute('id');";
    javaScript += "}";
    javaScript += "if(elem.hasAttribute('class')) {";
    javaScript += "alertString += '\\nClass=' + elem.getAttribute('class');";
    javaScript += "}";
    javaScript += "if(elem.hasAttribute('name')) {";
    javaScript += "alertString += '\\nName=' + elem.getAttribute('name');";
    javaScript += "}";
    javaScript += "alert(alertString);";
    javaScript += "return true;";
    javaScript += "}";
    javaScript += "function init() {";
    javaScript += "document.onclick = clickHandler;";
    javaScript += "}";

    frame->evaluateJavaScript(javaScript);
    frame->evaluateJavaScript("init()");
}
