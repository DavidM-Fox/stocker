#ifndef MAINWINDOW_H
#define MAINWINDOW_H
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

private slots:
    void on_exit();

    void on_homeViewButton();
    void on_stockViewButton();
    void on_newStockButton();
    void on_newStockEdit();
    void toUpper(const QString &text);
    void onStockListItemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;

    void configure_buttons();
    void configure_connections();
};

#endif // MAINWINDOW_H