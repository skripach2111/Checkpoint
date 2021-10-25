#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget_mainWindow->setCurrentIndex(0);
    ui->stackedWidget_workPlace->setCurrentIndex(0);
    ui->pushButton_back->setVisible(false);

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

    ui->tableView_workers->setModel(db->getWorkerModel());
    ui->comboBox_filterWorkerByPosition->setModel(db->getPositionModel());
    ui->comboBox_filterWorkerByPosition->setModelColumn(PositionModel::Column::TITLE);
    ui->comboBox_filterWorkerByLvlAccess->setModel(db->getAccessModel());
    ui->comboBox_filterWorkerByLvlAccess->setModelColumn(AccessModel::Column::TITLE);

    ui->tableView_checkpoints->setModel(db->getCheckpointModel());
    ui->comboBox_filterCheckpointByLvlAccess->setModel(db->getCheckpointModel());
    ui->comboBox_filterCheckpointByLvlAccess->setModelColumn(AccessModel::Column::TITLE);

    ui->tableView_authorizations->setModel(db->getAuthorizationModel());
    ui->comboBox_filterAuthorizationByCheckpoint->setModel(db->getCheckpointModel());
    ui->comboBox_filterAuthorizationByCheckpoint->setModelColumn(CheckpointModel::Column::TITLE);
    ui->comboBox_filterAuthorizationByLvlAccess->setModel(db->getAccessModel());
    ui->comboBox_filterAuthorizationByLvlAccess->setModelColumn(AccessModel::Column::TITLE);

    ui->tableView_accounts->setModel(db->getAccountModel());
    ui->comboBox_filterAccountsByPrivileges->setModel(db->getPrivilegeModel());
    ui->comboBox_filterAccountsByPrivileges->setModelColumn(PrivilegeModel::Column::TITLE);

    ui->tableView_lvlAccess->setModel(db->getAccessModel());

    ui->listView_positions->setModel(db->getPositionModel());
    ui->listView_positions->setModelColumn(PositionModel::Column::TITLE);

    ui->listView_privilege->setModel(db->getPrivilegeModel());
    ui->listView_privilege->setModelColumn(PrivilegeModel::Column::TITLE);

    ui->listView_states->setModel(db->getStateModel());
    ui->listView_states->setModelColumn(StateModel::Column::TITLE);
}


void MainWindow::on_pushButton_back_clicked()
{
    ui->stackedWidget_workPlace->setCurrentIndex(0);
    ui->stackedWidget_buttonPanels->setCurrentIndex(0);
    ui->pushButton_back->setVisible(false);
}

void MainWindow::on_pushButton_workers_clicked()
{
    ui->stackedWidget_workPlace->setCurrentIndex(1);
    ui->stackedWidget_buttonPanels->setCurrentIndex(1);
    ui->pushButton_back->setVisible(true);
}


void MainWindow::on_pushButton_checkpoints_clicked()
{
    ui->stackedWidget_workPlace->setCurrentIndex(2);
    ui->stackedWidget_buttonPanels->setCurrentIndex(2);
    ui->pushButton_back->setVisible(true);
}


void MainWindow::on_pushButton_authorizations_clicked()
{
    ui->stackedWidget_workPlace->setCurrentIndex(3);
    ui->stackedWidget_buttonPanels->setCurrentIndex(3);
    ui->pushButton_back->setVisible(true);
}


void MainWindow::on_pushButton_accounts_clicked()
{
    ui->stackedWidget_workPlace->setCurrentIndex(4);
    ui->stackedWidget_buttonPanels->setCurrentIndex(4);
    ui->pushButton_back->setVisible(true);
}


void MainWindow::on_pushButton_lvlAccesses_clicked()
{
    ui->stackedWidget_workPlace->setCurrentIndex(5);
    ui->stackedWidget_buttonPanels->setCurrentIndex(5);
    ui->pushButton_back->setVisible(true);
}


void MainWindow::on_pushButton_positions_clicked()
{
    ui->stackedWidget_workPlace->setCurrentIndex(6);
    ui->stackedWidget_buttonPanels->setCurrentIndex(6);
    ui->pushButton_back->setVisible(true);
}


void MainWindow::on_pushButton_privilege_clicked()
{
    ui->stackedWidget_workPlace->setCurrentIndex(7);
    ui->stackedWidget_buttonPanels->setCurrentIndex(7);
    ui->pushButton_back->setVisible(true);
}


void MainWindow::on_pushButton_states_clicked()
{
    ui->stackedWidget_workPlace->setCurrentIndex(8);
    ui->stackedWidget_buttonPanels->setCurrentIndex(8);
    ui->pushButton_back->setVisible(true);
}
