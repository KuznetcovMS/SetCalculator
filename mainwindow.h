#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "set.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_PB_UDef_clicked();

    void on_PB_UClear_clicked();

    void on_PB_USort_clicked();

    void on_PB_AClear_clicked();

    void on_PB_ASort_clicked();

    void on_PB_BClear_clicked();

    void on_PB_BSort_clicked();

    void on_PB_Calculate_clicked();

private:
    Ui::MainWindow *ui;
    Set A;
    Set B;
    Set res;

};
#endif // MAINWINDOW_H
