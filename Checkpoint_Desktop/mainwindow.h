#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QBuffer>
#include <QFileDialog>

#include <LimeReport>

#include "databasemodule.h"

#include "accessfiltermodel.h"
#include "accountfiltermodel.h"
#include "authorizationfiltermodel.h"
#include "checkpointfiltermodel.h"
#include "positionfiltermodel.h"
#include "workerfiltermodel.h"
#include "modelforcombobox.h"
#include "modelforprint.h"
#include "modelforprintcheckpoint.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QString addWorkerLabel = "Добавление сотрудника";
    QString updateWorkerLabel = "Редактирование сотрудника";

    QString addCheckpointLabel = "Добавление проходной";
    QString updateCheclpointLabel = "Редактирование проходной";

    QString addAccountLabel = "Добавление аккаунта";
    QString updateAccountLabel = "Редактирование аккаунта";

    QString addAccessLabel = "Добавление уровня доступа";
    QString updateAccesLabel = "Редактирование уравня доступа";

    QString addPositionLabel = "Добавление должности";
    QString updatePositionLabel = "Редактирование должности";

    bool flagAddWorker;
    bool flagAddCheckpoint;
    bool flagAddAccount;
    bool flagAddLvlAcces;
    bool flagAddPosition;

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

    enum Privileges {
        ADMIN = 1,
        BUHGALTER,
        SB
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

    void on_pushButton_editWorker_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_addWorkerLoadPhoto_clicked();

    void on_pushButton_addCheckpoint_clicked();

    void on_pushButton_editCheckpoint_clicked();

    void on_pushButton_removeCheckpoint_clicked();

    void on_pushButton_moreAboutAuthorization_clicked();

    void on_pushButton_addAccount_clicked();

    void on_pushButton_editAccount_clicked();

    void on_pushButton_moreAboutAccount_clicked();

    void on_pushButton_removeAccount_clicked();

    void on_pushButton_addLvlAccess_clicked();

    void on_pushButton_editLvlAccess_clicked();

    void on_pushButton_removeLvlAccess_clicked();

    void on_pushButton_addPosition_clicked();

    void on_pushButton_editPosition_clicked();

    void on_pushButton_removePosition_clicked();

    void on_pushButton_exit_clicked();

    void on_pushButton_viewWorkerPrintPass_clicked();

    void on_pushButton_updateTables_clicked();

    void on_dateEdit_filterAuthorization_userDateChanged(const QDate &date);

    void on_timeEdit_filterAuthorization_userTimeChanged(const QTime &time);

    void on_pushButton_clicked();

    void on_pushButton_viewCheckpoint_clicked();

private:
    Ui::MainWindow *ui;
};

QByteArray pixmapToByteArray(QPixmap pixmap);
#endif // MAINWINDOW_H
