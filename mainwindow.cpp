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
    std::cout << "URL: " << ui->urlLineEdit->text().toStdString() << std::endl;
    ui->webView->load(url);
    ui->webView->show();
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

    std::cout << ui->webView->url().toString().toStdString() << std::endl;
}
