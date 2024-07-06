#include <QApplication>
#include <QPushButton>
#include "GUI.h"
#include <string>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    string filename = "../melodii.txt";
    Repo repo{filename};
    Service srv{ repo};
    GUI gui{srv};
    gui.show();
    return a.exec();
}
