/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOW_UI_H
#define MAINWINDOW_UI_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *viewSelectFrame;
    QVBoxLayout *verticalLayout;
    QPushButton *homeViewButton;
    QPushButton *stockViewButton;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *homeView;
    QGridLayout *gridLayout_2;
    QTextBrowser *textBrowser;
    QFormLayout *formLayout;
    QLabel *keyLabel;
    QLineEdit *keyLineEdit;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QWidget *stockView;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer;
    QFrame *stockFrame;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *newStockWidget;
    QWidget *page1;
    QGridLayout *gridLayout;
    QPushButton *newStockButton;
    QWidget *page2;
    QGridLayout *gridLayout_4;
    QLineEdit *stockLineEdit;
    QLabel *label;
    QListWidget *stockList;
    QSpacerItem *spacingView;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1020, 715);
        MainWindow->setMinimumSize(QSize(600, 600));
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setAutoFillBackground(false);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        viewSelectFrame = new QFrame(centralwidget);
        viewSelectFrame->setObjectName(QString::fromUtf8("viewSelectFrame"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(viewSelectFrame->sizePolicy().hasHeightForWidth());
        viewSelectFrame->setSizePolicy(sizePolicy1);
        viewSelectFrame->setMinimumSize(QSize(64, 0));
        viewSelectFrame->setMaximumSize(QSize(64, 16777215));
        viewSelectFrame->setAutoFillBackground(false);
        viewSelectFrame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background-color:rgb(51, 51, 51);\n"
"}\n"
"QPushButton:hover{\n"
"background-color:rgb(81, 81, 81);\n"
"}\n"
"QPushButton:checked{\n"
"background-color:rgb(20, 20, 20);\n"
"}\n"
"QPushButton{\n"
"background-color:rgb(51,51,51);\n"
"}\n"
"QPushButton{\n"
"border-style:none;\n"
"}\n"
""));
        viewSelectFrame->setFrameShape(QFrame::NoFrame);
        viewSelectFrame->setFrameShadow(QFrame::Plain);
        viewSelectFrame->setLineWidth(1);
        verticalLayout = new QVBoxLayout(viewSelectFrame);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        homeViewButton = new QPushButton(viewSelectFrame);
        homeViewButton->setObjectName(QString::fromUtf8("homeViewButton"));
        homeViewButton->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(homeViewButton->sizePolicy().hasHeightForWidth());
        homeViewButton->setSizePolicy(sizePolicy2);
        homeViewButton->setMinimumSize(QSize(64, 48));
        homeViewButton->setMaximumSize(QSize(64, 48));
        homeViewButton->setBaseSize(QSize(64, 48));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icons/icons8-home-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        homeViewButton->setIcon(icon);
        homeViewButton->setIconSize(QSize(32, 32));
        homeViewButton->setCheckable(true);
        homeViewButton->setChecked(true);
        homeViewButton->setAutoExclusive(true);
        homeViewButton->setFlat(false);

        verticalLayout->addWidget(homeViewButton);

        stockViewButton = new QPushButton(viewSelectFrame);
        stockViewButton->setObjectName(QString::fromUtf8("stockViewButton"));
        stockViewButton->setEnabled(true);
        sizePolicy2.setHeightForWidth(stockViewButton->sizePolicy().hasHeightForWidth());
        stockViewButton->setSizePolicy(sizePolicy2);
        stockViewButton->setMinimumSize(QSize(64, 48));
        stockViewButton->setMaximumSize(QSize(64, 48));
        stockViewButton->setBaseSize(QSize(64, 48));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../icons/icons8-stocks-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        stockViewButton->setIcon(icon1);
        stockViewButton->setIconSize(QSize(32, 32));
        stockViewButton->setCheckable(true);
        stockViewButton->setChecked(false);
        stockViewButton->setAutoExclusive(true);

        verticalLayout->addWidget(stockViewButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(viewSelectFrame);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy3);
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        homeView = new QWidget();
        homeView->setObjectName(QString::fromUtf8("homeView"));
        homeView->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(homeView->sizePolicy().hasHeightForWidth());
        homeView->setSizePolicy(sizePolicy4);
        homeView->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 39, 40);\n"
"color: rgb(255, 255, 255);"));
        gridLayout_2 = new QGridLayout(homeView);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(homeView);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy5);
        textBrowser->setAutoFillBackground(false);
        textBrowser->setFrameShape(QFrame::NoFrame);
        textBrowser->setFrameShadow(QFrame::Plain);
        textBrowser->setOpenExternalLinks(false);

        gridLayout_2->addWidget(textBrowser, 1, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        keyLabel = new QLabel(homeView);
        keyLabel->setObjectName(QString::fromUtf8("keyLabel"));
        keyLabel->setAutoFillBackground(false);

        formLayout->setWidget(0, QFormLayout::LabelRole, keyLabel);

        keyLineEdit = new QLineEdit(homeView);
        keyLineEdit->setObjectName(QString::fromUtf8("keyLineEdit"));
        sizePolicy5.setHeightForWidth(keyLineEdit->sizePolicy().hasHeightForWidth());
        keyLineEdit->setSizePolicy(sizePolicy5);

        formLayout->setWidget(0, QFormLayout::FieldRole, keyLineEdit);


        gridLayout_2->addLayout(formLayout, 2, 1, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_6, 0, 1, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_7, 3, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        stackedWidget->addWidget(homeView);
        stockView = new QWidget();
        stockView->setObjectName(QString::fromUtf8("stockView"));
        stockView->setStyleSheet(QString::fromUtf8("background-color: rgb(25, 25, 25);"));
        gridLayout_3 = new QGridLayout(stockView);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 1, 1, 1);

        stockFrame = new QFrame(stockView);
        stockFrame->setObjectName(QString::fromUtf8("stockFrame"));
        QSizePolicy sizePolicy6(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(stockFrame->sizePolicy().hasHeightForWidth());
        stockFrame->setSizePolicy(sizePolicy6);
        stockFrame->setMinimumSize(QSize(30, 0));
        stockFrame->setMaximumSize(QSize(100, 16777215));
        stockFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 39, 40);\n"
"border-color: rgb(255, 255, 255);\n"
"color: rgb(255, 255, 255);"));
        verticalLayout_2 = new QVBoxLayout(stockFrame);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        newStockWidget = new QStackedWidget(stockFrame);
        newStockWidget->setObjectName(QString::fromUtf8("newStockWidget"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(newStockWidget->sizePolicy().hasHeightForWidth());
        newStockWidget->setSizePolicy(sizePolicy7);
        newStockWidget->setFrameShape(QFrame::NoFrame);
        newStockWidget->setLineWidth(0);
        page1 = new QWidget();
        page1->setObjectName(QString::fromUtf8("page1"));
        gridLayout = new QGridLayout(page1);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        newStockButton = new QPushButton(page1);
        newStockButton->setObjectName(QString::fromUtf8("newStockButton"));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(newStockButton->sizePolicy().hasHeightForWidth());
        newStockButton->setSizePolicy(sizePolicy8);
        newStockButton->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"background-color:rgb(81, 81, 81);\n"
"}\n"
"QPushButton{\n"
"border-style:none;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../icons/icons8-plus-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        newStockButton->setIcon(icon2);
        newStockButton->setIconSize(QSize(32, 32));

        gridLayout->addWidget(newStockButton, 0, 0, 1, 1);

        newStockWidget->addWidget(page1);
        page2 = new QWidget();
        page2->setObjectName(QString::fromUtf8("page2"));
        gridLayout_4 = new QGridLayout(page2);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        stockLineEdit = new QLineEdit(page2);
        stockLineEdit->setObjectName(QString::fromUtf8("stockLineEdit"));
        sizePolicy1.setHeightForWidth(stockLineEdit->sizePolicy().hasHeightForWidth());
        stockLineEdit->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(14);
        stockLineEdit->setFont(font);
        stockLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit:hover{\n"
"background-color:rgb(81, 81, 81);\n"
"}"));

        gridLayout_4->addWidget(stockLineEdit, 0, 0, 1, 1);

        newStockWidget->addWidget(page2);

        verticalLayout_2->addWidget(newStockWidget, 0, Qt::AlignTop);

        label = new QLabel(stockFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFrameShape(QFrame::Panel);
        label->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(label, 0, Qt::AlignVCenter);

        stockList = new QListWidget(stockFrame);
        stockList->setObjectName(QString::fromUtf8("stockList"));
        sizePolicy1.setHeightForWidth(stockList->sizePolicy().hasHeightForWidth());
        stockList->setSizePolicy(sizePolicy1);
        stockList->setFrameShape(QFrame::NoFrame);
        stockList->setFrameShadow(QFrame::Plain);
        stockList->setLineWidth(0);
        stockList->setMidLineWidth(0);
        stockList->setSortingEnabled(true);

        verticalLayout_2->addWidget(stockList);


        gridLayout_3->addWidget(stockFrame, 0, 0, 1, 1);

        stackedWidget->addWidget(stockView);

        horizontalLayout->addWidget(stackedWidget);

        spacingView = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacingView);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setEnabled(true);
        menubar->setGeometry(QRect(0, 0, 1020, 20));
        menubar->setAutoFillBackground(false);
        menubar->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"color:rgb(255, 255, 255);\n"
"\n"
"QMenubar:::QMenu:selected{\n"
"background:rgb(81, 81, 81);\n"
"}"));
        menubar->setDefaultUp(false);
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuFile->setStyleSheet(QString::fromUtf8("QMenu::item:selected{\n"
"background:rgb(81, 81, 81);\n"
"}"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);
        newStockWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Stocker", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(tooltip)
        homeViewButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Switch to Home View</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        homeViewButton->setText(QString());
#if QT_CONFIG(tooltip)
        stockViewButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Switch to stock view</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        stockViewButton->setText(QString());
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">-------------------------------------</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:28pt; font-weight:600;\">Stocker</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">-------------------------------------</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt"
                        "-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">A desktop application built with C++ and QT5 for viewing historical stock data pulled from Alpha Vantage</span></p></body></html>", nullptr));
        keyLabel->setText(QCoreApplication::translate("MainWindow", "Alpha Vantage API Key", nullptr));
        keyLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter key...", nullptr));
#if QT_CONFIG(tooltip)
        newStockButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Add a new stock</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        newStockButton->setText(QString());
        stockLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Symbol", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Stocks</p></body></html>", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOW_UI_H
