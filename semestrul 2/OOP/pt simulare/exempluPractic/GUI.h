#include <iostream>
#include "Service.h"
#include <QtWidgets/QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QTableWidget>
#include <QMessageBox>
#include <QHeaderView>
#include <QGroupBox>
#include <QRadioButton>
#include <qlistwidget.h>
#include <QStringList>
class GUI : public QWidget{
private:
    Service& service;
    QPushButton* btnStergere;
    QPushButton* btnFiltrareSuprafata;
    QPushButton* btnFiltrarePret;
    QPushButton* btnReload;

    QLabel* lblSuprafata1;
    QLabel* lblSuprafata2;
    QLineEdit* suprafata1;
    QLineEdit* suprafata2;

    QLabel* lblpret1;
    QLabel* lblpret2;
    QLineEdit* pret1;
    QLineEdit* pret2;

    QListWidget* lstApartamente;

    void intializare();
    void connect_signals();
    void reload_list(const vector<Apartament>& apartamente);

public:
    GUI(Service& service) : service{service}{
        intializare();
        connect_signals();
        reload_list(service.get_all());
    }
    void guiDelete();
};


