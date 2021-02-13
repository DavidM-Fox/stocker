#include "../inc/mainwindow.h"
#include "../inc/stocker_api.hpp"
#include "../inc/./ui_mainwindow.h"
#include "../inc/QCandlestickChart.h"

// MainWindow Constructor for stocker application
MainWindow::MainWindow(QWidget *parent) : 
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Import ui from QT Designer
    ui->setupUi(this);
    ui->homeViewButton->setIcon(QIcon("..\\..\\icons\\icons8-home-64.png"));
    ui->stockViewButton->setIcon(QIcon("..\\..\\icons\\icons8-stocks-64.png"));
    ui->dataViewButton->setIcon(QIcon("..\\..\\icons\\icons8-data-grid-64.png"));
    
    configure_buttons();
}

// MainWindow Deconstructor
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::configure_buttons()
{
    ui->homeViewButton->setIcon(QIcon("..\\..\\icons\\icons8-home-64.png"));
    ui->stockViewButton->setIcon(QIcon("..\\..\\icons\\icons8-stocks-64.png"));
    ui->dataViewButton->setIcon(QIcon("..\\..\\icons\\icons8-data-grid-64.png"));

    // connect(ui->homeViewButton, ui->homeViewButton->&QPushButton::isChecked, this, &MainWindow::on_homeViewButton());
    // connect(ui->stockViewButton, &QPushButton::isChecked, this, &MainWindow::on_stockViewButton());
    // connect(ui->dataViewButton, &QPushButton::isChecked, this, &MainWindow::on_dataViewButton());
    
    connect(ui->homeViewButton, &QPushButton::released, this, &MainWindow::on_homeViewButton);
    connect(ui->stockViewButton, &QPushButton::released, this, &MainWindow::on_stockViewButton);
    connect(ui->dataViewButton, &QPushButton::released, this, &MainWindow::on_dataViewButton);
}

void MainWindow::on_homeViewButton()
{
    ui->homeFrame->show();
    
}

void MainWindow::on_stockViewButton()
{
    ui->homeFrame->hide();
}

void MainWindow::on_dataViewButton()
{
    ui->homeFrame->hide();
}