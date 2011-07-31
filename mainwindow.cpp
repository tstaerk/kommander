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
    QString command=ui->lineEdit->text();
    QProcess *qp = new QProcess(0);
    ui->plainTextEdit->appendPlainText(QString("$ ").append(command));
    qp->start(command);
    while (qp->waitForFinished());
    QByteArray result=qp->readAll();
    ui->plainTextEdit->appendPlainText(result);
    ui->lineEdit->clear();
}

void MainWindow::addTab(QString caption)
{
    QWidget* tab=new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    ui->tabWidget->addTab(tab,QString());

    QGridLayout* qglo = new QGridLayout(tab);
    qglo->setSpacing(6);
    qglo->setContentsMargins(11, 11, 11, 11);
    qglo->setObjectName(QString::fromUtf8("gridLayout_2"));
    QPlainTextEdit* plainTextEdit = new QPlainTextEdit(tab);
    plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
    ui->tabWidget->setTabText(ui->tabWidget->indexOf(tab),caption);
    qglo->addWidget(plainTextEdit, 0, 0, 1, 1);

}

void MainWindow::on_pushButton_clicked()
{
    executecommand();
}

void MainWindow::on_lineEdit_returnPressed()
{
    executecommand();
}
