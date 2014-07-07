#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>
#include <QWebFrame>
#include <QtWebKitWidgets/QWebView>

#include <iostream>

#include "generate.h"
#include "javascripthandler.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
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


private:

    Ui::MainWindow *ui;
    bool collect;

    generate * seleniumCode;
    javaScriptHandler * api;

};

#endif // MAINWINDOW_H
