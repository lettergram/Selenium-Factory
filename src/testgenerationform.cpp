#include "testgenerationform.h"
#include "ui_testgenerationform.h"
#include <iostream>

testGenerationForm::testGenerationForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::testGenerationForm){
    ui->setupUi(this);
}

testGenerationForm::~testGenerationForm(){
    delete ui;
}

/**
 * @brief testGenerationForm::on_buttonBox_accepted - Accepted the generation form.
 *          Should call various functions to check the checkboxes,
 *          then call a python script to check for specific functions using the API,
 *          then finally should check to see if function already exists in database.
 *
 *          If the function does not exist in the database, create the test and add it
 *          to the database, potentially also adding it to a test suite. Have them also
 *          add a brief description (perhaps tags?), for quick searches and easy (later)
 *          combination of tests to create suites.
 *
 *          If the function does exist in the database, inform the user, and also direct
 *          them to the test location. Hopefully, the database will be full of similar tests.
 *          As well as other tests they may run in the future, allowing them to save time.
 */
void testGenerationForm::on_acceptButton_clicked(){
    std::cout << "here\n\n" << std::endl;
    this->hide();
}

void testGenerationForm::on_cencelButton_clicked(){
    this->hide();
}

/**
 * @brief testGenerationForm::on_Slider_valueChanged
 *
 *          The functions below are going to have various implications.
 *
 *          For example, on slidebarChrome = 99, the chrome browser should
 *          be tested maximally for what ever operating platforms chosen.
 *
 *          If on the other hand, slidebarChrome = 55, the chrome browser should
 *          be tested based on the following formula:
 *
 *          sidebarChrome / < OS Version Count >
 *
 */
void testGenerationForm::on_defaultSlider_valueChanged(int value){

}

void testGenerationForm::on_firefoxSlider_valueChanged(int value){

}




