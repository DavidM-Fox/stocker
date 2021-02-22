#include "mainwindow.h"
#include "mainwindow_ui.h"

/**
 * @brief MainWindow constructor
 * @param parent The parent to reside over this widget
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
      icon_dir("C:/github/stocker/icons/"),
      icon_homeView(icon_dir + "icons8-home-64.png"),
      icon_stockView(icon_dir + "icons8-stocks-64.png"),
      icon_newSymbol(icon_dir + "icons8-plus-64.png")
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
    ui->stacked_appView->setCurrentIndex(appView::HOMEVIEW);

    // Set button icons
    ui->button_switchToHomeView->setIcon(icon_homeView);
    ui->button_switchToStockView->setIcon(icon_stockView);

    // Set Connections between SIGNALS and SLOTS
    connect(ui->action_exit, &QAction::triggered, this,
            &QCoreApplication::quit);
    connect(ui->button_switchToHomeView, &QPushButton::released, this,
            &MainWindow::on_switchToHomeViewButton);
    connect(ui->button_switchToStockView, &QPushButton::released, this,
            &MainWindow::on_switchToStockViewButton);

    // connect(ui->stockLineEdit, &QLineEdit::returnPressed, this,
    //         &MainWindow::on_newStockEdit);
    // connect(ui->stockLineEdit, SIGNAL(textChanged(const QString &)), this,
    //         SLOT(toUpper(const QString &)));
    // connect(ui->stockList, SIGNAL(itemClicked(QListWidgetItem *)), this,
    // SLOT(onStockListItemClicked(QListWidgetItem *)));
}

/**
 * @brief SLOT - When user clicks homeViewButton, switch to home view
 */
void MainWindow::on_switchToHomeViewButton()
{
    ui->stacked_appView->setCurrentIndex(appView::HOMEVIEW);
}

/**
 * @brief SLOT - When user clicks stockViewButton, switch to stock view
 */
void MainWindow::on_switchToStockViewButton()
{
    ui->stacked_appView->setCurrentIndex(appView::STOCKVIEW);
}

/**
 * @brief SLOT - When user clicks newStockButton, switch the newStockWidget
 * view to display stockLineEdit and clear the text within.
 */
// void MainWindow::on_newStockButton()
// {
// ui->newStockWidget->setCurrentIndex(1);
// ui->stockLineEdit->clear();
// }

/**
 * @brief SLOT - When user presses enter on stockLineEdit, adds the typed symbol
 * as a new QListWidgetItem to stockList and switches back to newStock view
 */
// void MainWindow::on_newStockEdit()
// {
// QListWidgetItem *new_item = new QListWidgetItem;
// new_item->setText(ui->stockLineEdit->text());
// ui->stockList->insertItem(0, new_item);
// ui->newStockWidget->setCurrentIndex(0);
// }

/**
 * @brief SLOT - Used for keeping text capitalized within stockLineEdit
 * @param text The current text within stockLineEdit
 */
// void MainWindow::toUpper(const QString &text)
// {
// QLineEdit *le = qobject_cast<QLineEdit *>(sender());
// if (!le)
// return;
// le->setText(text.toUpper());
// }
//
// /**
//  * @brief SLOT -
//  */
// void MainWindow::onStockListItemClicked(QListWidgetItem *item)
// {
// qDebug() << item->text();
// }
