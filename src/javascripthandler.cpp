/*
 * Author: Austin Walters
 * Last Modified: July 23, 2014
 * Project: Selenium Factory
 */

#include "javascripthandler.h"
#include <QDebug>

/**
 * @brief javaScriptHandler::javaScriptHandler - generic consctructor for
 *          the javaScriptHandler class. Java Script code written by
 *          Gaurav D. Kale
 *
 *         Web Element order for CSV: TAG, id, class, name
 */
javaScriptHandler::javaScriptHandler(Generate * gen){

    userActionList = gen;

    QString javaScript = "function clickHandler(e){";
    javaScript += "var alertString, elem, evt = e ? e:event;";
    javaScript += "if (evt.srcElement) {";
    javaScript += "elem = evt.srcElement;";
    javaScript += "}else if (evt.target) {";
    javaScript += "elem = evt.target;";
    javaScript += "}";
    javaScript += "alertString = elem.tagName;";
    javaScript += "alertString += ', ';";
    javaScript += "if(elem.hasAttribute('id')) {";
    javaScript += "alertString += elem.getAttribute('id');";
    javaScript += "}";
    javaScript += "alertString += ', ';";
    javaScript += "if(elem.hasAttribute('class')) {";
    javaScript += "alertString += elem.getAttribute('class');";
    javaScript += "}";
    javaScript += "alertString += ', ';";
    javaScript += "if(elem.hasAttribute('name')) {";
    javaScript += "alertString += elem.getAttribute('name');";
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

    frame->addToJavaScriptWindowObject("bridgeOperations", this);
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

/**
 * @brief javaScriptHandler::outPutUserActions - returns
 * @return
 */
Generate * javaScriptHandler::outPutUserActions(){
    return userActionList;
}
