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

    QByteArray line = file.readLine();
    ui->source->setText(line);


}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::checkRegx(QRegExp rx)
{
    if (!rx.isValid() && rx.isEmpty() && rx.exactMatch("")){
        QMessageBox::information(this, "", "Not valid regx");
        return false;
    }
    else
       return true;
}

void MainWindow::on_butFind_clicked()
{
 ui->lwResult->clear();
    QRegExp rx(ui->regx->text());
    if (!checkRegx(rx))
       return ;
  int pos = 0;

  while ((pos = rx.indexIn(ui->source->toPlainText(), pos)) != -1 )
  {
     QString res = rx.cap(0);
      ui->lwResult->addItem(rx.cap(0));
      pos += rx.matchedLength();
  }



}

void MainWindow::on_butReadLine_clicked()
{
    QByteArray line = file.readLine();
    ui->source->setText(line);
}
