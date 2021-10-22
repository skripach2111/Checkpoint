#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = new DatabaseModule(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Connect_clicked()
{
    if(ui->lineEdit_login->text().size() == 0 || ui->lineEdit_password->text().size() == 0)
    {
        ui->label_loginErrors->setText("Не все поля заполнены!");
        return;
    }

    if(!db->connect(ui->lineEdit_login->text(), ui->lineEdit_password->text()))
    {
        ui->label_loginErrors->setText(db->lastError().databaseText());
        return;
    }

//    switch (db->getPrivileges()) {

//    }

    ui->stackedWidget_mainWindow->setCurrentIndex(1);
}

