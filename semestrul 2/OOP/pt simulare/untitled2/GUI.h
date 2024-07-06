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

class GUI : public QWidget
{
private:
    Service& service;
    QLabel* lblNume = new QLabel{"Nume"};
    QLabel* lblNumarThreaduri = new QLabel{"Numar threaduri"};
    QLabel* lblSocluProcesor = new QLabel{"Soclu procesor"};
    QLabel* lblPret = new QLabel{"Pret"};

    QLineEdit* editNume;
    QLineEdit* editNumarThreaduri;
    QLineEdit* editSocluProcesor;
    QLineEdit* editPret;

    QPushButton* btnAdaugaProcesor;
    QPushButton* btnFiltrare;
    QPushButton* btnReloadData;

    QListWidget* lstProcesoare;

    void intializeazaGUI();

    void connectSignalsSlots();
    void reloadProcesoare(vector<Procesor> procesoare);
public:
    GUI(Service& service) : service{service} {
        intializeazaGUI();
        connectSignalsSlots();
        reloadProcesoare(this->service.get_all_proc());
    }
    void guiAddProcesor();
};



