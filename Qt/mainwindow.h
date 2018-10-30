#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void update();

private slots:
    void on_freq_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QVector<double> x, y;
};

#endif // MAINWINDOW_H
