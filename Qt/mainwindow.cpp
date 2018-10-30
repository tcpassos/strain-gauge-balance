#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //*** GRAFICO ***//
    for (int i=0; i<100; i++)
    {
      x.push_back(i);
      y.push_back(0);
    }
    ui->graph->addGraph();
    ui->graph->graph(0)->setData(x, y);
    ui->graph->graph(0)->setPen(QPen(Qt::green));
    ui->graph->graph(0)->setBrush(QBrush(QColor(0, 200, 100, 100)));
    ui->graph->xAxis->setLabel("tempo (s)");
    ui->graph->yAxis->setLabel("peso (g)");
    ui->graph->xAxis->setRange(0, 100);
    ui->graph->yAxis->setRange(-120, 120);
    ui->graph->setInteraction(QCP::iRangeDrag, true);
    ui->graph->setInteraction(QCP::iRangeZoom, true);
    ui->graph->replot();

    //** TIMER **//
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000/ui->freq->value());
}

void MainWindow::update(){
    y[x.size() - 1] = static_cast<double>(ui->peso->value())/10;

    for (int i = 1; i < x.size(); i++){
      y[i-1] = y[i];
    }

    ui->graph->graph(0)->setData(x, y);
    ui->graph->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_freq_valueChanged(int value)
{
    timer->setInterval(1000/value);
}
