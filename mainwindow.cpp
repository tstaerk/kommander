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
    qp->start(ui->lineEdit->text());
    while (qp->waitForFinished());
    QByteArray result=qp->readAll();
    ui->plainTextEdit->setPlainText(QString(result));
}

void MainWindow::addTab()
{
    QWidget* tab=new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    ui->tabWidget->addTab(tab,QString());

}

void MainWindow::on_pushButton_clicked()
{
    executecommand();
}

void MainWindow::on_lineEdit_returnPressed()
{
    executecommand();
}
