#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "databasemodule.h"

#include "accessfiltermodel.h"
#include "accountfiltermodel.h"
#include "authorizationfiltermodel.h"
#include "checkpointfiltermodel.h"
#include "positionfiltermodel.h"
#include "workerfiltermodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    DatabaseModule* db;

    AccessFilterModel *filterAccess;
    AccountFilterModel *filterAccount;
    AuthorizationFilterModel *filterAuthorization;
    CheckpointFilterModel *filterCheckpoint;
    PositionFilterModel *filterPosition;
    WorkerFilterModel *filterWorker;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
