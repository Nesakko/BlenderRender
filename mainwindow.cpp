#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QDesktopServices>

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
    ui->CommandLine->setText(binst + " -b " + blend + SaveAs + Engine + format + stdef + st + enddef + end + tnum  + anim);

    //set ui widget default
    ui->stackedWidget->setCurrentIndex(0);
    ui->btn_ListDown->setVisible(false);
    ui->btn_ListUp->setVisible(false);
    ui->CommandLine->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

    //  ui actions and buttons
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
    ui->CommandLine->setText(binst + " -b " + blend + SaveAs + Engine + format + stdef + st + enddef + end + tnum  + anim);
    qDebug() << st;
}

void MainWindow::on_frameEnd_valueChanged(const QString &arg1)
{
    end = arg1;
    ui->CommandLine->setText(binst + " -b " + blend + SaveAs + Engine + format + stdef + st + enddef + end + tnum  + anim);
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

    ui->CommandLine->setText(binst + " -b " + blend + SaveAs + Engine + format + stdef + st + enddef + end + tnum  + anim);
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
    ui->CommandLine->setText(binst + " -b " + blend + SaveAs + Engine + format + stdef + st + enddef + end + tnum  + anim);
    qDebug() << animCheck;
}

void MainWindow::on_BlenderPathSelect_clicked()
{
    // Pas bon, a refaire :((

    QString Bdir = QFileDialog::getExistingDirectory(this, tr("Select Blender installation folder"), QDir::homePath(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    binst = Bdir;

    //QByteArray ba = binst.toLocal8Bit();
    //const char *c_str_binst = ba.data();

    //ui->BlenderPath->setText(binst);
    //system(c_str_binst);

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

    ui->CommandLine->setText(binst + " -b " + blend + SaveAs + Engine + format + stdef + st + enddef + end + tnum  + anim);
}

void MainWindow::on_BlendFile_textChanged(const QString &arg1)
{
    blend = arg1;
    ui->CommandLine->setText(binst + " -b " + blend + SaveAs + Engine + format + stdef + st + enddef + end + tnum  + anim);
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
    ui->CommandLine->setText(binst + " -b " + blend + SaveAs + Engine + format + stdef + st + enddef + end + tnum  + anim);
}

void MainWindow::on_btn_Render_clicked()
{
    QString render;
    QString bl;

    render = binst + " -b " + blend + SaveAs + Engine + format + stdef + st + enddef + end + tnum  + anim;
    bl = "notify-send 'Blender Render' '" + blend + "'";

    QByteArray ba = render.toLocal8Bit();
    const char *c_str_render = ba.data();
    QByteArray inst = bl.toLocal8Bit();
    const char *c_str_bl = inst.data();

    if(blend == ""){
        system("notify-send 'Blender Render' 'Error !! You have to add a blend file to render first'");
        //QMessageBox::critical(this, "Error", "You can't render nothing, select a blender file to render !! xD ");
        qDebug() << "MWAHAHAHA errooooooorrrrr !!!";
    }
    else{
        system(c_str_bl);
        qDebug() << c_str_bl;
        system(c_str_render);
    }
    qDebug() << "Render button pressed !!";
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

    ui->CommandLine->setText(binst + " -b " + blend + SaveAs + Engine + format + stdef + st + enddef + end + tnum  + anim);
    qDebug() << "The image save text was changed to : " + SaveAs;
}

void MainWindow::on_checkBox_2_toggled(bool checked)
{
    toveride = checked;

    if(toveride == false)
        tnum = "";

    ui->CommandLine->setText(binst + " -b " + blend + SaveAs + Engine + format + stdef + st + enddef + end + tnum  + anim);
}

void MainWindow::on_NumberThread_valueChanged(const QString &arg1)
{
    tnum = " -t " + arg1;
    ui->CommandLine->setText(binst + " -b " + blend + SaveAs + Engine + format + stdef + st + enddef + end + tnum  + anim);
    qDebug() << tnum;
}

void MainWindow::on_btn_GitHub_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/Nesakko", QUrl::TolerantMode));
}

void MainWindow::on_btn_Twitter_clicked()
{
    QDesktopServices::openUrl(QUrl("https://twitter.com/WiseNesakko", QUrl::TolerantMode));
}

void MainWindow::on_btn_Diaspora_clicked()
{
    QDesktopServices::openUrl(QUrl("https://pod.dapor.net/people/61cec8f086010137677d48600054b5a3", QUrl::TolerantMode));
}

void MainWindow::on_btn_Misskey_clicked()
{
    QDesktopServices::openUrl(QUrl("https://misskey.io/@Nesakko", QUrl::TolerantMode));
}

void MainWindow::on_BtnSide_Render_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

    qDebug() << "page Render";
}

void MainWindow::on_BtnSide_Queue_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    qDebug() << "page Queue";
}

void MainWindow::on_BtnSide_Param_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    qDebug() << "page Optios";
}

void MainWindow::on_BtnSide_Option4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    qDebug() << "page Other";
}


void MainWindow::on_btn_AddQueue_clicked()
{
    QString ToQueue;
    ToQueue = binst + " -b " + blend + SaveAs + Engine + format + stdef + st + enddef + end + tnum  + anim;
    ui->listWidget->addItem(ToQueue);
}

/*
void MainWindow::on_btn_ListUp_clicked()
{
    ui->listWidget->
}

void MainWindow::on_btn_ListDown_clicked()
{

}
*/

void MainWindow::on_btn_ListRemove_clicked()
{
    delete ui->listWidget->currentItem();
}
