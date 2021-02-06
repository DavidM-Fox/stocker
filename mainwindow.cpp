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

    // Set default dates for data form
    ui->startDateEdit->setDate(QDate::currentDate());
    ui->endDateEdit->setDate(QDate::currentDate());

    connect(ui->getDataButton, &QPushButton::released, this, &MainWindow::on_getDataButton_clicked);
}

// MainWindow Deconstructor
MainWindow::~MainWindow()
{
    // Free imported ui from QT Designer
    delete ui;
}

// Constructs quote based on form data when "Get Data" is clicked and updates stock_data_tableView
void MainWindow::on_getDataButton_clicked()
{
    std::string symbol = ui->symbolComboBox->currentText().toUtf8().constData();
    stocker::quote* Quote = new stocker::quote
    (
        symbol,
        ui->startDateEdit->date().toString("yyyy-MM-dd").toUtf8().constData(),
        ui->endDateEdit->date().toString("yyyy-MM-dd").toUtf8().constData(),
        interval_convert(ui->intervalComboBox->currentText().toUtf8().constData())
    );

    Quote->print_quote_info();
    std::string output_file = "..\\..\\stock_data\\" + symbol + ".csv";
    Quote->download_quote_data(output_file);
    process_stock_data(output_file, symbol);

    delete Quote;
    Quote = NULL;

}

// Creates a model from downloaded .csv file and updates stock_data_tableView
void MainWindow::process_stock_data(std::string output_file, std::string t_symbol) 
{

    // Build model from stock data .csv file
    QStandardItemModel *model = new QStandardItemModel;
    QFile file(QString::fromStdString(output_file));
    if (file.open(QIODevice::ReadOnly))
    {

        int lineindex = 0;     // file line counter
        QTextStream in(&file); // read to text stream

        while (!in.atEnd())
        {

            // read one line from textstream(separated by "\n")
            QString fileLine = in.readLine();

            // parse the read line into separate pieces(tokens) with "," as the delimiter
            QStringList lineToken = fileLine.split(",", QString::SkipEmptyParts);

            // load parsed data to model accordingly
            for (int j = 0; j < lineToken.size(); j++)
            {
                QString value = lineToken.at(j);
                QStandardItem *item = new QStandardItem(value);
                model->setItem(lineindex, j, item);
            }

            lineindex++;   
        }

    file.close();
    }

    // Set headers for model
    model->removeRow(0);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Open"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("High"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Low"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Close"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adj Close"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Volume"));
    
    // Update table view
    ui->stock_data_tableView->setModel(model);
    ui->stock_data_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->stock_data_tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // // Create chart from model data
    // QChart *chart = new QChart();
    // chart->setAnimationOptions(QChart::AllAnimations);
    
    // QLineSeries *series = new QLineSeries();

    // series->setName(QString::fromStdString(t_symbol));

    // QVXYModelMapper *mapper = new QVXYModelMapper(this);

    // mapper->setXColumn(0);
    // mapper->setYColumn(1);
    // mapper->setSeries(series);
    // mapper->setModel(model);
    // chart->addSeries(series);

    // chart->createDefaultAxes();
    // QChartView *chartView = new QChartView(chart);
    // chartView->setRenderHint(QPainter::Antialiasing);
    // chartView->setParent(ui->chart_frame);
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