#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->frameEnd, SIGNAL(st), ui->CommandLineInput, SLOT(st));


    // Set default value
    st = " -f 1";
    end = "-e 250";
    format = " -F PNG";
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
    st = " -f " +arg1;

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
    anim = checked;
    qDebug() << anim << endl;
}
