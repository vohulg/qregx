#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    file.setFileName("response.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "File not opened";

    while (!file.atEnd()) {
           QByteArray line = file.readLine();
           ui->source->setPlainText(line);
       }






}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::checkRegx(QRegExp rx)
{
    if (!rx.isValid() && rx.isEmpty() && rx.exactMatch(""))
        return false;
    else
        return true;
}
