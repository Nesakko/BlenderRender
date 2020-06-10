#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

    QString cmd;
    QString st;
    QString end;
    QString setFrame;
    QString anim;
    QString format;
    QString blend;
    QString binst;
    QString Engine;
    QString SaveAs;

    bool animCheck;


private slots:

    void on_closeButton_clicked();

    void on_actionAbout_Qt_triggered();

    void on_actionAbout_triggered();

    void on_frameStart_valueChanged(const QString &arg1);

    void on_frameEnd_valueChanged(const QString &arg1);

    void on_comboBox_activated(const QString &arg1);

    void on_checkBox_toggled(bool checked);

    void on_renderButton_clicked();


private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
