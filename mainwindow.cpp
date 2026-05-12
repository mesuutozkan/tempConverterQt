#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//slot has been created in mainwindow.gui. See prefix and postfix of the slot.

void MainWindow::on_pushButtonCtoF_clicked()
{
    //set a bool which controls input type conversion of toFloat method. (Takes address of "ok" as an argument.)

    bool ok;
    //use ui ptr, take texedit object's value (string) and cast its type to float

    float celcius =  ui ->textEdit ->toPlainText().toFloat(&ok);

    //convert c to f
    if(ok)
    {
    float fahrenheit = (celcius * 9/5) + 32;

    //use labeltext to set output with pushbutton "pushButtonCtoF" slot with signal.

    ui -> labelOut->setText("Output: " + QString::number(fahrenheit) + " F");

    }

    //set an error message.

    else
    {
        ui ->labelOut ->setText("Wrong input");

    }

}


void MainWindow::on_pushButtonFtoC_clicked()
{
    bool ok;

    float fahrenheit = ui ->textEdit ->toPlainText().toFloat(&ok);
    if(ok)
    {
    float celcius = (fahrenheit - 32) * 5/9;

    ui ->labelOut ->setText("Output: " + QString::number(celcius) + " C");

    }

    else
    {
        ui ->labelOut ->setText("Wrong input");

    }
}

