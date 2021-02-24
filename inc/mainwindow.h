#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "QCandlestickChart.h"
#include "avapi.h"
#include <QApplication>
#include <QDebug>
#include <QMainWindow>
#include <QWidget>
#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace appView {
enum view { HOMEVIEW = 0, STOCKVIEW };
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void setupMainWindow();

private slots:
    void on_switchToHomeViewButton();
    void on_switchToStockViewButton();
    void on_newApiKey();
    void on_newSymbol();
    void toUpper(const QString &text);

    void setSeriesType(const int &i);
    void setCandleCount(const int &i);
    void on_updateChart();

private:
    QString icon_dir;
    QIcon icon_homeView;
    QIcon icon_stockView;
    QIcon icon_newSymbol;

    std::string m_apiKey;
    QCandlestickChartView *m_chartView = nullptr;

    QString m_seriesTitle;
    avapi::function m_seriesType;
    std::string m_intradayInterval;
    size_t m_candleCount;

    static std::vector<QString> m_seriesTitleVect;
    static std::vector<avapi::function> m_seriesTypeVect;
    static std::vector<std::string> m_intradayIntervalVect;
    static std::vector<size_t> m_candleCountVect;
};

#endif // MAINWINDOW_H