#include <QApplication>
#include <QPushButton>
#include "GUI.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    string filename = "../produse.txt";
    Repo repo{filename};
    Validare valid;
    Service srv{ repo, valid};
    GUI gui{srv};
    gui.show();
    return a.exec();
}
