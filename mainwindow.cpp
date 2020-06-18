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

    //Default arguments
    binst = "blender";
    stdef = " -f ";
    st = "1";

    // Default command line on start
    ui->CommandLine->setText(binst + " -b " + blend + SaveAs + Engine + format + stdef + st + enddef + end + anim);
}

MainWindow::~MainWindow()
{
    delete ui;
}


    //  ui actions and buttons

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
    about.show();

    qDebug() << "Clicked About";

}

void MainWindow::on_frameStart_valueChanged(const QString &arg1)
{
    st = arg1;
    ui->CommandLine->setText(binst + " -b " + blend + SaveAs + Engine + format + stdef + st + enddef + end + anim);

    qDebug() << st;
}

void MainWindow::on_frameEnd_valueChanged(const QString &arg1)
{
    end = arg1;
    ui->CommandLine->setText(binst + " -b " + blend + SaveAs + Engine + format + stdef + st + enddef + end + anim);

    qDebug() << end;
}

void MainWindow::on_FormatSelect_activated(int index)
{
    if(index == 0)
        format = "";
    else if (index == 1)
        format = " -F PNG";
    else if (index == 2)
        format = " -F JPEG";
    else if (index == 3)
        format = " -F EXR";
    else if (index == 4)
        format = " -F MULTILAYER";
    else if (index == 5)
        format = " -F BMP";
    else if (index == 6)
        format = " -F TGA";
    else if (index == 7)
        format = " -F RAWTGA";
    else if (index == 8)
        format = " -F TIFF";
    else if (index == 9)
        format = " -F HDR";

    ui->CommandLine->setText(binst + " -b " + blend + SaveAs + Engine + format + stdef + st + enddef + end + anim);

    qDebug() << format;
}

void MainWindow::on_checkBox_toggled(bool checked)
{
    animCheck = checked;

    if(checked){
        anim = " -a";
        stdef = " -s ";
        enddef = " -e ";
        ui->label_2->setText("Frame Start");
    }
    else{
        anim = "";
        stdef = " -f ";
        enddef = "";
        end = "";
        ui->label_2->setText("Frame to render");
    }

    ui->CommandLine->setText(binst + " -b " + blend + SaveAs + Engine + format + stdef + st + enddef + end + anim);

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

    qDebug() << "File " + blend + " selected";
}

void MainWindow::on_BlenderPath_textChanged(const QString &arg1)
{
    QString b;
    b = arg1;

    if(b == "")
        binst = "blender";
    else
        binst = arg1;

    ui->CommandLine->setText(binst + " -b " + blend + SaveAs + Engine + format + stdef + st + enddef + end + anim);
}

void MainWindow::on_BlendFile_textChanged(const QString &arg1)
{
    blend = arg1;

    ui->CommandLine->setText(binst + " -b " + blend + SaveAs + Engine + format + stdef + st + enddef + end + anim);
}

void MainWindow::on_RenderEngine_currentIndexChanged(int index)
{
    if(index == 0){
        Engine = "";
        qDebug() << "Use engine selected in the blend file";
    }
    else if(index == 1){
        Engine = " -E CYCLES";
        qDebug() << "Swithed to " + Engine + " render engine";
    }
    else if(index == 2){
        Engine = " -E BLENDER_EEVEE";
        qDebug() << "Swithed to " + Engine + " render engine";
    }
    else if(index == 3){
        Engine = " -E BLENDER_WORKBENCH";
        qDebug() << "Swithed to " + Engine + " render engine";
    }

    ui->CommandLine->setText(binst + " -b " + blend + SaveAs + Engine + format + stdef + st + enddef + end + anim);
}

void MainWindow::on_renderButton_clicked()
{
    if(blend == ""){
        //QMessageBox::critical(this, "Error", "You can't render nothing, select a blender file to render !! xD ");
        qDebug() << "Hahaha errooooooorrrrr !!!";
    }
    else
        qDebug() << "render !! ";
}

void MainWindow::on_SaveRenderSelect_clicked()
{
    QString Sdir = QFileDialog::getExistingDirectory(this, tr("Select image save folder"), QDir::homePath(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    SaveAs = Sdir;

    ui->SaveRender->setText(SaveAs);

    qDebug() << "The folder " + SaveAs + "was selected";
}

void MainWindow::on_SaveRender_textChanged(const QString &arg1)
{
    QString s;
    s = arg1;

    if(s == "")
        SaveAs = "";
    else
        SaveAs = " -o " + arg1;

    ui->CommandLine->setText(binst + " -b " + blend + SaveAs + Engine + format + stdef + st + enddef + end + anim);

    qDebug() << "The image save text was changed to : " + SaveAs;
}
