/*
 * Author: Austin Walters
 * Last Modified: July 23, 2014
 * Project: Selenium Factory
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWebElement>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){

    ui->setupUi(this);
    ui->webView->load(QUrl("http://www.google.com"));
    ui->webView->show();

    gen = new Generate();
    api = new javaScriptHandler(gen);
    testGenForm = new testGenerationForm();

    ui->webView->grabKeyboard();

    collect = false;
}

MainWindow::~MainWindow(){
    delete ui;
}

/**
 * @brief MainWindow::on_urlLineEdit_returnPressed
 *   - A URL has been inputed and will now load webpage
 *
 * Helpful links:
 *      http://stackoverflow.com/questions/9966760/how-i-get-page-source-from-webview
 *      http://stackoverflow.com/questions/4975658/qt-qwebview-javascript-callback
 */
void MainWindow::on_urlLineEdit_returnPressed(){

    QUrl url(ui->urlLineEdit->text());
    ui->webView->load(url);

    for(int i = 0; i != 100; ui->webView->loadProgress(i)){ qDebug() << i; if(i == 0) break;  }
    ui->webView->show();
    ui->urlLineEdit->setText(ui->webView->url().toString());
}

/**
 * @brief MainWindow::on_toggleButton_released - Upon click
 *          sets "collect" variable to true/false -- Start/Stop.
 *          If collect is true, collect every object targeted/user input,
 *          in order to produce selenium code.
 */
void MainWindow::on_toggleButton_released(){

    collect = !collect;
    if(collect){
        ui->toggleButton->setText("Stop");
        api->turnOn();
    }else{
        ui->toggleButton->setText("Start");
        api->turnOff();
    }
}

/**
 * @brief MainWindow::on_backButton_clicked - Back button for browser,
 *          reloads the URL in the urlLineEdit
 */
void MainWindow::on_backButton_clicked(){
    ui->webView->back();
    ui->urlLineEdit->setText(ui->webView->url().toString());
}

/**
 * @brief MainWindow::on_genButton_released - Should generate selenium
 *          code based off the stack of items.
 */
void MainWindow::on_genButton_released(){

    ui->webView->releaseKeyboard();
    testGenForm->show();

    QDir dir;
    while(!dir.cd("scripts")){ dir.cdUp(); }
    api->outPutUserActions()->create(dir.path().toStdString(), "seleniumFunc.py");
}

/**
 * @brief MainWindow::on_webView_selectionChanged - Signaled on the selection change,
 *      CURRENTLY not very useful.
 */
void MainWindow::on_webView_selectionChanged(){
    if(!testGenForm->isVisible())
        ui->webView->grabKeyboard();
}

/**
 * @brief MainWindow::on_webView_loadProgress - Called as the webpage loads
 *          this provides a progress bar to the user.
 * @param progress - 0 - 100 value for the progress.
 */
void MainWindow::on_webView_loadProgress(int progress){

    ui->urlLineEdit->setVisible(false);
    ui->progressBar->setValue(progress);

    if(progress == 100){

        api->injectJavaScript(ui->webView->page()->mainFrame());

        gen->push(ui->webView->url().toString().toStdString()); // maybe should be somewhere else

        ui->urlLineEdit->setVisible(true);
        ui->urlLineEdit->setText(ui->webView->url().toString());
    }

}

/**
 * @brief MainWindow::on_refreshButton_released - Refresh Button,
 *          refreshes the page as you would suspect.
 */
void MainWindow::on_refreshButton_released(){
    on_urlLineEdit_returnPressed();
}

void MainWindow::on_toolButton_clicked(){
    ui->webView->releaseKeyboard();
    testGenForm->show();
}

void MainWindow::keyPressEvent( QKeyEvent *key ){
   std::cout << key->text().toStdString() << std::endl;
}

void MainWindow::on_urlLineEdit_selectionChanged(){
    std::cout << "url selected" << std::endl;
    ui->webView->releaseKeyboard();
}
