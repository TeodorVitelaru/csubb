#include "GUI.h"
using namespace std;

void GUI::intializare() {
    QHBoxLayout* lyMain = new QHBoxLayout;
    this->setLayout(lyMain);

    //left part of the window
    QWidget* left = new QWidget;
    QVBoxLayout* lyLeft = new QVBoxLayout;
    left->setLayout(lyLeft);
    btnStergere = new QPushButton("Stergere");
    lyLeft->addWidget(btnStergere);

    QWidget* formFiltrare1 = new QWidget;
    QFormLayout* lyFiltrare1 = new QFormLayout;
    formFiltrare1->setLayout(lyFiltrare1);
    lblSuprafata1 = new QLabel("Suprafata minima");
    suprafata1 = new QLineEdit;
    lyFiltrare1->addRow(lblSuprafata1, suprafata1);
    lblSuprafata2 = new QLabel("Suprafata maxima");
    suprafata2 = new QLineEdit;
    lyFiltrare1->addRow(lblSuprafata2, suprafata2);
    btnFiltrareSuprafata = new QPushButton("Filtrare dupa suprafata");
    lyFiltrare1->addWidget(btnFiltrareSuprafata);
    lyLeft->addWidget(formFiltrare1);

    QWidget* formFiltrare2 = new QWidget;
    QFormLayout* lyFiltrare2 = new QFormLayout;
    formFiltrare2->setLayout(lyFiltrare2);
    lblpret1 = new QLabel("Pret minim");
    pret1 = new QLineEdit;
    lyFiltrare1->addRow(lblpret1, pret1);
    lblpret2 = new QLabel("Pret maxim");
    pret2 = new QLineEdit;
    lyFiltrare1->addRow(lblpret2, pret2);
    btnFiltrarePret = new QPushButton("Filtrare dupa pret");
    lyFiltrare1->addWidget(btnFiltrarePret);
    //lyLeft->addWidget(formFiltrare2);

    lyMain->addWidget(left);



    //right part of the window with the list
    QWidget* right = new QWidget;
    QVBoxLayout* lyRight = new QVBoxLayout;
    right->setLayout(lyRight);
    lstApartamente = new QListWidget;
    btnReload = new QPushButton("Reload");
    lyRight->addWidget(lstApartamente);
    lyRight->addWidget(btnReload);
    lyMain->addWidget(right);
}

void GUI::connect_signals() {
    QObject::connect(btnStergere, &QPushButton::clicked, [&]() {
        guiDelete();
        this->reload_list(service.get_all());
    });

    QObject::connect(btnFiltrareSuprafata, &QPushButton::clicked, [&]() {
        try{
            int suprafata_min = stoi(suprafata1->text().toStdString());
            int suprafata_max = stoi(suprafata2->text().toStdString());
            suprafata1->clear();
            suprafata2->clear();
            this->reload_list(service.filtrare_suprafata(suprafata_min, suprafata_max));
        }
        catch (Exception& ex) {
            QMessageBox::warning(this, "Warning", QString::fromStdString(ex.getMessage()));
        }
        catch (std::invalid_argument)
        {
            QMessageBox::warning(this, "Warning", "Introduceti numere, nu caractere!");
        }
    });
    QObject::connect(btnFiltrarePret, &QPushButton::clicked, [&]() {
        try {
            int pret_min = pret1->text().toInt();
            int pret_max = pret2->text().toInt();
            pret1->clear();
            pret2->clear();
            this->reload_list(service.filtrare_pret(pret_min, pret_max));
        }
        catch (Exception& ex) {
            QMessageBox::warning(this, "Warning", QString::fromStdString(ex.getMessage()));
        }
    });
    QObject::connect(btnReload, &QPushButton::clicked, [&]() {
        this->reload_list(service.get_all());
    });
}

void GUI::reload_list(const vector<Apartament> &apartamente) {
    lstApartamente->clear();
    for (const auto& ap : apartamente) {
        auto item = new QListWidgetItem(QString::fromStdString(ap.get_strada() + " " + to_string(ap.get_suprafata()) + " " + to_string(ap.get_pret())));
        lstApartamente->addItem(item);
    }
}

void GUI::guiDelete() {
    try {
        if(lstApartamente->selectedItems().isEmpty()){
            QMessageBox::warning(this, "Warning", "Selectati un apartament ce vreti sa fie sters!");
            return;
        }
        auto item = lstApartamente->selectedItems().at(0);
        string strada = item->text().split(" ")[0].toStdString();
        int suprafata = item->text().split(" ")[1].toInt();
        int pret = item->text().split(" ")[2].toInt();
        Apartament ap{suprafata, strada, pret};
        service.stergere(ap);
        QMessageBox::information(this, "Information", "Apartamentul a fost sters cu succes!");
    }
    catch (Exception& ex) {
        QMessageBox::warning(this, "Warning", QString::fromStdString(ex.getMessage()));
    }

}
