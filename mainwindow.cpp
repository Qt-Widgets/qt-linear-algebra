#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // set up our table widget
    int width = ui->matrix->verticalHeader()->width() + 4;

    for (int i = 0; i < ui->matrix->columnCount(); i++) {
        width += ui->matrix->columnWidth(i);
    }
    int height = ui->matrix->horizontalHeader()->height();
    for (int i = 0; i < ui->matrix->rowCount(); i++) {
        height += ui->matrix->rowHeight(i);
    }
    QSize matrixSize = QSize(width, height);
    ui->matrix->setMaximumSize(matrixSize);
    ui->matrix->setMinimumSize(matrixSize);


}

MainWindow::~MainWindow()
{
    delete ui;
}
