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

    if(!db->connect(ui->lineEdit_login->text(), ui->lineEdit_password->text()))
    {
        ui->label_loginErrors->setText(db->lastError().databaseText());
        return;
    }

    //    switch (db->getPrivileges()) {

    //    }

    ui->stackedWidget_mainWindow->setCurrentIndex(PagesMainWindow::WORKSPACE);

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
}


void MainWindow::on_pushButton_back_clicked()
{
    ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::START);
    ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::MAINMENU_BUTTONS);
    ui->pushButton_back->setVisible(false);
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
    ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::AUTHORIZATIONS_BUTTONS);
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
    ui->lineEdit_addWorkerPIB->setText("");
    ui->lineEdit_addWorkerINN->setText("");
    ui->dateEdit_addWorkerDate->setDate(QDate::currentDate());
    ui->lineEdit_addWorkerPlaceFoRegistration->setText("");
    ui->lineEdit_addWorkerPlaceOfResidence->setText("");
    ui->lineEdit_addWorkerNumberPassport->setText("");
    ui->comboBox_addWorkerLvlAccess->setCurrentIndex(0);
    ui->comboBox_addWorkerPosition->setCurrentIndex(0);

    ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::WORKERS_ADD);
    ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::SAVE_CANCEL_BUTTONS);
    switchBackButton(true);
}


void MainWindow::on_pushButton_cancel_clicked()
{
    ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::START);
    ui->stackedWidget_buttonPanels->setCurrentIndex(PagesButtonsPanel::MAINMENU_BUTTONS);
    switchBackButton(false);
}


void MainWindow::on_pushButton_moreAboutWorker_clicked()
{
    if(ui->tableView_workers->currentIndex().column() == -1)
        return;
    QPixmap pixmap;
    pixmap.loadFromData(filterWorker->sourceModel()->index(ui->tableView_workers->currentIndex().row(), WorkerModel::Column::PHOTO).data(Qt::DisplayRole).toByteArray(), "JPG");

    ui->label_viewWorkerPIB->setText(filterWorker->sourceModel()->index(ui->tableView_workers->currentIndex().row(), WorkerModel::Column::PIB).data(Qt::DisplayRole).toString());
    ui->label_viewWorkerINN->setText(filterWorker->sourceModel()->index(ui->tableView_workers->currentIndex().row(), WorkerModel::Column::INN).data(Qt::DisplayRole).toString());
    ui->label_viewWorkerDateOfBirth->setText(filterWorker->sourceModel()->index(ui->tableView_workers->currentIndex().row(), WorkerModel::Column::DATE_OF_BIRTH).data(Qt::DisplayRole).toString());
    ui->label_viewWorkerPlaceOfRegistration->setText(filterWorker->sourceModel()->index(ui->tableView_workers->currentIndex().row(), WorkerModel::Column::PLACE_OF_REGISTRATION).data(Qt::DisplayRole).toString());
    ui->label_viewWorkerPlaceOfResidence->setText(filterWorker->sourceModel()->index(ui->tableView_workers->currentIndex().row(), WorkerModel::Column::PLACE_OF_RESIDENCE).data(Qt::DisplayRole).toString());
    ui->label_viewWorkerNumberPassport->setText(filterWorker->sourceModel()->index(ui->tableView_workers->currentIndex().row(), WorkerModel::Column::NUMBER_PASSPORT).data(Qt::DisplayRole).toString());
    ui->label_viewWorkerLvlAccess->setText(filterWorker->sourceModel()->index(ui->tableView_workers->currentIndex().row(), WorkerModel::Column::LVL_ACCESS).data(Qt::DisplayRole).toString());
    ui->label_viewWorkerPosition->setText(filterWorker->sourceModel()->index(ui->tableView_workers->currentIndex().row(), WorkerModel::Column::POSITION).data(Qt::DisplayRole).toString());
    ui->widget_viewWorkerPhoto->setScaledPixmap(pixmap);

    ui->stackedWidget_workPlace->setCurrentIndex(PagesWorkPlace::WORKERS_VIEW);
    switchBackButton(false);
}

