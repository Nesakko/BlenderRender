#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QTimer>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //if is an animation, add the frame start and end
    if(animCheck ==false)
        setFrame = st + end;
    else
        setFrame = st;

    //Command to execute, and test
    binst = "Blender";

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
    qDebug() << "Clicked AboutQT" << endl;
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, "About", "Project under LGPL v3 licence. Created with love by Nesakko, you can get the source on github : https://github.com/Nesakko/BlenderRender");
    qDebug() << "Clicked About" << endl;
}

void MainWindow::on_frameStart_valueChanged(const QString &arg1)
{
    if(animCheck==false)
        st = " -f " + arg1;
    else
        st = " -s " + arg1;

    qDebug() << st << endl;
}

void MainWindow::on_frameEnd_valueChanged(const QString &arg1)
{
    end = " -e " + arg1;

    qDebug() << end << endl;
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    format = " -F " + arg1;

    qDebug() << format << endl;
}

void MainWindow::on_checkBox_toggled(bool checked)
{
    animCheck = checked;
    qDebug() << animCheck << endl;
}

void MainWindow::on_renderButton_clicked()
{
    qDebug() << binst + " -b" + " file.blend" + format + st + end << endl;
}


