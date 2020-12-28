/********************************************************************************
** Form generated from reading UI file 'selectcity.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTCITY_H
#define UI_SELECTCITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectCity
{
public:
    QGridLayout *gridLayout_4;
    QStackedWidget *stackedWidget;
    QWidget *CityWidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_5;
    QListView *listCity;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *RefreshCity;
    QPushButton *BackSetCityButton;
    QWidget *UniversityWidget;
    QGridLayout *gridLayout_13;
    QGridLayout *gridLayout_6;
    QPushButton *BackSetUniversityButton;
    QGridLayout *gridLayout_14;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton;
    QListView *listUniver;
    QWidget *SpecialtyWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_7;
    QPushButton *BackSetSpecialtyButton;
    QListView *listSpecialty;
    QGridLayout *gridLayout_12;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QWidget *CourseWidget;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_15;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *BackSetCourseButton;
    QListView *listCourse;
    QWidget *RatingsWidget;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout_10;
    QTableView *tableRatings;
    QPushButton *BackRatingsButton;
    QHBoxLayout *horizontalLayout;
    QLineEdit *GetGroup;
    QLineEdit *GetNameStudent;
    QPushButton *Reset;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *SelectCity)
    {
        if (SelectCity->objectName().isEmpty())
            SelectCity->setObjectName(QString::fromUtf8("SelectCity"));
        SelectCity->resize(1049, 661);
        SelectCity->setMinimumSize(QSize(400, 100));
        SelectCity->setStyleSheet(QString::fromUtf8("QPushButton#BackSetUniversityButton  {\n"
"background-color: rgb(26, 37, 255);\n"
"}\n"
"\n"
"QPushButton#BackSetSpecialtyButton{\n"
"background-color: rgb(26, 37, 255);\n"
"}\n"
"\n"
"QPushButton#BackSetCourseButton{\n"
"background-color: rgb(26, 37, 255);\n"
"}\n"
"\n"
"QPushButton#BackRatingsButton{\n"
"background-color: rgb(26, 37, 255);\n"
"}\n"
"\n"
"QTableView {\n"
"	background-color: rgb(255, 255, 255);\n"
"	alternate-background-color: rgb(200, 200, 200);\n"
"}"));
        gridLayout_4 = new QGridLayout(SelectCity);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        stackedWidget = new QStackedWidget(SelectCity);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        CityWidget = new QWidget();
        CityWidget->setObjectName(QString::fromUtf8("CityWidget"));
        CityWidget->setMinimumSize(QSize(400, 100));
        gridLayout_3 = new QGridLayout(CityWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(10);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(5, 10, 5, 5);
        listCity = new QListView(CityWidget);
        listCity->setObjectName(QString::fromUtf8("listCity"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listCity->sizePolicy().hasHeightForWidth());
        listCity->setSizePolicy(sizePolicy);
        listCity->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(16);
        listCity->setFont(font);

        gridLayout_5->addWidget(listCity, 1, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        RefreshCity = new QPushButton(CityWidget);
        RefreshCity->setObjectName(QString::fromUtf8("RefreshCity"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(RefreshCity->sizePolicy().hasHeightForWidth());
        RefreshCity->setSizePolicy(sizePolicy1);
        RefreshCity->setMinimumSize(QSize(100, 40));
        RefreshCity->setMaximumSize(QSize(100, 40));

        gridLayout->addWidget(RefreshCity, 0, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout, 0, 1, 1, 1);

        BackSetCityButton = new QPushButton(CityWidget);
        BackSetCityButton->setObjectName(QString::fromUtf8("BackSetCityButton"));
        BackSetCityButton->setMinimumSize(QSize(50, 20));
        BackSetCityButton->setMaximumSize(QSize(100, 40));
        QFont font1;
        font1.setPointSize(26);
        BackSetCityButton->setFont(font1);
        BackSetCityButton->setCursor(QCursor(Qt::OpenHandCursor));
        BackSetCityButton->setLayoutDirection(Qt::LeftToRight);
        BackSetCityButton->setIconSize(QSize(16, 16));
        BackSetCityButton->setAutoRepeat(false);
        BackSetCityButton->setAutoRepeatDelay(300);
        BackSetCityButton->setAutoRepeatInterval(100);

        gridLayout_5->addWidget(BackSetCityButton, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_5, 0, 0, 1, 1);

        stackedWidget->addWidget(CityWidget);
        UniversityWidget = new QWidget();
        UniversityWidget->setObjectName(QString::fromUtf8("UniversityWidget"));
        UniversityWidget->setMinimumSize(QSize(400, 100));
        gridLayout_13 = new QGridLayout(UniversityWidget);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(10);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(5, 10, 5, 5);
        BackSetUniversityButton = new QPushButton(UniversityWidget);
        BackSetUniversityButton->setObjectName(QString::fromUtf8("BackSetUniversityButton"));
        BackSetUniversityButton->setMinimumSize(QSize(50, 20));
        BackSetUniversityButton->setMaximumSize(QSize(100, 40));
        BackSetUniversityButton->setFont(font1);
        BackSetUniversityButton->setCursor(QCursor(Qt::OpenHandCursor));

        gridLayout_6->addWidget(BackSetUniversityButton, 0, 0, 1, 1);

        gridLayout_14 = new QGridLayout();
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_14->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_14->addItem(horizontalSpacer_4, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_14->addItem(horizontalSpacer_5, 0, 2, 1, 1);

        pushButton = new QPushButton(UniversityWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMinimumSize(QSize(100, 40));
        pushButton->setMaximumSize(QSize(100, 40));

        gridLayout_14->addWidget(pushButton, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_14, 0, 1, 1, 1);

        listUniver = new QListView(UniversityWidget);
        listUniver->setObjectName(QString::fromUtf8("listUniver"));
        listUniver->setFont(font);

        gridLayout_6->addWidget(listUniver, 1, 1, 1, 1);


        gridLayout_13->addLayout(gridLayout_6, 0, 0, 1, 1);

        stackedWidget->addWidget(UniversityWidget);
        SpecialtyWidget = new QWidget();
        SpecialtyWidget->setObjectName(QString::fromUtf8("SpecialtyWidget"));
        gridLayout_2 = new QGridLayout(SpecialtyWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(10);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 10, 5, 0);
        BackSetSpecialtyButton = new QPushButton(SpecialtyWidget);
        BackSetSpecialtyButton->setObjectName(QString::fromUtf8("BackSetSpecialtyButton"));
        BackSetSpecialtyButton->setMinimumSize(QSize(50, 20));
        BackSetSpecialtyButton->setMaximumSize(QSize(100, 40));
        BackSetSpecialtyButton->setFont(font1);
        BackSetSpecialtyButton->setCursor(QCursor(Qt::OpenHandCursor));

        gridLayout_7->addWidget(BackSetSpecialtyButton, 0, 0, 1, 1);

        listSpecialty = new QListView(SpecialtyWidget);
        listSpecialty->setObjectName(QString::fromUtf8("listSpecialty"));
        sizePolicy.setHeightForWidth(listSpecialty->sizePolicy().hasHeightForWidth());
        listSpecialty->setSizePolicy(sizePolicy);
        listSpecialty->setFont(font);

        gridLayout_7->addWidget(listSpecialty, 1, 1, 1, 1);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(10, -1, 10, -1);
        pushButton_2 = new QPushButton(SpecialtyWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setMinimumSize(QSize(100, 40));
        pushButton_2->setMaximumSize(QSize(100, 40));

        gridLayout_12->addWidget(pushButton_2, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_12->addItem(horizontalSpacer_6, 0, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_12->addItem(horizontalSpacer_7, 0, 2, 1, 1);


        gridLayout_7->addLayout(gridLayout_12, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout_7, 0, 0, 1, 1);

        stackedWidget->addWidget(SpecialtyWidget);
        CourseWidget = new QWidget();
        CourseWidget->setObjectName(QString::fromUtf8("CourseWidget"));
        gridLayout_9 = new QGridLayout(CourseWidget);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(10);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 10, 5, 0);
        gridLayout_15 = new QGridLayout();
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_15->setContentsMargins(10, -1, 10, -1);
        pushButton_3 = new QPushButton(CourseWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        pushButton_3->setMinimumSize(QSize(100, 40));
        pushButton_3->setMaximumSize(QSize(100, 40));

        gridLayout_15->addWidget(pushButton_3, 0, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_15->addItem(horizontalSpacer_8, 0, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_15->addItem(horizontalSpacer_9, 0, 2, 1, 1);


        gridLayout_8->addLayout(gridLayout_15, 0, 1, 1, 1);

        BackSetCourseButton = new QPushButton(CourseWidget);
        BackSetCourseButton->setObjectName(QString::fromUtf8("BackSetCourseButton"));
        BackSetCourseButton->setMinimumSize(QSize(50, 20));
        BackSetCourseButton->setMaximumSize(QSize(100, 40));
        BackSetCourseButton->setFont(font1);
        BackSetCourseButton->setCursor(QCursor(Qt::OpenHandCursor));

        gridLayout_8->addWidget(BackSetCourseButton, 0, 0, 1, 1);

        listCourse = new QListView(CourseWidget);
        listCourse->setObjectName(QString::fromUtf8("listCourse"));
        listCourse->setFont(font);

        gridLayout_8->addWidget(listCourse, 1, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_8, 0, 0, 1, 1);

        stackedWidget->addWidget(CourseWidget);
        RatingsWidget = new QWidget();
        RatingsWidget->setObjectName(QString::fromUtf8("RatingsWidget"));
        gridLayout_11 = new QGridLayout(RatingsWidget);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(10);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 10, 5, 0);
        tableRatings = new QTableView(RatingsWidget);
        tableRatings->setObjectName(QString::fromUtf8("tableRatings"));
        tableRatings->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(10);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableRatings->sizePolicy().hasHeightForWidth());
        tableRatings->setSizePolicy(sizePolicy2);
        tableRatings->setMinimumSize(QSize(0, 0));
        tableRatings->setMaximumSize(QSize(16777215, 16777215));
        tableRatings->setSizeIncrement(QSize(0, 0));
        tableRatings->setFont(font);
        tableRatings->setFocusPolicy(Qt::StrongFocus);
        tableRatings->setAutoFillBackground(false);
        tableRatings->setLineWidth(1);
        tableRatings->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableRatings->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        tableRatings->setAlternatingRowColors(true);
        tableRatings->setTextElideMode(Qt::ElideMiddle);
        tableRatings->setShowGrid(false);
        tableRatings->setGridStyle(Qt::NoPen);
        tableRatings->setSortingEnabled(true);
        tableRatings->setWordWrap(false);
        tableRatings->setCornerButtonEnabled(false);
        tableRatings->horizontalHeader()->setCascadingSectionResizes(false);
        tableRatings->horizontalHeader()->setMinimumSectionSize(100);
        tableRatings->horizontalHeader()->setDefaultSectionSize(150);
        tableRatings->horizontalHeader()->setHighlightSections(false);
        tableRatings->horizontalHeader()->setStretchLastSection(false);
        tableRatings->verticalHeader()->setVisible(false);

        gridLayout_10->addWidget(tableRatings, 1, 1, 1, 1);

        BackRatingsButton = new QPushButton(RatingsWidget);
        BackRatingsButton->setObjectName(QString::fromUtf8("BackRatingsButton"));
        BackRatingsButton->setMinimumSize(QSize(50, 20));
        BackRatingsButton->setMaximumSize(QSize(100, 40));
        BackRatingsButton->setFont(font1);
        BackRatingsButton->setCursor(QCursor(Qt::OpenHandCursor));
        BackRatingsButton->setAutoFillBackground(false);

        gridLayout_10->addWidget(BackRatingsButton, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 0, 20, 0);
        GetGroup = new QLineEdit(RatingsWidget);
        GetGroup->setObjectName(QString::fromUtf8("GetGroup"));
        GetGroup->setMinimumSize(QSize(75, 30));
        GetGroup->setMaximumSize(QSize(200, 50));

        horizontalLayout->addWidget(GetGroup);

        GetNameStudent = new QLineEdit(RatingsWidget);
        GetNameStudent->setObjectName(QString::fromUtf8("GetNameStudent"));
        GetNameStudent->setMinimumSize(QSize(75, 30));
        GetNameStudent->setMaximumSize(QSize(200, 50));

        horizontalLayout->addWidget(GetNameStudent);

        Reset = new QPushButton(RatingsWidget);
        Reset->setObjectName(QString::fromUtf8("Reset"));
        Reset->setMinimumSize(QSize(100, 40));
        Reset->setMaximumSize(QSize(100, 40));
        QFont font2;
        font2.setPointSize(8);
        Reset->setFont(font2);
        Reset->setCursor(QCursor(Qt::OpenHandCursor));

        horizontalLayout->addWidget(Reset);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_10->addLayout(horizontalLayout, 0, 1, 1, 1);


        gridLayout_11->addLayout(gridLayout_10, 0, 0, 1, 1);

        stackedWidget->addWidget(RatingsWidget);

        gridLayout_4->addWidget(stackedWidget, 0, 0, 1, 1);


        retranslateUi(SelectCity);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(SelectCity);
    } // setupUi

    void retranslateUi(QDialog *SelectCity)
    {
        SelectCity->setWindowTitle(QCoreApplication::translate("SelectCity", "Dialog", nullptr));
        RefreshCity->setText(QCoreApplication::translate("SelectCity", "City", nullptr));
        BackSetCityButton->setText(QCoreApplication::translate("SelectCity", "\342\206\220\n"
"", nullptr));
        BackSetUniversityButton->setText(QCoreApplication::translate("SelectCity", "\342\206\220", nullptr));
        pushButton->setText(QCoreApplication::translate("SelectCity", "University", nullptr));
        BackSetSpecialtyButton->setText(QCoreApplication::translate("SelectCity", "\342\206\220", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SelectCity", "Specialty", nullptr));
        pushButton_3->setText(QCoreApplication::translate("SelectCity", "Course", nullptr));
        BackSetCourseButton->setText(QCoreApplication::translate("SelectCity", "\342\206\220", nullptr));
        BackRatingsButton->setText(QCoreApplication::translate("SelectCity", "\342\206\220\n"
"", nullptr));
        GetGroup->setPlaceholderText(QCoreApplication::translate("SelectCity", "Search group", nullptr));
        GetNameStudent->setPlaceholderText(QCoreApplication::translate("SelectCity", "Search Student name", nullptr));
        Reset->setText(QCoreApplication::translate("SelectCity", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectCity: public Ui_SelectCity {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTCITY_H
