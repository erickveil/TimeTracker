#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pbMinute_clicked()
{
    _advanceMinute(1);
    _setHourName();
}

void MainWindow::on_pbTenMin_clicked()
{
    _advanceMinute(10);
    _setHourName();
}

void MainWindow::on_pbHalfHour_clicked()
{
    _advanceMinute(30);
    _setHourName();
}

void MainWindow::on_pbHour_clicked()
{
    _advanceHour(1);
    _setHourName();
}

void MainWindow::on_pbWatch_clicked()
{
    _advanceHour(4);
    _setHourName();
}

void MainWindow::on_pbLongRest_clicked()
{
    _advanceHour(8);
    _setHourName();
}

void MainWindow::on_pbMorning_clicked()
{
    _advanceDay(1);
    on_pbRandMorn_clicked();
    _setHourName();
}

void MainWindow::_advanceMinute(int amt)
{
    int min = ui->sbMin->value();
    min += amt;
    if (min > 59) {
        _advanceHour(1);
        min = min-60;
        ui->sbMin->setValue(0);
        _advanceMinute(min);
        return;
    }
    ui->sbMin->setValue(min);
}

void MainWindow::_advanceHour(int amt)
{
    int hour = ui->sbDayHour->value();
    hour += amt;
    if (hour > 23) {
        _advanceDay(1);
        hour = hour - 24;
        ui->sbDayHour->setValue(0);
        _advanceHour(hour);
        return;
    }

    ui->sbDayHour->setValue(hour);

    if (hour == 0) { ui->sbHour->setValue(12); }
    else if (hour > 12) { ui->sbHour->setValue(hour - 12); }
    else { ui->sbHour->setValue(hour); }
}

void MainWindow::_advanceDay(int amt)
{
    int day = ui->sbDay->value();
    day += amt;
    int maxDays = _getMaxDays(ui->sbMonth->value());
    if (day > maxDays) {
        _advanceMonth(1);
        day = day - (maxDays + 1);
        ui->sbDay->setValue(0);
        _advanceDay(day);
        return;
    }

    ui->sbDay->setValue(day);
}

void MainWindow::_advanceMonth(int amt)
{
    int month = ui->sbMonth->value();
    month += amt;
    if (month > 12) {
        month = month - 12;
        ui->sbMonth->setValue(0);
        _advanceMonth(month);
        return;
    }
    ui->sbMonth->setValue(month);
}

int MainWindow::_getMaxDays(int month)
{
    // Long months: 1, 4, 7, 9, 11
    if ( month == 1 || month == 4 || month == 7 || month == 9 || month == 11 ) {
        return 31;
    }
    return 30;
}

void MainWindow::_setHourName()
{
    /*
     *              1	2	3	4	5	6	7	8	9	10	11	12
     * 1 Midnight	0	0	0	0	0	0	0	0	0	0	0	0
     * 2 Moondark	1	1	1	1	1	1	1	1	1	1	1	1
     * 3 Nightend	9	8	8	7	7	6	6	7	7	8	8	9
     * 4 Dawn		10	9	9	8	8	7	7	8	8	9	9	10
     * 5 Morning	11	10	10	9	9	8	8	9	9	10	10	11
     * 6 Highsun	12	12	12	12	12	12	12	12	12	12	12	12
     * 7 Afternoon	1	1	1	1	1	1	1	1	1	1	1	1
     * 8 Midday		2	3	3	4	4	5	5	4	4	3	3	2
     * 9 Evening	4	5	5	6	6	7	7	6	6	5	5	4
     * 10 Sunset	5	6	6	7	7	8	8	7	7	6	6	5
     * 11 Night		6	7	7	8	8	9	9	8	8	7	7	6
     */

}

void MainWindow::on_pbRandMorn_clicked()
{
    int hour = Dice::randomNumber(5, 9);
    ui->sbMin->setValue(0);
    ui->sbHour->setValue(hour);
    ui->sbDayHour->setValue(hour);
}

void MainWindow::on_pbRandDay_clicked()
{
    int hour = Dice::randomNumber(13, 19);
    ui->sbMin->setValue(0);
    ui->sbDayHour->setValue(hour);
    ui->sbHour->setValue(hour - 12);
}

void MainWindow::on_pbRandNight_clicked()
{
    int hour = Dice::randomNumber(20, 23);
    ui->sbMin->setValue(0);
    ui->sbDayHour->setValue(hour);
    ui->sbHour->setValue(hour - 12);

}
