#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "about.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_actionAbout_Qt_triggered();
    void on_actionAbout_triggered();
    void on_frameStart_valueChanged(const QString &arg1);
    void on_frameEnd_valueChanged(const QString &arg1);
    void on_FormatSelect_activated(int index);
    void on_checkBox_toggled(bool checked);
    void on_BlendSelect_clicked();
    void on_BlendFile_textChanged(const QString &arg1);
    void on_RenderEngine_currentIndexChanged(int index);
    void on_btn_Render_clicked();
    void on_SaveRenderSelect_clicked();
    void on_SaveRender_textChanged(const QString &arg1);
    void on_checkBox_2_toggled(bool checked);
    void on_NumberThread_valueChanged(const QString &arg1);
    void on_btn_GitHub_clicked();
    void on_btn_Twitter_clicked();
    void on_btn_Diaspora_clicked();
    void on_btn_Misskey_clicked();
    void on_BtnSide_Render_clicked();
    void on_BtnSide_Queue_clicked();
    void on_BtnSide_Param_clicked();
    void on_BtnSide_Option4_clicked();
    void on_btn_AddQueue_clicked();
    /*
    void on_btn_ListUp_clicked();
    void on_btn_ListDown_clicked();
    */
    void on_btn_ListRemove_clicked();

private:
    Ui::MainWindow *ui;

    About about;

    QString cmd;
    QString st;
    QString stdef;
    QString end;
    QString enddef;
    QString setFrame;
    QString anim;
    QString format;
    QString blend;
    QString Engine;
    QString SaveAs;
    QString tnum;

    QString currentBlend;
    QString engineIndex;
    QString formatIndex;

    bool toveride;
    bool animCheck;
};
#endif // MAINWINDOW_H
