#ifndef TESTGENERATIONFORM_H
#define TESTGENERATIONFORM_H

#include <QMainWindow>

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
    void on_buttonBox_accepted();

private:
    Ui::testGenerationForm *ui;
};

#endif // TESTGENERATIONFORM_H
