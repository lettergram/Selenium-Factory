/*
 * Author: Austin Walters
 * Last Modified: July 23, 2014
 * Project: Selenium Factory
 */

#ifndef TESTGENERATIONFORM_H
#define TESTGENERATIONFORM_H

#include <QMainWindow>
#include <QDir>
#include <QInputDialog>

#include <iostream>
#include <vector>
#include <string.h>

#include "parse.h"

namespace Ui {
class testGenerationForm;
}

class testGenerationForm : public QMainWindow
{
    Q_OBJECT

public:

    explicit testGenerationForm(QWidget *parent = 0);
    ~testGenerationForm();



private slots:

    void on_acceptButton_clicked();
    void on_cencelButton_clicked();

    void on_chromeSlider_valueChanged(int value);

    void on_firefoxSlider_valueChanged(int value);

    std::string selectedOptions();

    void on_androidVersionSlider_valueChanged(int value);

    void on_iosVersionSlider_valueChanged(int value);

    void on_testNameEdit_returnPressed();

private:

    Ui::testGenerationForm *ui;
    std::vector< std::vector<std::string> > opts;

    std::string funcDescription;

    std::string addAndroid(std::string);
    std::string addiOS(std::string);

    std::string addWindows(std::string);
    std::string addMac(std::string);
    std::string addLinux(std::string);

    std::string addOSBrowser(int);
};

#endif // TESTGENERATIONFORM_H
