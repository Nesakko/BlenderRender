#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Translaton
    QTranslator t;

    QStringList languages;
    languages << "English" << "Français";

    QString lang = QInputDialog::getItem(NULL, "Select Language", "Language", languages);

    if (lang == "Français"){
        t.load(":/BlenderRender_fr_FR.qm");
    }

    a.installTranslator(&t);
    // translation end

    MainWindow w;
    w.show();
    return a.exec();
}
