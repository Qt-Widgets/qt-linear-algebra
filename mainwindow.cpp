#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    vec1(nullptr),
    vec2(nullptr)
{
    ui->setupUi(this);

    // set the user interactions for the matrix plot
    ui->mainGraph->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


    vec1 = new QCPItemLine(ui->mainGraph);
    vec1->setPen(QPen(QColor(66, 244, 66)));
    vec1->setHead(QCPLineEnding::esSpikeArrow);
    vec1->start->setCoords(0, 0);
    vec1->end->setCoords(0, 0);

    vec2 = new QCPItemLine(ui->mainGraph);
    vec2->setPen(QPen(QColor(244, 66, 66)));
    vec2->setHead(QCPLineEnding::esSpikeArrow);
    vec2->start->setCoords(0, 0);
    vec2->end->setCoords(0, 0);
}

MainWindow::~MainWindow()
{
    delete vec1;
    delete vec2;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QPointF vp1(ui->vector1->item(0, 0)->text().toDouble(), ui->vector1->item(1, 0)->text().toDouble());
    QPointF vp2(ui->vector2->item(0, 0)->text().toDouble(), ui->vector2->item(1, 0)->text().toDouble());
    vec1->end->setCoords(vp1);
    vec2->end->setCoords(vp2);
    ui->mainGraph->replot();
}
