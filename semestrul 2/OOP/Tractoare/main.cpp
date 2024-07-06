#include <QApplication>
#include <QPushButton>
#include "GUI.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Repo repo{"../tractoare.txt"};
    Validator val;
    Service srv{ repo, val };
    GUI w{ srv };
    w.show();
    return QApplication::exec();
}
