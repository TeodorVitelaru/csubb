#include <QApplication>
#include <QPushButton>
#include "service.h"
#include "gui.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Repo repo{"../procesor.txt"};
    Service srv{repo};
    GUI gui{srv};
    gui.show();
    return a.exec();
}
