#include "testgenerationform.h"
#include "ui_testgenerationform.h"

testGenerationForm::testGenerationForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::testGenerationForm)
{
    ui->setupUi(this);
}

testGenerationForm::~testGenerationForm()
{
    delete ui;
}
