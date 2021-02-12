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
    ui->stockViewButton->setIcon(QIcon("..\\..\\icons\\icons8-stocks-64.png"));
}

// MainWindow Deconstructor
MainWindow::~MainWindow() { delete ui; }