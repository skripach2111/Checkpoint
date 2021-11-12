#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget_mainWindow->setCurrentIndex(PagesMainWindow::AUTHORIZATION);
    ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::START);
    ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::MAINMENU_BUTTONS);
    ui->pushButton_save->setVisible(false);
    ui->pushButton_cancel->setVisible(false);
    ui->pushButton_back->setVisible(false);

    ui->pushButton_moreAboutLvlAccess->setVisible(false);

    db = new DatabaseModule(this);

    settings = new QSettings("settings.conf", QSettings::NativeFormat);
    db->setHostAddress(settings->value("Connection/ip_address").toString());
    db->setHostPort(settings->value("Connection/port").toInt());

    connect(ui->radioButton_hideTheDismissed, SIGNAL(clicked()), this, SLOT(workerDissmissedFilterChanged()));
    connect(ui->radioButton_showDismissed, SIGNAL(clicked()), this, SLOT(workerDissmissedFilterChanged()));
    connect(ui->radioButton_showAll, SIGNAL(clicked()), this, SLOT(workerDissmissedFilterChanged()));

    //    connect(ui->checkBox_filterAuthorizationByStateIncoming, SIGNAL(stateChanged()), this, SLOT(authorizationStateFilterChenged()));
    //    connect(ui->checkBox_filterAuthorizationByStateInadmissible, SIGNAL(stateChanged()), this, SLOT(authorizationStateFilterChenged()));
    //    connect(ui->checkBox_filterAuthorizationByStateGraduates, SIGNAL(stateChanged()), this, SLOT(authorizationStateFilterChenged()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::switchBackButton(bool flag)
{
    ui->pushButton_back->setVisible(!flag);
    ui->pushButton_save->setVisible(flag);
    ui->pushButton_cancel->setVisible(flag);
}


void MainWindow::on_pushButton_Connect_clicked()
{
    if(ui->lineEdit_login->text().size() == 0 || ui->lineEdit_password->text().size() == 0)
    {
        ui->label_loginErrors->setText("Не все поля заполнены!");
        return;
    }

    //    if(!db->connect(ui->lineEdit_login->text(), ui->lineEdit_password->text()))
    //    {
    //        ui->label_loginErrors->setText(db->lastError().databaseText());
    //        return;
    //    }

    if(!db->connect("userCheckpoint", "user_checkpoint"))
    {
        ui->label_loginErrors->setText("Не удалось подключиться к серверу!");
        return;
    }

    ui->label_loginErrors->setText(db->authorizationUser(ui->lineEdit_login->text(), ui->lineEdit_password->text()));

    if(ui->label_loginErrors->text().size() != 0)
        return;

    db->selectTables();

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

    db->getWorkerModel()->select();

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
    workerCombobox = new ModelForComboBox(this);
    workerCombobox->setSourceModel(db->getWorkerModel());


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

    filterAccess->setEnabledFilterParam(AccessFilterModel::FilterParam::TITLE, false);
    filterAccess->setEnabledFilterParam(AccessFilterModel::FilterParam::PRIVILEGE, false);

    filterAccount->setEnabledFilterParam(AccountFilterModel::FilterParam::LOGIN, false);
    filterAccount->setEnabledFilterParam(AccountFilterModel::FilterParam::WORKER, false);
    filterAccount->setEnabledFilterParam(AccountFilterModel::FilterParam::PRIVILEGE, false);

    filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::WORKER, false);
    filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::AUTHORIZER, false);
    filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::DATE, false);
    filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::TIME, false);
    filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::CHECKPOINT, false);
    filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::LVL_ACCESS, false);
    filterAuthorization->setFilterParam(AuthorizationFilterModel::FilterParam::STATE_IN, 1);
    filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::STATE_IN, true);
    filterAuthorization->setFilterParam(AuthorizationFilterModel::FilterParam::STATE_OUT, 2);
    filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::STATE_OUT, true);
    filterAuthorization->setFilterParam(AuthorizationFilterModel::FilterParam::STATE_NOT_ALLOWED, 3);
    filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::STATE_NOT_ALLOWED, true);

    filterCheckpoint->setEnabledFilterParam(CheckpointFilterModel::FilterParam::TITLE, false);
    filterCheckpoint->setEnabledFilterParam(CheckpointFilterModel::FilterParam::LVL_ACCESS, false);

    filterWorker->setEnabledFilterParam(WorkerFilterModel::FilterParam::INN, false);
    filterWorker->setEnabledFilterParam(WorkerFilterModel::FilterParam::PIB, false);
    filterWorker->setEnabledFilterParam(WorkerFilterModel::FilterParam::POSITION, false);
    filterWorker->setEnabledFilterParam(WorkerFilterModel::FilterParam::LVL_ACCESS, false);
    filterWorker->setEnabledFilterParam(WorkerFilterModel::FilterParam::VIEW, true);
    filterWorker->setFilterParam(WorkerFilterModel::FilterParam::VIEW, WorkerFilterModel::ViewMode::HIDE_DISMISSED);

    filterPosition->setEnabledFilterParam(PositionFilterModel::FilterParam::TITLE, false);

    ui->comboBox_addAccountPrivilege->setModel(privilegeCombobox);
    ui->comboBox_addAccountPrivilege->setModelColumn(PrivilegeModel::Column::TITLE);
    ui->comboBox_addAccountWorker->setModel(workerCombobox);
    ui->comboBox_addAccountWorker->setModelColumn(WorkerModel::Column::PIB);

    ui->comboBox_addCheckpointLvlAccess->setModel(accessCombobox);
    ui->comboBox_addCheckpointLvlAccess->setModelColumn(AccessModel::Column::TITLE);

    ui->comboBox_addWorkerLvlAccess->setModel(accessCombobox);
    ui->comboBox_addWorkerLvlAccess->setModelColumn(AccessModel::Column::TITLE);
    ui->comboBox_addWorkerPosition->setModel(positionCombobox);
    ui->comboBox_addWorkerPosition->setModelColumn(PositionModel::Column::TITLE);

    QModelIndex index = db->getAccountModel()->getUserByLogin(ui->lineEdit_login->text());
    ui->label_login->setText(db->getAccountModel()->index(index.row(), AccountModel::Column::LOGIN).data().toString());
    ui->label_position->setText(db->getAccountModel()->index(index.row(), AccountModel::Column::PRIVILEGE).data().toString());
    ui->label_fio->setText(db->getAccountModel()->index(index.row(), AccountModel::Column::WORKER).data().toString());

    switch (db->getAccountModel()->index(index.row(), AccountModel::Column::PRIVILEGE).data(AccountModel::Role::Read).toInt())
    {
    case Privileges::ADMIN:
    {
        ui->pushButton_authorizations->setVisible(false);
        ui->pushButton_checkpoints->setVisible(false);
        ui->pushButton_lvlAccesses->setVisible(false);
        ui->pushButton_accounts->setVisible(true);
        ui->pushButton_privilege->setVisible(true);
        ui->pushButton_states->setVisible(true);
        ui->pushButton_workers->setVisible(false);
        ui->pushButton_positions->setVisible(false);
        break;
    }
    case Privileges::BUHGALTER:
    {
        ui->pushButton_authorizations->setVisible(false);
        ui->pushButton_checkpoints->setVisible(false);
        ui->pushButton_lvlAccesses->setVisible(false);
        ui->pushButton_accounts->setVisible(false);
        ui->pushButton_privilege->setVisible(false);
        ui->pushButton_states->setVisible(false);
        ui->pushButton_workers->setVisible(true);
        ui->pushButton_positions->setVisible(true);
        break;
    }
    case Privileges::SB:
    {
        ui->pushButton_authorizations->setVisible(true);
        ui->pushButton_checkpoints->setVisible(true);
        ui->pushButton_lvlAccesses->setVisible(true);
        ui->pushButton_accounts->setVisible(false);
        ui->pushButton_privilege->setVisible(false);
        ui->pushButton_states->setVisible(false);
        ui->pushButton_workers->setVisible(true);
        ui->pushButton_positions->setVisible(false);
        break;
    }
    default:
    {
        ui->label_loginErrors->setText("Доступ к программе запрещён!");
        return;
    }
    }

    ui->stackedWidget_mainWindow->setCurrentIndex(PagesMainWindow::WORKSPACE);
}


void MainWindow::on_pushButton_back_clicked()
{
    switch(ui->stackedWidget_workPlace->currentIndex())
    {
    case PagesWorkPlace::ACCOUNTS_VIEW:
    {
        ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::ACCOUNTS);
        ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::ACCOUNTS_BUTTONS);
        break;
    }
    case PagesWorkPlace::AUTHORIZATIONS_VIEW:
    {
        ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::AUTHORIZATIONS);
        ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::AUTHORIZATIONS_BUTTONS);
        break;
    }
    case PagesWorkPlace::CHECKPOINTS_VIEW:
    {
        ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::CHECKPOINTS);
        ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::CHECKPOINTS_BUTTONS);
        break;
    }
    case PagesWorkPlace::WORKERS_VIEW:
    {
        ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::WORKERS);
        ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::WORKERS_BUTTONS);
        break;
    }
    default:
    {
        ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::START);
        ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::MAINMENU_BUTTONS);
        ui->pushButton_back->setVisible(false);
    }
    }

}

void MainWindow::on_pushButton_workers_clicked()
{
    ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::WORKERS);
    ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::WORKERS_BUTTONS);
    ui->pushButton_back->setVisible(true);
}


void MainWindow::on_pushButton_checkpoints_clicked()
{
    ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::CHECKPOINTS);
    ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::CHECKPOINTS_BUTTONS);
    ui->pushButton_back->setVisible(true);
}


void MainWindow::on_pushButton_authorizations_clicked()
{
    ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::AUTHORIZATIONS);
    ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::AUTHORIZATIONS_BUTTONS);
    ui->pushButton_back->setVisible(true);
}


void MainWindow::on_pushButton_accounts_clicked()
{
    ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::ACCOUNTS);
    ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::ACCOUNTS_BUTTONS);
    ui->pushButton_back->setVisible(true);
}


void MainWindow::on_pushButton_lvlAccesses_clicked()
{
    ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::LVL_ACCESS);
    ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::LVL_ACCESS_BUTTONS);
    ui->pushButton_back->setVisible(true);
}


void MainWindow::on_pushButton_positions_clicked()
{
    ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::POSITION);
    ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::POSITION_BUTTONS);
    ui->pushButton_back->setVisible(true);
}


void MainWindow::on_pushButton_privilege_clicked()
{
    ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::PRIVILEGES);
    ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::PRIVILEGES_BUTTONS);
    ui->pushButton_back->setVisible(true);
}


void MainWindow::on_pushButton_states_clicked()
{
    ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::STATES);
    ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::STATES_BUTTONS);
    ui->pushButton_back->setVisible(true);
}

void MainWindow::on_pushButton_backToLogin_clicked()
{
    ui->stackedWidget_mainWindow->setCurrentIndex(PagesMainWindow::AUTHORIZATION);
}


void MainWindow::on_pushButton_settings_clicked()
{
    ui->label_currentHostAddress->setText(settings->value("Connection/ip_address").toString());
    ui->label_currentHostPort->setText(settings->value("Connection/port").toString());
    ui->stackedWidget_mainWindow->setCurrentIndex(PagesMainWindow::SETTINGS);
}


void MainWindow::on_pushButton_applySettings_clicked()
{
    if(ui->lineEdit_setHostAddress->text().size() != 0)
        settings->setValue("Connection/ip_address", ui->lineEdit_setHostAddress->text());
    if(ui->lineEdit_setHostPort->text().size() != 0)
        settings->setValue("Connection/port", ui->lineEdit_setHostPort->text());
    settings->sync();

    ui->label_currentHostAddress->setText(settings->value("Connection/ip_address").toString());
    ui->label_currentHostPort->setText(settings->value("Connection/port").toString());

    ui->lineEdit_setHostAddress->setText("");
    ui->lineEdit_setHostPort->setText("");
}


void MainWindow::on_lineEdit_filterWorkerByInn_editingFinished()
{
    if(ui->lineEdit_filterWorkerByInn->text().size() != 0)
    {
        filterWorker->setEnabledFilterParam(WorkerFilterModel::FilterParam::INN, true);
        filterWorker->setFilterParam(WorkerFilterModel::FilterParam::INN, ui->lineEdit_filterWorkerByInn->text());
    }
    else
        filterWorker->setEnabledFilterParam(WorkerFilterModel::FilterParam::INN, false);
}


void MainWindow::on_lineEdit_filterWorkerByFIO_editingFinished()
{
    if(ui->lineEdit_filterWorkerByFIO->text().size() != 0)
    {
        filterWorker->setEnabledFilterParam(WorkerFilterModel::FilterParam::PIB, true);
        filterWorker->setFilterParam(WorkerFilterModel::FilterParam::PIB, ui->lineEdit_filterWorkerByFIO->text());
    }
    else
        filterWorker->setEnabledFilterParam(WorkerFilterModel::FilterParam::PIB, false);
}


void MainWindow::on_comboBox_filterWorkerByPosition_currentIndexChanged(int index)
{
    if(index == 0)
        filterWorker->setEnabledFilterParam(WorkerFilterModel::FilterParam::POSITION, false);
    else
    {
        filterWorker->setEnabledFilterParam(WorkerFilterModel::FilterParam::POSITION, true);
        filterWorker->setFilterParam(WorkerFilterModel::FilterParam::POSITION, positionCombobox->data(positionCombobox->index(index, 0)));
    }
}


void MainWindow::on_comboBox_filterWorkerByLvlAccess_currentIndexChanged(int index)
{
    if(index == 0)
        filterWorker->setEnabledFilterParam(WorkerFilterModel::FilterParam::LVL_ACCESS, false);
    else
    {
        filterWorker->setEnabledFilterParam(WorkerFilterModel::FilterParam::LVL_ACCESS, true);
        filterWorker->setFilterParam(WorkerFilterModel::FilterParam::LVL_ACCESS, accessCombobox->data(accessCombobox->index(index, AccessModel::Column::ID)));
    }
}

void MainWindow::workerDissmissedFilterChanged()
{
    if(ui->radioButton_hideTheDismissed->isChecked())
        filterWorker->setFilterParam(WorkerFilterModel::FilterParam::VIEW, WorkerFilterModel::ViewMode::HIDE_DISMISSED);
    else if(ui->radioButton_showAll->isChecked())
        filterWorker->setFilterParam(WorkerFilterModel::FilterParam::VIEW, WorkerFilterModel::ViewMode::SHOW_ALL);
    else if(ui->radioButton_showDismissed->isChecked())
        filterWorker->setFilterParam(WorkerFilterModel::FilterParam::VIEW, WorkerFilterModel::ViewMode::SHOW_ONLY_DISMISSED);
}

//void MainWindow::authorizationStateFilterChenged()
//{
//    if(ui->checkBox_filterAuthorizationByStateGraduates)
//    {
//        filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::STATE_IN, true);
//        filterAuthorization->setFilterParam(AuthorizationFilterModel::FilterParam::STATE_IN, 1);
//    }
//    else
//    {

//    }
//}



void MainWindow::on_lineEdit_filterCheckpointByTitle_editingFinished()
{
    if(ui->lineEdit_filterCheckpointByTitle->text().size() != 0)
    {
        filterCheckpoint->setEnabledFilterParam(CheckpointFilterModel::FilterParam::TITLE, true);
        filterCheckpoint->setFilterParam(CheckpointFilterModel::FilterParam::TITLE, ui->lineEdit_filterCheckpointByTitle->text());
    }
    else
        filterCheckpoint->setEnabledFilterParam(CheckpointFilterModel::FilterParam::TITLE, false);
}


void MainWindow::on_comboBox_filterCheckpointByLvlAccess_currentIndexChanged(int index)
{
    if(index == 0)
        filterCheckpoint->setEnabledFilterParam(CheckpointFilterModel::FilterParam::LVL_ACCESS, false);
    else
    {
        filterCheckpoint->setEnabledFilterParam(CheckpointFilterModel::FilterParam::LVL_ACCESS, true);
        filterCheckpoint->setFilterParam(CheckpointFilterModel::FilterParam::LVL_ACCESS, accessCombobox->data(accessCombobox->index(index, AccessModel::Column::ID)));
    }
}


void MainWindow::on_checkBox_filterAuthorizationByDate_stateChanged(int arg1)
{
    if(arg1 == 1)
    {
        ui->dateEdit_filterAuthorization->setEnabled(true);
        filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::DATE, true);
        filterAuthorization->setFilterParam(AuthorizationFilterModel::FilterParam::DATE, ui->dateEdit_filterAuthorization->date());
    }
    else
    {
        ui->dateEdit_filterAuthorization->setEnabled(false);
        filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::DATE, false);
    }
}


void MainWindow::on_checkBox_filterAuthorizationByTime_stateChanged(int arg1)
{
    if(arg1 == 1)
    {
        ui->timeEdit_filterAuthorization->setEnabled(true);
        filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::TIME, true);
        filterAuthorization->setFilterParam(AuthorizationFilterModel::FilterParam::TIME, ui->timeEdit_filterAuthorization->time());
    }
    else
    {
        ui->timeEdit_filterAuthorization->setEnabled(false);
        filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::TIME, false);
    }
}


void MainWindow::on_lineEdit_filterAuthorizationByWorker_editingFinished()
{
    if(ui->lineEdit_filterAuthorizationByWorker->text().size() != 0)
    {
        filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::WORKER, true);
        filterAuthorization->setFilterParam(AuthorizationFilterModel::FilterParam::WORKER, ui->lineEdit_filterAuthorizationByWorker->text());
    }
    else
        filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::WORKER, false);
}


void MainWindow::on_lineEdit_filterAuthorizationByAuthorizer_editingFinished()
{
    if(ui->lineEdit_filterAuthorizationByAuthorizer->text().size() != 0)
    {
        filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::AUTHORIZER, true);
        filterAuthorization->setFilterParam(AuthorizationFilterModel::FilterParam::AUTHORIZER, ui->lineEdit_filterAuthorizationByAuthorizer->text());
    }
    else
        filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::AUTHORIZER, false);
}


void MainWindow::on_comboBox_filterAuthorizationByCheckpoint_currentIndexChanged(int index)
{
    if(index == 0)
        filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::CHECKPOINT, false);
    else
    {
        filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::CHECKPOINT, true);
        filterAuthorization->setFilterParam(AuthorizationFilterModel::FilterParam::CHECKPOINT, checkpointCombobox->data(checkpointCombobox->index(index, 0)));
    }
}


void MainWindow::on_comboBox_filterAuthorizationByLvlAccess_currentIndexChanged(int index)
{
    if(index == 0)
        filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::LVL_ACCESS, false);
    else
    {
        filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::LVL_ACCESS, true);
        filterAuthorization->setFilterParam(AuthorizationFilterModel::FilterParam::LVL_ACCESS, accessCombobox->data(accessCombobox->index(index, 0)));
    }
}


void MainWindow::on_checkBox_filterAuthorizationByStateIncoming_stateChanged(int arg1)
{
    if(ui->checkBox_filterAuthorizationByStateGraduates->isChecked())
    {
        filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::STATE_IN, true);
        filterAuthorization->setFilterParam(AuthorizationFilterModel::FilterParam::STATE_IN, 1);
    }
    else
        filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::STATE_IN, false);
}


void MainWindow::on_checkBox_filterAuthorizationByStateGraduates_stateChanged(int arg1)
{
    if(ui->checkBox_filterAuthorizationByStateGraduates->isChecked())
    {
        filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::STATE_OUT, true);
        filterAuthorization->setFilterParam(AuthorizationFilterModel::FilterParam::STATE_OUT, 2);
    }
    else
        filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::STATE_OUT, false);
}


void MainWindow::on_checkBox_filterAuthorizationByStateInadmissible_stateChanged(int arg1)
{
    if(ui->checkBox_filterAuthorizationByStateGraduates->isChecked())
    {
        filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::STATE_NOT_ALLOWED, true);
        filterAuthorization->setFilterParam(AuthorizationFilterModel::FilterParam::STATE_NOT_ALLOWED, 3);
    }
    else
        filterAuthorization->setEnabledFilterParam(AuthorizationFilterModel::FilterParam::STATE_NOT_ALLOWED, false);
}


void MainWindow::on_lineEdit_filterAccountsByLogin_editingFinished()
{
    if(ui->lineEdit_filterAccountsByLogin->text().size() != 0)
    {
        filterAccount->setEnabledFilterParam(AccountFilterModel::FilterParam::LOGIN, true);
        filterAccount->setFilterParam(AccountFilterModel::FilterParam::LOGIN, ui->lineEdit_filterAccountsByLogin->text());
    }
    else
        filterAccount->setEnabledFilterParam(AccountFilterModel::FilterParam::LOGIN, false);
}


void MainWindow::on_lineEdit_filterAccountsByFIO_editingFinished()
{
    if(ui->lineEdit_filterAccountsByFIO->text().size() != 0)
    {
        filterAccount->setEnabledFilterParam(AccountFilterModel::FilterParam::WORKER, true);
        filterAccount->setFilterParam(AccountFilterModel::FilterParam::WORKER, ui->lineEdit_filterAccountsByFIO->text());
    }
    else
        filterAccount->setEnabledFilterParam(AccountFilterModel::FilterParam::WORKER, false);
}


void MainWindow::on_comboBox_filterAccountsByPrivileges_currentIndexChanged(int index)
{
    if(index == 0)
        filterAccount->setEnabledFilterParam(AccountFilterModel::FilterParam::PRIVILEGE, false);
    else
    {
        filterAccount->setEnabledFilterParam(AccountFilterModel::FilterParam::PRIVILEGE, true);
        filterAccount->setFilterParam(AccountFilterModel::FilterParam::PRIVILEGE, privilegeCombobox->data(privilegeCombobox->index(index, 0)));
    }
}


void MainWindow::on_lineEdit_filterLvlAccessByTitle_editingFinished()
{
    if(ui->lineEdit_filterLvlAccessByTitle->text().size() != 0)
    {
        filterAccess->setEnabledFilterParam(AccessFilterModel::FilterParam::TITLE, true);
        filterAccess->setFilterParam(AccessFilterModel::FilterParam::TITLE, ui->lineEdit_filterLvlAccessByTitle->text());
    }
    else
        filterAccess->setEnabledFilterParam(AccessFilterModel::FilterParam::TITLE, false);
}


void MainWindow::on_spinBox_filterLvlAccessByLvl_valueChanged(int arg1)
{
    if(arg1 == 0)
        filterAccess->setEnabledFilterParam(AccessFilterModel::FilterParam::PRIVILEGE, false);
    else
    {
        filterAccess->setEnabledFilterParam(AccessFilterModel::FilterParam::PRIVILEGE, true);
        filterAccess->setFilterParam(AccessFilterModel::FilterParam::PRIVILEGE, arg1);
    }
}


void MainWindow::on_lineEdit_filterPositionsByTitle_editingFinished()
{
    if(ui->lineEdit_filterPositionsByTitle->text().size() != 0)
    {
        filterPosition->setEnabledFilterParam(PositionFilterModel::FilterParam::TITLE, true);
        filterPosition->setFilterParam(PositionFilterModel::FilterParam::TITLE, ui->lineEdit_filterPositionsByTitle->text());
    }
    else
        filterPosition->setEnabledFilterParam(PositionFilterModel::FilterParam::TITLE, false);
}


void MainWindow::on_pushButton_addWorker_clicked()
{
    flagAddWorker = true;
    ui->label_addWorkerLabel->setText(addWorkerLabel);

    ui->lineEdit_addWorkerINN->setEnabled(true);
    ui->lineEdit_addWorkerPIB->setText("");
    ui->lineEdit_addWorkerINN->setText("");
    ui->dateEdit_addWorkerDate->setDate(QDate::currentDate());
    ui->lineEdit_addWorkerPlaceFoRegistration->setText("");
    ui->lineEdit_addWorkerPlaceOfResidence->setText("");
    ui->lineEdit_addWorkerNumberPassport->setText("");
    ui->comboBox_addWorkerLvlAccess->setCurrentIndex(0);
    ui->comboBox_addWorkerPosition->setCurrentIndex(0);
    ui->comboBox_addWorkerStateDissmised->setCurrentIndex(0);
    ui->widget_addWorkerPhoto->setScaledPixmap(QPixmap());

    ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::WORKERS_ADD);
    ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::SAVE_CANCEL_BUTTONS);
    switchBackButton(true);
}


void MainWindow::on_pushButton_cancel_clicked()
{
    switch (ui->stackedWidget_workPlace->currentIndex())
    {
    case WORKERS_ADD:
    case WORKERS_VIEW:
    {
        ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::WORKERS);
        ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::WORKERS_BUTTONS);
        break;
    }
    case CHECKPOINTS_ADD:
    case CHECKPOINTS_VIEW:
    {
        ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::CHECKPOINTS);
        ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::CHECKPOINTS_BUTTONS);
        break;
    }
    case AUTHORIZATIONS_VIEW:
    {
        ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::AUTHORIZATIONS);
        ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::AUTHORIZATIONS_BUTTONS);
        break;
    }
    case ACCOUNTS_ADD:
    case ACCOUNTS_VIEW:
    {
        ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::ACCOUNTS);
        ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::ACCOUNTS_BUTTONS);
        break;
    }
    case ACCESS_ADD:
    {
        ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::LVL_ACCESS);
        ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::LVL_ACCESS_BUTTONS);
        break;
    }
    case POSITION_ADD:
    {
        ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::POSITION);
        ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::POSITION_BUTTONS);
        break;
    }
    }

    switchBackButton(false);
}


void MainWindow::on_pushButton_moreAboutWorker_clicked()
{
    if(ui->tableView_workers->currentIndex().column() == -1)
        return;

    QPixmap pixmap;
    pixmap.loadFromData(filterWorker->sourceModel()->index(filterWorker->mapToSource(ui->tableView_workers->currentIndex()).row(), WorkerModel::Column::PHOTO).data().toByteArray());

    ui->label_viewWorkerPIB->setText(filterWorker->sourceModel()->index(filterWorker->mapToSource(ui->tableView_workers->currentIndex()).row(), WorkerModel::Column::PIB).data().toString());
    ui->label_viewWorkerINN->setText(filterWorker->sourceModel()->index(filterWorker->mapToSource(ui->tableView_workers->currentIndex()).row(), WorkerModel::Column::INN).data().toString());
    ui->label_viewWorkerDateOfBirth->setText(filterWorker->sourceModel()->index(filterWorker->mapToSource(ui->tableView_workers->currentIndex()).row(), WorkerModel::Column::DATE_OF_BIRTH).data().toString());
    ui->label_viewWorkerPlaceOfRegistration->setText(filterWorker->sourceModel()->index(filterWorker->mapToSource(ui->tableView_workers->currentIndex()).row(), WorkerModel::Column::PLACE_OF_REGISTRATION).data().toString());
    ui->label_viewWorkerPlaceOfResidence->setText(filterWorker->sourceModel()->index(filterWorker->mapToSource(ui->tableView_workers->currentIndex()).row(), WorkerModel::Column::PLACE_OF_RESIDENCE).data().toString());
    ui->label_viewWorkerNumberPassport->setText(filterWorker->sourceModel()->index(filterWorker->mapToSource(ui->tableView_workers->currentIndex()).row(), WorkerModel::Column::NUMBER_PASSPORT).data().toString());
    ui->label_viewWorkerLvlAccess->setText(filterWorker->sourceModel()->index(filterWorker->mapToSource(ui->tableView_workers->currentIndex()).row(), WorkerModel::Column::LVL_ACCESS).data().toString());
    ui->label_viewWorkerPosition->setText(filterWorker->sourceModel()->index(filterWorker->mapToSource(ui->tableView_workers->currentIndex()).row(), WorkerModel::Column::POSITION).data().toString());
    ui->widget_viewWorkerPhoto->setScaledPixmap(pixmap);
    if(filterWorker->sourceModel()->index(filterWorker->mapToSource(ui->tableView_workers->currentIndex()).row(), WorkerModel::Column::FLAG).data().toInt())
        ui->label_viewWorkerStateDissmised->setText("Уволен");
    else
        ui->label_viewWorkerStateDissmised->setText("Работает");

    ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::WORKERS_VIEW);
    switchBackButton(false);
}


void MainWindow::on_pushButton_editWorker_clicked()
{
    if(ui->tableView_workers->currentIndex().column() == -1)
        return;

    flagAddWorker = false;
    ui->label_addWorkerLabel->setText(updateWorkerLabel);

    QPixmap pixmap;
    pixmap.loadFromData(filterWorker->sourceModel()->index(filterWorker->mapToSource(ui->tableView_workers->currentIndex()).row(), WorkerModel::Column::PHOTO).data().toByteArray());

    ui->comboBox_addWorkerLvlAccess->setCurrentIndex(filterWorker->sourceModel()->index(filterWorker->mapToSource(ui->tableView_workers->currentIndex()).row(), WorkerModel::Column::LVL_ACCESS).data(WorkerModel::Role::Read).toInt());
    ui->comboBox_addWorkerPosition->setCurrentIndex(filterWorker->sourceModel()->index(filterWorker->mapToSource(ui->tableView_workers->currentIndex()).row(), WorkerModel::Column::POSITION).data(WorkerModel::Role::Read).toInt());
    ui->dateEdit_addWorkerDate->setDate(filterWorker->sourceModel()->index(filterWorker->mapToSource(ui->tableView_workers->currentIndex()).row(), WorkerModel::Column::DATE_OF_BIRTH).data().toDate());
    ui->lineEdit_addWorkerINN->setEnabled(false);
    ui->lineEdit_addWorkerINN->setText(filterWorker->sourceModel()->index(filterWorker->mapToSource(ui->tableView_workers->currentIndex()).row(), WorkerModel::Column::INN).data().toString());
    ui->lineEdit_addWorkerNumberPassport->setText(filterWorker->sourceModel()->index(filterWorker->mapToSource(ui->tableView_workers->currentIndex()).row(), WorkerModel::Column::NUMBER_PASSPORT).data().toString());
    ui->lineEdit_addWorkerPIB->setText(filterWorker->sourceModel()->index(filterWorker->mapToSource(ui->tableView_workers->currentIndex()).row(), WorkerModel::Column::PIB).data().toString());
    ui->lineEdit_addWorkerPlaceFoRegistration->setText(filterWorker->sourceModel()->index(filterWorker->mapToSource(ui->tableView_workers->currentIndex()).row(), WorkerModel::Column::PLACE_OF_REGISTRATION).data().toString());
    ui->lineEdit_addWorkerPlaceOfResidence->setText(filterWorker->sourceModel()->index(filterWorker->mapToSource(ui->tableView_workers->currentIndex()).row(), WorkerModel::Column::PLACE_OF_RESIDENCE).data().toString());
    ui->widget_addWorkerPhoto->setScaledPixmap(pixmap);
    ui->comboBox_addWorkerStateDissmised->setCurrentIndex(filterWorker->sourceModel()->index(filterWorker->mapToSource(ui->tableView_workers->currentIndex()).row(), WorkerModel::Column::FLAG).data().toInt());

    ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::WORKERS_ADD);
    ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::SAVE_CANCEL_BUTTONS);
    switchBackButton(true);
}


void MainWindow::on_pushButton_save_clicked()
{
    switch(ui->stackedWidget_workPlace->currentIndex())
    {
    case PagesWorkPlace::WORKERS_ADD:
    {
        if(flagAddWorker)
        {
            db->getWorkerModel()->appendRow(ui->lineEdit_addWorkerINN->text().toInt(),
                                            pixmapToByteArray(ui->widget_addWorkerPhoto->getPixmap()),
                                            ui->lineEdit_addWorkerPIB->text(), ui->dateEdit_addWorkerDate->date(),
                                            ui->lineEdit_addWorkerPlaceFoRegistration->text(),
                                            ui->lineEdit_addWorkerPlaceOfResidence->text(),
                                            ui->lineEdit_addWorkerNumberPassport->text(),
                                            ui->comboBox_addWorkerPosition->currentIndex(),
                                            ui->comboBox_addWorkerLvlAccess->currentIndex(), ui->comboBox_addWorkerStateDissmised->currentIndex());
        }
        else
        {
            db->getWorkerModel()->updatedRow(filterWorker->mapToSource(ui->tableView_workers->currentIndex()).row(), ui->lineEdit_addWorkerINN->text().toInt(),
                                             pixmapToByteArray(ui->widget_addWorkerPhoto->getPixmap()),
                                             ui->lineEdit_addWorkerPIB->text(), ui->dateEdit_addWorkerDate->date(),
                                             ui->lineEdit_addWorkerPlaceFoRegistration->text(),
                                             ui->lineEdit_addWorkerPlaceOfResidence->text(),
                                             ui->lineEdit_addWorkerNumberPassport->text(),
                                             ui->comboBox_addWorkerPosition->currentIndex(),
                                             ui->comboBox_addWorkerLvlAccess->currentIndex(), ui->comboBox_addWorkerStateDissmised->currentIndex());
        }

        db->getWorkerModel()->saveChanges();
        db->getWorkerModel()->select();

        ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::WORKERS);
        ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::WORKERS_BUTTONS);
        break;
    }
    case PagesWorkPlace::CHECKPOINTS_ADD:
    {
        if(flagAddCheckpoint)
        {
            db->getCheckpointModel()->appendRow(0, ui->lineEdit_addCheckpointTitle->text(),
                                                ui->lineEdit_addCheckpointLocation->text(),
                                                ui->comboBox_addCheckpointLvlAccess->currentIndex(), 0);
        }
        else
        {
            db->getCheckpointModel()->updateRow(filterCheckpoint->sourceModel()->index(filterCheckpoint->mapToSource(ui->tableView_checkpoints->currentIndex()).row(), CheckpointModel::Column::ID).data().toInt(),
                                                ui->lineEdit_addCheckpointTitle->text(),
                                                ui->lineEdit_addCheckpointLocation->text(),
                                                ui->comboBox_addCheckpointLvlAccess->currentIndex(), 0);
        }

        db->getCheckpointModel()->saveChanges();
        db->getCheckpointModel()->select();

        ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::CHECKPOINTS);
        ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::CHECKPOINTS_BUTTONS);
        break;
    }
    case PagesWorkPlace::ACCOUNTS_ADD:
    {
        if(flagAddAccount)
        {
            db->getAccountModel()->appendRow(ui->lineEdit_addAccountLogin->text(), ui->lineEdit_addAccountPasswordFirst->text(),
                                             ui->comboBox_addAccountPrivilege->currentIndex(),
                                             workerCombobox->index(ui->comboBox_addAccountWorker->currentIndex(), WorkerModel::Column::INN).data().toInt());
        }
        else
        {
            db->getAccountModel()->updateRow(filterAccount->mapToSource(ui->tableView_accounts->currentIndex()).row(),
                                             ui->lineEdit_addAccountLogin->text(),
                                             ui->lineEdit_addAccountPasswordFirst->text(),
                                             ui->comboBox_addAccountPrivilege->currentIndex(),
                                             workerCombobox->index(ui->comboBox_addAccountWorker->currentIndex(), WorkerModel::Column::INN).data().toInt());
        }

        db->getAccountModel()->saveChange();
        db->getAccountModel()->select();

        ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::ACCOUNTS);
        ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::ACCOUNTS_BUTTONS);
        break;
    }
    case PagesWorkPlace::ACCESS_ADD:
    {
        if(flagAddLvlAcces)
        {
            db->getAccessModel()->appendRow(ui->lineEdit_addAccessTitle->text(), ui->spinBox_addAccessLvl->value(), 0);
        }
        else
        {
            db->getAccessModel()->updateRow(filterAccess->mapToSource(ui->tableView_lvlAccess->currentIndex()).row(),
                                            ui->lineEdit_addAccessTitle->text(), ui->spinBox_addAccessLvl->value(), 0);
        }

        db->getAccessModel()->saveChanges();
        db->getAccessModel()->select();

        ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::LVL_ACCESS);
        ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::LVL_ACCESS_BUTTONS);
        break;
    }
    case PagesWorkPlace::POSITION_ADD:
    {
        if(flagAddPosition)
        {
            db->getPositionModel()->appendRow(0, ui->lineEdit_addPositionTitle->text(), 0);
        }
        else
        {
            db->getPositionModel()->updateRow(filterPosition->mapToSource(filterPosition->index(ui->listView_positions->currentIndex().row(), 0)).row(),
                                              0, ui->lineEdit_addPositionTitle->text(), 0);
        }

        db->getPositionModel()->saveChanges();
        db->getPositionModel()->select();

        ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::POSITION);
        ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::POSITION_BUTTONS);
        break;
    }
    }

    switchBackButton(false);
}

QByteArray pixmapToByteArray(QPixmap pixmap)
{
    QByteArray bytes;
    QBuffer buffer(&bytes);
    buffer.open(QIODevice::Append);
    pixmap.save(&buffer, "JPG");
    buffer.close();


    return bytes;
}

void MainWindow::on_pushButton_addWorkerLoadPhoto_clicked()
{
    QFileDialog dialog(this);

    QString dir = dialog.getSaveFileName();
    QPixmap pixmap;
    pixmap.load(dir);

    ui->widget_addWorkerPhoto->setScaledPixmap(pixmap);
}


void MainWindow::on_pushButton_addCheckpoint_clicked()
{
    flagAddCheckpoint = true;

    ui->label_addCheckpointLabel->setText(addCheckpointLabel);
    ui->comboBox_addCheckpointLvlAccess->setCurrentIndex(0);
    ui->lineEdit_addCheckpointLocation->setText("");
    ui->lineEdit_addCheckpointTitle->setText("");

    ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::CHECKPOINTS_ADD);
    ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::SAVE_CANCEL_BUTTONS);
    switchBackButton(true);
}


void MainWindow::on_pushButton_editCheckpoint_clicked()
{
    if(ui->tableView_checkpoints->currentIndex().row() == -1)
        return;

    flagAddCheckpoint = false;

    ui->label_addCheckpointLabel->setText(updateCheclpointLabel);

    ui->comboBox_addCheckpointLvlAccess->setCurrentIndex(filterCheckpoint->sourceModel()->index(filterCheckpoint->mapToSource(ui->tableView_checkpoints->currentIndex()).row(), CheckpointModel::Column::LVL_ACCESS).data(CheckpointModel::Role::Read).toInt());
    ui->lineEdit_addCheckpointLocation->setText(filterCheckpoint->sourceModel()->index(filterCheckpoint->mapToSource(ui->tableView_checkpoints->currentIndex()).row(), CheckpointModel::Column::LOCATION).data().toString());
    ui->lineEdit_addCheckpointTitle->setText(filterCheckpoint->sourceModel()->index(filterCheckpoint->mapToSource(ui->tableView_checkpoints->currentIndex()).row(), CheckpointModel::Column::TITLE).data().toString());

    ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::CHECKPOINTS_ADD);
    ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::SAVE_CANCEL_BUTTONS);
    switchBackButton(true);
}


void MainWindow::on_pushButton_removeCheckpoint_clicked()
{
    if(ui->tableView_checkpoints->currentIndex().row() == -1)
        return;

    db->getCheckpointModel()->removeRow(filterCheckpoint->mapToSource(ui->tableView_checkpoints->currentIndex()).row());
    db->getCheckpointModel()->saveChanges();
    db->getCheckpointModel()->select();
}


void MainWindow::on_pushButton_moreAboutAuthorization_clicked()
{
    if(ui->tableView_authorizations->currentIndex().row() == -1)
        return;

    ui->label_viewAuthorizationAuthorizer->setText(filterAuthorization->sourceModel()->index(filterAuthorization->mapToSource(ui->tableView_authorizations->currentIndex()).row(), AuthorizationModel::Column::AUTHORIZER).data().toString());
    ui->label_viewAuthorizationCheckpoint->setText(filterAuthorization->sourceModel()->index(filterAuthorization->mapToSource(ui->tableView_authorizations->currentIndex()).row(), AuthorizationModel::Column::CHECKPOINT).data().toString());
    ui->label_viewAuthorizationDate->setText(filterAuthorization->sourceModel()->index(filterAuthorization->mapToSource(ui->tableView_authorizations->currentIndex()).row(), AuthorizationModel::Column::DATE).data().toString());
    ui->label_viewAuthorizationState->setText(filterAuthorization->sourceModel()->index(filterAuthorization->mapToSource(ui->tableView_authorizations->currentIndex()).row(), AuthorizationModel::Column::STATE).data().toString());
    ui->label_viewAuthorizationTime->setText(filterAuthorization->sourceModel()->index(filterAuthorization->mapToSource(ui->tableView_authorizations->currentIndex()).row(), AuthorizationModel::Column::TIME).data().toString());
    ui->label_viewAuthorizationWorker->setText(filterAuthorization->sourceModel()->index(filterAuthorization->mapToSource(ui->tableView_authorizations->currentIndex()).row(), AuthorizationModel::Column::CHECKPOINT).data().toString());

    ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::AUTHORIZATIONS_VIEW);
}


void MainWindow::on_pushButton_addAccount_clicked()
{
    flagAddAccount = true;

    ui->label_addAccountLabel->setText(addAccountLabel);

    ui->comboBox_addAccountPrivilege->setCurrentIndex(0);
    ui->comboBox_addAccountWorker->setCurrentIndex(0);
    ui->lineEdit_addAccountLogin->setEnabled(true);
    ui->lineEdit_addAccountLogin->setText("");
    ui->lineEdit_addAccountPasswordFirst->setText("");
    ui->lineEdit_addAccountPasswordSecond->setText("");

    ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::ACCOUNTS_ADD);
    ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::SAVE_CANCEL_BUTTONS);
    switchBackButton(true);
}


void MainWindow::on_pushButton_editAccount_clicked()
{
    if(ui->tableView_accounts->currentIndex().row() == -1)
        return;

    flagAddAccount = false;

    ui->label_addAccountLabel->setText(updateAccountLabel);

    ui->comboBox_addAccountPrivilege->setCurrentIndex(filterAccount->sourceModel()->index(filterAccount->mapToSource(ui->tableView_accounts->currentIndex()).row(), AccountModel::Column::PRIVILEGE).data(AccountModel::Role::Read).toInt());
    ui->comboBox_addAccountWorker->setCurrentIndex(filterAccount->sourceModel()->index(filterAccount->mapToSource(ui->tableView_accounts->currentIndex()).row(), AccountModel::Column::WORKER).data(AccountModel::Role::Read).toInt());
    ui->lineEdit_addAccountLogin->setEnabled(false);
    ui->lineEdit_addAccountLogin->setText(filterAccount->sourceModel()->index(filterAccount->mapToSource(ui->tableView_accounts->currentIndex()).row(), AccountModel::Column::LOGIN).data().toString());
    ui->lineEdit_addAccountPasswordFirst->setText(filterAccount->sourceModel()->index(filterAccount->mapToSource(ui->tableView_accounts->currentIndex()).row(), AccountModel::Column::PASSWORD).data().toString());

    ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::ACCOUNTS_ADD);
    ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::SAVE_CANCEL_BUTTONS);
    switchBackButton(true);
}


void MainWindow::on_pushButton_moreAboutAccount_clicked()
{
    if(ui->tableView_accounts->currentIndex().row() == -1)
        return;

    ui->label_viewAccountLogin->setText(filterAccount->sourceModel()->index(filterAccount->mapToSource(ui->tableView_accounts->currentIndex()).row(), AccountModel::Column::LOGIN).data().toString());
    ui->label_viewAccountPrivilege->setText(filterAccount->sourceModel()->index(filterAccount->mapToSource(ui->tableView_accounts->currentIndex()).row(), AccountModel::Column::PRIVILEGE).data().toString());
    ui->label_viewAccountWorker->setText(filterAccount->sourceModel()->index(filterAccount->mapToSource(ui->tableView_accounts->currentIndex()).row(), AccountModel::Column::WORKER).data().toString());

    ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::ACCOUNTS_VIEW);
}


void MainWindow::on_pushButton_removeAccount_clicked()
{
    if(ui->tableView_accounts->currentIndex().row() == -1)
        return;

    db->getAccountModel()->removeRow(filterAccount->mapToSource(ui->tableView_accounts->currentIndex()).row());
    db->getAccountModel()->saveChange();
    db->getAccountModel()->select();
}


void MainWindow::on_pushButton_addLvlAccess_clicked()
{
    flagAddLvlAcces = true;

    ui->label_addLvlAccessLabel->setText(addAccessLabel);

    ui->lineEdit_addAccessTitle->setText("");
    ui->spinBox_addAccessLvl->setValue(0);

    ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::ACCESS_ADD);
    ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::SAVE_CANCEL_BUTTONS);
    switchBackButton(true);
}


void MainWindow::on_pushButton_editLvlAccess_clicked()
{
    if(ui->tableView_lvlAccess->currentIndex().row() == -1)
        return;

    flagAddLvlAcces = false;

    ui->label_addLvlAccessLabel->setText(updateAccesLabel);

    ui->lineEdit_addAccessTitle->setText(filterAccess->sourceModel()->index(filterAccess->mapToSource(ui->tableView_lvlAccess->currentIndex()).row(), AccessModel::Column::TITLE).data().toString());
    ui->spinBox_addAccessLvl->setValue(filterAccess->sourceModel()->index(filterAccess->mapToSource(ui->tableView_lvlAccess->currentIndex()).row(), AccessModel::Column::PRIVILEGE).data().toInt());

    ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::ACCESS_ADD);
    ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::SAVE_CANCEL_BUTTONS);
    switchBackButton(true);
}


void MainWindow::on_pushButton_removeLvlAccess_clicked()
{
    if(ui->tableView_lvlAccess->currentIndex().row() == -1)
        return;

    db->getAccessModel()->removeRow(filterAccess->mapToSource(ui->tableView_lvlAccess->currentIndex()).row());
    db->getAccessModel()->saveChanges();
    db->getAccessModel()->select();
}


void MainWindow::on_pushButton_addPosition_clicked()
{
    flagAddPosition = true;

    ui->label_addPositionLabel->setText(addPositionLabel);

    ui->lineEdit_addPositionTitle->setText("");

    ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::POSITION_ADD);
    ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::SAVE_CANCEL_BUTTONS);
    switchBackButton(true);
}


void MainWindow::on_pushButton_editPosition_clicked()
{
    if(ui->listView_positions->currentIndex().row() == -1)
        return;

    flagAddPosition = false;

    ui->label_addPositionLabel->setText(updatePositionLabel);

    ui->lineEdit_addPositionTitle->setText(filterPosition->sourceModel()->index(filterPosition->mapToSource(filterPosition->index(ui->listView_positions->currentIndex().row(), 0)).row(), PositionModel::Column::TITLE).data().toString());
    //ui->label_addPositionLabel->setText(filterPosition->sourceModel()->index(filterPosition->mapToSource(ui->listView_positions->currentIndex()).row(), PositionModel::Column::TITLE).data().toString());


    ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::POSITION_ADD);
    ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::SAVE_CANCEL_BUTTONS);
    switchBackButton(true);
}


void MainWindow::on_pushButton_removePosition_clicked()
{
    if(ui->listView_positions->currentIndex().row() == -1)
        return;

    db->getPositionModel()->removeRow(filterPosition->mapToSource(filterPosition->index(ui->listView_positions->currentIndex().row(), 0)).row());
    db->getPositionModel()->saveChanges();
    db->getPositionModel()->select();
}


void MainWindow::on_pushButton_exit_clicked()
{
    db->disconnect();
    ui->lineEdit_login->setText("");
    ui->lineEdit_password->setText("");
    ui->label_loginErrors->setText("");

    ui->stackedWidget_mainWindow->setCurrentIndex(PagesMainWindow::AUTHORIZATION);
    ui->pushButton_back->clicked();
}

