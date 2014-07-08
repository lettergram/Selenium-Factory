#include "javascripthandler.h"
#include <QDebug>

/**
 * @brief javaScriptHandler::javaScriptHandler - generic consctructor for
 *          the javaScriptHandler class
 */
javaScriptHandler::javaScriptHandler(){

    userActionList = new Generate();

    QString javaScript = "function clickHandler(e){";
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
    javaScript += "bridgeOperations.webElement(alertString);";
    javaScript += "return true;";
    javaScript += "}";
    javaScript += "function init() {";
    javaScript += "document.onclick = clickHandler;";
    javaScript += "}";

    webElementIdentification = new QString(javaScript);
}

/**
 * @brief javaScriptHandler::injectJavaScript - Returns string of java script
 *          to inject into the web page. Used for callback functions.
 * @return string of java script to inject
 */
void javaScriptHandler::injectJavaScript(QWebFrame *frame){

    frame->evaluateJavaScript(*webElementIdentification);
    frame->evaluateJavaScript("init()");
}

/**
 * @brief javaScriptHandler::webElement - Called when by
 *          the javascript when a web element is selected
 *
 * @param element - QString containing the characteristics of the
 *                  web element
 */
void javaScriptHandler::webElement(QString element){
    userActionList->push(element.toStdString());
}
