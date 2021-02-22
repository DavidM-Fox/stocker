#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "avapi.h"
#include <QApplication>
#include <QDebug>
#include <QListWidgetItem>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void setupMainWindow();

private slots:
    void on_homeViewButton();
    void on_stockViewButton();
    void on_newStockButton();
    void on_newStockEdit();
    void toUpper(const QString &text);
    void onStockListItemClicked(QListWidgetItem *item);

private:
    static QString icon_dir;
    static QIcon icon_homeView;
    static QIcon icon_stockView;
    static QIcon icon_newSymbol;
};

#endif // MAINWINDOW_H