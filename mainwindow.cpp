#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // set the user interactions for the matrix plot
    //QCP::Interactions
    ui->matrixPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // define the first box
    QCPItemRect* matrix1 = new QCPItemRect(ui->matrixPlot);
    QPointF matrix1TopLeft(ui->matrix1->item(1, 0)->text().toDouble(), ui->matrix1->item(0, 0)->text().toDouble());
    QPointF matrix1BottomRight(ui->matrix1->item(1, 1)->text().toDouble(), ui->matrix1->item(0, 1)->text().toDouble());
    matrix1->topLeft->setCoords(matrix1TopLeft);
    matrix1->bottomRight->setCoords(matrix1BottomRight);

    ui->matrixPlot->replot();

    // clean up
    delete matrix1;
}
