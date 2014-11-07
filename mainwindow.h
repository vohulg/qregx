#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegExp>
#include <QMessageBox>
#include <QFile>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_butFind_clicked();

    void on_butReadLine_clicked();

private:
    Ui::MainWindow *ui;
    bool checkRegx(QRegExp rx);
    QFile file;
};

#endif // MAINWINDOW_H
