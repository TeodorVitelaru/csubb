#include <QApplication>
#include <QPushButton>
#include "GUI.h"
#include "teste.h"

using namespace std;

int main(int argc, char *argv[]) {
    test_all();
    QApplication a(argc, argv);
    Repo repo{"../elevi.txt"};
    Service srv{repo};
    GUI gui{srv};
    gui.show();
    return a.exec();
}
