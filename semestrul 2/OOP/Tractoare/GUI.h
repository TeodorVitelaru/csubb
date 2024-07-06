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
#include <QComboBox>
#include "TabelModel.h"
#pragma once

class GUI : public QWidget
{
private:
    Service& srv;

    //pentru tabel
    TableModel* modelTabel;
    QTableView* tblV = new QTableView;

    //pentru adaugare
    QLineEdit* editId = new QLineEdit;
    QLineEdit* editDenumire = new QLineEdit;
    QLineEdit* editTip = new QLineEdit;
    QLineEdit* editNrRoti = new QLineEdit;
    QLabel* lblId = new QLabel{ "Id:" };
    QLabel* lblDenumire = new QLabel{ "Denumire:" };
    QLabel* lblTip = new QLabel{ "Tip:" };
    QLabel* lblNrRoti = new QLabel{ "NrRoti:" };
    QPushButton* btnAdauga = new QPushButton{ "Adauga" };

    //facem combo box
    QComboBox* combo = new QComboBox;
    QLabel* lblCombo = new QLabel{ "Tipuri de tractoare" };


    //pentru cerucri
    QWidget* cercuri = new QWidget;
    QVBoxLayout* lyCercuri = new QVBoxLayout;


    void initGUI();
    void connectSignalsSlots();
    void reloadData();
public:
    GUI(Service& srv) : srv{ srv } {
        modelTabel = new TableModel{ srv.sortare() };
        tblV->setModel(modelTabel);
        this->initGUI();
        this->connectSignalsSlots();
        this->reloadData();
    }


};


