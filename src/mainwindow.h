/*
 * Author: Austin Walters
 * Last Modified: July 23, 2014
 * Project: Selenium Factory
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>
#include <QWebFrame>
#include <QtWebKitWidgets/QWebView>
#include <QDir>
#include <QKeyEvent>

#include <iostream>

#include "generate.h"
#include "javascripthandler.h"
#include "testgenerationform.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_urlLineEdit_returnPressed();
    void on_toggleButton_released();
    void on_genButton_released();
    void on_webView_selectionChanged();
    void on_backButton_clicked();
    void on_webView_loadProgress(int progress);
    void on_refreshButton_released();
    void on_toolButton_clicked();
    void keyPressEvent( QKeyEvent *k );

    void on_urlLineEdit_selectionChanged();

private:

    Ui::MainWindow *ui;
    bool collect;

    javaScriptHandler * api;
    Generate * gen;
    testGenerationForm * testGenForm;

};

#endif // MAINWINDOW_H
