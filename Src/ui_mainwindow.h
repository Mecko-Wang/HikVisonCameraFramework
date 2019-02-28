/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_set_param;
    QAction *action_2;
    QAction *action_3;
    QAction *action_5;
    QAction *action_connect_PLC;
    QWidget *centralWidget;
    QPushButton *pb_Start;
    QPushButton *pb_Stop;
    QLabel *lb_PlcState1;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_cam2;
    QPushButton *pb_connectCamera2;
    QCheckBox *checkBox_Continuous2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_8;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_cam1;
    QPushButton *pb_connectCamera1;
    QCheckBox *checkBox_Continuous1;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_cam3;
    QPushButton *pb_connectCamera3;
    QCheckBox *checkBox_Continuous3;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_11;
    QWidget *widget3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    QTextEdit *edit_message;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_15;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_cam4;
    QPushButton *pb_connectCamera4;
    QCheckBox *checkBox_Continuous4;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_17;
    QWidget *widget4;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_18;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_cam5;
    QPushButton *pb_connectCamera5;
    QCheckBox *checkBox_Continuous5;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_20;
    QWidget *widget5;
    QLabel *lb_PlcState2;
    QLabel *lb_PlcState3;
    QLabel *lb_PlcState4;
    QLabel *lb_PlcState5;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1440, 820);
        action_set_param = new QAction(MainWindow);
        action_set_param->setObjectName(QStringLiteral("action_set_param"));
        action_set_param->setCheckable(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/set-param.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        action_set_param->setIcon(icon);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icon/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_2->setIcon(icon1);
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icon/filenew.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_3->setIcon(icon2);
        action_5 = new QAction(MainWindow);
        action_5->setObjectName(QStringLiteral("action_5"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icon/fileclose.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_5->setIcon(icon3);
        action_connect_PLC = new QAction(MainWindow);
        action_connect_PLC->setObjectName(QStringLiteral("action_connect_PLC"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icon/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_connect_PLC->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pb_Start = new QPushButton(centralWidget);
        pb_Start->setObjectName(QStringLiteral("pb_Start"));
        pb_Start->setEnabled(false);
        pb_Start->setGeometry(QRect(1270, 40, 150, 80));
        pb_Start->setMinimumSize(QSize(150, 80));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        pb_Start->setFont(font);
        pb_Stop = new QPushButton(centralWidget);
        pb_Stop->setObjectName(QStringLiteral("pb_Stop"));
        pb_Stop->setEnabled(false);
        pb_Stop->setGeometry(QRect(1270, 180, 150, 80));
        pb_Stop->setMinimumSize(QSize(150, 80));
        pb_Stop->setFont(font);
        lb_PlcState1 = new QLabel(centralWidget);
        lb_PlcState1->setObjectName(QStringLiteral("lb_PlcState1"));
        lb_PlcState1->setGeometry(QRect(1310, 330, 81, 51));
        lb_PlcState1->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(18);
        lb_PlcState1->setFont(font1);
        lb_PlcState1->setStyleSheet(QStringLiteral("background:red"));
        lb_PlcState1->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 1241, 748));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_cam2 = new QLabel(gridLayoutWidget);
        label_cam2->setObjectName(QStringLiteral("label_cam2"));
        label_cam2->setMinimumSize(QSize(50, 20));
        label_cam2->setMaximumSize(QSize(50, 20));

        horizontalLayout_2->addWidget(label_cam2);

        pb_connectCamera2 = new QPushButton(gridLayoutWidget);
        pb_connectCamera2->setObjectName(QStringLiteral("pb_connectCamera2"));
        pb_connectCamera2->setEnabled(true);
        pb_connectCamera2->setMinimumSize(QSize(30, 20));
        pb_connectCamera2->setMaximumSize(QSize(30, 20));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icon/media-play-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_connectCamera2->setIcon(icon5);

        horizontalLayout_2->addWidget(pb_connectCamera2);

        checkBox_Continuous2 = new QCheckBox(gridLayoutWidget);
        checkBox_Continuous2->setObjectName(QStringLiteral("checkBox_Continuous2"));
        checkBox_Continuous2->setEnabled(false);
        checkBox_Continuous2->setMinimumSize(QSize(90, 20));
        checkBox_Continuous2->setMaximumSize(QSize(90, 20));

        horizontalLayout_2->addWidget(checkBox_Continuous2);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));

        horizontalLayout_4->addLayout(horizontalLayout_8);


        verticalLayout_4->addLayout(horizontalLayout_4);

        widget2 = new QWidget(gridLayoutWidget);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setMinimumSize(QSize(408, 341));
        widget2->setMaximumSize(QSize(408, 341));
        widget2->setStyleSheet(QStringLiteral("background:lightgray"));

        verticalLayout_4->addWidget(widget2);


        gridLayout->addLayout(verticalLayout_4, 0, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_cam1 = new QLabel(gridLayoutWidget);
        label_cam1->setObjectName(QStringLiteral("label_cam1"));
        label_cam1->setMinimumSize(QSize(50, 20));
        label_cam1->setMaximumSize(QSize(50, 20));

        horizontalLayout->addWidget(label_cam1);

        pb_connectCamera1 = new QPushButton(gridLayoutWidget);
        pb_connectCamera1->setObjectName(QStringLiteral("pb_connectCamera1"));
        pb_connectCamera1->setEnabled(true);
        pb_connectCamera1->setMinimumSize(QSize(30, 20));
        pb_connectCamera1->setMaximumSize(QSize(30, 20));
        pb_connectCamera1->setIcon(icon5);

        horizontalLayout->addWidget(pb_connectCamera1);

        checkBox_Continuous1 = new QCheckBox(gridLayoutWidget);
        checkBox_Continuous1->setObjectName(QStringLiteral("checkBox_Continuous1"));
        checkBox_Continuous1->setEnabled(false);
        checkBox_Continuous1->setMinimumSize(QSize(90, 20));
        checkBox_Continuous1->setMaximumSize(QSize(90, 20));

        horizontalLayout->addWidget(checkBox_Continuous1);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));

        horizontalLayout_3->addLayout(horizontalLayout_7);


        verticalLayout_3->addLayout(horizontalLayout_3);

        widget1 = new QWidget(gridLayoutWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setMinimumSize(QSize(408, 341));
        widget1->setMaximumSize(QSize(408, 341));
        widget1->setStyleSheet(QStringLiteral("background:lightgray"));

        verticalLayout_3->addWidget(widget1);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_cam3 = new QLabel(gridLayoutWidget);
        label_cam3->setObjectName(QStringLiteral("label_cam3"));
        label_cam3->setMinimumSize(QSize(50, 20));
        label_cam3->setMaximumSize(QSize(50, 20));

        horizontalLayout_10->addWidget(label_cam3);

        pb_connectCamera3 = new QPushButton(gridLayoutWidget);
        pb_connectCamera3->setObjectName(QStringLiteral("pb_connectCamera3"));
        pb_connectCamera3->setEnabled(true);
        pb_connectCamera3->setMinimumSize(QSize(30, 20));
        pb_connectCamera3->setMaximumSize(QSize(30, 20));
        pb_connectCamera3->setIcon(icon5);

        horizontalLayout_10->addWidget(pb_connectCamera3);

        checkBox_Continuous3 = new QCheckBox(gridLayoutWidget);
        checkBox_Continuous3->setObjectName(QStringLiteral("checkBox_Continuous3"));
        checkBox_Continuous3->setEnabled(false);
        checkBox_Continuous3->setMinimumSize(QSize(90, 20));
        checkBox_Continuous3->setMaximumSize(QSize(90, 20));

        horizontalLayout_10->addWidget(checkBox_Continuous3);


        horizontalLayout_9->addLayout(horizontalLayout_10);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));

        horizontalLayout_9->addLayout(horizontalLayout_11);


        verticalLayout_5->addLayout(horizontalLayout_9);

        widget3 = new QWidget(gridLayoutWidget);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setMinimumSize(QSize(408, 341));
        widget3->setMaximumSize(QSize(408, 341));
        widget3->setStyleSheet(QStringLiteral("background:lightgray"));

        verticalLayout_5->addWidget(widget3);


        gridLayout->addLayout(verticalLayout_5, 0, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(100, 20));
        label_4->setStyleSheet(QStringLiteral("background:rgb(200,200,100)"));

        horizontalLayout_5->addWidget(label_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_5);

        edit_message = new QTextEdit(gridLayoutWidget);
        edit_message->setObjectName(QStringLiteral("edit_message"));
        edit_message->setEnabled(true);
        edit_message->setMinimumSize(QSize(100, 100));
        edit_message->setMaximumSize(QSize(900, 900));

        verticalLayout_2->addWidget(edit_message);


        gridLayout->addLayout(verticalLayout_2, 1, 2, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_cam4 = new QLabel(gridLayoutWidget);
        label_cam4->setObjectName(QStringLiteral("label_cam4"));
        label_cam4->setMinimumSize(QSize(50, 20));
        label_cam4->setMaximumSize(QSize(50, 20));

        horizontalLayout_16->addWidget(label_cam4);

        pb_connectCamera4 = new QPushButton(gridLayoutWidget);
        pb_connectCamera4->setObjectName(QStringLiteral("pb_connectCamera4"));
        pb_connectCamera4->setEnabled(true);
        pb_connectCamera4->setMinimumSize(QSize(30, 20));
        pb_connectCamera4->setMaximumSize(QSize(30, 20));
        pb_connectCamera4->setIcon(icon5);

        horizontalLayout_16->addWidget(pb_connectCamera4);

        checkBox_Continuous4 = new QCheckBox(gridLayoutWidget);
        checkBox_Continuous4->setObjectName(QStringLiteral("checkBox_Continuous4"));
        checkBox_Continuous4->setEnabled(false);
        checkBox_Continuous4->setMinimumSize(QSize(90, 20));
        checkBox_Continuous4->setMaximumSize(QSize(90, 20));

        horizontalLayout_16->addWidget(checkBox_Continuous4);


        horizontalLayout_15->addLayout(horizontalLayout_16);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_6);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));

        horizontalLayout_15->addLayout(horizontalLayout_17);


        verticalLayout_7->addLayout(horizontalLayout_15);

        widget4 = new QWidget(gridLayoutWidget);
        widget4->setObjectName(QStringLiteral("widget4"));
        widget4->setMinimumSize(QSize(408, 341));
        widget4->setMaximumSize(QSize(408, 341));
        widget4->setStyleSheet(QStringLiteral("background:lightgray"));

        verticalLayout_7->addWidget(widget4);


        gridLayout->addLayout(verticalLayout_7, 1, 0, 1, 1);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        label_cam5 = new QLabel(gridLayoutWidget);
        label_cam5->setObjectName(QStringLiteral("label_cam5"));
        label_cam5->setMinimumSize(QSize(50, 20));
        label_cam5->setMaximumSize(QSize(50, 20));

        horizontalLayout_19->addWidget(label_cam5);

        pb_connectCamera5 = new QPushButton(gridLayoutWidget);
        pb_connectCamera5->setObjectName(QStringLiteral("pb_connectCamera5"));
        pb_connectCamera5->setEnabled(true);
        pb_connectCamera5->setMinimumSize(QSize(30, 20));
        pb_connectCamera5->setMaximumSize(QSize(30, 20));
        pb_connectCamera5->setIcon(icon5);

        horizontalLayout_19->addWidget(pb_connectCamera5);

        checkBox_Continuous5 = new QCheckBox(gridLayoutWidget);
        checkBox_Continuous5->setObjectName(QStringLiteral("checkBox_Continuous5"));
        checkBox_Continuous5->setEnabled(false);
        checkBox_Continuous5->setMinimumSize(QSize(90, 20));
        checkBox_Continuous5->setMaximumSize(QSize(90, 20));

        horizontalLayout_19->addWidget(checkBox_Continuous5);


        horizontalLayout_18->addLayout(horizontalLayout_19);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_7);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));

        horizontalLayout_18->addLayout(horizontalLayout_20);


        verticalLayout_8->addLayout(horizontalLayout_18);

        widget5 = new QWidget(gridLayoutWidget);
        widget5->setObjectName(QStringLiteral("widget5"));
        widget5->setMinimumSize(QSize(408, 341));
        widget5->setMaximumSize(QSize(408, 341));
        widget5->setStyleSheet(QStringLiteral("background:lightgray"));

        verticalLayout_8->addWidget(widget5);


        gridLayout->addLayout(verticalLayout_8, 1, 1, 1, 1);

        lb_PlcState2 = new QLabel(centralWidget);
        lb_PlcState2->setObjectName(QStringLiteral("lb_PlcState2"));
        lb_PlcState2->setGeometry(QRect(1310, 390, 81, 51));
        lb_PlcState2->setMinimumSize(QSize(0, 0));
        lb_PlcState2->setFont(font1);
        lb_PlcState2->setStyleSheet(QStringLiteral("background:red"));
        lb_PlcState2->setAlignment(Qt::AlignCenter);
        lb_PlcState3 = new QLabel(centralWidget);
        lb_PlcState3->setObjectName(QStringLiteral("lb_PlcState3"));
        lb_PlcState3->setGeometry(QRect(1310, 450, 81, 51));
        lb_PlcState3->setMinimumSize(QSize(0, 0));
        lb_PlcState3->setFont(font1);
        lb_PlcState3->setStyleSheet(QStringLiteral("background:red"));
        lb_PlcState3->setAlignment(Qt::AlignCenter);
        lb_PlcState4 = new QLabel(centralWidget);
        lb_PlcState4->setObjectName(QStringLiteral("lb_PlcState4"));
        lb_PlcState4->setGeometry(QRect(1310, 510, 81, 51));
        lb_PlcState4->setMinimumSize(QSize(0, 0));
        lb_PlcState4->setFont(font1);
        lb_PlcState4->setStyleSheet(QStringLiteral("background:red"));
        lb_PlcState4->setAlignment(Qt::AlignCenter);
        lb_PlcState5 = new QLabel(centralWidget);
        lb_PlcState5->setObjectName(QStringLiteral("lb_PlcState5"));
        lb_PlcState5->setGeometry(QRect(1310, 570, 81, 51));
        lb_PlcState5->setMinimumSize(QSize(0, 0));
        lb_PlcState5->setFont(font1);
        lb_PlcState5->setStyleSheet(QStringLiteral("background:red"));
        lb_PlcState5->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1440, 17));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(action_2);
        menu->addSeparator();
        menu->addAction(action_3);
        menu->addSeparator();
        menu->addAction(action_5);
        menu_2->addAction(action_set_param);
        menu_2->addSeparator();
        menu_2->addAction(action_connect_PLC);
        menu_2->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BJM5-D", Q_NULLPTR));
        action_set_param->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\350\256\276\347\275\256", Q_NULLPTR));
        action_2->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", Q_NULLPTR));
        action_3->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272", Q_NULLPTR));
        action_5->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
        action_connect_PLC->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245PLC", Q_NULLPTR));
        pb_Start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", Q_NULLPTR));
        pb_Stop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", Q_NULLPTR));
        lb_PlcState1->setText(QApplication::translate("MainWindow", "PLC1", Q_NULLPTR));
        label_cam2->setText(QApplication::translate("MainWindow", "Camera2\357\274\232", Q_NULLPTR));
        pb_connectCamera2->setText(QString());
        checkBox_Continuous2->setText(QApplication::translate("MainWindow", "\350\277\236\347\273\255\346\230\276\347\244\272", Q_NULLPTR));
        label_cam1->setText(QApplication::translate("MainWindow", "Camera1\357\274\232", Q_NULLPTR));
        pb_connectCamera1->setText(QString());
        checkBox_Continuous1->setText(QApplication::translate("MainWindow", "\350\277\236\347\273\255\346\230\276\347\244\272", Q_NULLPTR));
        label_cam3->setText(QApplication::translate("MainWindow", "Camera3\357\274\232", Q_NULLPTR));
        pb_connectCamera3->setText(QString());
        checkBox_Continuous3->setText(QApplication::translate("MainWindow", "\350\277\236\347\273\255\346\230\276\347\244\272", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\350\277\220\350\241\214\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        label_cam4->setText(QApplication::translate("MainWindow", "Camera4\357\274\232", Q_NULLPTR));
        pb_connectCamera4->setText(QString());
        checkBox_Continuous4->setText(QApplication::translate("MainWindow", "\350\277\236\347\273\255\346\230\276\347\244\272", Q_NULLPTR));
        label_cam5->setText(QApplication::translate("MainWindow", "Camera5\357\274\232", Q_NULLPTR));
        pb_connectCamera5->setText(QString());
        checkBox_Continuous5->setText(QApplication::translate("MainWindow", "\350\277\236\347\273\255\346\230\276\347\244\272", Q_NULLPTR));
        lb_PlcState2->setText(QApplication::translate("MainWindow", "PLC2", Q_NULLPTR));
        lb_PlcState3->setText(QApplication::translate("MainWindow", "PLC3", Q_NULLPTR));
        lb_PlcState4->setText(QApplication::translate("MainWindow", "PLC4", Q_NULLPTR));
        lb_PlcState5->setText(QApplication::translate("MainWindow", "PLC5", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\347\263\273\347\273\237", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
