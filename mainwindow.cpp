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
    api = new javaScriptHandler(this);

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
 *      http://stackoverflow.com/questions/2726609/qt-4-6-adding-objects-and-sub-objects-to-qwebview-window-object-c-javascrip
 *
 */
void MainWindow::on_urlLineEdit_returnPressed(){

    QUrl url(ui->urlLineEdit->text());
    ui->webView->load(url);

    // Still need to figure this out
    QString javaScript = api->injectJavaScript();

    attachWindowObject();
    QWebFrame *frame = ui->webView->page()->mainFrame();

    ui->webView->connect(frame,
            SIGNAL(javaScriptWindowObjectCleared()),
            this, SLOT(attachWindowObject()));

    ui->webView->connect(api,
            SIGNAL(win_bar()),
            this, SLOT(bluesBros()));

    frame->evaluateJavaScript("document.body.innerHTML += 'this is the first test'");

    javaScript += "document.body.innerHTML +=" + javaScript;

    // busy waiting bad
    for(int i = 0; i != 100; ui->webView->loadProgress(i)){ qDebug() << i; if(i == 0) break;  }
    frame->evaluateJavaScript(javaScript);

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
    this->seleniumCode->create();
}

/**
 * @brief MainWindow::on_webView_selectionChanged - Signaled on the selection change,
 *      CURRENTLY not very useful.
 */
void MainWindow::on_webView_selectionChanged(){


    QWebFrame *frame = ui->webView->page()->mainFrame();
    QString html = ui->webView->page()->mainFrame()->toHtml();

    frame->evaluateJavaScript("document.body.innerHTML += 'this is the first test'");
    std::cout << ui->webView->page()->settings()->JavascriptEnabled << std::endl;
    QString javaScript = "document.body.innerHTML += 'src='scriptName.js'";// + api->injectJavaScript() + "'";
    frame->evaluateJavaScript(javaScript);

    std::cout << html.toStdString() << std::endl;
    std::cout << javaScript.toStdString() << std::endl;

    QVariant f1result = frame->evaluateJavaScript("tester('Selection Changed')");
    qDebug() << "Selection Changed: " << f1result;

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

/**
 * @brief MainWindow::on_refreshButton_released - Refresh Button,
 *          refreshes the page as you would suspect.
 */
void MainWindow::on_refreshButton_released(){
    on_urlLineEdit_returnPressed();
}

/**
 * @brief MainWindow::attachWindowObject - attaches javaScriptHandler object
 *      to the page mainframe
 */
void MainWindow::attachWindowObject(){
    ui->webView->page()->mainFrame()->addToJavaScriptWindowObject(QString("api"), api);
}

void MainWindow::bluesBros(){
        std::cout << "here" << std::endl;
        qDebug() << "foo and bar are getting the band back together!";
};
