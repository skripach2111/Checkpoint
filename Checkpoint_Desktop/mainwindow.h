#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>

#include "databasemodule.h"

#include "accessfiltermodel.h"
#include "accountfiltermodel.h"
#include "authorizationfiltermodel.h"
#include "checkpointfiltermodel.h"
#include "positionfiltermodel.h"
#include "workerfiltermodel.h"
#include "modelforcombobox.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QSettings *settings;

    DatabaseModule* db;

    AccessFilterModel *filterAccess;
    AccountFilterModel *filterAccount;
    AuthorizationFilterModel *filterAuthorization;
    CheckpointFilterModel *filterCheckpoint;
    PositionFilterModel *filterPosition;
    WorkerFilterModel *filterWorker;

    ModelForComboBox *accessCombobox;
    ModelForComboBox *positionCombobox;
    ModelForComboBox *privilegeCombobox;
    ModelForComboBox *stateCombobox;
    ModelForComboBox *checkpointCombobox;
    ModelForComboBox *workerCombobox;

    enum PagesMainWindow {
        AUTHORIZATION = 0,
        WORKSPACE,
        SETTINGS
    };

    enum PagesWorkPlace {
        START = 0,
        WORKERS,
        CHECKPOINTS,
        AUTHORIZATIONS,
        ACCOUNTS,
        LVL_ACCESS,
        POSITION,
        PRIVILEGES,
        STATES,
        WORKERS_ADD,
        WORKERS_VIEW,
        CHECKPOINTS_ADD,
        CHECKPOINTS_VIEW,
        AUTHORIZATIONS_VIEW,
        ACCOUNTS_ADD,
        ACCOUNTS_VIEW,
        ACCESS_ADD,
        POSITION_ADD
    };

    enum PagesButtonsPanel {
        MAINMENU_BUTTONS = 0,
        WORKERS_BUTTONS,
        CHECKPOINTS_BUTTONS,
        AUTHORIZATIONS_BUTTONS,
        ACCOUNTS_BUTTONS,
        LVL_ACCESS_BUTTONS,
        POSITION_BUTTONS,
        PRIVILEGES_BUTTONS,
        STATES_BUTTONS,
        SAVE_CANCEL_BUTTONS
    };

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void switchBackButton(bool flag);

private slots:
    void on_pushButton_Connect_clicked();

    void on_pushButton_workers_clicked();

    void on_pushButton_states_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_checkpoints_clicked();

    void on_pushButton_authorizations_clicked();

    void on_pushButton_accounts_clicked();

    void on_pushButton_lvlAccesses_clicked();

    void on_pushButton_positions_clicked();

    void on_pushButton_privilege_clicked();

    void on_pushButton_backToLogin_clicked();

    void on_pushButton_settings_clicked();

    void on_pushButton_applySettings_clicked();

    void on_lineEdit_filterWorkerByInn_editingFinished();

    void on_lineEdit_filterWorkerByFIO_editingFinished();

    void on_comboBox_filterWorkerByPosition_currentIndexChanged(int index);

    void on_comboBox_filterWorkerByLvlAccess_currentIndexChanged(int index);

    void workerDissmissedFilterChanged();
//    void authorizationStateFilterChenged();

    void on_lineEdit_filterCheckpointByTitle_editingFinished();

    void on_comboBox_filterCheckpointByLvlAccess_currentIndexChanged(int index);

    void on_checkBox_filterAuthorizationByDate_stateChanged(int arg1);

    void on_checkBox_filterAuthorizationByTime_stateChanged(int arg1);

    void on_lineEdit_filterAuthorizationByWorker_editingFinished();

    void on_lineEdit_filterAuthorizationByAuthorizer_editingFinished();

    void on_comboBox_filterAuthorizationByCheckpoint_currentIndexChanged(int index);

    void on_comboBox_filterAuthorizationByLvlAccess_currentIndexChanged(int index);

    void on_checkBox_filterAuthorizationByStateIncoming_stateChanged(int arg1);

    void on_checkBox_filterAuthorizationByStateGraduates_stateChanged(int arg1);

    void on_checkBox_filterAuthorizationByStateInadmissible_stateChanged(int arg1);

    void on_lineEdit_filterAccountsByLogin_editingFinished();

    void on_lineEdit_filterAccountsByFIO_editingFinished();

    void on_comboBox_filterAccountsByPrivileges_currentIndexChanged(int index);

    void on_lineEdit_filterLvlAccessByTitle_editingFinished();

    void on_spinBox_filterLvlAccessByLvl_valueChanged(int arg1);

    void on_lineEdit_filterPositionsByTitle_editingFinished();

    void on_pushButton_addWorker_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_moreAboutWorker_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
