#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QTimer>
#include <QProcess>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Command to execute, and test
    binst = "blender";
    st = " -f 1";

/*
    //if is an animation, add the frame start and end
    if(animCheck)
        setFrame = st;
    else
        setFrame = st + end;
*/

    ui->CommandLine->setText(binst + " -b " + blend + format + st);

    //update variable


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
    qDebug() << "Clicked AboutQT";
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, "About", "Project under LGPL v3 licence. Created with love by Nesakko, you can get the source on github : https://github.com/Nesakko/BlenderRender");
    qDebug() << "Clicked About";
}

void MainWindow::on_frameStart_valueChanged(const QString &arg1)
{
    if(animCheck==false)
        st = " --render-frame " + arg1;
    else
        st = " --frame-start " + arg1;
    ui->CommandLine->setText(binst + " -b " + blend + format + st);

    qDebug() << st;
}

void MainWindow::on_frameEnd_valueChanged(const QString &arg1)
{
    end = " --frame-end " + arg1;
    ui->CommandLine->setText(binst + " -b " + blend + format + st);

    qDebug() << end;
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    format = " -F " + arg1;
    ui->CommandLine->setText(binst + " -b " + blend + format + st);

    qDebug() << format;
}

void MainWindow::on_checkBox_toggled(bool checked)
{
    animCheck = checked;

    if(checked)
        anim = " -a";
    else
        anim = "";

    if(checked)
        ui->label_2->setText("Frame Start");
    else
        ui->label_2->setText("Frame to render");

    ui->CommandLine->setText(binst + " -b " + blend + format + st);

    qDebug() << animCheck;
}

void MainWindow::on_BlenderPathSelect_clicked()
{
    QString Bdir = QFileDialog::getExistingDirectory(this, tr("Select Blender installation folder"), QDir::homePath(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    binst = Bdir;

    ui->BlenderPath->setText(binst);

    qDebug() << "The folder " + binst + "was selected";
}

void MainWindow::on_BlendSelect_clicked()
{
    QString filter = "Blender scene (*.blend) ;; All files (*.*)";
    QString blendfile = QFileDialog::getOpenFileName(this, "Open Blender file", QDir::homePath(), filter);
    blend = blendfile;

    ui->BlendFile->setText(blend);

    qDebug() << "File " + blend + " was selected";
}

void MainWindow::on_BlenderPath_textChanged(const QString &arg1)
{
    binst = arg1;
    ui->CommandLine->setText(binst + " -b " + blend + format + st);

    qDebug() << "The Blender install text was changed to : " + binst;
}

void MainWindow::on_BlendFile_textChanged(const QString &arg1)
{
    blend = arg1;
    ui->CommandLine->setText(binst + " -b " + blend + format + st);

    qDebug() << "The blender file text was changed to : " + blend;
}

void MainWindow::on_renderButton_clicked()
{
    qDebug() << "render !! ";
}

