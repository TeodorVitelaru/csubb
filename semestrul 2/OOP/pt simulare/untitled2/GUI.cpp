#include "GUI.h"
#include <QHBoxLayout>
#include "errors.h"

using namespace std;

void GUI::intializeazaGUI() {
    //main layout
    QHBoxLayout* lyMain = new QHBoxLayout;
    this->setLayout(lyMain);

    //left side with buttons
    QWidget* left = new QWidget;
    QVBoxLayout* lyLeft = new QVBoxLayout;
    left->setLayout(lyLeft);

    QWidget* form = new QWidget;
    QFormLayout* lyForm = new QFormLayout;
    form->setLayout(lyForm);
    editNume = new QLineEdit;
    editNumarThreaduri = new QLineEdit;
    editSocluProcesor = new QLineEdit;
    editPret = new QLineEdit;
    btnAdaugaProcesor = new QPushButton{"Adauga procesor"};
    btnReloadData = new QPushButton{"Reincarca datele"};

    lyForm->addRow(lblNume, editNume);
    lyForm->addRow(lblNumarThreaduri, editNumarThreaduri);
    lyForm->addRow(lblSocluProcesor, editSocluProcesor);
    lyForm->addRow(lblPret, editPret);
    lyForm->addWidget(btnAdaugaProcesor);
    lyForm->addWidget(btnReloadData);

    lyLeft->addWidget(form);
    lyMain->addWidget(left);

    //right side with list
    QWidget* right = new QWidget;
    QVBoxLayout* lyRight = new QVBoxLayout;
    right->setLayout(lyRight);

    lstProcesoare = new QListWidget;
    lyRight->addWidget(lstProcesoare);
    lyMain->addWidget(right);
}

void GUI::reloadProcesoare(vector<Procesor> procesoare) {
    lstProcesoare->clear();
    for (auto& procesor : procesoare) {
        auto item = new QListWidgetItem(QString::fromStdString(procesor.get_nume() + " " + procesor.get_socluProcesor() + " " + to_string(procesor.get_numarThreaduri()) + " " + to_string(procesor.get_pret())));
        lstProcesoare->addItem(item);
    }
}

void GUI::guiAddProcesor() {
    try{
        string nume = editNume->text().toStdString();
        int numarThreaduri = stoi(editNumarThreaduri->text().toStdString());
        string socluProcesor = editSocluProcesor->text().toStdString();
        int pret = stoi(editPret->text().toStdString());
        editNume->clear();
        editNumarThreaduri->clear();
        editSocluProcesor->clear();
        editPret->clear();
        service.adaugare_procesor(nume, numarThreaduri, socluProcesor, pret);
        this->reloadProcesoare(service.get_all_proc());
        QMessageBox::information(this, "Succes", "Procesor adaugat cu succes");
    }
    catch (Exception& e) {
        QMessageBox::information(this, "Warning", "Datele introduse sunt invalide");
    }
}

void GUI::connectSignalsSlots() {
    QObject::connect(btnAdaugaProcesor, &QPushButton::clicked, this, &GUI::guiAddProcesor);
    QObject::connect(btnReloadData, &QPushButton::clicked, [this]() {
        reloadProcesoare(service.get_all_proc());
    });
    QObject::connect(lstProcesoare, &QListWidget::itemSelectionChanged, [this]() {
        auto selected = lstProcesoare->selectedItems();
        if (selected.isEmpty()) {
            editNume->clear();
            editNumarThreaduri->clear();
            editSocluProcesor->clear();
            editPret->clear();
            return;
        }
        auto item = selected.at(0);
        string nume = item->text().toStdString();
        string numeProcesor = nume.substr(0, nume.find(" "));
        Procesor procesor = service.find(numeProcesor);
        editNume->setText(QString::fromStdString(procesor.get_nume()));
        editNumarThreaduri->setText(QString::fromStdString(to_string(procesor.get_numarThreaduri())));
        editSocluProcesor->setText(QString::fromStdString(procesor.get_socluProcesor()));
        editPret->setText(QString::fromStdString(to_string(procesor.get_pret())));
    });
}
