#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    // when the program is started, it will receive parameters like root@node1 root@node2.
    // For every parameter the program will open a tab and execute commands in this tab.
    void addTab(QString caption);
    ~MainWindow();

private slots:
    // execute command and clear input field
    void executecommand();
    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
