/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <scaledpixmap.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_11;
    QStackedWidget *stackedWidget_mainWindow;
    QWidget *page_authorization;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_exitLogin;
    QPushButton *pushButton_faq;
    QPushButton *pushButton_settings;
    QSpacerItem *horizontalSpacer_3;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFrame *frame_3;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_login;
    QLabel *label_3;
    QLineEdit *lineEdit_password;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_loginErrors;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Connect;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_4;
    QWidget *page_workplace;
    QGridLayout *gridLayout_3;
    QStackedWidget *stackedWidget_workPlace;
    QWidget *page_start;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_7;
    QLabel *label_4;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_8;
    QWidget *page_workers;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_6;
    QFrame *frame_5;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_filterWorkerByInn;
    QComboBox *comboBox_filterWorkerByLvlAccess;
    QLineEdit *lineEdit_filterWorkerByFIO;
    QComboBox *comboBox_filterWorkerByPosition;
    QRadioButton *radioButton_showDismissed;
    QRadioButton *radioButton_showAll;
    QRadioButton *radioButton_hideTheDismissed;
    QTableView *tableView_workers;
    QWidget *page_checkpoints;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_7;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_filterCheckpointByTitle;
    QComboBox *comboBox_filterCheckpointByLvlAccess;
    QSpacerItem *horizontalSpacer_7;
    QTableView *tableView_checkpoints;
    QWidget *page_authorizations;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_8;
    QFrame *frame_7;
    QGridLayout *gridLayout;
    QCheckBox *checkBox_filterAuthorizationByStateInadmissible;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBox_filterAuthorizationByDate;
    QDateEdit *dateEdit_filterAuthorization;
    QLineEdit *lineEdit_filterAuthorizationByWorker;
    QComboBox *comboBox_filterAuthorizationByLvlAccess;
    QFrame *frame_9;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *checkBox_filterAuthorizationByTime;
    QTimeEdit *timeEdit_filterAuthorization;
    QCheckBox *checkBox_filterAuthorizationByStateIncoming;
    QCheckBox *checkBox_filterAuthorizationByStateGraduates;
    QLineEdit *lineEdit_filterAuthorizationByAuthorizer;
    QComboBox *comboBox_filterAuthorizationByCheckpoint;
    QTableView *tableView_authorizations;
    QWidget *page_accounts;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_9;
    QFrame *frame_10;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEdit_filterAccountsByLogin;
    QLineEdit *lineEdit_filterAccountsByFIO;
    QComboBox *comboBox_filterAccountsByPrivileges;
    QTableView *tableView_accounts;
    QWidget *page_lvlAccess;
    QVBoxLayout *verticalLayout_21;
    QLabel *label_10;
    QFrame *frame_11;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *lineEdit_filterLvlAccessByTitle;
    QLabel *label_11;
    QSpinBox *spinBox_filterLvlAccessByLvl;
    QSpacerItem *horizontalSpacer_8;
    QTableView *tableView_lvlAccess;
    QWidget *page_positions;
    QVBoxLayout *verticalLayout_24;
    QLabel *label_12;
    QFrame *frame_12;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *lineEdit_filterPositionsByTitle;
    QSpacerItem *horizontalSpacer_9;
    QListView *listView_positions;
    QWidget *page_privileges;
    QVBoxLayout *verticalLayout_27;
    QLabel *label_13;
    QListView *listView_privilege;
    QWidget *page_states;
    QVBoxLayout *verticalLayout_29;
    QLabel *label_15;
    QListView *listView_states;
    QWidget *page_workers_add;
    QVBoxLayout *verticalLayout_32;
    QLabel *label_addWorkerLabel;
    QScrollArea *scrollArea_9;
    QWidget *scrollAreaWidgetContents_8;
    QVBoxLayout *verticalLayout_35;
    QFrame *frame_14;
    QVBoxLayout *verticalLayout_33;
    QLabel *label_30;
    QFrame *line;
    QHBoxLayout *horizontalLayout_17;
    QVBoxLayout *verticalLayout_36;
    ScaledPixmap *widget_addWorkerPhoto;
    QPushButton *pushButton_addWorkerLoadPhoto;
    QVBoxLayout *verticalLayout_37;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_24;
    QLineEdit *lineEdit_addWorkerPIB;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_25;
    QLineEdit *lineEdit_addWorkerINN;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_26;
    QDateEdit *dateEdit_addWorkerDate;
    QSpacerItem *horizontalSpacer_14;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_27;
    QLineEdit *lineEdit_addWorkerPlaceFoRegistration;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_28;
    QLineEdit *lineEdit_addWorkerPlaceOfResidence;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_29;
    QLineEdit *lineEdit_addWorkerNumberPassport;
    QHBoxLayout *horizontalLayout_48;
    QLabel *label_47;
    QLineEdit *lineEdit_workerLogin;
    QHBoxLayout *horizontalLayout_49;
    QLabel *label_48;
    QLineEdit *lineEdit_workerPassword;
    QFrame *frame_15;
    QVBoxLayout *verticalLayout_34;
    QLabel *label_31;
    QFrame *line_2;
    QGridLayout *gridLayout_7;
    QLabel *label_33;
    QSpacerItem *horizontalSpacer_12;
    QLabel *label_32;
    QComboBox *comboBox_addWorkerLvlAccess;
    QComboBox *comboBox_addWorkerPosition;
    QLabel *label_23;
    QComboBox *comboBox_addWorkerStateDissmised;
    QSpacerItem *verticalSpacer_23;
    QWidget *page_workers_view;
    QVBoxLayout *verticalLayout_39;
    QLabel *label_34;
    QScrollArea *scrollArea_10;
    QWidget *scrollAreaWidgetContents_9;
    QVBoxLayout *verticalLayout_43;
    QFrame *frame_16;
    QVBoxLayout *verticalLayout_40;
    QLabel *label_35;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_22;
    ScaledPixmap *widget_viewWorkerPhoto;
    QVBoxLayout *verticalLayout_42;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_37;
    QLabel *label_viewWorkerPIB;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_38;
    QLabel *label_viewWorkerINN;
    QSpacerItem *horizontalSpacer_15;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_39;
    QLabel *label_viewWorkerDateOfBirth;
    QSpacerItem *horizontalSpacer_16;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_40;
    QLabel *label_viewWorkerPlaceOfRegistration;
    QSpacerItem *horizontalSpacer_17;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_41;
    QLabel *label_viewWorkerPlaceOfResidence;
    QSpacerItem *horizontalSpacer_18;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_42;
    QLabel *label_viewWorkerNumberPassport;
    QSpacerItem *horizontalSpacer_19;
    QHBoxLayout *horizontalLayout_46;
    QLabel *label_46;
    QLabel *label_workerLogin;
    QSpacerItem *horizontalSpacer_38;
    QFrame *frame_17;
    QVBoxLayout *verticalLayout_41;
    QLabel *label_36;
    QFrame *line_4;
    QGridLayout *gridLayout_8;
    QLabel *label_51;
    QLabel *label_49;
    QSpacerItem *horizontalSpacer_20;
    QLabel *label_viewWorkerLvlAccess;
    QLabel *label_viewWorkerPosition;
    QLabel *label_43;
    QLabel *label_viewWorkerStateDissmised;
    QSpacerItem *verticalSpacer_24;
    QHBoxLayout *horizontalLayout_23;
    QSpacerItem *horizontalSpacer_21;
    QPushButton *pushButton_viewWorkerPrintPass;
    QWidget *page_checkpoints_add;
    QVBoxLayout *verticalLayout_44;
    QLabel *label_addCheckpointLabel;
    QScrollArea *scrollArea_11;
    QWidget *scrollAreaWidgetContents_10;
    QVBoxLayout *verticalLayout_45;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_54;
    QLineEdit *lineEdit_addCheckpointTitle;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_55;
    QLineEdit *lineEdit_addCheckpointLocation;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_56;
    QComboBox *comboBox_addCheckpointLvlAccess;
    QSpacerItem *horizontalSpacer_22;
    QSpacerItem *verticalSpacer_25;
    QWidget *page_checkpoints_view;
    QVBoxLayout *verticalLayout_46;
    QLabel *label_57;
    QScrollArea *scrollArea_12;
    QWidget *scrollAreaWidgetContents_11;
    QVBoxLayout *verticalLayout_47;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_58;
    QLabel *label_viewCheckpointTitle;
    QSpacerItem *horizontalSpacer_23;
    QHBoxLayout *horizontalLayout_28;
    QLabel *label_60;
    QLabel *label_viewCheckpointLocation;
    QSpacerItem *horizontalSpacer_24;
    QHBoxLayout *horizontalLayout_29;
    QLabel *label_62;
    QLabel *label_viewCheckpointLvlAccess;
    QSpacerItem *horizontalSpacer_25;
    QSpacerItem *verticalSpacer_26;
    QHBoxLayout *horizontalLayout_50;
    QSpacerItem *horizontalSpacer_39;
    QPushButton *pushButton;
    QWidget *page_authorizations_view;
    QVBoxLayout *verticalLayout_48;
    QLabel *label_64;
    QScrollArea *scrollArea_13;
    QWidget *scrollAreaWidgetContents_12;
    QVBoxLayout *verticalLayout_49;
    QHBoxLayout *horizontalLayout_30;
    QLabel *label_65;
    QLabel *label_viewAuthorizationWorker;
    QSpacerItem *horizontalSpacer_26;
    QHBoxLayout *horizontalLayout_31;
    QLabel *label_67;
    QLabel *label_viewAuthorizationDate;
    QSpacerItem *horizontalSpacer_27;
    QHBoxLayout *horizontalLayout_32;
    QLabel *label_68;
    QLabel *label_viewAuthorizationTime;
    QSpacerItem *horizontalSpacer_28;
    QHBoxLayout *horizontalLayout_33;
    QLabel *label_69;
    QLabel *label_viewAuthorizationState;
    QSpacerItem *horizontalSpacer_29;
    QHBoxLayout *horizontalLayout_34;
    QLabel *label_70;
    QLabel *label_viewAuthorizationAuthorizer;
    QSpacerItem *horizontalSpacer_30;
    QHBoxLayout *horizontalLayout_35;
    QLabel *label_71;
    QLabel *label_viewAuthorizationCheckpoint;
    QSpacerItem *horizontalSpacer_31;
    QSpacerItem *verticalSpacer_27;
    QWidget *page_accounts_add;
    QVBoxLayout *verticalLayout_50;
    QLabel *label_addAccountLabel;
    QScrollArea *scrollArea_14;
    QWidget *scrollAreaWidgetContents_13;
    QVBoxLayout *verticalLayout_51;
    QHBoxLayout *horizontalLayout_36;
    QLabel *label_78;
    QLineEdit *lineEdit_addAccountLogin;
    QHBoxLayout *horizontalLayout_38;
    QLabel *label_80;
    QLineEdit *lineEdit_addAccountPasswordFirst;
    QLineEdit *lineEdit_addAccountPasswordSecond;
    QHBoxLayout *horizontalLayout_39;
    QLabel *label_81;
    QComboBox *comboBox_addAccountPrivilege;
    QSpacerItem *horizontalSpacer_32;
    QHBoxLayout *horizontalLayout_37;
    QLabel *label_79;
    QComboBox *comboBox_addAccountWorker;
    QSpacerItem *horizontalSpacer_33;
    QSpacerItem *verticalSpacer_28;
    QWidget *page_accounts_ciew;
    QVBoxLayout *verticalLayout_52;
    QLabel *label_82;
    QScrollArea *scrollArea_15;
    QWidget *scrollAreaWidgetContents_14;
    QVBoxLayout *verticalLayout_53;
    QHBoxLayout *horizontalLayout_40;
    QLabel *label_83;
    QLabel *label_viewAccountLogin;
    QSpacerItem *horizontalSpacer_34;
    QHBoxLayout *horizontalLayout_41;
    QLabel *label_84;
    QLabel *label_viewAccountPrivilege;
    QSpacerItem *horizontalSpacer_35;
    QHBoxLayout *horizontalLayout_42;
    QLabel *label_85;
    QLabel *label_viewAccountWorker;
    QSpacerItem *horizontalSpacer_36;
    QSpacerItem *verticalSpacer_29;
    QWidget *page_access_add;
    QVBoxLayout *verticalLayout_54;
    QLabel *label_addLvlAccessLabel;
    QScrollArea *scrollArea_16;
    QWidget *scrollAreaWidgetContents_15;
    QVBoxLayout *verticalLayout_55;
    QHBoxLayout *horizontalLayout_43;
    QLabel *label_90;
    QLineEdit *lineEdit_addAccessTitle;
    QHBoxLayout *horizontalLayout_44;
    QLabel *label_91;
    QSpinBox *spinBox_addAccessLvl;
    QSpacerItem *horizontalSpacer_37;
    QSpacerItem *verticalSpacer_30;
    QWidget *page_position_add;
    QVBoxLayout *verticalLayout_56;
    QLabel *label_addPositionLabel;
    QScrollArea *scrollArea_17;
    QWidget *scrollAreaWidgetContents_16;
    QVBoxLayout *verticalLayout_57;
    QHBoxLayout *horizontalLayout_45;
    QLabel *label_93;
    QLineEdit *lineEdit_addPositionTitle;
    QSpacerItem *verticalSpacer_31;
    QFrame *frame_leftPanel;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_userInfoPanel;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_login;
    QLabel *label_position;
    QLabel *label_fio;
    QSpacerItem *verticalSpacer;
    QFrame *frame_buttonsPanell;
    QVBoxLayout *verticalLayout_6;
    QStackedWidget *stackedWidget_buttonPanels;
    QWidget *page_mainMenuButtons;
    QVBoxLayout *verticalLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_mainMenuButtons;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_5;
    QPushButton *pushButton_workers;
    QPushButton *pushButton_checkpoints;
    QPushButton *pushButton_authorizations;
    QPushButton *pushButton_accounts;
    QPushButton *pushButton_lvlAccesses;
    QPushButton *pushButton_positions;
    QPushButton *pushButton_privilege;
    QPushButton *pushButton_states;
    QSpacerItem *verticalSpacer_33;
    QPushButton *pushButton_updateTables;
    QSpacerItem *verticalSpacer_6;
    QWidget *page_workersButtons;
    QVBoxLayout *verticalLayout_10;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer_9;
    QPushButton *pushButton_addWorker;
    QPushButton *pushButton_editWorker;
    QPushButton *pushButton_moreAboutWorker;
    QSpacerItem *verticalSpacer_10;
    QWidget *page_checkpointsButtons;
    QVBoxLayout *verticalLayout_14;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_13;
    QSpacerItem *verticalSpacer_13;
    QPushButton *pushButton_addCheckpoint;
    QPushButton *pushButton_editCheckpoint;
    QPushButton *pushButton_removeCheckpoint;
    QPushButton *pushButton_viewCheckpoint;
    QSpacerItem *verticalSpacer_12;
    QWidget *page_authorizationsButtons;
    QVBoxLayout *verticalLayout_18;
    QScrollArea *scrollArea_4;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_16;
    QSpacerItem *verticalSpacer_14;
    QPushButton *pushButton_moreAboutAuthorization;
    QSpacerItem *verticalSpacer_15;
    QWidget *page_accountsButtons;
    QVBoxLayout *verticalLayout_20;
    QScrollArea *scrollArea_5;
    QWidget *scrollAreaWidgetContents_4;
    QVBoxLayout *verticalLayout_19;
    QSpacerItem *verticalSpacer_16;
    QPushButton *pushButton_addAccount;
    QPushButton *pushButton_editAccount;
    QPushButton *pushButton_moreAboutAccount;
    QPushButton *pushButton_removeAccount;
    QSpacerItem *verticalSpacer_17;
    QWidget *page_lvlAccessButtons;
    QVBoxLayout *verticalLayout_23;
    QScrollArea *scrollArea_6;
    QWidget *scrollAreaWidgetContents_5;
    QVBoxLayout *verticalLayout_22;
    QSpacerItem *verticalSpacer_18;
    QPushButton *pushButton_addLvlAccess;
    QPushButton *pushButton_editLvlAccess;
    QPushButton *pushButton_moreAboutLvlAccess;
    QPushButton *pushButton_removeLvlAccess;
    QSpacerItem *verticalSpacer_19;
    QWidget *page_positionsButtons;
    QVBoxLayout *verticalLayout_26;
    QScrollArea *scrollArea_7;
    QWidget *scrollAreaWidgetContents_6;
    QVBoxLayout *verticalLayout_25;
    QSpacerItem *verticalSpacer_20;
    QPushButton *pushButton_addPosition;
    QPushButton *pushButton_editPosition;
    QPushButton *pushButton_removePosition;
    QSpacerItem *verticalSpacer_21;
    QWidget *page_privilegesButtons;
    QVBoxLayout *verticalLayout_28;
    QLabel *label_14;
    QWidget *page_statesButtons;
    QVBoxLayout *verticalLayout_30;
    QLabel *label_16;
    QWidget *page_toolButtonst;
    QVBoxLayout *verticalLayout_38;
    QScrollArea *scrollArea_18;
    QWidget *scrollAreaWidgetContents_17;
    QVBoxLayout *verticalLayout_58;
    QLabel *label_errorMessage;
    QPushButton *pushButton_save;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_back;
    QSpacerItem *verticalSpacer_32;
    QSpacerItem *verticalSpacer_11;
    QPushButton *pushButton_exit;
    QWidget *page_settings;
    QGridLayout *gridLayout_5;
    QScrollArea *scrollArea_8;
    QWidget *scrollAreaWidgetContents_7;
    QVBoxLayout *verticalLayout_31;
    QLabel *label_18;
    QFrame *frame_13;
    QGridLayout *gridLayout_6;
    QLabel *label_20;
    QLineEdit *lineEdit_setHostPort;
    QLabel *label_19;
    QLineEdit *lineEdit_setHostAddress;
    QLabel *label_currentHostPort;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_21;
    QLabel *label_currentHostAddress;
    QLabel *label_22;
    QLabel *label_44;
    QLineEdit *lineEdit_setDbName;
    QLabel *label_45;
    QLabel *label_currentDbName;
    QSpacerItem *verticalSpacer_22;
    QPushButton *pushButton_applySettings;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_17;
    QPushButton *pushButton_backToLogin;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_11 = new QVBoxLayout(centralwidget);
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        stackedWidget_mainWindow = new QStackedWidget(centralwidget);
        stackedWidget_mainWindow->setObjectName(QString::fromUtf8("stackedWidget_mainWindow"));
        page_authorization = new QWidget();
        page_authorization->setObjectName(QString::fromUtf8("page_authorization"));
        gridLayout_2 = new QGridLayout(page_authorization);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        pushButton_exitLogin = new QPushButton(page_authorization);
        pushButton_exitLogin->setObjectName(QString::fromUtf8("pushButton_exitLogin"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(pushButton_exitLogin->sizePolicy().hasHeightForWidth());
        pushButton_exitLogin->setSizePolicy(sizePolicy);
        pushButton_exitLogin->setMaximumSize(QSize(40, 40));
        QIcon icon;
        icon.addFile(QString::fromUtf8("icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_exitLogin->setIcon(icon);
        pushButton_exitLogin->setIconSize(QSize(36, 36));
        pushButton_exitLogin->setFlat(true);

        horizontalLayout->addWidget(pushButton_exitLogin);

        pushButton_faq = new QPushButton(page_authorization);
        pushButton_faq->setObjectName(QString::fromUtf8("pushButton_faq"));
        sizePolicy.setHeightForWidth(pushButton_faq->sizePolicy().hasHeightForWidth());
        pushButton_faq->setSizePolicy(sizePolicy);
        pushButton_faq->setMaximumSize(QSize(40, 40));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("icons/faq.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_faq->setIcon(icon1);
        pushButton_faq->setIconSize(QSize(36, 36));
        pushButton_faq->setFlat(true);

        horizontalLayout->addWidget(pushButton_faq);

        pushButton_settings = new QPushButton(page_authorization);
        pushButton_settings->setObjectName(QString::fromUtf8("pushButton_settings"));
        sizePolicy.setHeightForWidth(pushButton_settings->sizePolicy().hasHeightForWidth());
        pushButton_settings->setSizePolicy(sizePolicy);
        pushButton_settings->setMaximumSize(QSize(40, 40));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("icons/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_settings->setIcon(icon2);
        pushButton_settings->setIconSize(QSize(36, 36));
        pushButton_settings->setFlat(true);

        horizontalLayout->addWidget(pushButton_settings);


        gridLayout_2->addLayout(horizontalLayout, 0, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(133, 335, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 0, 3, 1);

        frame = new QFrame(page_authorization);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(380, 0));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        label->setFont(font);

        verticalLayout->addWidget(label);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::NoFrame);
        frame_3->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame_3);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEdit_login = new QLineEdit(frame_3);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_login);

        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        lineEdit_password = new QLineEdit(frame_3);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_password);


        verticalLayout->addWidget(frame_3);

        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::NoFrame);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_loginErrors = new QLabel(frame_4);
        label_loginErrors->setObjectName(QString::fromUtf8("label_loginErrors"));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(64, 64, 64, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_loginErrors->setPalette(palette);

        horizontalLayout_2->addWidget(label_loginErrors);

        horizontalSpacer = new QSpacerItem(165, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_Connect = new QPushButton(frame_4);
        pushButton_Connect->setObjectName(QString::fromUtf8("pushButton_Connect"));

        horizontalLayout_2->addWidget(pushButton_Connect);


        verticalLayout->addWidget(frame_4);


        gridLayout_2->addWidget(frame, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(482, 65, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 0, 1, 3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 2, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 65, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 3, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 1, 4, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 0, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(159, 186, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 2, 3, 1, 2);

        stackedWidget_mainWindow->addWidget(page_authorization);
        page_workplace = new QWidget();
        page_workplace->setObjectName(QString::fromUtf8("page_workplace"));
        gridLayout_3 = new QGridLayout(page_workplace);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        stackedWidget_workPlace = new QStackedWidget(page_workplace);
        stackedWidget_workPlace->setObjectName(QString::fromUtf8("stackedWidget_workPlace"));
        page_start = new QWidget();
        page_start->setObjectName(QString::fromUtf8("page_start"));
        verticalLayout_7 = new QVBoxLayout(page_start);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_7);

        label_4 = new QLabel(page_start);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font1;
        font1.setPointSize(26);
        font1.setBold(true);
        font1.setUnderline(false);
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_4);

        label_5 = new QLabel(page_start);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_5);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_8);

        stackedWidget_workPlace->addWidget(page_start);
        page_workers = new QWidget();
        page_workers->setObjectName(QString::fromUtf8("page_workers"));
        verticalLayout_8 = new QVBoxLayout(page_workers);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(page_workers);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font2;
        font2.setPointSize(26);
        font2.setBold(true);
        label_6->setFont(font2);

        verticalLayout_8->addWidget(label_6);

        frame_5 = new QFrame(page_workers);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_5);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        lineEdit_filterWorkerByInn = new QLineEdit(frame_5);
        lineEdit_filterWorkerByInn->setObjectName(QString::fromUtf8("lineEdit_filterWorkerByInn"));

        gridLayout_4->addWidget(lineEdit_filterWorkerByInn, 0, 0, 1, 1);

        comboBox_filterWorkerByLvlAccess = new QComboBox(frame_5);
        comboBox_filterWorkerByLvlAccess->setObjectName(QString::fromUtf8("comboBox_filterWorkerByLvlAccess"));

        gridLayout_4->addWidget(comboBox_filterWorkerByLvlAccess, 0, 3, 1, 1);

        lineEdit_filterWorkerByFIO = new QLineEdit(frame_5);
        lineEdit_filterWorkerByFIO->setObjectName(QString::fromUtf8("lineEdit_filterWorkerByFIO"));

        gridLayout_4->addWidget(lineEdit_filterWorkerByFIO, 0, 1, 1, 1);

        comboBox_filterWorkerByPosition = new QComboBox(frame_5);
        comboBox_filterWorkerByPosition->setObjectName(QString::fromUtf8("comboBox_filterWorkerByPosition"));
        comboBox_filterWorkerByPosition->setInsertPolicy(QComboBox::InsertAfterCurrent);
        comboBox_filterWorkerByPosition->setMinimumContentsLength(0);

        gridLayout_4->addWidget(comboBox_filterWorkerByPosition, 0, 2, 1, 1);

        radioButton_showDismissed = new QRadioButton(frame_5);
        radioButton_showDismissed->setObjectName(QString::fromUtf8("radioButton_showDismissed"));

        gridLayout_4->addWidget(radioButton_showDismissed, 1, 3, 1, 1);

        radioButton_showAll = new QRadioButton(frame_5);
        radioButton_showAll->setObjectName(QString::fromUtf8("radioButton_showAll"));

        gridLayout_4->addWidget(radioButton_showAll, 1, 2, 1, 1);

        radioButton_hideTheDismissed = new QRadioButton(frame_5);
        radioButton_hideTheDismissed->setObjectName(QString::fromUtf8("radioButton_hideTheDismissed"));
        radioButton_hideTheDismissed->setChecked(true);

        gridLayout_4->addWidget(radioButton_hideTheDismissed, 1, 1, 1, 1);


        verticalLayout_8->addWidget(frame_5);

        tableView_workers = new QTableView(page_workers);
        tableView_workers->setObjectName(QString::fromUtf8("tableView_workers"));
        tableView_workers->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_workers->setDragDropOverwriteMode(false);
        tableView_workers->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView_workers->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_workers->setWordWrap(false);
        tableView_workers->verticalHeader()->setVisible(false);

        verticalLayout_8->addWidget(tableView_workers);

        stackedWidget_workPlace->addWidget(page_workers);
        page_checkpoints = new QWidget();
        page_checkpoints->setObjectName(QString::fromUtf8("page_checkpoints"));
        verticalLayout_12 = new QVBoxLayout(page_checkpoints);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(page_checkpoints);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font2);

        verticalLayout_12->addWidget(label_7);

        frame_6 = new QFrame(page_checkpoints);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lineEdit_filterCheckpointByTitle = new QLineEdit(frame_6);
        lineEdit_filterCheckpointByTitle->setObjectName(QString::fromUtf8("lineEdit_filterCheckpointByTitle"));

        horizontalLayout_3->addWidget(lineEdit_filterCheckpointByTitle);

        comboBox_filterCheckpointByLvlAccess = new QComboBox(frame_6);
        comboBox_filterCheckpointByLvlAccess->setObjectName(QString::fromUtf8("comboBox_filterCheckpointByLvlAccess"));

        horizontalLayout_3->addWidget(comboBox_filterCheckpointByLvlAccess);

        horizontalSpacer_7 = new QSpacerItem(186, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout_12->addWidget(frame_6);

        tableView_checkpoints = new QTableView(page_checkpoints);
        tableView_checkpoints->setObjectName(QString::fromUtf8("tableView_checkpoints"));
        tableView_checkpoints->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_checkpoints->setProperty("showDropIndicator", QVariant(false));
        tableView_checkpoints->setDragDropOverwriteMode(false);
        tableView_checkpoints->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView_checkpoints->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_checkpoints->verticalHeader()->setVisible(false);

        verticalLayout_12->addWidget(tableView_checkpoints);

        stackedWidget_workPlace->addWidget(page_checkpoints);
        page_authorizations = new QWidget();
        page_authorizations->setObjectName(QString::fromUtf8("page_authorizations"));
        verticalLayout_15 = new QVBoxLayout(page_authorizations);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(page_authorizations);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font2);

        verticalLayout_15->addWidget(label_8);

        frame_7 = new QFrame(page_authorizations);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_7);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        checkBox_filterAuthorizationByStateInadmissible = new QCheckBox(frame_7);
        checkBox_filterAuthorizationByStateInadmissible->setObjectName(QString::fromUtf8("checkBox_filterAuthorizationByStateInadmissible"));
        checkBox_filterAuthorizationByStateInadmissible->setChecked(true);

        gridLayout->addWidget(checkBox_filterAuthorizationByStateInadmissible, 2, 2, 1, 1);

        frame_8 = new QFrame(frame_7);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_8);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        checkBox_filterAuthorizationByDate = new QCheckBox(frame_8);
        checkBox_filterAuthorizationByDate->setObjectName(QString::fromUtf8("checkBox_filterAuthorizationByDate"));

        horizontalLayout_4->addWidget(checkBox_filterAuthorizationByDate);

        dateEdit_filterAuthorization = new QDateEdit(frame_8);
        dateEdit_filterAuthorization->setObjectName(QString::fromUtf8("dateEdit_filterAuthorization"));
        dateEdit_filterAuthorization->setEnabled(false);

        horizontalLayout_4->addWidget(dateEdit_filterAuthorization);


        gridLayout->addWidget(frame_8, 0, 2, 1, 1);

        lineEdit_filterAuthorizationByWorker = new QLineEdit(frame_7);
        lineEdit_filterAuthorizationByWorker->setObjectName(QString::fromUtf8("lineEdit_filterAuthorizationByWorker"));

        gridLayout->addWidget(lineEdit_filterAuthorizationByWorker, 0, 0, 1, 2);

        comboBox_filterAuthorizationByLvlAccess = new QComboBox(frame_7);
        comboBox_filterAuthorizationByLvlAccess->addItem(QString());
        comboBox_filterAuthorizationByLvlAccess->setObjectName(QString::fromUtf8("comboBox_filterAuthorizationByLvlAccess"));
        comboBox_filterAuthorizationByLvlAccess->setInsertPolicy(QComboBox::InsertAtTop);

        gridLayout->addWidget(comboBox_filterAuthorizationByLvlAccess, 1, 3, 1, 1);

        frame_9 = new QFrame(frame_7);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_9);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        checkBox_filterAuthorizationByTime = new QCheckBox(frame_9);
        checkBox_filterAuthorizationByTime->setObjectName(QString::fromUtf8("checkBox_filterAuthorizationByTime"));

        horizontalLayout_5->addWidget(checkBox_filterAuthorizationByTime);

        timeEdit_filterAuthorization = new QTimeEdit(frame_9);
        timeEdit_filterAuthorization->setObjectName(QString::fromUtf8("timeEdit_filterAuthorization"));
        timeEdit_filterAuthorization->setEnabled(false);

        horizontalLayout_5->addWidget(timeEdit_filterAuthorization);


        gridLayout->addWidget(frame_9, 1, 2, 1, 1);

        checkBox_filterAuthorizationByStateIncoming = new QCheckBox(frame_7);
        checkBox_filterAuthorizationByStateIncoming->setObjectName(QString::fromUtf8("checkBox_filterAuthorizationByStateIncoming"));
        checkBox_filterAuthorizationByStateIncoming->setChecked(true);
        checkBox_filterAuthorizationByStateIncoming->setTristate(false);

        gridLayout->addWidget(checkBox_filterAuthorizationByStateIncoming, 2, 0, 1, 1);

        checkBox_filterAuthorizationByStateGraduates = new QCheckBox(frame_7);
        checkBox_filterAuthorizationByStateGraduates->setObjectName(QString::fromUtf8("checkBox_filterAuthorizationByStateGraduates"));
        checkBox_filterAuthorizationByStateGraduates->setChecked(true);

        gridLayout->addWidget(checkBox_filterAuthorizationByStateGraduates, 2, 1, 1, 1);

        lineEdit_filterAuthorizationByAuthorizer = new QLineEdit(frame_7);
        lineEdit_filterAuthorizationByAuthorizer->setObjectName(QString::fromUtf8("lineEdit_filterAuthorizationByAuthorizer"));

        gridLayout->addWidget(lineEdit_filterAuthorizationByAuthorizer, 1, 0, 1, 2);

        comboBox_filterAuthorizationByCheckpoint = new QComboBox(frame_7);
        comboBox_filterAuthorizationByCheckpoint->addItem(QString());
        comboBox_filterAuthorizationByCheckpoint->setObjectName(QString::fromUtf8("comboBox_filterAuthorizationByCheckpoint"));
        comboBox_filterAuthorizationByCheckpoint->setEditable(false);
        comboBox_filterAuthorizationByCheckpoint->setInsertPolicy(QComboBox::InsertAtTop);
        comboBox_filterAuthorizationByCheckpoint->setFrame(true);

        gridLayout->addWidget(comboBox_filterAuthorizationByCheckpoint, 0, 3, 1, 1);


        verticalLayout_15->addWidget(frame_7);

        tableView_authorizations = new QTableView(page_authorizations);
        tableView_authorizations->setObjectName(QString::fromUtf8("tableView_authorizations"));
        tableView_authorizations->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_authorizations->setProperty("showDropIndicator", QVariant(false));
        tableView_authorizations->setDragDropOverwriteMode(false);
        tableView_authorizations->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView_authorizations->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_authorizations->verticalHeader()->setVisible(false);

        verticalLayout_15->addWidget(tableView_authorizations);

        stackedWidget_workPlace->addWidget(page_authorizations);
        page_accounts = new QWidget();
        page_accounts->setObjectName(QString::fromUtf8("page_accounts"));
        verticalLayout_17 = new QVBoxLayout(page_accounts);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        verticalLayout_17->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(page_accounts);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font2);

        verticalLayout_17->addWidget(label_9);

        frame_10 = new QFrame(page_accounts);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_10);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lineEdit_filterAccountsByLogin = new QLineEdit(frame_10);
        lineEdit_filterAccountsByLogin->setObjectName(QString::fromUtf8("lineEdit_filterAccountsByLogin"));

        horizontalLayout_6->addWidget(lineEdit_filterAccountsByLogin);

        lineEdit_filterAccountsByFIO = new QLineEdit(frame_10);
        lineEdit_filterAccountsByFIO->setObjectName(QString::fromUtf8("lineEdit_filterAccountsByFIO"));

        horizontalLayout_6->addWidget(lineEdit_filterAccountsByFIO);

        comboBox_filterAccountsByPrivileges = new QComboBox(frame_10);
        comboBox_filterAccountsByPrivileges->setObjectName(QString::fromUtf8("comboBox_filterAccountsByPrivileges"));

        horizontalLayout_6->addWidget(comboBox_filterAccountsByPrivileges);


        verticalLayout_17->addWidget(frame_10);

        tableView_accounts = new QTableView(page_accounts);
        tableView_accounts->setObjectName(QString::fromUtf8("tableView_accounts"));
        tableView_accounts->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_accounts->setTabKeyNavigation(false);
        tableView_accounts->setProperty("showDropIndicator", QVariant(false));
        tableView_accounts->setDragDropOverwriteMode(false);
        tableView_accounts->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView_accounts->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_accounts->verticalHeader()->setVisible(false);

        verticalLayout_17->addWidget(tableView_accounts);

        stackedWidget_workPlace->addWidget(page_accounts);
        page_lvlAccess = new QWidget();
        page_lvlAccess->setObjectName(QString::fromUtf8("page_lvlAccess"));
        verticalLayout_21 = new QVBoxLayout(page_lvlAccess);
        verticalLayout_21->setObjectName(QString::fromUtf8("verticalLayout_21"));
        verticalLayout_21->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(page_lvlAccess);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font2);

        verticalLayout_21->addWidget(label_10);

        frame_11 = new QFrame(page_lvlAccess);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame_11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        lineEdit_filterLvlAccessByTitle = new QLineEdit(frame_11);
        lineEdit_filterLvlAccessByTitle->setObjectName(QString::fromUtf8("lineEdit_filterLvlAccessByTitle"));

        horizontalLayout_7->addWidget(lineEdit_filterLvlAccessByTitle);

        label_11 = new QLabel(frame_11);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_7->addWidget(label_11);

        spinBox_filterLvlAccessByLvl = new QSpinBox(frame_11);
        spinBox_filterLvlAccessByLvl->setObjectName(QString::fromUtf8("spinBox_filterLvlAccessByLvl"));

        horizontalLayout_7->addWidget(spinBox_filterLvlAccessByLvl);

        horizontalSpacer_8 = new QSpacerItem(185, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);


        verticalLayout_21->addWidget(frame_11);

        tableView_lvlAccess = new QTableView(page_lvlAccess);
        tableView_lvlAccess->setObjectName(QString::fromUtf8("tableView_lvlAccess"));
        tableView_lvlAccess->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_lvlAccess->setTabKeyNavigation(false);
        tableView_lvlAccess->setProperty("showDropIndicator", QVariant(false));
        tableView_lvlAccess->setDragDropOverwriteMode(false);
        tableView_lvlAccess->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView_lvlAccess->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_lvlAccess->verticalHeader()->setVisible(false);

        verticalLayout_21->addWidget(tableView_lvlAccess);

        stackedWidget_workPlace->addWidget(page_lvlAccess);
        page_positions = new QWidget();
        page_positions->setObjectName(QString::fromUtf8("page_positions"));
        verticalLayout_24 = new QVBoxLayout(page_positions);
        verticalLayout_24->setObjectName(QString::fromUtf8("verticalLayout_24"));
        verticalLayout_24->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(page_positions);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font2);

        verticalLayout_24->addWidget(label_12);

        frame_12 = new QFrame(page_positions);
        frame_12->setObjectName(QString::fromUtf8("frame_12"));
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        horizontalLayout_8 = new QHBoxLayout(frame_12);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        lineEdit_filterPositionsByTitle = new QLineEdit(frame_12);
        lineEdit_filterPositionsByTitle->setObjectName(QString::fromUtf8("lineEdit_filterPositionsByTitle"));

        horizontalLayout_8->addWidget(lineEdit_filterPositionsByTitle);

        horizontalSpacer_9 = new QSpacerItem(255, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);


        verticalLayout_24->addWidget(frame_12);

        listView_positions = new QListView(page_positions);
        listView_positions->setObjectName(QString::fromUtf8("listView_positions"));
        listView_positions->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView_positions->setProperty("showDropIndicator", QVariant(false));
        listView_positions->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_24->addWidget(listView_positions);

        stackedWidget_workPlace->addWidget(page_positions);
        page_privileges = new QWidget();
        page_privileges->setObjectName(QString::fromUtf8("page_privileges"));
        verticalLayout_27 = new QVBoxLayout(page_privileges);
        verticalLayout_27->setObjectName(QString::fromUtf8("verticalLayout_27"));
        verticalLayout_27->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(page_privileges);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font2);

        verticalLayout_27->addWidget(label_13);

        listView_privilege = new QListView(page_privileges);
        listView_privilege->setObjectName(QString::fromUtf8("listView_privilege"));
        listView_privilege->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView_privilege->setProperty("showDropIndicator", QVariant(false));
        listView_privilege->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_27->addWidget(listView_privilege);

        stackedWidget_workPlace->addWidget(page_privileges);
        page_states = new QWidget();
        page_states->setObjectName(QString::fromUtf8("page_states"));
        verticalLayout_29 = new QVBoxLayout(page_states);
        verticalLayout_29->setObjectName(QString::fromUtf8("verticalLayout_29"));
        verticalLayout_29->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(page_states);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font2);

        verticalLayout_29->addWidget(label_15);

        listView_states = new QListView(page_states);
        listView_states->setObjectName(QString::fromUtf8("listView_states"));
        listView_states->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView_states->setProperty("showDropIndicator", QVariant(false));
        listView_states->setSelectionBehavior(QAbstractItemView::SelectRows);
        listView_states->setResizeMode(QListView::Fixed);

        verticalLayout_29->addWidget(listView_states);

        stackedWidget_workPlace->addWidget(page_states);
        page_workers_add = new QWidget();
        page_workers_add->setObjectName(QString::fromUtf8("page_workers_add"));
        verticalLayout_32 = new QVBoxLayout(page_workers_add);
        verticalLayout_32->setObjectName(QString::fromUtf8("verticalLayout_32"));
        label_addWorkerLabel = new QLabel(page_workers_add);
        label_addWorkerLabel->setObjectName(QString::fromUtf8("label_addWorkerLabel"));
        label_addWorkerLabel->setFont(font2);

        verticalLayout_32->addWidget(label_addWorkerLabel);

        scrollArea_9 = new QScrollArea(page_workers_add);
        scrollArea_9->setObjectName(QString::fromUtf8("scrollArea_9"));
        scrollArea_9->setWidgetResizable(true);
        scrollAreaWidgetContents_8 = new QWidget();
        scrollAreaWidgetContents_8->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_8"));
        scrollAreaWidgetContents_8->setGeometry(QRect(0, 0, 545, 508));
        verticalLayout_35 = new QVBoxLayout(scrollAreaWidgetContents_8);
        verticalLayout_35->setObjectName(QString::fromUtf8("verticalLayout_35"));
        frame_14 = new QFrame(scrollAreaWidgetContents_8);
        frame_14->setObjectName(QString::fromUtf8("frame_14"));
        frame_14->setFrameShape(QFrame::StyledPanel);
        frame_14->setFrameShadow(QFrame::Raised);
        verticalLayout_33 = new QVBoxLayout(frame_14);
        verticalLayout_33->setObjectName(QString::fromUtf8("verticalLayout_33"));
        label_30 = new QLabel(frame_14);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        label_30->setFont(font3);

        verticalLayout_33->addWidget(label_30);

        line = new QFrame(frame_14);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_33->addWidget(line);


        verticalLayout_35->addWidget(frame_14);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        verticalLayout_36 = new QVBoxLayout();
        verticalLayout_36->setObjectName(QString::fromUtf8("verticalLayout_36"));
        widget_addWorkerPhoto = new ScaledPixmap(scrollAreaWidgetContents_8);
        widget_addWorkerPhoto->setObjectName(QString::fromUtf8("widget_addWorkerPhoto"));
        sizePolicy1.setHeightForWidth(widget_addWorkerPhoto->sizePolicy().hasHeightForWidth());
        widget_addWorkerPhoto->setSizePolicy(sizePolicy1);
        widget_addWorkerPhoto->setMinimumSize(QSize(140, 180));

        verticalLayout_36->addWidget(widget_addWorkerPhoto);

        pushButton_addWorkerLoadPhoto = new QPushButton(scrollAreaWidgetContents_8);
        pushButton_addWorkerLoadPhoto->setObjectName(QString::fromUtf8("pushButton_addWorkerLoadPhoto"));

        verticalLayout_36->addWidget(pushButton_addWorkerLoadPhoto);


        horizontalLayout_17->addLayout(verticalLayout_36);

        verticalLayout_37 = new QVBoxLayout();
        verticalLayout_37->setObjectName(QString::fromUtf8("verticalLayout_37"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_24 = new QLabel(scrollAreaWidgetContents_8);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        QFont font4;
        font4.setBold(true);
        label_24->setFont(font4);

        horizontalLayout_9->addWidget(label_24);

        lineEdit_addWorkerPIB = new QLineEdit(scrollAreaWidgetContents_8);
        lineEdit_addWorkerPIB->setObjectName(QString::fromUtf8("lineEdit_addWorkerPIB"));

        horizontalLayout_9->addWidget(lineEdit_addWorkerPIB);


        verticalLayout_37->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_25 = new QLabel(scrollAreaWidgetContents_8);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setFont(font4);

        horizontalLayout_10->addWidget(label_25);

        lineEdit_addWorkerINN = new QLineEdit(scrollAreaWidgetContents_8);
        lineEdit_addWorkerINN->setObjectName(QString::fromUtf8("lineEdit_addWorkerINN"));
        lineEdit_addWorkerINN->setMaxLength(11);

        horizontalLayout_10->addWidget(lineEdit_addWorkerINN);


        verticalLayout_37->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_26 = new QLabel(scrollAreaWidgetContents_8);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setFont(font4);

        horizontalLayout_11->addWidget(label_26);

        dateEdit_addWorkerDate = new QDateEdit(scrollAreaWidgetContents_8);
        dateEdit_addWorkerDate->setObjectName(QString::fromUtf8("dateEdit_addWorkerDate"));

        horizontalLayout_11->addWidget(dateEdit_addWorkerDate);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_14);


        verticalLayout_37->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_27 = new QLabel(scrollAreaWidgetContents_8);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setFont(font4);

        horizontalLayout_12->addWidget(label_27);

        lineEdit_addWorkerPlaceFoRegistration = new QLineEdit(scrollAreaWidgetContents_8);
        lineEdit_addWorkerPlaceFoRegistration->setObjectName(QString::fromUtf8("lineEdit_addWorkerPlaceFoRegistration"));

        horizontalLayout_12->addWidget(lineEdit_addWorkerPlaceFoRegistration);


        verticalLayout_37->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_28 = new QLabel(scrollAreaWidgetContents_8);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setFont(font4);

        horizontalLayout_13->addWidget(label_28);

        lineEdit_addWorkerPlaceOfResidence = new QLineEdit(scrollAreaWidgetContents_8);
        lineEdit_addWorkerPlaceOfResidence->setObjectName(QString::fromUtf8("lineEdit_addWorkerPlaceOfResidence"));

        horizontalLayout_13->addWidget(lineEdit_addWorkerPlaceOfResidence);


        verticalLayout_37->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_29 = new QLabel(scrollAreaWidgetContents_8);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setFont(font4);

        horizontalLayout_14->addWidget(label_29);

        lineEdit_addWorkerNumberPassport = new QLineEdit(scrollAreaWidgetContents_8);
        lineEdit_addWorkerNumberPassport->setObjectName(QString::fromUtf8("lineEdit_addWorkerNumberPassport"));

        horizontalLayout_14->addWidget(lineEdit_addWorkerNumberPassport);


        verticalLayout_37->addLayout(horizontalLayout_14);

        horizontalLayout_48 = new QHBoxLayout();
        horizontalLayout_48->setObjectName(QString::fromUtf8("horizontalLayout_48"));
        label_47 = new QLabel(scrollAreaWidgetContents_8);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setFont(font4);

        horizontalLayout_48->addWidget(label_47);

        lineEdit_workerLogin = new QLineEdit(scrollAreaWidgetContents_8);
        lineEdit_workerLogin->setObjectName(QString::fromUtf8("lineEdit_workerLogin"));

        horizontalLayout_48->addWidget(lineEdit_workerLogin);


        verticalLayout_37->addLayout(horizontalLayout_48);

        horizontalLayout_49 = new QHBoxLayout();
        horizontalLayout_49->setObjectName(QString::fromUtf8("horizontalLayout_49"));
        label_48 = new QLabel(scrollAreaWidgetContents_8);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setFont(font4);

        horizontalLayout_49->addWidget(label_48);

        lineEdit_workerPassword = new QLineEdit(scrollAreaWidgetContents_8);
        lineEdit_workerPassword->setObjectName(QString::fromUtf8("lineEdit_workerPassword"));
        lineEdit_workerPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_49->addWidget(lineEdit_workerPassword);


        verticalLayout_37->addLayout(horizontalLayout_49);


        horizontalLayout_17->addLayout(verticalLayout_37);


        verticalLayout_35->addLayout(horizontalLayout_17);

        frame_15 = new QFrame(scrollAreaWidgetContents_8);
        frame_15->setObjectName(QString::fromUtf8("frame_15"));
        frame_15->setFrameShape(QFrame::StyledPanel);
        frame_15->setFrameShadow(QFrame::Raised);
        verticalLayout_34 = new QVBoxLayout(frame_15);
        verticalLayout_34->setObjectName(QString::fromUtf8("verticalLayout_34"));
        label_31 = new QLabel(frame_15);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setFont(font3);

        verticalLayout_34->addWidget(label_31);

        line_2 = new QFrame(frame_15);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_34->addWidget(line_2);


        verticalLayout_35->addWidget(frame_15);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_33 = new QLabel(scrollAreaWidgetContents_8);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setFont(font4);

        gridLayout_7->addWidget(label_33, 1, 0, 1, 2);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_12, 1, 4, 1, 1);

        label_32 = new QLabel(scrollAreaWidgetContents_8);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setFont(font4);

        gridLayout_7->addWidget(label_32, 0, 0, 1, 1);

        comboBox_addWorkerLvlAccess = new QComboBox(scrollAreaWidgetContents_8);
        comboBox_addWorkerLvlAccess->setObjectName(QString::fromUtf8("comboBox_addWorkerLvlAccess"));

        gridLayout_7->addWidget(comboBox_addWorkerLvlAccess, 1, 2, 1, 1);

        comboBox_addWorkerPosition = new QComboBox(scrollAreaWidgetContents_8);
        comboBox_addWorkerPosition->setObjectName(QString::fromUtf8("comboBox_addWorkerPosition"));

        gridLayout_7->addWidget(comboBox_addWorkerPosition, 0, 1, 1, 2);

        label_23 = new QLabel(scrollAreaWidgetContents_8);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setFont(font4);

        gridLayout_7->addWidget(label_23, 2, 0, 1, 1);

        comboBox_addWorkerStateDissmised = new QComboBox(scrollAreaWidgetContents_8);
        comboBox_addWorkerStateDissmised->addItem(QString());
        comboBox_addWorkerStateDissmised->addItem(QString());
        comboBox_addWorkerStateDissmised->setObjectName(QString::fromUtf8("comboBox_addWorkerStateDissmised"));

        gridLayout_7->addWidget(comboBox_addWorkerStateDissmised, 2, 1, 1, 2);


        verticalLayout_35->addLayout(gridLayout_7);

        verticalSpacer_23 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_35->addItem(verticalSpacer_23);

        scrollArea_9->setWidget(scrollAreaWidgetContents_8);

        verticalLayout_32->addWidget(scrollArea_9);

        stackedWidget_workPlace->addWidget(page_workers_add);
        page_workers_view = new QWidget();
        page_workers_view->setObjectName(QString::fromUtf8("page_workers_view"));
        verticalLayout_39 = new QVBoxLayout(page_workers_view);
        verticalLayout_39->setObjectName(QString::fromUtf8("verticalLayout_39"));
        label_34 = new QLabel(page_workers_view);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setFont(font2);

        verticalLayout_39->addWidget(label_34);

        scrollArea_10 = new QScrollArea(page_workers_view);
        scrollArea_10->setObjectName(QString::fromUtf8("scrollArea_10"));
        scrollArea_10->setWidgetResizable(true);
        scrollAreaWidgetContents_9 = new QWidget();
        scrollAreaWidgetContents_9->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_9"));
        scrollAreaWidgetContents_9->setGeometry(QRect(0, 0, 545, 508));
        verticalLayout_43 = new QVBoxLayout(scrollAreaWidgetContents_9);
        verticalLayout_43->setObjectName(QString::fromUtf8("verticalLayout_43"));
        frame_16 = new QFrame(scrollAreaWidgetContents_9);
        frame_16->setObjectName(QString::fromUtf8("frame_16"));
        frame_16->setFrameShape(QFrame::StyledPanel);
        frame_16->setFrameShadow(QFrame::Raised);
        verticalLayout_40 = new QVBoxLayout(frame_16);
        verticalLayout_40->setObjectName(QString::fromUtf8("verticalLayout_40"));
        label_35 = new QLabel(frame_16);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setFont(font3);

        verticalLayout_40->addWidget(label_35);

        line_3 = new QFrame(frame_16);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_40->addWidget(line_3);


        verticalLayout_43->addWidget(frame_16);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        widget_viewWorkerPhoto = new ScaledPixmap(scrollAreaWidgetContents_9);
        widget_viewWorkerPhoto->setObjectName(QString::fromUtf8("widget_viewWorkerPhoto"));
        sizePolicy1.setHeightForWidth(widget_viewWorkerPhoto->sizePolicy().hasHeightForWidth());
        widget_viewWorkerPhoto->setSizePolicy(sizePolicy1);
        widget_viewWorkerPhoto->setMinimumSize(QSize(140, 180));

        horizontalLayout_22->addWidget(widget_viewWorkerPhoto);

        verticalLayout_42 = new QVBoxLayout();
        verticalLayout_42->setObjectName(QString::fromUtf8("verticalLayout_42"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_37 = new QLabel(scrollAreaWidgetContents_9);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setFont(font4);

        horizontalLayout_15->addWidget(label_37);

        label_viewWorkerPIB = new QLabel(scrollAreaWidgetContents_9);
        label_viewWorkerPIB->setObjectName(QString::fromUtf8("label_viewWorkerPIB"));

        horizontalLayout_15->addWidget(label_viewWorkerPIB);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_13);


        verticalLayout_42->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_38 = new QLabel(scrollAreaWidgetContents_9);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setFont(font4);

        horizontalLayout_16->addWidget(label_38);

        label_viewWorkerINN = new QLabel(scrollAreaWidgetContents_9);
        label_viewWorkerINN->setObjectName(QString::fromUtf8("label_viewWorkerINN"));

        horizontalLayout_16->addWidget(label_viewWorkerINN);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_15);


        verticalLayout_42->addLayout(horizontalLayout_16);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_39 = new QLabel(scrollAreaWidgetContents_9);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setFont(font4);

        horizontalLayout_18->addWidget(label_39);

        label_viewWorkerDateOfBirth = new QLabel(scrollAreaWidgetContents_9);
        label_viewWorkerDateOfBirth->setObjectName(QString::fromUtf8("label_viewWorkerDateOfBirth"));

        horizontalLayout_18->addWidget(label_viewWorkerDateOfBirth);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_16);


        verticalLayout_42->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_40 = new QLabel(scrollAreaWidgetContents_9);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setFont(font4);

        horizontalLayout_19->addWidget(label_40);

        label_viewWorkerPlaceOfRegistration = new QLabel(scrollAreaWidgetContents_9);
        label_viewWorkerPlaceOfRegistration->setObjectName(QString::fromUtf8("label_viewWorkerPlaceOfRegistration"));

        horizontalLayout_19->addWidget(label_viewWorkerPlaceOfRegistration);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_17);


        verticalLayout_42->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_41 = new QLabel(scrollAreaWidgetContents_9);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setFont(font4);

        horizontalLayout_20->addWidget(label_41);

        label_viewWorkerPlaceOfResidence = new QLabel(scrollAreaWidgetContents_9);
        label_viewWorkerPlaceOfResidence->setObjectName(QString::fromUtf8("label_viewWorkerPlaceOfResidence"));

        horizontalLayout_20->addWidget(label_viewWorkerPlaceOfResidence);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_18);


        verticalLayout_42->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_42 = new QLabel(scrollAreaWidgetContents_9);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setFont(font4);

        horizontalLayout_21->addWidget(label_42);

        label_viewWorkerNumberPassport = new QLabel(scrollAreaWidgetContents_9);
        label_viewWorkerNumberPassport->setObjectName(QString::fromUtf8("label_viewWorkerNumberPassport"));

        horizontalLayout_21->addWidget(label_viewWorkerNumberPassport);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_19);


        verticalLayout_42->addLayout(horizontalLayout_21);

        horizontalLayout_46 = new QHBoxLayout();
        horizontalLayout_46->setObjectName(QString::fromUtf8("horizontalLayout_46"));
        label_46 = new QLabel(scrollAreaWidgetContents_9);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setFont(font4);

        horizontalLayout_46->addWidget(label_46);

        label_workerLogin = new QLabel(scrollAreaWidgetContents_9);
        label_workerLogin->setObjectName(QString::fromUtf8("label_workerLogin"));

        horizontalLayout_46->addWidget(label_workerLogin);

        horizontalSpacer_38 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_46->addItem(horizontalSpacer_38);


        verticalLayout_42->addLayout(horizontalLayout_46);


        horizontalLayout_22->addLayout(verticalLayout_42);


        verticalLayout_43->addLayout(horizontalLayout_22);

        frame_17 = new QFrame(scrollAreaWidgetContents_9);
        frame_17->setObjectName(QString::fromUtf8("frame_17"));
        frame_17->setFrameShape(QFrame::StyledPanel);
        frame_17->setFrameShadow(QFrame::Raised);
        verticalLayout_41 = new QVBoxLayout(frame_17);
        verticalLayout_41->setObjectName(QString::fromUtf8("verticalLayout_41"));
        label_36 = new QLabel(frame_17);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setFont(font3);

        verticalLayout_41->addWidget(label_36);

        line_4 = new QFrame(frame_17);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_41->addWidget(line_4);


        verticalLayout_43->addWidget(frame_17);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_51 = new QLabel(scrollAreaWidgetContents_9);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setFont(font4);

        gridLayout_8->addWidget(label_51, 1, 0, 1, 2);

        label_49 = new QLabel(scrollAreaWidgetContents_9);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setFont(font4);

        gridLayout_8->addWidget(label_49, 0, 0, 1, 1);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_20, 0, 3, 1, 1);

        label_viewWorkerLvlAccess = new QLabel(scrollAreaWidgetContents_9);
        label_viewWorkerLvlAccess->setObjectName(QString::fromUtf8("label_viewWorkerLvlAccess"));

        gridLayout_8->addWidget(label_viewWorkerLvlAccess, 1, 2, 1, 1);

        label_viewWorkerPosition = new QLabel(scrollAreaWidgetContents_9);
        label_viewWorkerPosition->setObjectName(QString::fromUtf8("label_viewWorkerPosition"));

        gridLayout_8->addWidget(label_viewWorkerPosition, 0, 1, 1, 2);

        label_43 = new QLabel(scrollAreaWidgetContents_9);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setFont(font4);

        gridLayout_8->addWidget(label_43, 2, 0, 1, 1);

        label_viewWorkerStateDissmised = new QLabel(scrollAreaWidgetContents_9);
        label_viewWorkerStateDissmised->setObjectName(QString::fromUtf8("label_viewWorkerStateDissmised"));

        gridLayout_8->addWidget(label_viewWorkerStateDissmised, 2, 1, 1, 2);


        verticalLayout_43->addLayout(gridLayout_8);

        verticalSpacer_24 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_43->addItem(verticalSpacer_24);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer_21);

        pushButton_viewWorkerPrintPass = new QPushButton(scrollAreaWidgetContents_9);
        pushButton_viewWorkerPrintPass->setObjectName(QString::fromUtf8("pushButton_viewWorkerPrintPass"));

        horizontalLayout_23->addWidget(pushButton_viewWorkerPrintPass);


        verticalLayout_43->addLayout(horizontalLayout_23);

        scrollArea_10->setWidget(scrollAreaWidgetContents_9);

        verticalLayout_39->addWidget(scrollArea_10);

        stackedWidget_workPlace->addWidget(page_workers_view);
        page_checkpoints_add = new QWidget();
        page_checkpoints_add->setObjectName(QString::fromUtf8("page_checkpoints_add"));
        verticalLayout_44 = new QVBoxLayout(page_checkpoints_add);
        verticalLayout_44->setObjectName(QString::fromUtf8("verticalLayout_44"));
        label_addCheckpointLabel = new QLabel(page_checkpoints_add);
        label_addCheckpointLabel->setObjectName(QString::fromUtf8("label_addCheckpointLabel"));
        label_addCheckpointLabel->setFont(font2);

        verticalLayout_44->addWidget(label_addCheckpointLabel);

        scrollArea_11 = new QScrollArea(page_checkpoints_add);
        scrollArea_11->setObjectName(QString::fromUtf8("scrollArea_11"));
        scrollArea_11->setWidgetResizable(true);
        scrollAreaWidgetContents_10 = new QWidget();
        scrollAreaWidgetContents_10->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_10"));
        scrollAreaWidgetContents_10->setGeometry(QRect(0, 0, 214, 117));
        verticalLayout_45 = new QVBoxLayout(scrollAreaWidgetContents_10);
        verticalLayout_45->setObjectName(QString::fromUtf8("verticalLayout_45"));
        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        label_54 = new QLabel(scrollAreaWidgetContents_10);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setFont(font4);

        horizontalLayout_24->addWidget(label_54);

        lineEdit_addCheckpointTitle = new QLineEdit(scrollAreaWidgetContents_10);
        lineEdit_addCheckpointTitle->setObjectName(QString::fromUtf8("lineEdit_addCheckpointTitle"));

        horizontalLayout_24->addWidget(lineEdit_addCheckpointTitle);


        verticalLayout_45->addLayout(horizontalLayout_24);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        label_55 = new QLabel(scrollAreaWidgetContents_10);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setFont(font4);

        horizontalLayout_25->addWidget(label_55);

        lineEdit_addCheckpointLocation = new QLineEdit(scrollAreaWidgetContents_10);
        lineEdit_addCheckpointLocation->setObjectName(QString::fromUtf8("lineEdit_addCheckpointLocation"));

        horizontalLayout_25->addWidget(lineEdit_addCheckpointLocation);


        verticalLayout_45->addLayout(horizontalLayout_25);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        label_56 = new QLabel(scrollAreaWidgetContents_10);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        label_56->setFont(font4);

        horizontalLayout_26->addWidget(label_56);

        comboBox_addCheckpointLvlAccess = new QComboBox(scrollAreaWidgetContents_10);
        comboBox_addCheckpointLvlAccess->setObjectName(QString::fromUtf8("comboBox_addCheckpointLvlAccess"));

        horizontalLayout_26->addWidget(comboBox_addCheckpointLvlAccess);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_26->addItem(horizontalSpacer_22);


        verticalLayout_45->addLayout(horizontalLayout_26);

        verticalSpacer_25 = new QSpacerItem(20, 384, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_45->addItem(verticalSpacer_25);

        scrollArea_11->setWidget(scrollAreaWidgetContents_10);

        verticalLayout_44->addWidget(scrollArea_11);

        stackedWidget_workPlace->addWidget(page_checkpoints_add);
        page_checkpoints_view = new QWidget();
        page_checkpoints_view->setObjectName(QString::fromUtf8("page_checkpoints_view"));
        verticalLayout_46 = new QVBoxLayout(page_checkpoints_view);
        verticalLayout_46->setObjectName(QString::fromUtf8("verticalLayout_46"));
        label_57 = new QLabel(page_checkpoints_view);
        label_57->setObjectName(QString::fromUtf8("label_57"));
        label_57->setFont(font2);

        verticalLayout_46->addWidget(label_57);

        scrollArea_12 = new QScrollArea(page_checkpoints_view);
        scrollArea_12->setObjectName(QString::fromUtf8("scrollArea_12"));
        scrollArea_12->setWidgetResizable(true);
        scrollAreaWidgetContents_11 = new QWidget();
        scrollAreaWidgetContents_11->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_11"));
        scrollAreaWidgetContents_11->setGeometry(QRect(0, 0, 545, 508));
        verticalLayout_47 = new QVBoxLayout(scrollAreaWidgetContents_11);
        verticalLayout_47->setObjectName(QString::fromUtf8("verticalLayout_47"));
        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        label_58 = new QLabel(scrollAreaWidgetContents_11);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        label_58->setFont(font4);

        horizontalLayout_27->addWidget(label_58);

        label_viewCheckpointTitle = new QLabel(scrollAreaWidgetContents_11);
        label_viewCheckpointTitle->setObjectName(QString::fromUtf8("label_viewCheckpointTitle"));

        horizontalLayout_27->addWidget(label_viewCheckpointTitle);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_27->addItem(horizontalSpacer_23);


        verticalLayout_47->addLayout(horizontalLayout_27);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        label_60 = new QLabel(scrollAreaWidgetContents_11);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        label_60->setFont(font4);

        horizontalLayout_28->addWidget(label_60);

        label_viewCheckpointLocation = new QLabel(scrollAreaWidgetContents_11);
        label_viewCheckpointLocation->setObjectName(QString::fromUtf8("label_viewCheckpointLocation"));

        horizontalLayout_28->addWidget(label_viewCheckpointLocation);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_28->addItem(horizontalSpacer_24);


        verticalLayout_47->addLayout(horizontalLayout_28);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        label_62 = new QLabel(scrollAreaWidgetContents_11);
        label_62->setObjectName(QString::fromUtf8("label_62"));
        label_62->setFont(font4);

        horizontalLayout_29->addWidget(label_62);

        label_viewCheckpointLvlAccess = new QLabel(scrollAreaWidgetContents_11);
        label_viewCheckpointLvlAccess->setObjectName(QString::fromUtf8("label_viewCheckpointLvlAccess"));

        horizontalLayout_29->addWidget(label_viewCheckpointLvlAccess);

        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_29->addItem(horizontalSpacer_25);


        verticalLayout_47->addLayout(horizontalLayout_29);

        verticalSpacer_26 = new QSpacerItem(20, 402, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_47->addItem(verticalSpacer_26);

        horizontalLayout_50 = new QHBoxLayout();
        horizontalLayout_50->setObjectName(QString::fromUtf8("horizontalLayout_50"));
        horizontalSpacer_39 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_50->addItem(horizontalSpacer_39);

        pushButton = new QPushButton(scrollAreaWidgetContents_11);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_50->addWidget(pushButton);


        verticalLayout_47->addLayout(horizontalLayout_50);

        scrollArea_12->setWidget(scrollAreaWidgetContents_11);

        verticalLayout_46->addWidget(scrollArea_12);

        stackedWidget_workPlace->addWidget(page_checkpoints_view);
        page_authorizations_view = new QWidget();
        page_authorizations_view->setObjectName(QString::fromUtf8("page_authorizations_view"));
        verticalLayout_48 = new QVBoxLayout(page_authorizations_view);
        verticalLayout_48->setObjectName(QString::fromUtf8("verticalLayout_48"));
        label_64 = new QLabel(page_authorizations_view);
        label_64->setObjectName(QString::fromUtf8("label_64"));
        label_64->setFont(font2);

        verticalLayout_48->addWidget(label_64);

        scrollArea_13 = new QScrollArea(page_authorizations_view);
        scrollArea_13->setObjectName(QString::fromUtf8("scrollArea_13"));
        scrollArea_13->setWidgetResizable(true);
        scrollAreaWidgetContents_12 = new QWidget();
        scrollAreaWidgetContents_12->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_12"));
        scrollAreaWidgetContents_12->setGeometry(QRect(0, 0, 168, 186));
        verticalLayout_49 = new QVBoxLayout(scrollAreaWidgetContents_12);
        verticalLayout_49->setObjectName(QString::fromUtf8("verticalLayout_49"));
        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        label_65 = new QLabel(scrollAreaWidgetContents_12);
        label_65->setObjectName(QString::fromUtf8("label_65"));
        label_65->setFont(font4);

        horizontalLayout_30->addWidget(label_65);

        label_viewAuthorizationWorker = new QLabel(scrollAreaWidgetContents_12);
        label_viewAuthorizationWorker->setObjectName(QString::fromUtf8("label_viewAuthorizationWorker"));

        horizontalLayout_30->addWidget(label_viewAuthorizationWorker);

        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_30->addItem(horizontalSpacer_26);


        verticalLayout_49->addLayout(horizontalLayout_30);

        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        label_67 = new QLabel(scrollAreaWidgetContents_12);
        label_67->setObjectName(QString::fromUtf8("label_67"));
        label_67->setFont(font4);

        horizontalLayout_31->addWidget(label_67);

        label_viewAuthorizationDate = new QLabel(scrollAreaWidgetContents_12);
        label_viewAuthorizationDate->setObjectName(QString::fromUtf8("label_viewAuthorizationDate"));

        horizontalLayout_31->addWidget(label_viewAuthorizationDate);

        horizontalSpacer_27 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_31->addItem(horizontalSpacer_27);


        verticalLayout_49->addLayout(horizontalLayout_31);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setObjectName(QString::fromUtf8("horizontalLayout_32"));
        label_68 = new QLabel(scrollAreaWidgetContents_12);
        label_68->setObjectName(QString::fromUtf8("label_68"));
        label_68->setFont(font4);

        horizontalLayout_32->addWidget(label_68);

        label_viewAuthorizationTime = new QLabel(scrollAreaWidgetContents_12);
        label_viewAuthorizationTime->setObjectName(QString::fromUtf8("label_viewAuthorizationTime"));

        horizontalLayout_32->addWidget(label_viewAuthorizationTime);

        horizontalSpacer_28 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_32->addItem(horizontalSpacer_28);


        verticalLayout_49->addLayout(horizontalLayout_32);

        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        label_69 = new QLabel(scrollAreaWidgetContents_12);
        label_69->setObjectName(QString::fromUtf8("label_69"));
        label_69->setFont(font4);

        horizontalLayout_33->addWidget(label_69);

        label_viewAuthorizationState = new QLabel(scrollAreaWidgetContents_12);
        label_viewAuthorizationState->setObjectName(QString::fromUtf8("label_viewAuthorizationState"));

        horizontalLayout_33->addWidget(label_viewAuthorizationState);

        horizontalSpacer_29 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_33->addItem(horizontalSpacer_29);


        verticalLayout_49->addLayout(horizontalLayout_33);

        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setObjectName(QString::fromUtf8("horizontalLayout_34"));
        label_70 = new QLabel(scrollAreaWidgetContents_12);
        label_70->setObjectName(QString::fromUtf8("label_70"));
        label_70->setFont(font4);

        horizontalLayout_34->addWidget(label_70);

        label_viewAuthorizationAuthorizer = new QLabel(scrollAreaWidgetContents_12);
        label_viewAuthorizationAuthorizer->setObjectName(QString::fromUtf8("label_viewAuthorizationAuthorizer"));

        horizontalLayout_34->addWidget(label_viewAuthorizationAuthorizer);

        horizontalSpacer_30 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_34->addItem(horizontalSpacer_30);


        verticalLayout_49->addLayout(horizontalLayout_34);

        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setObjectName(QString::fromUtf8("horizontalLayout_35"));
        label_71 = new QLabel(scrollAreaWidgetContents_12);
        label_71->setObjectName(QString::fromUtf8("label_71"));
        label_71->setFont(font4);

        horizontalLayout_35->addWidget(label_71);

        label_viewAuthorizationCheckpoint = new QLabel(scrollAreaWidgetContents_12);
        label_viewAuthorizationCheckpoint->setObjectName(QString::fromUtf8("label_viewAuthorizationCheckpoint"));

        horizontalLayout_35->addWidget(label_viewAuthorizationCheckpoint);

        horizontalSpacer_31 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_35->addItem(horizontalSpacer_31);


        verticalLayout_49->addLayout(horizontalLayout_35);

        verticalSpacer_27 = new QSpacerItem(20, 318, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_49->addItem(verticalSpacer_27);

        scrollArea_13->setWidget(scrollAreaWidgetContents_12);

        verticalLayout_48->addWidget(scrollArea_13);

        stackedWidget_workPlace->addWidget(page_authorizations_view);
        page_accounts_add = new QWidget();
        page_accounts_add->setObjectName(QString::fromUtf8("page_accounts_add"));
        verticalLayout_50 = new QVBoxLayout(page_accounts_add);
        verticalLayout_50->setObjectName(QString::fromUtf8("verticalLayout_50"));
        label_addAccountLabel = new QLabel(page_accounts_add);
        label_addAccountLabel->setObjectName(QString::fromUtf8("label_addAccountLabel"));
        label_addAccountLabel->setFont(font2);

        verticalLayout_50->addWidget(label_addAccountLabel);

        scrollArea_14 = new QScrollArea(page_accounts_add);
        scrollArea_14->setObjectName(QString::fromUtf8("scrollArea_14"));
        scrollArea_14->setWidgetResizable(true);
        scrollAreaWidgetContents_13 = new QWidget();
        scrollAreaWidgetContents_13->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_13"));
        scrollAreaWidgetContents_13->setGeometry(QRect(0, 0, 545, 508));
        verticalLayout_51 = new QVBoxLayout(scrollAreaWidgetContents_13);
        verticalLayout_51->setObjectName(QString::fromUtf8("verticalLayout_51"));
        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setObjectName(QString::fromUtf8("horizontalLayout_36"));
        label_78 = new QLabel(scrollAreaWidgetContents_13);
        label_78->setObjectName(QString::fromUtf8("label_78"));
        label_78->setFont(font4);

        horizontalLayout_36->addWidget(label_78);

        lineEdit_addAccountLogin = new QLineEdit(scrollAreaWidgetContents_13);
        lineEdit_addAccountLogin->setObjectName(QString::fromUtf8("lineEdit_addAccountLogin"));

        horizontalLayout_36->addWidget(lineEdit_addAccountLogin);


        verticalLayout_51->addLayout(horizontalLayout_36);

        horizontalLayout_38 = new QHBoxLayout();
        horizontalLayout_38->setObjectName(QString::fromUtf8("horizontalLayout_38"));
        label_80 = new QLabel(scrollAreaWidgetContents_13);
        label_80->setObjectName(QString::fromUtf8("label_80"));
        label_80->setFont(font4);

        horizontalLayout_38->addWidget(label_80);

        lineEdit_addAccountPasswordFirst = new QLineEdit(scrollAreaWidgetContents_13);
        lineEdit_addAccountPasswordFirst->setObjectName(QString::fromUtf8("lineEdit_addAccountPasswordFirst"));
        lineEdit_addAccountPasswordFirst->setEchoMode(QLineEdit::Password);

        horizontalLayout_38->addWidget(lineEdit_addAccountPasswordFirst);

        lineEdit_addAccountPasswordSecond = new QLineEdit(scrollAreaWidgetContents_13);
        lineEdit_addAccountPasswordSecond->setObjectName(QString::fromUtf8("lineEdit_addAccountPasswordSecond"));
        lineEdit_addAccountPasswordSecond->setEchoMode(QLineEdit::Password);

        horizontalLayout_38->addWidget(lineEdit_addAccountPasswordSecond);


        verticalLayout_51->addLayout(horizontalLayout_38);

        horizontalLayout_39 = new QHBoxLayout();
        horizontalLayout_39->setObjectName(QString::fromUtf8("horizontalLayout_39"));
        label_81 = new QLabel(scrollAreaWidgetContents_13);
        label_81->setObjectName(QString::fromUtf8("label_81"));
        label_81->setFont(font4);

        horizontalLayout_39->addWidget(label_81);

        comboBox_addAccountPrivilege = new QComboBox(scrollAreaWidgetContents_13);
        comboBox_addAccountPrivilege->setObjectName(QString::fromUtf8("comboBox_addAccountPrivilege"));
        comboBox_addAccountPrivilege->setMinimumSize(QSize(100, 0));

        horizontalLayout_39->addWidget(comboBox_addAccountPrivilege);

        horizontalSpacer_32 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_39->addItem(horizontalSpacer_32);


        verticalLayout_51->addLayout(horizontalLayout_39);

        horizontalLayout_37 = new QHBoxLayout();
        horizontalLayout_37->setObjectName(QString::fromUtf8("horizontalLayout_37"));
        label_79 = new QLabel(scrollAreaWidgetContents_13);
        label_79->setObjectName(QString::fromUtf8("label_79"));
        label_79->setFont(font4);

        horizontalLayout_37->addWidget(label_79);

        comboBox_addAccountWorker = new QComboBox(scrollAreaWidgetContents_13);
        comboBox_addAccountWorker->setObjectName(QString::fromUtf8("comboBox_addAccountWorker"));
        comboBox_addAccountWorker->setMinimumSize(QSize(200, 0));

        horizontalLayout_37->addWidget(comboBox_addAccountWorker);

        horizontalSpacer_33 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_37->addItem(horizontalSpacer_33);


        verticalLayout_51->addLayout(horizontalLayout_37);

        verticalSpacer_28 = new QSpacerItem(20, 350, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_51->addItem(verticalSpacer_28);

        scrollArea_14->setWidget(scrollAreaWidgetContents_13);

        verticalLayout_50->addWidget(scrollArea_14);

        stackedWidget_workPlace->addWidget(page_accounts_add);
        page_accounts_ciew = new QWidget();
        page_accounts_ciew->setObjectName(QString::fromUtf8("page_accounts_ciew"));
        verticalLayout_52 = new QVBoxLayout(page_accounts_ciew);
        verticalLayout_52->setObjectName(QString::fromUtf8("verticalLayout_52"));
        label_82 = new QLabel(page_accounts_ciew);
        label_82->setObjectName(QString::fromUtf8("label_82"));
        label_82->setFont(font2);

        verticalLayout_52->addWidget(label_82);

        scrollArea_15 = new QScrollArea(page_accounts_ciew);
        scrollArea_15->setObjectName(QString::fromUtf8("scrollArea_15"));
        scrollArea_15->setWidgetResizable(true);
        scrollAreaWidgetContents_14 = new QWidget();
        scrollAreaWidgetContents_14->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_14"));
        scrollAreaWidgetContents_14->setGeometry(QRect(0, 0, 146, 102));
        verticalLayout_53 = new QVBoxLayout(scrollAreaWidgetContents_14);
        verticalLayout_53->setObjectName(QString::fromUtf8("verticalLayout_53"));
        horizontalLayout_40 = new QHBoxLayout();
        horizontalLayout_40->setObjectName(QString::fromUtf8("horizontalLayout_40"));
        label_83 = new QLabel(scrollAreaWidgetContents_14);
        label_83->setObjectName(QString::fromUtf8("label_83"));
        label_83->setFont(font4);

        horizontalLayout_40->addWidget(label_83);

        label_viewAccountLogin = new QLabel(scrollAreaWidgetContents_14);
        label_viewAccountLogin->setObjectName(QString::fromUtf8("label_viewAccountLogin"));

        horizontalLayout_40->addWidget(label_viewAccountLogin);

        horizontalSpacer_34 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_40->addItem(horizontalSpacer_34);


        verticalLayout_53->addLayout(horizontalLayout_40);

        horizontalLayout_41 = new QHBoxLayout();
        horizontalLayout_41->setObjectName(QString::fromUtf8("horizontalLayout_41"));
        label_84 = new QLabel(scrollAreaWidgetContents_14);
        label_84->setObjectName(QString::fromUtf8("label_84"));
        label_84->setFont(font4);

        horizontalLayout_41->addWidget(label_84);

        label_viewAccountPrivilege = new QLabel(scrollAreaWidgetContents_14);
        label_viewAccountPrivilege->setObjectName(QString::fromUtf8("label_viewAccountPrivilege"));

        horizontalLayout_41->addWidget(label_viewAccountPrivilege);

        horizontalSpacer_35 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_41->addItem(horizontalSpacer_35);


        verticalLayout_53->addLayout(horizontalLayout_41);

        horizontalLayout_42 = new QHBoxLayout();
        horizontalLayout_42->setObjectName(QString::fromUtf8("horizontalLayout_42"));
        label_85 = new QLabel(scrollAreaWidgetContents_14);
        label_85->setObjectName(QString::fromUtf8("label_85"));
        label_85->setFont(font4);

        horizontalLayout_42->addWidget(label_85);

        label_viewAccountWorker = new QLabel(scrollAreaWidgetContents_14);
        label_viewAccountWorker->setObjectName(QString::fromUtf8("label_viewAccountWorker"));

        horizontalLayout_42->addWidget(label_viewAccountWorker);

        horizontalSpacer_36 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_42->addItem(horizontalSpacer_36);


        verticalLayout_53->addLayout(horizontalLayout_42);

        verticalSpacer_29 = new QSpacerItem(20, 402, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_53->addItem(verticalSpacer_29);

        scrollArea_15->setWidget(scrollAreaWidgetContents_14);

        verticalLayout_52->addWidget(scrollArea_15);

        stackedWidget_workPlace->addWidget(page_accounts_ciew);
        page_access_add = new QWidget();
        page_access_add->setObjectName(QString::fromUtf8("page_access_add"));
        verticalLayout_54 = new QVBoxLayout(page_access_add);
        verticalLayout_54->setObjectName(QString::fromUtf8("verticalLayout_54"));
        label_addLvlAccessLabel = new QLabel(page_access_add);
        label_addLvlAccessLabel->setObjectName(QString::fromUtf8("label_addLvlAccessLabel"));
        label_addLvlAccessLabel->setFont(font2);

        verticalLayout_54->addWidget(label_addLvlAccessLabel);

        scrollArea_16 = new QScrollArea(page_access_add);
        scrollArea_16->setObjectName(QString::fromUtf8("scrollArea_16"));
        scrollArea_16->setWidgetResizable(true);
        scrollAreaWidgetContents_15 = new QWidget();
        scrollAreaWidgetContents_15->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_15"));
        scrollAreaWidgetContents_15->setGeometry(QRect(0, 0, 191, 85));
        verticalLayout_55 = new QVBoxLayout(scrollAreaWidgetContents_15);
        verticalLayout_55->setObjectName(QString::fromUtf8("verticalLayout_55"));
        horizontalLayout_43 = new QHBoxLayout();
        horizontalLayout_43->setObjectName(QString::fromUtf8("horizontalLayout_43"));
        label_90 = new QLabel(scrollAreaWidgetContents_15);
        label_90->setObjectName(QString::fromUtf8("label_90"));

        horizontalLayout_43->addWidget(label_90);

        lineEdit_addAccessTitle = new QLineEdit(scrollAreaWidgetContents_15);
        lineEdit_addAccessTitle->setObjectName(QString::fromUtf8("lineEdit_addAccessTitle"));

        horizontalLayout_43->addWidget(lineEdit_addAccessTitle);


        verticalLayout_55->addLayout(horizontalLayout_43);

        horizontalLayout_44 = new QHBoxLayout();
        horizontalLayout_44->setObjectName(QString::fromUtf8("horizontalLayout_44"));
        label_91 = new QLabel(scrollAreaWidgetContents_15);
        label_91->setObjectName(QString::fromUtf8("label_91"));

        horizontalLayout_44->addWidget(label_91);

        spinBox_addAccessLvl = new QSpinBox(scrollAreaWidgetContents_15);
        spinBox_addAccessLvl->setObjectName(QString::fromUtf8("spinBox_addAccessLvl"));

        horizontalLayout_44->addWidget(spinBox_addAccessLvl);

        horizontalSpacer_37 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_44->addItem(horizontalSpacer_37);


        verticalLayout_55->addLayout(horizontalLayout_44);

        verticalSpacer_30 = new QSpacerItem(20, 417, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_55->addItem(verticalSpacer_30);

        scrollArea_16->setWidget(scrollAreaWidgetContents_15);

        verticalLayout_54->addWidget(scrollArea_16);

        stackedWidget_workPlace->addWidget(page_access_add);
        page_position_add = new QWidget();
        page_position_add->setObjectName(QString::fromUtf8("page_position_add"));
        verticalLayout_56 = new QVBoxLayout(page_position_add);
        verticalLayout_56->setObjectName(QString::fromUtf8("verticalLayout_56"));
        label_addPositionLabel = new QLabel(page_position_add);
        label_addPositionLabel->setObjectName(QString::fromUtf8("label_addPositionLabel"));
        label_addPositionLabel->setFont(font2);

        verticalLayout_56->addWidget(label_addPositionLabel);

        scrollArea_17 = new QScrollArea(page_position_add);
        scrollArea_17->setObjectName(QString::fromUtf8("scrollArea_17"));
        scrollArea_17->setWidgetResizable(true);
        scrollAreaWidgetContents_16 = new QWidget();
        scrollAreaWidgetContents_16->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_16"));
        scrollAreaWidgetContents_16->setGeometry(QRect(0, 0, 124, 51));
        verticalLayout_57 = new QVBoxLayout(scrollAreaWidgetContents_16);
        verticalLayout_57->setObjectName(QString::fromUtf8("verticalLayout_57"));
        horizontalLayout_45 = new QHBoxLayout();
        horizontalLayout_45->setObjectName(QString::fromUtf8("horizontalLayout_45"));
        label_93 = new QLabel(scrollAreaWidgetContents_16);
        label_93->setObjectName(QString::fromUtf8("label_93"));

        horizontalLayout_45->addWidget(label_93);

        lineEdit_addPositionTitle = new QLineEdit(scrollAreaWidgetContents_16);
        lineEdit_addPositionTitle->setObjectName(QString::fromUtf8("lineEdit_addPositionTitle"));

        horizontalLayout_45->addWidget(lineEdit_addPositionTitle);


        verticalLayout_57->addLayout(horizontalLayout_45);

        verticalSpacer_31 = new QSpacerItem(20, 452, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_57->addItem(verticalSpacer_31);

        scrollArea_17->setWidget(scrollAreaWidgetContents_16);

        verticalLayout_56->addWidget(scrollArea_17);

        stackedWidget_workPlace->addWidget(page_position_add);

        gridLayout_3->addWidget(stackedWidget_workPlace, 0, 1, 1, 1);

        frame_leftPanel = new QFrame(page_workplace);
        frame_leftPanel->setObjectName(QString::fromUtf8("frame_leftPanel"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame_leftPanel->sizePolicy().hasHeightForWidth());
        frame_leftPanel->setSizePolicy(sizePolicy2);
        frame_leftPanel->setMinimumSize(QSize(211, 411));
        frame_leftPanel->setMaximumSize(QSize(211, 16777215));
        frame_leftPanel->setFrameShape(QFrame::StyledPanel);
        frame_leftPanel->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_leftPanel);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        frame_userInfoPanel = new QFrame(frame_leftPanel);
        frame_userInfoPanel->setObjectName(QString::fromUtf8("frame_userInfoPanel"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frame_userInfoPanel->sizePolicy().hasHeightForWidth());
        frame_userInfoPanel->setSizePolicy(sizePolicy3);
        frame_userInfoPanel->setAutoFillBackground(false);
        frame_userInfoPanel->setStyleSheet(QString::fromUtf8(""));
        frame_userInfoPanel->setFrameShape(QFrame::StyledPanel);
        frame_userInfoPanel->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_userInfoPanel);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_4 = new QSpacerItem(20, 46, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        label_login = new QLabel(frame_userInfoPanel);
        label_login->setObjectName(QString::fromUtf8("label_login"));
        QFont font5;
        font5.setPointSize(15);
        font5.setBold(true);
        font5.setItalic(false);
        label_login->setFont(font5);

        verticalLayout_2->addWidget(label_login);

        label_position = new QLabel(frame_userInfoPanel);
        label_position->setObjectName(QString::fromUtf8("label_position"));
        QFont font6;
        font6.setItalic(true);
        label_position->setFont(font6);

        verticalLayout_2->addWidget(label_position);

        label_fio = new QLabel(frame_userInfoPanel);
        label_fio->setObjectName(QString::fromUtf8("label_fio"));
        QFont font7;
        font7.setPointSize(12);
        label_fio->setFont(font7);
        label_fio->setWordWrap(true);

        verticalLayout_2->addWidget(label_fio);

        verticalSpacer = new QSpacerItem(20, 46, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout_5->addWidget(frame_userInfoPanel);

        frame_buttonsPanell = new QFrame(frame_leftPanel);
        frame_buttonsPanell->setObjectName(QString::fromUtf8("frame_buttonsPanell"));
        frame_buttonsPanell->setAutoFillBackground(true);
        frame_buttonsPanell->setStyleSheet(QString::fromUtf8(""));
        frame_buttonsPanell->setFrameShape(QFrame::NoFrame);
        frame_buttonsPanell->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_buttonsPanell);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        stackedWidget_buttonPanels = new QStackedWidget(frame_buttonsPanell);
        stackedWidget_buttonPanels->setObjectName(QString::fromUtf8("stackedWidget_buttonPanels"));
        page_mainMenuButtons = new QWidget();
        page_mainMenuButtons->setObjectName(QString::fromUtf8("page_mainMenuButtons"));
        verticalLayout_3 = new QVBoxLayout(page_mainMenuButtons);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(page_mainMenuButtons);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_mainMenuButtons = new QWidget();
        scrollAreaWidgetContents_mainMenuButtons->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_mainMenuButtons"));
        scrollAreaWidgetContents_mainMenuButtons->setGeometry(QRect(0, -206, 177, 464));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents_mainMenuButtons);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);

        pushButton_workers = new QPushButton(scrollAreaWidgetContents_mainMenuButtons);
        pushButton_workers->setObjectName(QString::fromUtf8("pushButton_workers"));
        pushButton_workers->setMinimumSize(QSize(0, 40));
        pushButton_workers->setAutoExclusive(false);
        pushButton_workers->setFlat(false);

        verticalLayout_4->addWidget(pushButton_workers);

        pushButton_checkpoints = new QPushButton(scrollAreaWidgetContents_mainMenuButtons);
        pushButton_checkpoints->setObjectName(QString::fromUtf8("pushButton_checkpoints"));
        pushButton_checkpoints->setMinimumSize(QSize(0, 40));
        pushButton_checkpoints->setFlat(false);

        verticalLayout_4->addWidget(pushButton_checkpoints);

        pushButton_authorizations = new QPushButton(scrollAreaWidgetContents_mainMenuButtons);
        pushButton_authorizations->setObjectName(QString::fromUtf8("pushButton_authorizations"));
        pushButton_authorizations->setMinimumSize(QSize(0, 40));
        pushButton_authorizations->setFlat(false);

        verticalLayout_4->addWidget(pushButton_authorizations);

        pushButton_accounts = new QPushButton(scrollAreaWidgetContents_mainMenuButtons);
        pushButton_accounts->setObjectName(QString::fromUtf8("pushButton_accounts"));
        pushButton_accounts->setMinimumSize(QSize(0, 40));
        pushButton_accounts->setFlat(false);

        verticalLayout_4->addWidget(pushButton_accounts);

        pushButton_lvlAccesses = new QPushButton(scrollAreaWidgetContents_mainMenuButtons);
        pushButton_lvlAccesses->setObjectName(QString::fromUtf8("pushButton_lvlAccesses"));
        pushButton_lvlAccesses->setMinimumSize(QSize(0, 40));
        pushButton_lvlAccesses->setFlat(false);

        verticalLayout_4->addWidget(pushButton_lvlAccesses);

        pushButton_positions = new QPushButton(scrollAreaWidgetContents_mainMenuButtons);
        pushButton_positions->setObjectName(QString::fromUtf8("pushButton_positions"));
        pushButton_positions->setMinimumSize(QSize(0, 40));
        pushButton_positions->setFlat(false);

        verticalLayout_4->addWidget(pushButton_positions);

        pushButton_privilege = new QPushButton(scrollAreaWidgetContents_mainMenuButtons);
        pushButton_privilege->setObjectName(QString::fromUtf8("pushButton_privilege"));
        pushButton_privilege->setMinimumSize(QSize(0, 40));
        pushButton_privilege->setFlat(false);

        verticalLayout_4->addWidget(pushButton_privilege);

        pushButton_states = new QPushButton(scrollAreaWidgetContents_mainMenuButtons);
        pushButton_states->setObjectName(QString::fromUtf8("pushButton_states"));
        pushButton_states->setMinimumSize(QSize(0, 40));
        pushButton_states->setAutoRepeat(false);
        pushButton_states->setFlat(false);

        verticalLayout_4->addWidget(pushButton_states);

        verticalSpacer_33 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_33);

        pushButton_updateTables = new QPushButton(scrollAreaWidgetContents_mainMenuButtons);
        pushButton_updateTables->setObjectName(QString::fromUtf8("pushButton_updateTables"));
        pushButton_updateTables->setMinimumSize(QSize(0, 40));

        verticalLayout_4->addWidget(pushButton_updateTables);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_6);

        scrollArea->setWidget(scrollAreaWidgetContents_mainMenuButtons);

        verticalLayout_3->addWidget(scrollArea);

        stackedWidget_buttonPanels->addWidget(page_mainMenuButtons);
        page_workersButtons = new QWidget();
        page_workersButtons->setObjectName(QString::fromUtf8("page_workersButtons"));
        verticalLayout_10 = new QVBoxLayout(page_workersButtons);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        scrollArea_2 = new QScrollArea(page_workersButtons);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setFrameShape(QFrame::NoFrame);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 159, 162));
        verticalLayout_9 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalSpacer_9 = new QSpacerItem(20, 43, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_9);

        pushButton_addWorker = new QPushButton(scrollAreaWidgetContents);
        pushButton_addWorker->setObjectName(QString::fromUtf8("pushButton_addWorker"));
        pushButton_addWorker->setMinimumSize(QSize(0, 40));

        verticalLayout_9->addWidget(pushButton_addWorker);

        pushButton_editWorker = new QPushButton(scrollAreaWidgetContents);
        pushButton_editWorker->setObjectName(QString::fromUtf8("pushButton_editWorker"));
        pushButton_editWorker->setMinimumSize(QSize(0, 40));

        verticalLayout_9->addWidget(pushButton_editWorker);

        pushButton_moreAboutWorker = new QPushButton(scrollAreaWidgetContents);
        pushButton_moreAboutWorker->setObjectName(QString::fromUtf8("pushButton_moreAboutWorker"));
        pushButton_moreAboutWorker->setMinimumSize(QSize(0, 40));

        verticalLayout_9->addWidget(pushButton_moreAboutWorker);

        verticalSpacer_10 = new QSpacerItem(20, 44, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_10);

        scrollArea_2->setWidget(scrollAreaWidgetContents);

        verticalLayout_10->addWidget(scrollArea_2);

        stackedWidget_buttonPanels->addWidget(page_workersButtons);
        page_checkpointsButtons = new QWidget();
        page_checkpointsButtons->setObjectName(QString::fromUtf8("page_checkpointsButtons"));
        verticalLayout_14 = new QVBoxLayout(page_checkpointsButtons);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        scrollArea_3 = new QScrollArea(page_checkpointsButtons);
        scrollArea_3->setObjectName(QString::fromUtf8("scrollArea_3"));
        scrollArea_3->setFrameShape(QFrame::NoFrame);
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, -53, 159, 208));
        verticalLayout_13 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalSpacer_13 = new QSpacerItem(20, 44, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_13->addItem(verticalSpacer_13);

        pushButton_addCheckpoint = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_addCheckpoint->setObjectName(QString::fromUtf8("pushButton_addCheckpoint"));
        pushButton_addCheckpoint->setMinimumSize(QSize(0, 40));

        verticalLayout_13->addWidget(pushButton_addCheckpoint);

        pushButton_editCheckpoint = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_editCheckpoint->setObjectName(QString::fromUtf8("pushButton_editCheckpoint"));
        pushButton_editCheckpoint->setMinimumSize(QSize(0, 40));

        verticalLayout_13->addWidget(pushButton_editCheckpoint);

        pushButton_removeCheckpoint = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_removeCheckpoint->setObjectName(QString::fromUtf8("pushButton_removeCheckpoint"));
        pushButton_removeCheckpoint->setMinimumSize(QSize(0, 40));

        verticalLayout_13->addWidget(pushButton_removeCheckpoint);

        pushButton_viewCheckpoint = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_viewCheckpoint->setObjectName(QString::fromUtf8("pushButton_viewCheckpoint"));
        pushButton_viewCheckpoint->setMinimumSize(QSize(0, 40));

        verticalLayout_13->addWidget(pushButton_viewCheckpoint);

        verticalSpacer_12 = new QSpacerItem(20, 43, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_13->addItem(verticalSpacer_12);

        scrollArea_3->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_14->addWidget(scrollArea_3);

        stackedWidget_buttonPanels->addWidget(page_checkpointsButtons);
        page_authorizationsButtons = new QWidget();
        page_authorizationsButtons->setObjectName(QString::fromUtf8("page_authorizationsButtons"));
        verticalLayout_18 = new QVBoxLayout(page_authorizationsButtons);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        scrollArea_4 = new QScrollArea(page_authorizationsButtons);
        scrollArea_4->setObjectName(QString::fromUtf8("scrollArea_4"));
        scrollArea_4->setFrameShape(QFrame::NoFrame);
        scrollArea_4->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 98, 70));
        verticalLayout_16 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        verticalSpacer_14 = new QSpacerItem(20, 89, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer_14);

        pushButton_moreAboutAuthorization = new QPushButton(scrollAreaWidgetContents_3);
        pushButton_moreAboutAuthorization->setObjectName(QString::fromUtf8("pushButton_moreAboutAuthorization"));
        pushButton_moreAboutAuthorization->setMinimumSize(QSize(0, 40));

        verticalLayout_16->addWidget(pushButton_moreAboutAuthorization);

        verticalSpacer_15 = new QSpacerItem(20, 90, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer_15);

        scrollArea_4->setWidget(scrollAreaWidgetContents_3);

        verticalLayout_18->addWidget(scrollArea_4);

        stackedWidget_buttonPanels->addWidget(page_authorizationsButtons);
        page_accountsButtons = new QWidget();
        page_accountsButtons->setObjectName(QString::fromUtf8("page_accountsButtons"));
        verticalLayout_20 = new QVBoxLayout(page_accountsButtons);
        verticalLayout_20->setObjectName(QString::fromUtf8("verticalLayout_20"));
        scrollArea_5 = new QScrollArea(page_accountsButtons);
        scrollArea_5->setObjectName(QString::fromUtf8("scrollArea_5"));
        scrollArea_5->setFrameShape(QFrame::NoFrame);
        scrollArea_5->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 110, 208));
        verticalLayout_19 = new QVBoxLayout(scrollAreaWidgetContents_4);
        verticalLayout_19->setObjectName(QString::fromUtf8("verticalLayout_19"));
        verticalSpacer_16 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_19->addItem(verticalSpacer_16);

        pushButton_addAccount = new QPushButton(scrollAreaWidgetContents_4);
        pushButton_addAccount->setObjectName(QString::fromUtf8("pushButton_addAccount"));
        pushButton_addAccount->setMinimumSize(QSize(0, 40));

        verticalLayout_19->addWidget(pushButton_addAccount);

        pushButton_editAccount = new QPushButton(scrollAreaWidgetContents_4);
        pushButton_editAccount->setObjectName(QString::fromUtf8("pushButton_editAccount"));
        pushButton_editAccount->setMinimumSize(QSize(0, 40));

        verticalLayout_19->addWidget(pushButton_editAccount);

        pushButton_moreAboutAccount = new QPushButton(scrollAreaWidgetContents_4);
        pushButton_moreAboutAccount->setObjectName(QString::fromUtf8("pushButton_moreAboutAccount"));
        pushButton_moreAboutAccount->setMinimumSize(QSize(0, 40));

        verticalLayout_19->addWidget(pushButton_moreAboutAccount);

        pushButton_removeAccount = new QPushButton(scrollAreaWidgetContents_4);
        pushButton_removeAccount->setObjectName(QString::fromUtf8("pushButton_removeAccount"));
        pushButton_removeAccount->setMinimumSize(QSize(0, 40));

        verticalLayout_19->addWidget(pushButton_removeAccount);

        verticalSpacer_17 = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_19->addItem(verticalSpacer_17);

        scrollArea_5->setWidget(scrollAreaWidgetContents_4);

        verticalLayout_20->addWidget(scrollArea_5);

        stackedWidget_buttonPanels->addWidget(page_accountsButtons);
        page_lvlAccessButtons = new QWidget();
        page_lvlAccessButtons->setObjectName(QString::fromUtf8("page_lvlAccessButtons"));
        verticalLayout_23 = new QVBoxLayout(page_lvlAccessButtons);
        verticalLayout_23->setObjectName(QString::fromUtf8("verticalLayout_23"));
        scrollArea_6 = new QScrollArea(page_lvlAccessButtons);
        scrollArea_6->setObjectName(QString::fromUtf8("scrollArea_6"));
        scrollArea_6->setFrameShape(QFrame::NoFrame);
        scrollArea_6->setWidgetResizable(true);
        scrollAreaWidgetContents_5 = new QWidget();
        scrollAreaWidgetContents_5->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_5"));
        scrollAreaWidgetContents_5->setGeometry(QRect(0, 0, 110, 208));
        verticalLayout_22 = new QVBoxLayout(scrollAreaWidgetContents_5);
        verticalLayout_22->setObjectName(QString::fromUtf8("verticalLayout_22"));
        verticalSpacer_18 = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_22->addItem(verticalSpacer_18);

        pushButton_addLvlAccess = new QPushButton(scrollAreaWidgetContents_5);
        pushButton_addLvlAccess->setObjectName(QString::fromUtf8("pushButton_addLvlAccess"));
        pushButton_addLvlAccess->setMinimumSize(QSize(0, 40));

        verticalLayout_22->addWidget(pushButton_addLvlAccess);

        pushButton_editLvlAccess = new QPushButton(scrollAreaWidgetContents_5);
        pushButton_editLvlAccess->setObjectName(QString::fromUtf8("pushButton_editLvlAccess"));
        pushButton_editLvlAccess->setMinimumSize(QSize(0, 40));

        verticalLayout_22->addWidget(pushButton_editLvlAccess);

        pushButton_moreAboutLvlAccess = new QPushButton(scrollAreaWidgetContents_5);
        pushButton_moreAboutLvlAccess->setObjectName(QString::fromUtf8("pushButton_moreAboutLvlAccess"));
        pushButton_moreAboutLvlAccess->setMinimumSize(QSize(0, 40));

        verticalLayout_22->addWidget(pushButton_moreAboutLvlAccess);

        pushButton_removeLvlAccess = new QPushButton(scrollAreaWidgetContents_5);
        pushButton_removeLvlAccess->setObjectName(QString::fromUtf8("pushButton_removeLvlAccess"));
        pushButton_removeLvlAccess->setMinimumSize(QSize(0, 40));

        verticalLayout_22->addWidget(pushButton_removeLvlAccess);

        verticalSpacer_19 = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_22->addItem(verticalSpacer_19);

        scrollArea_6->setWidget(scrollAreaWidgetContents_5);

        verticalLayout_23->addWidget(scrollArea_6);

        stackedWidget_buttonPanels->addWidget(page_lvlAccessButtons);
        page_positionsButtons = new QWidget();
        page_positionsButtons->setObjectName(QString::fromUtf8("page_positionsButtons"));
        verticalLayout_26 = new QVBoxLayout(page_positionsButtons);
        verticalLayout_26->setObjectName(QString::fromUtf8("verticalLayout_26"));
        scrollArea_7 = new QScrollArea(page_positionsButtons);
        scrollArea_7->setObjectName(QString::fromUtf8("scrollArea_7"));
        scrollArea_7->setFrameShape(QFrame::NoFrame);
        scrollArea_7->setWidgetResizable(true);
        scrollAreaWidgetContents_6 = new QWidget();
        scrollAreaWidgetContents_6->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_6"));
        scrollAreaWidgetContents_6->setGeometry(QRect(0, 0, 110, 162));
        verticalLayout_25 = new QVBoxLayout(scrollAreaWidgetContents_6);
        verticalLayout_25->setObjectName(QString::fromUtf8("verticalLayout_25"));
        verticalSpacer_20 = new QSpacerItem(20, 44, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_25->addItem(verticalSpacer_20);

        pushButton_addPosition = new QPushButton(scrollAreaWidgetContents_6);
        pushButton_addPosition->setObjectName(QString::fromUtf8("pushButton_addPosition"));
        pushButton_addPosition->setMinimumSize(QSize(0, 40));

        verticalLayout_25->addWidget(pushButton_addPosition);

        pushButton_editPosition = new QPushButton(scrollAreaWidgetContents_6);
        pushButton_editPosition->setObjectName(QString::fromUtf8("pushButton_editPosition"));
        pushButton_editPosition->setMinimumSize(QSize(0, 40));

        verticalLayout_25->addWidget(pushButton_editPosition);

        pushButton_removePosition = new QPushButton(scrollAreaWidgetContents_6);
        pushButton_removePosition->setObjectName(QString::fromUtf8("pushButton_removePosition"));
        pushButton_removePosition->setMinimumSize(QSize(0, 40));

        verticalLayout_25->addWidget(pushButton_removePosition);

        verticalSpacer_21 = new QSpacerItem(20, 44, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_25->addItem(verticalSpacer_21);

        scrollArea_7->setWidget(scrollAreaWidgetContents_6);

        verticalLayout_26->addWidget(scrollArea_7);

        stackedWidget_buttonPanels->addWidget(page_positionsButtons);
        page_privilegesButtons = new QWidget();
        page_privilegesButtons->setObjectName(QString::fromUtf8("page_privilegesButtons"));
        verticalLayout_28 = new QVBoxLayout(page_privilegesButtons);
        verticalLayout_28->setObjectName(QString::fromUtf8("verticalLayout_28"));
        label_14 = new QLabel(page_privilegesButtons);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setAlignment(Qt::AlignCenter);
        label_14->setWordWrap(true);

        verticalLayout_28->addWidget(label_14);

        stackedWidget_buttonPanels->addWidget(page_privilegesButtons);
        page_statesButtons = new QWidget();
        page_statesButtons->setObjectName(QString::fromUtf8("page_statesButtons"));
        verticalLayout_30 = new QVBoxLayout(page_statesButtons);
        verticalLayout_30->setObjectName(QString::fromUtf8("verticalLayout_30"));
        label_16 = new QLabel(page_statesButtons);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setAlignment(Qt::AlignCenter);
        label_16->setWordWrap(true);

        verticalLayout_30->addWidget(label_16);

        stackedWidget_buttonPanels->addWidget(page_statesButtons);
        page_toolButtonst = new QWidget();
        page_toolButtonst->setObjectName(QString::fromUtf8("page_toolButtonst"));
        verticalLayout_38 = new QVBoxLayout(page_toolButtonst);
        verticalLayout_38->setObjectName(QString::fromUtf8("verticalLayout_38"));
        scrollArea_18 = new QScrollArea(page_toolButtonst);
        scrollArea_18->setObjectName(QString::fromUtf8("scrollArea_18"));
        scrollArea_18->setWidgetResizable(true);
        scrollAreaWidgetContents_17 = new QWidget();
        scrollAreaWidgetContents_17->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_17"));
        scrollAreaWidgetContents_17->setGeometry(QRect(0, 0, 98, 35));
        verticalLayout_58 = new QVBoxLayout(scrollAreaWidgetContents_17);
        verticalLayout_58->setObjectName(QString::fromUtf8("verticalLayout_58"));
        label_errorMessage = new QLabel(scrollAreaWidgetContents_17);
        label_errorMessage->setObjectName(QString::fromUtf8("label_errorMessage"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_errorMessage->setPalette(palette1);
        label_errorMessage->setTextFormat(Qt::PlainText);
        label_errorMessage->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_errorMessage->setWordWrap(true);

        verticalLayout_58->addWidget(label_errorMessage);

        scrollArea_18->setWidget(scrollAreaWidgetContents_17);

        verticalLayout_38->addWidget(scrollArea_18);

        stackedWidget_buttonPanels->addWidget(page_toolButtonst);

        verticalLayout_6->addWidget(stackedWidget_buttonPanels);

        pushButton_save = new QPushButton(frame_buttonsPanell);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setMinimumSize(QSize(0, 40));

        verticalLayout_6->addWidget(pushButton_save);

        pushButton_cancel = new QPushButton(frame_buttonsPanell);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setMinimumSize(QSize(0, 40));

        verticalLayout_6->addWidget(pushButton_cancel);

        pushButton_back = new QPushButton(frame_buttonsPanell);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        pushButton_back->setMinimumSize(QSize(0, 40));

        verticalLayout_6->addWidget(pushButton_back);

        verticalSpacer_32 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_32);

        verticalSpacer_11 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_6->addItem(verticalSpacer_11);

        pushButton_exit = new QPushButton(frame_buttonsPanell);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        pushButton_exit->setMinimumSize(QSize(0, 40));

        verticalLayout_6->addWidget(pushButton_exit);


        verticalLayout_5->addWidget(frame_buttonsPanell);

        frame_buttonsPanell->raise();
        frame_userInfoPanel->raise();

        gridLayout_3->addWidget(frame_leftPanel, 0, 0, 1, 1);

        stackedWidget_mainWindow->addWidget(page_workplace);
        page_settings = new QWidget();
        page_settings->setObjectName(QString::fromUtf8("page_settings"));
        gridLayout_5 = new QGridLayout(page_settings);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        scrollArea_8 = new QScrollArea(page_settings);
        scrollArea_8->setObjectName(QString::fromUtf8("scrollArea_8"));
        scrollArea_8->setWidgetResizable(true);
        scrollAreaWidgetContents_7 = new QWidget();
        scrollAreaWidgetContents_7->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_7"));
        scrollAreaWidgetContents_7->setGeometry(QRect(0, 0, 311, 163));
        verticalLayout_31 = new QVBoxLayout(scrollAreaWidgetContents_7);
        verticalLayout_31->setObjectName(QString::fromUtf8("verticalLayout_31"));
        label_18 = new QLabel(scrollAreaWidgetContents_7);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        QFont font8;
        font8.setPointSize(14);
        font8.setBold(true);
        font8.setItalic(false);
        label_18->setFont(font8);

        verticalLayout_31->addWidget(label_18);

        frame_13 = new QFrame(scrollAreaWidgetContents_7);
        frame_13->setObjectName(QString::fromUtf8("frame_13"));
        frame_13->setFrameShape(QFrame::StyledPanel);
        frame_13->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_13);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_20 = new QLabel(frame_13);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_20, 1, 0, 1, 1);

        lineEdit_setHostPort = new QLineEdit(frame_13);
        lineEdit_setHostPort->setObjectName(QString::fromUtf8("lineEdit_setHostPort"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lineEdit_setHostPort->sizePolicy().hasHeightForWidth());
        lineEdit_setHostPort->setSizePolicy(sizePolicy4);
        lineEdit_setHostPort->setClearButtonEnabled(false);

        gridLayout_6->addWidget(lineEdit_setHostPort, 1, 1, 1, 1);

        label_19 = new QLabel(frame_13);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_19, 0, 0, 1, 1);

        lineEdit_setHostAddress = new QLineEdit(frame_13);
        lineEdit_setHostAddress->setObjectName(QString::fromUtf8("lineEdit_setHostAddress"));
        sizePolicy4.setHeightForWidth(lineEdit_setHostAddress->sizePolicy().hasHeightForWidth());
        lineEdit_setHostAddress->setSizePolicy(sizePolicy4);
        lineEdit_setHostAddress->setClearButtonEnabled(false);

        gridLayout_6->addWidget(lineEdit_setHostAddress, 0, 1, 1, 1);

        label_currentHostPort = new QLabel(frame_13);
        label_currentHostPort->setObjectName(QString::fromUtf8("label_currentHostPort"));
        QFont font9;
        font9.setPointSize(10);
        font9.setBold(true);
        font9.setItalic(true);
        label_currentHostPort->setFont(font9);

        gridLayout_6->addWidget(label_currentHostPort, 1, 3, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(361, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_11, 0, 4, 1, 1);

        label_21 = new QLabel(frame_13);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_6->addWidget(label_21, 0, 2, 1, 1);

        label_currentHostAddress = new QLabel(frame_13);
        label_currentHostAddress->setObjectName(QString::fromUtf8("label_currentHostAddress"));
        label_currentHostAddress->setFont(font9);

        gridLayout_6->addWidget(label_currentHostAddress, 0, 3, 1, 1);

        label_22 = new QLabel(frame_13);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_6->addWidget(label_22, 1, 2, 1, 1);

        label_44 = new QLabel(frame_13);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_44, 2, 0, 1, 1);

        lineEdit_setDbName = new QLineEdit(frame_13);
        lineEdit_setDbName->setObjectName(QString::fromUtf8("lineEdit_setDbName"));

        gridLayout_6->addWidget(lineEdit_setDbName, 2, 1, 1, 1);

        label_45 = new QLabel(frame_13);
        label_45->setObjectName(QString::fromUtf8("label_45"));

        gridLayout_6->addWidget(label_45, 2, 2, 1, 1);

        label_currentDbName = new QLabel(frame_13);
        label_currentDbName->setObjectName(QString::fromUtf8("label_currentDbName"));
        QFont font10;
        font10.setBold(true);
        font10.setItalic(true);
        label_currentDbName->setFont(font10);

        gridLayout_6->addWidget(label_currentDbName, 2, 3, 1, 1);


        verticalLayout_31->addWidget(frame_13);

        verticalSpacer_22 = new QSpacerItem(20, 359, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_31->addItem(verticalSpacer_22);

        scrollArea_8->setWidget(scrollAreaWidgetContents_7);

        gridLayout_5->addWidget(scrollArea_8, 1, 0, 1, 4);

        pushButton_applySettings = new QPushButton(page_settings);
        pushButton_applySettings->setObjectName(QString::fromUtf8("pushButton_applySettings"));

        gridLayout_5->addWidget(pushButton_applySettings, 2, 3, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(599, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_10, 2, 1, 1, 1);

        label_17 = new QLabel(page_settings);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font2);

        gridLayout_5->addWidget(label_17, 0, 0, 1, 4);

        pushButton_backToLogin = new QPushButton(page_settings);
        pushButton_backToLogin->setObjectName(QString::fromUtf8("pushButton_backToLogin"));

        gridLayout_5->addWidget(pushButton_backToLogin, 2, 2, 1, 1);

        stackedWidget_mainWindow->addWidget(page_settings);

        verticalLayout_11->addWidget(stackedWidget_mainWindow);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget_mainWindow->setCurrentIndex(1);
        stackedWidget_workPlace->setCurrentIndex(12);
        comboBox_filterAuthorizationByLvlAccess->setCurrentIndex(-1);
        comboBox_filterAuthorizationByCheckpoint->setCurrentIndex(-1);
        stackedWidget_buttonPanels->setCurrentIndex(2);
        pushButton_workers->setDefault(false);
        pushButton_checkpoints->setDefault(false);
        pushButton_authorizations->setDefault(false);
        pushButton_accounts->setDefault(false);
        pushButton_lvlAccesses->setDefault(false);
        pushButton_positions->setDefault(false);
        pushButton_privilege->setDefault(false);
        pushButton_states->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_exitLogin->setText(QString());
        pushButton_faq->setText(QString());
        pushButton_settings->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        lineEdit_password->setInputMask(QString());
        label_loginErrors->setText(QString());
        pushButton_Connect->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\321\201\321\202\321\203\320\277\320\270\320\274!", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\224\320\273\321\217 \320\275\320\260\321\207\320\260\320\273\320\260 \321\200\320\260\320\261\320\276\321\202\321\213 - \320\262\321\213\320\261\320\270\321\200\320\270\321\202\320\265 \320\270\320\275\321\202\320\265\321\200\320\265\321\201\321\203\321\216\321\211\320\270\320\271 \321\200\320\260\320\267\320\264\320\265\320\273 \320\262 \320\274\320\265\320\275\321\216 \321\201\320\273\320\265\320\262\320\260.", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\270", nullptr));
        lineEdit_filterWorkerByInn->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\230\320\235\320\235", nullptr));
        comboBox_filterWorkerByLvlAccess->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 \320\264\320\276\321\201\321\202\321\203\320\277\320\260", nullptr));
        lineEdit_filterWorkerByFIO->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\244\320\230\320\236", nullptr));
        comboBox_filterWorkerByPosition->setCurrentText(QString());
        comboBox_filterWorkerByPosition->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        radioButton_showDismissed->setText(QCoreApplication::translate("MainWindow", "\320\242\320\276\320\273\321\214\320\272\320\276 \321\203\320\262\320\276\320\273\320\265\320\275\320\275\321\213\320\265", nullptr));
        radioButton_showAll->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\262\321\201\320\265\321\205", nullptr));
        radioButton_hideTheDismissed->setText(QCoreApplication::translate("MainWindow", "\320\241\320\272\321\200\321\213\321\202\321\214 \321\203\320\262\320\276\320\273\320\265\320\275\320\275\321\213\321\205", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\275\321\202\321\200\320\276\320\273\321\214\320\275\321\213\320\265 \320\277\321\203\320\275\320\272\321\202\321\213", nullptr));
        lineEdit_filterCheckpointByTitle->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        comboBox_filterCheckpointByLvlAccess->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 \320\264\320\276\321\201\321\202\321\203\320\277\320\260", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\320\265\321\211\320\265\320\275\320\270\321\217", nullptr));
        checkBox_filterAuthorizationByStateInadmissible->setText(QCoreApplication::translate("MainWindow", "\320\235\320\265\320\264\320\276\320\277\321\203\321\211\320\265\320\275\320\275\321\213\321\205", nullptr));
        checkBox_filterAuthorizationByDate->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260", nullptr));
        lineEdit_filterAuthorizationByWorker->setText(QString());
        lineEdit_filterAuthorizationByWorker->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\244\320\230\320\236 \320\277\321\200\320\276\321\210\320\265\320\264\321\210\320\265\320\263\320\276", nullptr));
        comboBox_filterAuthorizationByLvlAccess->setItemText(0, QCoreApplication::translate("MainWindow", "\320\275\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));

        comboBox_filterAuthorizationByLvlAccess->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 \320\264\320\276\321\201\321\202\321\203\320\277\320\260", nullptr));
        checkBox_filterAuthorizationByTime->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217", nullptr));
        checkBox_filterAuthorizationByStateIncoming->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\321\210\320\265\320\264\321\210\320\270\321\205", nullptr));
        checkBox_filterAuthorizationByStateGraduates->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\270\320\275\321\203\320\262\321\210\320\270\321\205", nullptr));
        lineEdit_filterAuthorizationByAuthorizer->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\244\320\230\320\236 \320\277\321\200\320\276\320\277\321\203\321\201\321\202\320\270\320\262\321\210\320\265\320\263\320\276", nullptr));
        comboBox_filterAuthorizationByCheckpoint->setItemText(0, QCoreApplication::translate("MainWindow", "\320\275\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));

        comboBox_filterAuthorizationByCheckpoint->setCurrentText(QString());
        comboBox_filterAuthorizationByCheckpoint->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\277\321\203\321\201\320\272\320\275\320\276\320\271 \320\277\321\203\320\275\320\272\321\202", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\220\320\272\320\272\320\260\321\203\320\275\321\202\321\213", nullptr));
        lineEdit_filterAccountsByLogin->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        lineEdit_filterAccountsByFIO->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\244\320\230\320\236 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260", nullptr));
        comboBox_filterAccountsByPrivileges->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\262\320\270\320\273\320\265\320\263\320\270\320\270", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\243\321\200\320\276\320\262\320\275\320\270 \320\264\320\276\321\201\321\202\321\203\320\277\320\260", nullptr));
        lineEdit_filterLvlAccessByTitle->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276 \320\270\320\265\321\200\320\260\321\200\321\205\320\270\320\270:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\320\270", nullptr));
        lineEdit_filterPositionsByTitle->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\262\320\270\320\273\320\265\320\263\320\270\320\270", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\321\217 \320\260\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\320\270", nullptr));
        label_addWorkerLabel->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\276\320\262", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "\320\233\320\270\321\207\320\275\320\260\321\217 \320\270\321\204\320\275\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
        pushButton_addWorkerLoadPhoto->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214\n"
"\321\204\320\276\321\202\320\276", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "\320\244\320\230\320\236:", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "\320\230\320\235\320\235:", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217:", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\201\321\202\320\276 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\320\270:", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\201\321\202\320\276 \320\266\320\270\321\202\320\265\320\273\321\214\321\201\321\202\320\262\320\260:", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "\320\241\320\265\321\200\320\270\321\217 \320\270 \320\275\320\276\320\274\320\265\321\200 \320\277\320\260\321\201\320\277\320\276\321\200\321\202\320\260:", nullptr));
        label_47->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275 \320\260\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\320\270:", nullptr));
        label_48->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214 \320\260\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\320\270:", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\264\320\276\320\273\320\266\320\275\320\276\321\201\321\202\320\270", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 \320\264\320\276\321\201\321\202\321\203\320\277\320\260:", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214:", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265:", nullptr));
        comboBox_addWorkerStateDissmised->setItemText(0, QCoreApplication::translate("MainWindow", "\320\240\320\260\320\261\320\276\321\202\320\260\320\265\321\202", nullptr));
        comboBox_addWorkerStateDissmised->setItemText(1, QCoreApplication::translate("MainWindow", "\320\243\320\262\320\276\320\273\320\265\320\275", nullptr));

        label_34->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "\320\233\320\270\321\207\320\275\320\260\321\217 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "\320\244\320\230\320\236:", nullptr));
        label_viewWorkerPIB->setText(QCoreApplication::translate("MainWindow", "_fio", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "\320\230\320\235\320\235:", nullptr));
        label_viewWorkerINN->setText(QCoreApplication::translate("MainWindow", "_inn", nullptr));
        label_39->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217:", nullptr));
        label_viewWorkerDateOfBirth->setText(QCoreApplication::translate("MainWindow", "_dateOfBirth", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\201\321\202\320\276 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\320\270:", nullptr));
        label_viewWorkerPlaceOfRegistration->setText(QCoreApplication::translate("MainWindow", "_placeOfRegistration", nullptr));
        label_41->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\201\321\202\320\276 \320\277\321\200\320\276\320\266\320\270\320\262\320\260\320\275\320\270\320\265\321\217:", nullptr));
        label_viewWorkerPlaceOfResidence->setText(QCoreApplication::translate("MainWindow", "_placeOfResidence", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "\320\241\320\265\321\200\320\270\321\217 \320\270 \320\275\320\276\320\274\320\265\321\200 \320\277\320\260\321\201\320\277\320\276\321\200\321\202\320\260:", nullptr));
        label_viewWorkerNumberPassport->setText(QCoreApplication::translate("MainWindow", "_numberPassport", nullptr));
        label_46->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275 \320\260\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\320\270:", nullptr));
        label_workerLogin->setText(QCoreApplication::translate("MainWindow", "_workerLogin", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\264\320\276\320\273\320\266\320\275\320\276\321\201\321\202\320\270", nullptr));
        label_51->setText(QCoreApplication::translate("MainWindow", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 \320\264\320\276\321\201\321\202\321\203\320\277\320\260:", nullptr));
        label_49->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214:", nullptr));
        label_viewWorkerLvlAccess->setText(QCoreApplication::translate("MainWindow", "_lvlAccess", nullptr));
        label_viewWorkerPosition->setText(QCoreApplication::translate("MainWindow", "_position", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265:", nullptr));
        label_viewWorkerStateDissmised->setText(QString());
        pushButton_viewWorkerPrintPass->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\207\320\260\321\202\320\260\321\202\321\214\n"
"\320\277\321\200\320\276\320\277\321\203\321\201\320\272", nullptr));
        label_addCheckpointLabel->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\321\200\320\276\321\205\320\276\320\264\320\275\320\276\320\271", nullptr));
        label_54->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265:", nullptr));
        label_55->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265:", nullptr));
        label_56->setText(QCoreApplication::translate("MainWindow", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 \320\264\320\276\321\201\321\202\321\203\320\277\320\260:", nullptr));
        label_57->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200", nullptr));
        label_58->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265:", nullptr));
        label_viewCheckpointTitle->setText(QCoreApplication::translate("MainWindow", "_title", nullptr));
        label_60->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265:", nullptr));
        label_viewCheckpointLocation->setText(QCoreApplication::translate("MainWindow", "_location", nullptr));
        label_62->setText(QCoreApplication::translate("MainWindow", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 \320\264\320\276\321\201\321\202\321\203\320\277\320\260:", nullptr));
        label_viewCheckpointLvlAccess->setText(QCoreApplication::translate("MainWindow", "_lvlAccess", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\207\320\260\321\202\320\260\321\202\321\214\n"
"\320\262\321\213\320\262\320\265\321\201\320\272\321\203", nullptr));
        label_64->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200", nullptr));
        label_65->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272:", nullptr));
        label_viewAuthorizationWorker->setText(QCoreApplication::translate("MainWindow", "_worker", nullptr));
        label_67->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260:", nullptr));
        label_viewAuthorizationDate->setText(QCoreApplication::translate("MainWindow", "_date", nullptr));
        label_68->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217:", nullptr));
        label_viewAuthorizationTime->setText(QCoreApplication::translate("MainWindow", "_time", nullptr));
        label_69->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265:", nullptr));
        label_viewAuthorizationState->setText(QCoreApplication::translate("MainWindow", "_state", nullptr));
        label_70->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260 \320\262\320\260\321\205\321\202\320\265:", nullptr));
        label_viewAuthorizationAuthorizer->setText(QCoreApplication::translate("MainWindow", "_authorizer", nullptr));
        label_71->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\205\320\276\320\264\320\275\320\260\321\217:", nullptr));
        label_viewAuthorizationCheckpoint->setText(QCoreApplication::translate("MainWindow", "_checkpoint", nullptr));
        label_addAccountLabel->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\260\320\272\320\272\320\260\321\203\320\275\321\202\320\260", nullptr));
        label_78->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        label_80->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        label_81->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\260:", nullptr));
        label_79->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272:", nullptr));
        label_82->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200", nullptr));
        label_83->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        label_viewAccountLogin->setText(QCoreApplication::translate("MainWindow", "_login", nullptr));
        label_84->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\260:", nullptr));
        label_viewAccountPrivilege->setText(QCoreApplication::translate("MainWindow", "_privilege", nullptr));
        label_85->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272:", nullptr));
        label_viewAccountWorker->setText(QCoreApplication::translate("MainWindow", "_worker", nullptr));
        label_addLvlAccessLabel->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\203\321\200\320\276\320\262\320\275\321\217 \320\264\320\276\321\201\321\202\321\203\320\277\320\260", nullptr));
        label_90->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265:", nullptr));
        label_91->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\267\320\270\321\206\320\270\321\217 \320\262 \320\270\320\265\321\200\320\260\321\200\321\205\320\270\320\270:", nullptr));
        label_addPositionLabel->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\264\320\276\320\273\320\266\320\275\320\276\321\201\321\202\320\270:", nullptr));
        label_93->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265:", nullptr));
        label_login->setText(QCoreApplication::translate("MainWindow", "_login", nullptr));
        label_position->setText(QCoreApplication::translate("MainWindow", "_position", nullptr));
        label_fio->setText(QCoreApplication::translate("MainWindow", "_fio", nullptr));
        pushButton_workers->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\270", nullptr));
        pushButton_checkpoints->setText(QCoreApplication::translate("MainWindow", "\320\232\320\237\320\237", nullptr));
        pushButton_authorizations->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\320\265\321\211\320\265\320\275\320\270\321\217", nullptr));
        pushButton_accounts->setText(QCoreApplication::translate("MainWindow", "\320\220\320\272\320\272\320\260\321\203\320\275\321\202\321\213", nullptr));
        pushButton_lvlAccesses->setText(QCoreApplication::translate("MainWindow", "\320\243\321\200\320\276\320\262\320\275\320\270 \320\264\320\276\321\201\321\202\321\203\320\277\320\260", nullptr));
        pushButton_positions->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\320\270", nullptr));
        pushButton_privilege->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\262\320\270\320\273\320\265\320\263\320\270\320\270", nullptr));
        pushButton_states->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\321\217\n"
"\320\260\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\320\270", nullptr));
        pushButton_updateTables->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214\n"
"\320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216", nullptr));
        pushButton_addWorker->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_editWorker->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        pushButton_moreAboutWorker->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\321\200\320\276\320\261\320\275\320\265\320\265", nullptr));
        pushButton_addCheckpoint->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_editCheckpoint->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        pushButton_removeCheckpoint->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButton_viewCheckpoint->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214", nullptr));
        pushButton_moreAboutAuthorization->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\321\200\320\276\320\261\320\275\320\265\320\265", nullptr));
        pushButton_addAccount->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_editAccount->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        pushButton_moreAboutAccount->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\321\200\320\276\320\261\320\275\320\265\320\265", nullptr));
        pushButton_removeAccount->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButton_addLvlAccess->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_editLvlAccess->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        pushButton_moreAboutLvlAccess->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\321\200\320\276\320\261\320\275\320\265\320\265", nullptr));
        pushButton_removeLvlAccess->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButton_addPosition->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_editPosition->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        pushButton_removePosition->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260 \320\264\320\260\320\275\320\275\321\213\320\271 \320\274\320\276\320\274\320\265\320\275\321\202 \321\204\321\203\320\275\320\272\321\206\320\270\320\271 \320\264\320\273\321\217 \321\215\321\202\320\276\320\263\320\276 \321\200\320\260\320\267\320\264\320\265\320\273\320\260 \320\275\320\265\321\202.", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260 \320\264\320\260\320\275\320\275\321\213\320\271 \320\274\320\276\320\274\320\265\320\275\321\202 \321\204\321\203\320\275\320\272\321\206\320\270\320\271 \320\264\320\273\321\217 \321\215\321\202\320\276\320\263\320\276 \321\200\320\260\320\267\320\264\320\265\320\273\320\260 \320\275\320\265\321\202.", nullptr));
        label_errorMessage->setText(QCoreApplication::translate("MainWindow", "_errorMessage", nullptr));
        pushButton_save->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        pushButton_back->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        pushButton_exit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\200\321\202:", nullptr));
        lineEdit_setHostPort->setPlaceholderText(QCoreApplication::translate("MainWindow", "3306", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "\320\220\320\264\321\200\320\265\321\201 \321\201\320\265\321\200\320\262\320\265\321\200\320\260:", nullptr));
        lineEdit_setHostAddress->setPlaceholderText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        label_currentHostPort->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271:", nullptr));
        label_currentHostAddress->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271:", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\221\320\224:", nullptr));
        lineEdit_setDbName->setPlaceholderText(QCoreApplication::translate("MainWindow", "name", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\265\320\265:", nullptr));
        label_currentDbName->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_applySettings->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        pushButton_backToLogin->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
