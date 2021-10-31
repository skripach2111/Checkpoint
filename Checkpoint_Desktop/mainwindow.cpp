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

    filterAccess = new AccessFilterModel(this);
    filterAccess->setSourceModel(db->getAccessModel());
    filterAccount = new AccountFilterModel(this);
    filterAccount->setSourceModel(db->getAccountModel());
    filterAuthorization = new AuthorizationFilterModel(this);
    filterAuthorization->setSourceModel(db->getAuthorizationModel());
    filterCheckpoint = new CheckpointFilterModel(this);
    filterCheckpoint->setSourceModel(db->getCheckpointModel());
    filterPosition = new PositionFilterModel(this);
    filterPosition->setSourceModel(db->getPositionModel());
    filterWorker = new WorkerFilterModel(this);
    filterWorker->setSourceModel(db->getWorkerModel());

    accessCombobox = new ModelForComboBox(this);
    accessCombobox->setSourceModel(db->getAccessModel());
    positionCombobox = new ModelForComboBox(this);
    positionCombobox->setSourceModel(db->getPositionModel());
    privilegeCombobox = new ModelForComboBox(this);
    privilegeCombobox->setSourceModel(db->getPrivilegeModel());
    stateCombobox = new ModelForComboBox(this);
    stateCombobox->setSourceModel(db->getStateModel());
    checkpointCombobox = new ModelForComboBox(this);
    checkpointCombobox->setSourceModel(db->getCheckpointModel());


    ui->tableView_workers->setModel(filterWorker);
    ui->comboBox_filterWorkerByPosition->setModel(positionCombobox);
    ui->comboBox_filterWorkerByPosition->setModelColumn(PositionModel::Column::TITLE);
    ui->comboBox_filterWorkerByLvlAccess->setModel(accessCombobox);
    ui->comboBox_filterWorkerByLvlAccess->setModelColumn(AccessModel::Column::TITLE);

    ui->tableView_checkpoints->setModel(filterCheckpoint);
    ui->comboBox_filterCheckpointByLvlAccess->setModel(accessCombobox);
    ui->comboBox_filterCheckpointByLvlAccess->setModelColumn(AccessModel::Column::TITLE);

    ui->tableView_authorizations->setModel(filterAuthorization);
    ui->comboBox_filterAuthorizationByCheckpoint->setModel(checkpointCombobox);
    ui->comboBox_filterAuthorizationByCheckpoint->setModelColumn(CheckpointModel::Column::TITLE);
    ui->comboBox_filterAuthorizationByLvlAccess->setModel(accessCombobox);
    ui->comboBox_filterAuthorizationByLvlAccess->setModelColumn(AccessModel::Column::TITLE);

    ui->tableView_accounts->setModel(filterAccount);
    ui->comboBox_filterAccountsByPrivileges->setModel(privilegeCombobox);
    ui->comboBox_filterAccountsByPrivileges->setModelColumn(PrivilegeModel::Column::TITLE);

    ui->tableView_lvlAccess->setModel(filterAccess);

    ui->listView_positions->setModel(filterPosition);
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
