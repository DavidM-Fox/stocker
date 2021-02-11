#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "include/stockerAPI.hpp"
#include <QDebug>

// MainWindow Constructor for stocker application
MainWindow::MainWindow(QWidget *parent) : 
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Import ui from QT Designer
    ui->setupUi(this);

    set_ui_defaults();
    // set_connects();
}

// MainWindow Deconstructor
MainWindow::~MainWindow()
{
    // Free imported ui from QT Designer
    delete ui;
}

void MainWindow::set_ui_defaults() 
{
    // Set default dates for data form
    ui->startDateEdit->setDate(QDate::currentDate());
    ui->endDateEdit->setDate(QDate::currentDate());
}

void MainWindow::set_connects() 
{
    connect(ui->getDataButton, &QPushButton::released, this, &MainWindow::on_getDataButton_clicked);
}

// Constructs quote based on form data when "Get Data" is clicked and updates stock_data_tableView
void MainWindow::on_getDataButton_clicked()
{
    std::string ticker = ui->tickerLineEdit->text().toUtf8().constData();
    stocker::quote* Quote = new stocker::quote
    (
        ticker,
        ui->startDateEdit->date().toString("yyyy-MM-dd").toUtf8().constData(),
        ui->endDateEdit->date().toString("yyyy-MM-dd").toUtf8().constData(),
        interval_convert(ui->intervalComboBox->currentText().toUtf8().constData())
    );

    Quote->print_quote_info();
    std::string output_file = "..\\..\\stock_data\\" + ticker + ".csv";
    Quote->download_quote_data(output_file);
    // int test = process_stock_data(output_file, ticker);

    delete Quote;
    Quote = NULL;
}

// Creates a model from downloaded .csv file and updates stock_data_tableView
int MainWindow::process_stock_data(std::string output_file, std::string t_symbol) 
{
    // Build model from stock data .csv file
    QStandardItemModel *model = new QStandardItemModel;
    QStringList categories;
    QFile file(QString::fromStdString(output_file));
    if (file.open(QIODevice::ReadOnly))
    {

        int lineindex = 0;     // file line counter
        QTextStream in(&file); // read to text stream

        while (!in.atEnd())
        {
            // read one line from textstream(separated by "\n")
            QString line = in.readLine();

            // Skip csv header line
            if (line.startsWith("Date"))
                continue;

            // parse the read line into separate pieces(tokens)
            QStringList lineToken = line.split(",");

            // load parsed data to model accordingly
            for (int j = 0; j < lineToken.size(); j++)
            {
                QString value = lineToken.at(j);
                if (j == 0)
                {
                    categories << value;
                }
                QStandardItem *item = new QStandardItem(value);
                model->setItem(lineindex, j, item);
            }
            lineindex++;   
        }
    file.close();
    }
    else
    {
        return -1;
    }

    // Set headers for model
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Open"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("High"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Low"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Close"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adj Close"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Volume"));
/*    
    // Update table view
    ui->stock_data_tableView->setModel(model);
    ui->stock_data_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->stock_data_tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
*/
    // Create candlestick series
    QCandlestickSeries *series = new QCandlestickSeries();
    series->setName(QString::fromStdString(output_file));
    series->setIncreasingColor(QColor(Qt::green));
    series->setDecreasingColor(QColor(Qt::red));



    QHCandlestickModelMapper *mapper = new QHCandlestickModelMapper();
    mapper->setModel(model);
    mapper->setFirstSetRow(1);
    mapper->setTimestampColumn(0);
    mapper->setOpenColumn(1);
    mapper->setHighColumn(2);
    mapper->setLowColumn(3);
    mapper->setCloseColumn(4);
    mapper->setSeries(series);
    // mapper->lastSetRow(line_index)

    QChart *chart = new QChart();
    chart->addSeries(series);
    std::string chart_title = t_symbol + " Historical Data";
    chart->setTitle(QString::fromStdString(chart_title));
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->createDefaultAxes();

    chart->createDefaultAxes();

    QBarCategoryAxis *axisX = qobject_cast<QBarCategoryAxis *>(chart->axes(Qt::Horizontal).at(0));
    axisX->setCategories(categories);

    QValueAxis *axisY = qobject_cast<QValueAxis *>(chart->axes(Qt::Vertical).at(0));
    axisY->setMax(axisY->max() * 1.01);
    axisY->setMin(axisY->min() * 0.99);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->gridLayout->addWidget(chartView,0,1);

    return 1;

}


// Converts interval string to proper format
std::string MainWindow::interval_convert(std::string from) 
{
    std::string to;
    
    if(from == "Daily")
        to = "1d";
    else if(from == "Weekly")
        to = "1wk";
    else if(from == "Monthly")
        to = "1mo";
    
    return to;
}