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
    QAction *action_exit;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_selectAppView;
    QVBoxLayout *verticalLayout;
    QPushButton *button_switchToHomeView;
    QPushButton *button_switchToStockView;
    QSpacerItem *vspacer1;
    QStackedWidget *stacked_appView;
    QWidget *page_homeView;
    QGridLayout *gridLayout_2;
    QTextBrowser *textBrowser_homeInfo;
    QFormLayout *form_apiKey;
    QLabel *label_api;
    QLineEdit *lineEdit_apiKey;
    QSpacerItem *vspacer2;
    QSpacerItem *vspacer3;
    QSpacerItem *hspacer1;
    QSpacerItem *hspacer2;
    QWidget *page_stockView;
    QGridLayout *gridLayout_3;
    QMenuBar *menu_bar;
    QMenu *menu_file;
    QStatusBar *status_bar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1020, 715);
        MainWindow->setMinimumSize(QSize(600, 600));
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setAutoFillBackground(false);
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
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
        frame_selectAppView = new QFrame(centralwidget);
        frame_selectAppView->setObjectName(QString::fromUtf8("frame_selectAppView"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_selectAppView->sizePolicy().hasHeightForWidth());
        frame_selectAppView->setSizePolicy(sizePolicy1);
        frame_selectAppView->setMinimumSize(QSize(64, 0));
        frame_selectAppView->setMaximumSize(QSize(64, 16777215));
        frame_selectAppView->setAutoFillBackground(false);
        frame_selectAppView->setStyleSheet(QString::fromUtf8("QFrame{\n"
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
        frame_selectAppView->setFrameShape(QFrame::NoFrame);
        frame_selectAppView->setFrameShadow(QFrame::Plain);
        frame_selectAppView->setLineWidth(1);
        verticalLayout = new QVBoxLayout(frame_selectAppView);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        button_switchToHomeView = new QPushButton(frame_selectAppView);
        button_switchToHomeView->setObjectName(QString::fromUtf8("button_switchToHomeView"));
        button_switchToHomeView->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(button_switchToHomeView->sizePolicy().hasHeightForWidth());
        button_switchToHomeView->setSizePolicy(sizePolicy2);
        button_switchToHomeView->setMinimumSize(QSize(64, 48));
        button_switchToHomeView->setMaximumSize(QSize(64, 48));
        button_switchToHomeView->setBaseSize(QSize(64, 48));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icons/icons8-home-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_switchToHomeView->setIcon(icon);
        button_switchToHomeView->setIconSize(QSize(32, 32));
        button_switchToHomeView->setCheckable(true);
        button_switchToHomeView->setChecked(true);
        button_switchToHomeView->setAutoExclusive(true);
        button_switchToHomeView->setFlat(false);

        verticalLayout->addWidget(button_switchToHomeView);

        button_switchToStockView = new QPushButton(frame_selectAppView);
        button_switchToStockView->setObjectName(QString::fromUtf8("button_switchToStockView"));
        button_switchToStockView->setEnabled(true);
        sizePolicy2.setHeightForWidth(button_switchToStockView->sizePolicy().hasHeightForWidth());
        button_switchToStockView->setSizePolicy(sizePolicy2);
        button_switchToStockView->setMinimumSize(QSize(64, 48));
        button_switchToStockView->setMaximumSize(QSize(64, 48));
        button_switchToStockView->setBaseSize(QSize(64, 48));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../icons/icons8-stocks-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_switchToStockView->setIcon(icon1);
        button_switchToStockView->setIconSize(QSize(32, 32));
        button_switchToStockView->setCheckable(true);
        button_switchToStockView->setChecked(false);
        button_switchToStockView->setAutoExclusive(true);

        verticalLayout->addWidget(button_switchToStockView);

        vspacer1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(vspacer1);


        horizontalLayout->addWidget(frame_selectAppView);

        stacked_appView = new QStackedWidget(centralwidget);
        stacked_appView->setObjectName(QString::fromUtf8("stacked_appView"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(stacked_appView->sizePolicy().hasHeightForWidth());
        stacked_appView->setSizePolicy(sizePolicy3);
        stacked_appView->setStyleSheet(QString::fromUtf8(""));
        page_homeView = new QWidget();
        page_homeView->setObjectName(QString::fromUtf8("page_homeView"));
        page_homeView->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(page_homeView->sizePolicy().hasHeightForWidth());
        page_homeView->setSizePolicy(sizePolicy4);
        page_homeView->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 39, 40);\n"
"color: rgb(255, 255, 255);"));
        gridLayout_2 = new QGridLayout(page_homeView);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        textBrowser_homeInfo = new QTextBrowser(page_homeView);
        textBrowser_homeInfo->setObjectName(QString::fromUtf8("textBrowser_homeInfo"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(textBrowser_homeInfo->sizePolicy().hasHeightForWidth());
        textBrowser_homeInfo->setSizePolicy(sizePolicy5);
        textBrowser_homeInfo->setAutoFillBackground(false);
        textBrowser_homeInfo->setFrameShape(QFrame::NoFrame);
        textBrowser_homeInfo->setFrameShadow(QFrame::Plain);
        textBrowser_homeInfo->setOpenExternalLinks(false);

        gridLayout_2->addWidget(textBrowser_homeInfo, 1, 1, 1, 1);

        form_apiKey = new QFormLayout();
        form_apiKey->setObjectName(QString::fromUtf8("form_apiKey"));
        label_api = new QLabel(page_homeView);
        label_api->setObjectName(QString::fromUtf8("label_api"));
        label_api->setAutoFillBackground(false);

        form_apiKey->setWidget(0, QFormLayout::LabelRole, label_api);

        lineEdit_apiKey = new QLineEdit(page_homeView);
        lineEdit_apiKey->setObjectName(QString::fromUtf8("lineEdit_apiKey"));
        sizePolicy5.setHeightForWidth(lineEdit_apiKey->sizePolicy().hasHeightForWidth());
        lineEdit_apiKey->setSizePolicy(sizePolicy5);

        form_apiKey->setWidget(0, QFormLayout::FieldRole, lineEdit_apiKey);


        gridLayout_2->addLayout(form_apiKey, 2, 1, 1, 1);

        vspacer2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(vspacer2, 0, 1, 1, 1);

        vspacer3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(vspacer3, 3, 1, 1, 1);

        hspacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(hspacer1, 1, 0, 1, 1);

        hspacer2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(hspacer2, 1, 2, 1, 1);

        stacked_appView->addWidget(page_homeView);
        page_stockView = new QWidget();
        page_stockView->setObjectName(QString::fromUtf8("page_stockView"));
        page_stockView->setStyleSheet(QString::fromUtf8("background-color: rgb(25, 25, 25);"));
        gridLayout_3 = new QGridLayout(page_stockView);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        stacked_appView->addWidget(page_stockView);

        horizontalLayout->addWidget(stacked_appView);

        MainWindow->setCentralWidget(centralwidget);
        menu_bar = new QMenuBar(MainWindow);
        menu_bar->setObjectName(QString::fromUtf8("menu_bar"));
        menu_bar->setEnabled(true);
        menu_bar->setGeometry(QRect(0, 0, 1020, 20));
        menu_bar->setAutoFillBackground(false);
        menu_bar->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"color:rgb(255, 255, 255);\n"
"\n"
"QMenubar:::QMenu:selected{\n"
"background:rgb(81, 81, 81);\n"
"}"));
        menu_bar->setDefaultUp(false);
        menu_file = new QMenu(menu_bar);
        menu_file->setObjectName(QString::fromUtf8("menu_file"));
        menu_file->setStyleSheet(QString::fromUtf8("QMenu::item:selected{\n"
"background:rgb(81, 81, 81);\n"
"}"));
        MainWindow->setMenuBar(menu_bar);
        status_bar = new QStatusBar(MainWindow);
        status_bar->setObjectName(QString::fromUtf8("status_bar"));
        status_bar->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);"));
        MainWindow->setStatusBar(status_bar);

        menu_bar->addAction(menu_file->menuAction());
        menu_file->addAction(action_exit);

        retranslateUi(MainWindow);

        stacked_appView->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Stocker", nullptr));
        action_exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(tooltip)
        button_switchToHomeView->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Switch to Home View</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        button_switchToHomeView->setText(QString());
#if QT_CONFIG(tooltip)
        button_switchToStockView->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Switch to stock view</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        button_switchToStockView->setText(QString());
        textBrowser_homeInfo->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">-------------------------------------</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:28pt; font-weight:600;\">Stocker</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">-------------------------------------</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt"
                        "-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">A desktop application built with C++ and QT5 for viewing historical stock data pulled from Alpha Vantage</span></p></body></html>", nullptr));
        label_api->setText(QCoreApplication::translate("MainWindow", "Alpha Vantage API Key", nullptr));
        lineEdit_apiKey->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter key...", nullptr));
        menu_file->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOW_UI_H
