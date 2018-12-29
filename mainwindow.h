#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QMainWindow>
#include <QString>

#include "dice.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pbMinute_clicked();

    void on_pbTenMin_clicked();

    void on_pbHalfHour_clicked();

    void on_pbHour_clicked();

    void on_pbWatch_clicked();

    void on_pbLongRest_clicked();

    void on_pbMorning_clicked();


    void on_pbRandMorn_clicked();

    void on_pbRandDay_clicked();

    void on_pbRandNight_clicked();

private:
    Ui::MainWindow *ui;

    void _advanceMinute(int amt);
    void _advanceHour(int amt);
    void _advanceDay(int amt);
    void _advanceMonth(int amt);
    int _getMaxDays(int month);
    void _setHourName();
};

#endif // MAINWINDOW_H
