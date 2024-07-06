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
#include <QPainter>
#pragma once

class GUI : public QWidget
{
private:
    Service& srv;

    //pentrtu tabel
    QTableWidget* tblParcare;

    //pentru adaugare
    QLineEdit* editId = new QLineEdit;
    QLineEdit* editAdresa = new QLineEdit;
    QLineEdit* editStare = new QLineEdit;
    QLineEdit* editLinii = new QLineEdit;
    QLineEdit* editColoane = new QLineEdit;
    QLabel* lblId = new QLabel{ "Id:" };
    QLabel* lblStare = new QLabel{ "Stare:" };
    QLabel* lblLinii = new QLabel{ "Linii:" };
    QLabel* lblColoane = new QLabel{ "Coloane:" };
    QLabel* lblAdresa = new QLabel{ "Adresa:" };
    QPushButton* btnAdauga = new QPushButton("Adauga");
    QPushButton* btnModificare = new QPushButton("Modifica");
    QPushButton* aleator = new QPushButton("Aleator");
    QPushButton* btnFereastra = new QPushButton("Fereastra");

    //functii pentru gui;
    void initializareGUI();
    void connectSignalsSlots();
    void reloadData();
public:
    GUI(Service& srv) : srv{srv} {
        this->initializareGUI();
        this->connectSignalsSlots();
        this->reloadData();
    }

};


