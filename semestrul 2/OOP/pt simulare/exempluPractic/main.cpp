#include <QApplication>
#include <QPushButton>
#include "gui.h"
#include "teste.h"

int main(int argc, char *argv[]) {
    test_all();
    QApplication a(argc, argv);
    Repo repo{"../apartamente.txt"};
    Service srv{repo};
    GUI gui{srv};
    gui.show();
    return QApplication::exec();
}
