#include <QApplication>
#include <QPushButton>
#include "GUI.h"
#include "teste.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    test_all();
    Repo repo{ "../parcari.txt" };
    Validator valid;
    Service srv{ repo, valid };
    GUI w{ srv };
    w.show();
    return a.exec();
}
