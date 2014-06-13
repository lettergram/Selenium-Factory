#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWebElement>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){

    ui->setupUi(this);
    ui->webView->load(QUrl("http://www.google.com"));
    ui->webView->show();

    this->seleniumCode = new generate();

    collect = false;
}

MainWindow::~MainWindow(){
    delete ui;
}

/**
 * @brief MainWindow::on_urlLineEdit_returnPressed
 *   - A URL has been inputed and will now load webpage
 */
void MainWindow::on_urlLineEdit_returnPressed(){

    QUrl url(ui->urlLineEdit->text());
    ui->webView->load(url);
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
    }else{
        ui->toggleButton->setText("Start");
    }
}

// Back button for browser
void MainWindow::on_backButton_clicked(){
    ui->webView->back();
    ui->urlLineEdit->setText(ui->webView->url().toString());
}

// Generate Code upon release
void MainWindow::on_genButton_released(){
    this->seleniumCode->create();
}

// STILL WORK IN PROGRESS
// Should push the object the user clicks on into the seleniumCode stack.
void MainWindow::on_webView_selectionChanged(){

    if(ui->webView->page()->hasSelection()){
        std::cout << "Web Element: " << ui->webView->page()->currentFrame()->documentElement().localName().toStdString() << std::endl;
    }

    this->seleniumCode->push(ui->webView->page()->currentFrame()->documentElement().localName().toStdString());

    ui->urlLineEdit->setText(ui->webView->url().toString());
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
         ui->urlLineEdit->setVisible(true);
         ui->urlLineEdit->setText(ui->webView->url().toString());
    }
}
