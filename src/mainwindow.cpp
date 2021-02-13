#include "../inc/mainwindow.h"
#include "../inc/./ui_mainwindow.h"
#include "../inc/QCandlestickChart.h"
#include "../inc/stocker_api.hpp"

// MainWindow Constructor for stocker application
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // Import ui from QT Designer
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    configure_buttons();
    configure_connections();
}

// MainWindow Deconstructor
MainWindow::~MainWindow() { delete ui; }

// Slots for signals

void MainWindow::on_exit() { QCoreApplication::quit(); }
void MainWindow::on_homeViewButton() { ui->stackedWidget->setCurrentIndex(0); }
void MainWindow::on_stockViewButton()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->newStockWidget->setCurrentIndex(0);
}
void MainWindow::on_newStockButton()
{
    ui->newStockWidget->setCurrentIndex(1);
    ui->stockLineEdit->clear();
}
void MainWindow::on_newStockEdit()
{
    QListWidgetItem *new_item = new QListWidgetItem;
    new_item->setText(ui->stockLineEdit->text());
    ui->stockList->insertItem(0, new_item);
    ui->newStockWidget->setCurrentIndex(0);
}
void MainWindow::toUpper(const QString &text)
{
    QLineEdit *le = qobject_cast<QLineEdit *>(sender());
    if (!le)
        return;
    le->setText(text.toUpper());
}

void MainWindow::onStockListItemClicked(QListWidgetItem *item)
{
    qDebug() << item->text();
}

void MainWindow::configure_buttons()
{
    QIcon homeIcon = QIcon("..\\..\\icons\\icons8-home-64.png");
    QIcon stockIcon = QIcon("..\\..\\icons\\icons8-stocks-64.png");
    QIcon newIcon = QIcon("C:/github/stocker/icons/icons8-plus-64.png");

    ui->homeViewButton->setIcon(homeIcon);
    ui->stockViewButton->setIcon(stockIcon);
    ui->newStockButton->setIcon(newIcon);
}

void MainWindow::configure_connections()
{
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::on_exit);

    connect(ui->homeViewButton, &QPushButton::released, this,
            &MainWindow::on_homeViewButton);
    connect(ui->stockViewButton, &QPushButton::released, this,
            &MainWindow::on_stockViewButton);
    connect(ui->newStockButton, &QPushButton::released, this,
            &MainWindow::on_newStockButton);

    connect(ui->stockLineEdit, &QLineEdit::returnPressed, this,
            &MainWindow::on_newStockEdit);
    connect(ui->stockLineEdit, SIGNAL(textChanged(const QString &)), this,
            SLOT(toUpper(const QString &)));

    connect(ui->stockList, SIGNAL(itemClicked(QListWidgetItem *)), this,
            SLOT(onStockListItemClicked(QListWidgetItem *)));
}