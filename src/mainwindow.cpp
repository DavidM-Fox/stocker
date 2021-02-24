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
      icon_newSymbol(icon_dir + "icons8-plus-64.png"), m_apiKey("")
{
    // Import ui from QT Designer
    ui->setupUi(this);
    setupMainWindow();
    ui->frame_stockInfo->hide();

    try {
        m_apiKey = avapi::readFirstLineFromFile("../../api.key");
        qDebug()
            << "Success: Api.key file found within project root directory.";
    }
    catch (...) {
        qDebug()
            << "Exception: Unable to find or open an api.key in project root "
               "directory.";
    }
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
    connect(ui->lineEdit_apiKey, &QLineEdit::returnPressed, this,
            &MainWindow::on_newApiKey);
    connect(ui->lineEdit_symbol, &QLineEdit::returnPressed, this,
            &MainWindow::on_newSymbol);
    connect(ui->lineEdit_symbol, SIGNAL(textChanged(const QString &)), this,
            SLOT(toUpper(const QString &)));

    connect(ui->comboBox_seriesType, SIGNAL(activated(const int &)), this,
            SLOT(setSeriesType(const int &)));

    connect(ui->comboBox_candleCount, SIGNAL(activated(const int &)), this,
            SLOT(setCandleCount(const int &)));

    connect(ui->button_updateChart, &QPushButton::released, this,
            &MainWindow::on_updateChart);
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

void MainWindow::on_newApiKey()
{
    m_apiKey = ui->lineEdit_apiKey->text().toStdString();
}

/**
 * @brief SLOT - When user presses enter on stockLineEdit, adds the typed symbol
 * as a new QListWidgetItem to stockList and switches back to newStock view
 *
 * @todo Add exception handling for when symbol is incorrect
 */
void MainWindow::on_newSymbol()
{
    if (m_apiKey == "") {
        QMessageBox dialog(this);
        dialog.setText("An Alpha Vantage API key is not set.");
        dialog.exec();
    }
    else {
        qDebug() << "Success: An API Key was found to use for avapi::quote";
        std::string symbol = ui->lineEdit_symbol->text().toStdString();
        avapi::Quote quote(symbol, m_apiKey);
        avapi::time_pair global_quote;
        avapi::time_series series;

        // Catch
        try {
            global_quote = quote.getGlobalQuote();
            series = quote.getTimeSeries(avapi::INTRADAY, 10, "15min");
        }
        catch (...) {
            qDebug() << "An exception occured when trying to get symbol data: "
                        "Incorrect API key, stock symbol, or connection error.";
            QMessageBox dialog(this);
            dialog.setText("Incorrect API Key/Symbol, or max number of queries "
                           "reached last minute (Max 5 per minute).");
            dialog.exec();
            return;
        }

        ui->label_symbolField->setText(QString::fromStdString(symbol));
        ui->label_latestDayField->setText(
            QDateTime::fromSecsSinceEpoch(global_quote.first)
                .toString("yyyy-MM-dd"));
        ui->label_openField->setText(QString::number(global_quote.second[0]));
        ui->label_highField->setText(QString::number(global_quote.second[1]));
        ui->label_lowField->setText(QString::number(global_quote.second[2]));
        ui->label_priceField->setText(QString::number(global_quote.second[3]));
        ui->label_volumeField->setText(QString::number(global_quote.second[4]));
        ui->label_previousCloseField->setText(
            QString::number(global_quote.second[5]));
        ui->label_changeField->setText(QString::number(global_quote.second[6]));
        ui->label_changePercentField->setText(
            QString::number(global_quote.second[7]));

        ui->frame_stockInfo->show();

        if (m_chartView == NULL) {

            // Creating the initial chart view
            m_chartView = new QCandlestickChartView();
            m_chartView->setChartTitle(QString::fromStdString(symbol));
            m_chartView->addAvapiSeries(
                series, QString::fromStdString("Intraday"), avapi::INTRADAY);
            m_chartView->setViewDefaults();
            m_chartView->setChartDefaults();
            ui->layout_chartView->addWidget(m_chartView);
        }
        else {
            // Change Chart Data
            m_chartView->chart()->removeAllSeries();
            m_chartView->setChartTitle(QString::fromStdString(symbol));
            m_chartView->addAvapiSeries(
                series, QString::fromStdString("Intraday"), avapi::DAILY);
            m_chartView->setViewDefaults();
            m_chartView->setChartDefaults();
        }
    }
}

/**
 * @brief SLOT - Used for keeping lineEdit_symbol->text() capitalized
 * @param text The current text within lineEdit_symbol
 */
void MainWindow::toUpper(const QString &text)
{
    QLineEdit *le = qobject_cast<QLineEdit *>(sender());
    if (!le)
        return;
    le->setText(text.toUpper());
}

/**
 * @brief SLOT - Set m_seriesType and m_intradayInterval when
 * comboBox_seriesType is activated
 * @param i The combo box index
 */
void MainWindow::setSeriesType(const int &i)
{
    // Set m_seriesType function
    m_seriesTitle = m_seriesTitleVect[i];
    m_seriesType = m_seriesTypeVect[i];
    m_intradayInterval = m_intradayIntervalVect[i];
}

/**
 * @brief SLOT - Set m_candleCount when
 * comboBox_candleCount is activated
 * @param i The combo box index
 */
void MainWindow::setCandleCount(const int &i)
{
    m_candleCount = m_candleCountVect[i];
}

void MainWindow::on_updateChart()
{
    // Create new quote object
    std::string symbol = ui->label_symbolField->text().toStdString();
    avapi::Quote quote(symbol, m_apiKey);
    avapi::time_series series;

    // Try to get new time series
    try {
        series = quote.getTimeSeries(m_seriesType, m_candleCount,
                                     m_intradayInterval);
    }
    catch (...) {
        qDebug() << "An exception occured when trying to get symbol data: "
                    "Cannot query Alpha Vantage server. Either no connection "
                    "or too many API calls in last minute.";
        QMessageBox dialog(this);
        dialog.setText("Max number of queries "
                       "reached last minute (Max 5 per minute).");
        dialog.exec();
        return;
    }

    // Remove Last Chart
    ui->layout_chartView->removeWidget(m_chartView);
    delete m_chartView;
    m_chartView = new QCandlestickChartView();

    // Change Chart Data
    // m_chartView->chart()->removeAllSeries();
    m_chartView->setChartTitle(QString::fromStdString(symbol));
    m_chartView->addAvapiSeries(series, m_seriesTitle, m_seriesType);
    m_chartView->setViewDefaults();
    m_chartView->setChartDefaults();
    ui->layout_chartView->addWidget(m_chartView);
}

std::vector<QString> MainWindow::m_seriesTitleVect{
    QString::fromStdString("Intraday 15min"),
    QString::fromStdString("Intraday 30min"), QString::fromStdString("Daily"),
    QString::fromStdString("Weekly"), QString::fromStdString("Monthly")};
std::vector<avapi::function> MainWindow::m_seriesTypeVect{
    avapi::INTRADAY, avapi::INTRADAY, avapi::DAILY, avapi::WEEKLY,
    avapi::MONTHLY};
std::vector<std::string> MainWindow::m_intradayIntervalVect{"15min", "30min",
                                                            "", "", ""};
std::vector<size_t> MainWindow::m_candleCountVect{10, 30, 60, 100, 0};