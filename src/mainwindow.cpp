#include "mainwindow.h"
#include "mainwindow_ui.h"

/**
 * @brief MainWindow constructor
 * @param parent The parent to reside over this widget
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // Import ui from QT Designer
    ui->setupUi(this);
    setupMainWindow();

    avapi::Quote quote("GME", avapi::readFirstLineFromFile("../../api.key"));
    avapi::time_series series = quote.getTimeSeries(avapi::DAILY, 20);
    avapi::printSeries(series);
}

/**
 * @brief MainWindow Deconstructor, frees ui from QT Designer
 */
MainWindow::~MainWindow() { delete ui; }

/**
 * @brief Configures the ui and logic for the application
 */
void MainWindow::setupMainWindow()
{
    // Set opening view to home
    ui->stackedWidget->setCurrentIndex(0);

    // Set button icons
    ui->homeViewButton->setIcon(icon_homeView);
    ui->stockViewButton->setIcon(icon_stockView);
    ui->newStockButton->setIcon(icon_newSymbol);

    // Set Connections between SIGNALS and SLOTS
    connect(ui->actionExit, &QAction::triggered, this, &QCoreApplication::quit);
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

/**
 * @brief SLOT - When user clicks homeViewButton, switch to home view
 */
void MainWindow::on_homeViewButton() { ui->stackedWidget->setCurrentIndex(0); }

/**
 * @brief SLOT - When user clicks stockViewButton, switch to stock view
 */
void MainWindow::on_stockViewButton()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->newStockWidget->setCurrentIndex(0);
}

/**
 * @brief SLOT - When user clicks newStockButton, switch the newStockWidget
 * view to display stockLineEdit and clear the text within.
 */
void MainWindow::on_newStockButton()
{
    ui->newStockWidget->setCurrentIndex(1);
    ui->stockLineEdit->clear();
}

/**
 * @brief SLOT - When user presses enter on stockLineEdit, adds the typed symbol
 * as a new QListWidgetItem to stockList and switches back to newStock view
 */
void MainWindow::on_newStockEdit()
{
    QListWidgetItem *new_item = new QListWidgetItem;
    new_item->setText(ui->stockLineEdit->text());
    ui->stockList->insertItem(0, new_item);
    ui->newStockWidget->setCurrentIndex(0);
}

/**
 * @brief SLOT - Used for keeping text capitalized within stockLineEdit
 * @param text The current text within stockLineEdit
 */
void MainWindow::toUpper(const QString &text)
{
    QLineEdit *le = qobject_cast<QLineEdit *>(sender());
    if (!le)
        return;
    le->setText(text.toUpper());
}

/**
 * @brief SLOT -
 */
void MainWindow::onStockListItemClicked(QListWidgetItem *item)
{
    qDebug() << item->text();
}

QString MainWindow::icon_dir("C:/github/stocker/icons/");
QIcon MainWindow::icon_homeView(icon_dir + "icons8-home-64.png");
QIcon MainWindow::icon_stockView(icon_dir + "icons8-stocks-64.png");
QIcon MainWindow::icon_newSymbol(icon_dir + "icons8-plus-64.png");