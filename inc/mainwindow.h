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

private:
    QString icon_dir;
    QIcon icon_homeView;
    QIcon icon_stockView;
    QIcon icon_newSymbol;

    std::string m_apiKey;
    QCandlestickChartView *m_chartView = nullptr;
};

#endif // MAINWINDOW_H