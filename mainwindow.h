#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private:
        Ui::MainWindow *ui;

        void set_ui_defaults();
        void set_connects();

        void on_getDataButton_clicked();
        int process_stock_data(std::string output_file, std::string t_symbol);
        std::string interval_convert(std::string from);


};

#endif // MAINWINDOW_H
