#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::executecommand()
{
    QProcess *qp = new QProcess(0);
    qp->start(QString("ls -l"));
    while (qp->waitForFinished());
    QByteArray result=qp->readAll();
    ui->plainTextEdit->setPlainText(QString(result));
}

void MainWindow::on_pushButton_clicked()
{
    executecommand();
}

void MainWindow::on_lineEdit_returnPressed()
{
    executecommand();
}
