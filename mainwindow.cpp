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
    //use ui ptr, take texedit object's value (string) and cast its type to float

    float celcius =  ui ->textEdit ->toPlainText().toFloat();

    //convert c to f

    float fahrenheit = (celcius * 9/5) + 32;

    //use labeltext to set output with pushbutton "pushButtonCtoF" slot with signal.

    ui -> labelOut->setText("Output: " + QString::number(fahrenheit) + " F");



}


void MainWindow::on_pushButtonFtoC_clicked()
{
    float fahrenheit = ui ->textEdit ->toPlainText().toFloat();

    float celcius = (fahrenheit - 32) * 5/9;

    ui ->labelOut ->setText("Output: " + QString::number(celcius) + " C");

}

