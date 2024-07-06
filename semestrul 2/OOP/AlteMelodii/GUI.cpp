
#include "GUI.h"
#include <QPainter>
#include "qdebug.h"

void GUI::initGUI() {


    //main layout
    QHBoxLayout* lyMain = new QHBoxLayout;
    this->setLayout(lyMain);

    //left part of the window, pentu care setam layout vertical
    QWidget* left = new QWidget;
    QVBoxLayout* lyLeft = new QVBoxLayout;
    left->setLayout(lyLeft);

    //tabelul cu melodii
    this->tblMelodii = new QTableWidget;
    this->tblMelodii->setColumnCount(4);
    QStringList labels;
    labels << "ID" << "TITLU" << "ARTIST" << "RANK";
    this->tblMelodii->setHorizontalHeaderLabels(labels);
    lyLeft->addWidget(this->tblMelodii);
    lyMain->addWidget(left);


    QWidget* right = new QWidget;
    QVBoxLayout* lyRight = new QVBoxLayout;
    right->setLayout(lyRight);

    //pentru formulare
    QWidget* form = new QWidget;
    QFormLayout* lyForm = new QFormLayout;
    form->setLayout(lyForm);
    lyForm->addRow(lblTitlu, this->editTitlu);

    this->sliderRank->setMinimum(1);
    this->sliderRank->setMaximum(10);
    lyForm->addRow(new QLabel("Rank"), this->sliderRank);
    btnUpdate = new QPushButton("Update");
    lyForm->addWidget(btnUpdate);
    btnDelete = new QPushButton("Delete");
    lyForm->addWidget(btnDelete);
    //painter
    rankWidget = new RankWidget(srv.rank_fr());
    rankWidget->setFixedSize(300, 300);
    lyForm->addWidget(rankWidget);

    lyRight->addWidget(form);
    lyMain->addWidget(right);

    //celalalt tabel cu melodii
    QWidget* tabel = new QWidget;
    QVBoxLayout* lyTabel = new QVBoxLayout;
    tabel->setLayout(lyTabel);
    lyTabel->addWidget(tblV);
    lyMain->addWidget(tabel);
}

void GUI::connectSignals() {
    QObject::connect(btnDelete, &QPushButton::clicked, [&]()
    {
        int row = this->tblMelodii->currentRow();
        if (row < 0 || row >= this->tblMelodii->rowCount()) {
            return;
        }
        try {
            int id = this->tblMelodii->item(row, 0)->text().toInt();
            if(srv.ultima_melodie(id) == true)
                throw Exception("Ultima melodie nu poate fi stearsa!");
            this->srv.sterge_melodie(id);
            this->reloadData();
            this->reloadTabel();
            rankWidget->setRanks(srv.rank_fr());
            rankWidget->update();
            QMessageBox::information(this, "Info", "Melodie stearsa!");
        }
        catch (Exception& ex) {
            QMessageBox::critical(this, "Error", QString::fromStdString(ex.get_msg()));
        }
    });
    QObject::connect(tblMelodii, &QTableWidget::itemClicked, [&]() {
        int row = this->tblMelodii->currentRow();
        if (row < 0 || row >= this->tblMelodii->rowCount()) {
            return;
        }
        try {
            string titlu = this->tblMelodii->item(row, 1)->text().toStdString();
            this->editTitlu->setText(QString::fromStdString(titlu));
        }
        catch (Exception& ex) {
            QMessageBox::critical(this, "Error", QString::fromStdString(ex.get_msg()));
        }
    });
    QObject::connect(btnUpdate, &QPushButton::clicked, [&]() {
        int row = this->tblMelodii->currentRow();
        if (row < 0 || row >= this->tblMelodii->rowCount()) {
            return;
        }
        int id = this->tblMelodii->item(row, 0)->text().toInt();
        string titlu = this->editTitlu->text().toStdString();
        int newRank = this->sliderRank->value(); // Get the new rank from the slider
        try {
            srv.modifica_melodie(id, titlu, newRank);
            this->reloadData();
            this->reloadTabel();
            rankWidget->setRanks(srv.rank_fr());
            rankWidget->update();
            QMessageBox::information(this, "Info", "Melodie actualizata!");
        }
        catch (Exception& ex) {
            QMessageBox::critical(this, "Error", QString::fromStdString(ex.get_msg()));
        }
    });
}

void GUI::reloadData() {
    //stergem datele existente din tabel
    this->tblMelodii->setRowCount(0);

    //adaugam datele din repository
    vector<Melodie> melodii = this->srv.sortare();
    for (const auto& m : melodii) {
        int row = this->tblMelodii->rowCount();
        this->tblMelodii->setRowCount(row + 1);
        this->tblMelodii->setItem(row, 0, new QTableWidgetItem(QString::number(m.getId())));
        this->tblMelodii->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(m.getTitlu())));
        this->tblMelodii->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(m.getArtist())));
        this->tblMelodii->setItem(row, 3, new QTableWidgetItem(QString::number(m.getRank())));
    }
}

void GUI::reloadTabel() {
    modelTabel->setOferte(srv.get_all());
}

