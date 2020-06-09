#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_closeButton_clicked()
{
    QApplication::quit();
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this, "About Qt");
}

void MainWindow::on_BlenderPathSelect_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Select Blender installation folder", QDir::homePath());
}

void MainWindow::on_BlendSelect_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Select your blend file", QDir::homePath());
}

void MainWindow::on_SaveRenderSelect_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Select save folder", QDir::homePath());
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, "About", "Project under LGPL v3 licence. Created with love by Nesakko, you can get the source on github : https://github.com/Nesakko/BlenderRender");
}
