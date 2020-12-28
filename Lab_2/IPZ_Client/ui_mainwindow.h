/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_5;
    QStackedWidget *stackedWidget;
    QWidget *LoginWidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QPushButton *ExitButton;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *verticalSpacer_4;
    QPushButton *LoginButton;
    QPushButton *RegisterButton;
    QSpacerItem *horizontalSpacer_16;
    QGridLayout *gridLayout_4;
    QLineEdit *GetLogin;
    QLineEdit *GetPass;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QWidget *RegisterWidget;
    QGridLayout *gridLayout_13;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout_6;
    QPushButton *RegisterWidgetButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QLineEdit *LoginRegisterWidget;
    QLineEdit *PassRegisterWidget;
    QLineEdit *ConfirmPassRegisterWidget;
    QGridLayout *gridLayout_12;
    QPushButton *BackRegisterWidget;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(742, 466);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"\n"
"background-color: rgb(26, 37, 255);}\n"
"\n"
"QPushButton{\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(114, 255, 20);\n"
"border-radius:15px;}\n"
"\n"
"QPushButton#BackRegisterWidget{\n"
"background-color: rgb(26, 37, 255);\n"
"\n"
"}\n"
"\n"
"QPushButton#BackSetCityButton{\n"
"background-color: rgb(26, 37, 255);\n"
"}\n"
"\n"
"QLineEdit{\n"
"	color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 254, 237);\n"
"border-radius:15px;\n"
"	\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_5 = new QGridLayout(centralwidget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setVerticalSpacing(0);
        gridLayout_5->setContentsMargins(-1, -1, -1, 0);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        LoginWidget = new QWidget();
        LoginWidget->setObjectName(QString::fromUtf8("LoginWidget"));
        LoginWidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout_3 = new QGridLayout(LoginWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(20, 20, 20, 20);
        ExitButton = new QPushButton(LoginWidget);
        ExitButton->setObjectName(QString::fromUtf8("ExitButton"));
        sizePolicy.setHeightForWidth(ExitButton->sizePolicy().hasHeightForWidth());
        ExitButton->setSizePolicy(sizePolicy);
        ExitButton->setMinimumSize(QSize(100, 25));
        ExitButton->setMaximumSize(QSize(200, 40));
        ExitButton->setCursor(QCursor(Qt::OpenHandCursor));
        ExitButton->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(ExitButton, 2, 1, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_15, 1, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 3, 1, 1, 1);

        LoginButton = new QPushButton(LoginWidget);
        LoginButton->setObjectName(QString::fromUtf8("LoginButton"));
        sizePolicy.setHeightForWidth(LoginButton->sizePolicy().hasHeightForWidth());
        LoginButton->setSizePolicy(sizePolicy);
        LoginButton->setMinimumSize(QSize(100, 25));
        LoginButton->setMaximumSize(QSize(200, 40));
        LoginButton->setCursor(QCursor(Qt::OpenHandCursor));

        gridLayout_2->addWidget(LoginButton, 0, 1, 1, 1);

        RegisterButton = new QPushButton(LoginWidget);
        RegisterButton->setObjectName(QString::fromUtf8("RegisterButton"));
        sizePolicy.setHeightForWidth(RegisterButton->sizePolicy().hasHeightForWidth());
        RegisterButton->setSizePolicy(sizePolicy);
        RegisterButton->setMinimumSize(QSize(100, 25));
        RegisterButton->setMaximumSize(QSize(200, 40));
        RegisterButton->setCursor(QCursor(Qt::OpenHandCursor));

        gridLayout_2->addWidget(RegisterButton, 1, 1, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_16, 1, 0, 1, 1);

        gridLayout_2->setRowStretch(0, 10);
        gridLayout_2->setRowStretch(1, 10);
        gridLayout_2->setRowStretch(2, 10);
        gridLayout_2->setRowStretch(3, 1);
        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 3);
        gridLayout_2->setColumnStretch(2, 1);

        gridLayout->addLayout(gridLayout_2, 1, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(20, 20, 20, 20);
        GetLogin = new QLineEdit(LoginWidget);
        GetLogin->setObjectName(QString::fromUtf8("GetLogin"));
        sizePolicy.setHeightForWidth(GetLogin->sizePolicy().hasHeightForWidth());
        GetLogin->setSizePolicy(sizePolicy);
        GetLogin->setMinimumSize(QSize(250, 25));
        GetLogin->setMaximumSize(QSize(500, 50));
        GetLogin->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(GetLogin, 1, 1, 1, 1);

        GetPass = new QLineEdit(LoginWidget);
        GetPass->setObjectName(QString::fromUtf8("GetPass"));
        sizePolicy.setHeightForWidth(GetPass->sizePolicy().hasHeightForWidth());
        GetPass->setSizePolicy(sizePolicy);
        GetPass->setMinimumSize(QSize(250, 25));
        GetPass->setMaximumSize(QSize(500, 50));
        GetPass->setEchoMode(QLineEdit::Password);
        GetPass->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        GetPass->setClearButtonEnabled(false);

        gridLayout_4->addWidget(GetPass, 2, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        gridLayout_4->setRowStretch(0, 1);
        gridLayout_4->setRowStretch(1, 2);
        gridLayout_4->setRowStretch(2, 2);
        gridLayout_4->setColumnStretch(0, 1);
        gridLayout_4->setColumnStretch(1, 1);
        gridLayout_4->setColumnStretch(2, 1);

        gridLayout->addLayout(gridLayout_4, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        stackedWidget->addWidget(LoginWidget);
        RegisterWidget = new QWidget();
        RegisterWidget->setObjectName(QString::fromUtf8("RegisterWidget"));
        gridLayout_13 = new QGridLayout(RegisterWidget);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(20, 20, 20, 20);
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(20, 20, 20, 20);
        RegisterWidgetButton = new QPushButton(RegisterWidget);
        RegisterWidgetButton->setObjectName(QString::fromUtf8("RegisterWidgetButton"));
        sizePolicy.setHeightForWidth(RegisterWidgetButton->sizePolicy().hasHeightForWidth());
        RegisterWidgetButton->setSizePolicy(sizePolicy);
        RegisterWidgetButton->setMinimumSize(QSize(100, 25));
        RegisterWidgetButton->setMaximumSize(QSize(250, 50));
        RegisterWidgetButton->setCursor(QCursor(Qt::OpenHandCursor));

        gridLayout_6->addWidget(RegisterWidgetButton, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer, 1, 1, 1, 1);


        gridLayout_11->addLayout(gridLayout_6, 3, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, -1, -1);
        LoginRegisterWidget = new QLineEdit(RegisterWidget);
        LoginRegisterWidget->setObjectName(QString::fromUtf8("LoginRegisterWidget"));
        sizePolicy.setHeightForWidth(LoginRegisterWidget->sizePolicy().hasHeightForWidth());
        LoginRegisterWidget->setSizePolicy(sizePolicy);
        LoginRegisterWidget->setMinimumSize(QSize(200, 25));
        LoginRegisterWidget->setMaximumSize(QSize(600, 50));

        verticalLayout->addWidget(LoginRegisterWidget);

        PassRegisterWidget = new QLineEdit(RegisterWidget);
        PassRegisterWidget->setObjectName(QString::fromUtf8("PassRegisterWidget"));
        sizePolicy.setHeightForWidth(PassRegisterWidget->sizePolicy().hasHeightForWidth());
        PassRegisterWidget->setSizePolicy(sizePolicy);
        PassRegisterWidget->setMinimumSize(QSize(200, 25));
        PassRegisterWidget->setMaximumSize(QSize(600, 50));
        PassRegisterWidget->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        verticalLayout->addWidget(PassRegisterWidget);

        ConfirmPassRegisterWidget = new QLineEdit(RegisterWidget);
        ConfirmPassRegisterWidget->setObjectName(QString::fromUtf8("ConfirmPassRegisterWidget"));
        sizePolicy.setHeightForWidth(ConfirmPassRegisterWidget->sizePolicy().hasHeightForWidth());
        ConfirmPassRegisterWidget->setSizePolicy(sizePolicy);
        ConfirmPassRegisterWidget->setMinimumSize(QSize(200, 25));
        ConfirmPassRegisterWidget->setMaximumSize(QSize(600, 50));
        ConfirmPassRegisterWidget->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        ConfirmPassRegisterWidget->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(ConfirmPassRegisterWidget);


        gridLayout_11->addLayout(verticalLayout, 2, 1, 1, 1);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        BackRegisterWidget = new QPushButton(RegisterWidget);
        BackRegisterWidget->setObjectName(QString::fromUtf8("BackRegisterWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(BackRegisterWidget->sizePolicy().hasHeightForWidth());
        BackRegisterWidget->setSizePolicy(sizePolicy1);
        BackRegisterWidget->setMinimumSize(QSize(50, 20));
        BackRegisterWidget->setMaximumSize(QSize(100, 40));
        QFont font;
        font.setPointSize(26);
        BackRegisterWidget->setFont(font);
        BackRegisterWidget->setCursor(QCursor(Qt::OpenHandCursor));

        gridLayout_12->addWidget(BackRegisterWidget, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_12->addItem(horizontalSpacer_5, 0, 1, 1, 1);


        gridLayout_11->addLayout(gridLayout_12, 0, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_6, 3, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_11->addItem(verticalSpacer_5, 1, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_7, 2, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_11->addItem(verticalSpacer_2, 4, 1, 1, 1);

        gridLayout_11->setRowStretch(1, 1);
        gridLayout_11->setRowStretch(2, 5);
        gridLayout_11->setRowStretch(3, 5);

        gridLayout_13->addLayout(gridLayout_11, 0, 0, 1, 1);

        stackedWidget->addWidget(RegisterWidget);

        gridLayout_5->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ExitButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        LoginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        RegisterButton->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        GetLogin->setText(QString());
        GetLogin->setPlaceholderText(QCoreApplication::translate("MainWindow", "Login", nullptr));
#if QT_CONFIG(accessibility)
        GetPass->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        GetPass->setInputMask(QString());
        GetPass->setText(QString());
        GetPass->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        RegisterWidgetButton->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        LoginRegisterWidget->setPlaceholderText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        PassRegisterWidget->setPlaceholderText(QCoreApplication::translate("MainWindow", "Pass", nullptr));
        ConfirmPassRegisterWidget->setPlaceholderText(QCoreApplication::translate("MainWindow", "Confirm pass", nullptr));
        BackRegisterWidget->setText(QCoreApplication::translate("MainWindow", "\342\206\220\n"
"", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
