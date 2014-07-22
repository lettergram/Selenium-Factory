#include "testgenerationform.h"
#include "ui_testgenerationform.h"

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
    this->selectedOptions();
    this->hide();
}

/**
 * @brief testGenerationForm::on_cencelButton_clicked
 *      Returns every value in the test genearation
 *      form to the default state.
 */
void testGenerationForm::on_cencelButton_clicked(){

    ui->chromeSlider->setValue(0);
    ui->firefoxSlider->setValue(0);

    ui->androidCheckBox->setChecked(false);
    ui->iosCheckBox->setChecked(false);
    ui->windowsCheckBox->setChecked(false);
    ui->macCheckBox->setChecked(false);
    ui->linuxCheckBox->setChecked(false);

    ui->chromeCheckBox->setChecked(false);
    ui->firefoxCheckBox->setChecked(false);
    ui->safariCheckBox->setChecked(false);
    ui->operaCheckBox->setChecked(false);
    ui->IECheckBox->setChecked(false);
    ui->defaultBrowserCheckBox->setChecked(false);

    ui->deviceBox->setChecked(false);

    ui->testSuiteCheckBox->setChecked(false);
    ui->testNameEdit->setText("Specific Test Name");
    ui->testSuiteEdit->setText("New Test Suite");

    this->hide();
}

/**
 * @brief Slider Value
 *
 *          The functions below are going to have various implications.
 *
 *          For example, on slidebarChrome = 99, the chrome browser versions
 *          should be tested maximally for what ever operating platforms chosen.
 *
 *          If on the other hand, slidebarChrome = 55, half the chrome browser
 *          versions should be tested on the various OS versions.
 *
 */

void testGenerationForm::on_chromeSlider_valueChanged(int value){
    int version = double(99 - value) / double(99.0 / 36.0);
    ui->chromeCheckBox->setText("Chrome " + QString::number(version) + ".0");
}

/**
 * @brief testGenerationForm::on_firefoxSlider_valueChanged
 *            Changes the versions tested on FireFox,
 *              from most recent to least recent post.
 * @param value
 */
void testGenerationForm::on_firefoxSlider_valueChanged(int value){
    int version = double(99 - value) / double(99.0 / 26.0);
    version += 4;
    ui->firefoxCheckBox->setText("FireFox " + QString::number(version));
}

void testGenerationForm::on_androidVersionSlider_valueChanged(int value){
    value = double(99 - value) / double(99.0 / 4.0);
    ui->androidCheckBox->setText("Android 4." + QString::number(value));
}

void testGenerationForm::on_iosVersionSlider_valueChanged(int value){
    value = double(99 - value) / double(99.0 / 7.0);

    // Ugly, fix later with CSV sheet
    double version;
    if(value == 7){
        version = 7.1;
    }else if(value == 6){
        version = 7.0;
    }else if(value == 5){
        version = 6.1;
    }else if(value == 4){
        version = 6.0;
    }else if(value == 3){
        version = 5.1;
    }else if(value == 2){
        version = 5.0;
    }else{
        version = 4.3;
    }

    ui->iosCheckBox->setText("iOS " + QString::number(version));
}

/**
 * @brief testGenerationForm::selectedOptions
 *
 *          Returns the selected options in the following form:
 *
 *          Platform, Platform Version, OS, Browser, Browser Version, Device (nil if none);
 *
 *          Each string of options will be broken up by a semicolon, and the device
 *          category will be nil if no device was selected.
 */
std::string testGenerationForm::selectedOptions(){
    std::string options = "";

    if(ui->androidCheckBox->isChecked()){
       options += addAndroid(options);
    }

    std::cout << options << std::endl;
    return options;
}

std::string testGenerationForm::addAndroid(std::string options){
    options += "Linux,";
    int val = int(99 - ui->androidVersionSlider->value()) / double(99.0 / 4.0);
    options += "4." + QString::number(val).toStdString();
    return options;
}

std::string testGenerationForm::addiOS(std::string options){

}

std::string testGenerationForm::addDesktop(std::string options){

}
