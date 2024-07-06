#include "GUI.h"
#include <QHBoxLayout>
#include "Errors.h"


void GUI::initializare() {
    QHBoxLayout* lyMain = new QHBoxLayout;
    this->setLayout(lyMain);

    //setam partea din stanga
    QWidget* left = new QWidget;
    QVBoxLayout* lyLeft = new QVBoxLayout;
    left->setLayout(lyLeft);

    QWidget* form = new QWidget;
    QFormLayout* lyForm = new QFormLayout;
    form->setLayout(lyForm);
    ateliere = new QLineEdit;
    lblAteliere = new QLabel("Ateliere");
    lyForm->addRow(lblAteliere, ateliere);
    btnSortare = new QPushButton("Sortare");
    lyForm->addWidget(btnSortare);
    btnMuzica = new QPushButton("Muzica");
    lyForm->addWidget(btnMuzica);
    btnSport = new QPushButton("Sport");
    lyForm->addWidget(btnSport);
    btnStiinte = new QPushButton("Stiinte");
    lyForm->addWidget(btnStiinte);
    btnInformatica = new QPushButton("Informatica");
    lyForm->addWidget(btnInformatica);


    lyLeft->addWidget(form);
    lyMain->addWidget(left);

    //setam partea din dreapta cu lista
    QWidget* right = new QWidget;
    QVBoxLayout* lyRight = new QVBoxLayout;
    right->setLayout(lyRight);
    lstElevi = new QListWidget;
    lyRight->addWidget(lstElevi);

    lyMain->addWidget(right);
}

void GUI::connect_signals() {
    QObject::connect(lstElevi, &QListWidget::itemSelectionChanged, [&]() {
        try {
            if (lstElevi->selectedItems().isEmpty()) {
                ateliere->setText("");
                return;
            }
            auto sel = lstElevi->selectedItems().at(0);
            string nume = sel->text().split(" ")[0].toStdString();
            string scoala = sel->text().split(" ")[1].toStdString();
            Elev elev = srv.get_elev(nume, scoala);
            ateliere->setText(QString::fromStdString(elev.get_atelier()));
        }
        catch (Exception& ex) {
            QMessageBox::warning(this, "Warning", QString::fromStdString(ex.getMessage()));
        }
    });
    QObject::connect(btnSortare, &QPushButton::clicked, [&]() {
        srv.sortare_nume();
        reload_list(srv.getElevi());
    });
    QObject::connect(btnMuzica, &QPushButton::clicked, [&]() {
        QWidget* w = new QWidget;
        QVBoxLayout* ly = new QVBoxLayout;
        w->setLayout(ly);
        QTableWidget* tabel = new QTableWidget;
        tabel = new QTableWidget(10, 1);
        QStringList tblHeaderList;
        tblHeaderList << "ELEV";
        tabel->setHorizontalHeaderLabels(tblHeaderList);

        //optiune pentru a se redimensiona celulele din tabel in functie de continut
        tabel->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

        vector<Elev> elevi_inscrisi;
        for(auto& el : srv.getElevi())
            if(el.get_atelier() == "Muzica")
                elevi_inscrisi.push_back(el);
        tabel->clearContents();
        tabel->setRowCount(elevi_inscrisi.size());

        int lineNumber = 0;
        for(auto& oferta : elevi_inscrisi)
        {
            tabel->setItem(lineNumber, 0, new QTableWidgetItem(QString::fromStdString(oferta.get_nume())));
            lineNumber++;
        }
        ly->addWidget(tabel);
        w->show();
    });
    QObject::connect(btnSport, &QPushButton::clicked, [&]() {
        QWidget* w = new QWidget;
        QVBoxLayout* ly = new QVBoxLayout;
        w->setLayout(ly);
        QTableWidget* tabel = new QTableWidget;
        tabel = new QTableWidget(10, 1);
        QStringList tblHeaderList;
        tblHeaderList << "ELEV";
        tabel->setHorizontalHeaderLabels(tblHeaderList);

        //optiune pentru a se redimensiona celulele din tabel in functie de continut
        tabel->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

        vector<Elev> elevi_inscrisi;
        for(auto& el : srv.getElevi())
            if(el.get_atelier() == "Sport")
                elevi_inscrisi.push_back(el);
        tabel->clearContents();
        tabel->setRowCount(elevi_inscrisi.size());

        int lineNumber = 0;
        for(auto& oferta : elevi_inscrisi)
        {
            tabel->setItem(lineNumber, 0, new QTableWidgetItem(QString::fromStdString(oferta.get_nume())));
            lineNumber++;
        }
        w->show();
    });

    QObject::connect(btnStiinte, &QPushButton::clicked, [&]() {
        QWidget* w = new QWidget;
        QVBoxLayout* ly = new QVBoxLayout;
        w->setLayout(ly);
        QTableWidget* tabel = new QTableWidget;
        tabel = new QTableWidget(10, 1);
        QStringList tblHeaderList;
        tblHeaderList << "ELEV";
        tabel->setHorizontalHeaderLabels(tblHeaderList);

        //optiune pentru a se redimensiona celulele din tabel in functie de continut
        tabel->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

        vector<Elev> elevi_inscrisi;
        for(auto& el : srv.getElevi())
            if(el.get_atelier() == "Stiinte")
                elevi_inscrisi.push_back(el);
        tabel->clearContents();
        tabel->setRowCount(elevi_inscrisi.size());

        int lineNumber = 0;
        for(auto& oferta : elevi_inscrisi)
        {
            tabel->setItem(lineNumber, 0, new QTableWidgetItem(QString::fromStdString(oferta.get_nume())));
            lineNumber++;
        }
        w->show();
    });
    QObject::connect(btnInformatica, &QPushButton::clicked, [&]() {
        QWidget* w = new QWidget;
        QVBoxLayout* ly = new QVBoxLayout;
        w->setLayout(ly);
        QTableWidget* tabel = new QTableWidget;
        tabel = new QTableWidget(10, 1);
        QStringList tblHeaderList;
        tblHeaderList << "ELEV";
        tabel->setHorizontalHeaderLabels(tblHeaderList);

        //optiune pentru a se redimensiona celulele din tabel in functie de continut
        tabel->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

        vector<Elev> elevi_inscrisi;
        for(auto& el : srv.getElevi())
            if(el.get_atelier() == "Informatica")
                elevi_inscrisi.push_back(el);
        tabel->clearContents();
        tabel->setRowCount(elevi_inscrisi.size());

        int lineNumber = 0;
        for(auto& oferta : elevi_inscrisi)
        {
            tabel->setItem(lineNumber, 0, new QTableWidgetItem(QString::fromStdString(oferta.get_nume())));
            lineNumber++;
        }
        ly->addWidget(tabel);
        w->show();
    });
}


void GUI::reload_list(const vector<Elev>& elevi) {
    lstElevi->clear();
    for (const auto& el : elevi) {
        lstElevi->addItem(QString::fromStdString(el.get_nume() + " " + el.get_scoala()));
    }
}


