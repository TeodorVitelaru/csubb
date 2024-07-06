

#include "GUI.h"
#include "PtLbel.h"
#include <iostream>

void GUI::initGUI() {
    //main layout
    QHBoxLayout* lyMain = new QHBoxLayout;
    this->setLayout(lyMain);

    //left side - table
    QWidget* left = new QWidget;
    QVBoxLayout* lyLeft = new QVBoxLayout;
    left->setLayout(lyLeft);
    this->tblProduse = new QTableWidget;
    this->tblProduse->setColumnCount(5);
    QStringList labels;
    labels << "ID" << "Nume" << "Tip" << "Pret" << "Nr. vocale";
    this->tblProduse->setHorizontalHeaderLabels(labels);

    lyLeft->addWidget(this->tblProduse);
    lyMain->addWidget(left);


    //right side - form
    QWidget* right = new QWidget;
    QVBoxLayout* lyRight = new QVBoxLayout;
    right->setLayout(lyRight);
    lyMain->addWidget(right);

    //form layout
    QWidget* form = new QWidget;
    QFormLayout* formLy = new QFormLayout;
    form->setLayout(formLy);
    lyRight->addWidget(form);
    formLy->addRow(lblId, editId);
    formLy->addRow(lblNume, editNume);
    formLy->addRow(lblTip, editTip);
    formLy->addRow(lblPret, editPret);
    formLy->addWidget(btnAdauga);
    formLy->addWidget(sliderPret);

    //one more side with the new table
    QWidget* table = new QWidget;
    QVBoxLayout* lyTable = new QVBoxLayout;
    table->setLayout(lyTable);
    lyTable->addWidget(tblV);
    lyMain->addWidget(table);

}

void GUI::reloadData() {
    this->tblProduse->setRowCount(0);
    vector<Produs> produse = this->srv.sortare();
    for (const auto& prod : produse) {
        int row = this->tblProduse->rowCount();
        this->tblProduse->setRowCount(row + 1);
        this->tblProduse->setItem(row, 0, new QTableWidgetItem(QString::number(prod.getId())));
        this->tblProduse->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(prod.getNume())));
        this->tblProduse->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(prod.getTip())));
        this->tblProduse->setItem(row, 3, new QTableWidgetItem(QString::number(prod.getPret())));
        this->tblProduse->setItem(row, 4, new QTableWidgetItem(QString::number(prod.get_nr_vocale())));
    }
}

void GUI::connectSignalsSlots() {
    //conections
    QObject::connect(btnAdauga, &QPushButton::clicked, this, [&]()
    {
        try {
            int id = editId->text().toInt();
            string nume = editNume->text().toStdString();
            string tip = editTip->text().toStdString();
            double pret = editPret->text().toInt();
            srv.adauga_produs(id, nume, tip, pret);
            this->reloadData();
            QMessageBox::information(this, "Succes", "Produs adaugat cu succes!");
        }
        catch (Exception& ex) {
            QMessageBox::critical(this, "Error", QString::fromStdString(ex.get_msg()));
        }
    });
    QObject::connect(sliderPret, &QSlider::valueChanged, this, [&]() {

        double val = sliderPret->value();
        vector<Produs> produse = srv.sortare();
        this->tblProduse->setRowCount(0);
        for (const auto& prod : produse) {
            int row = this->tblProduse->rowCount();
            this->tblProduse->setRowCount(row + 1);
            this->tblProduse->setItem(row, 0, new QTableWidgetItem(QString::number(prod.getId())));
            this->tblProduse->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(prod.getNume())));
            this->tblProduse->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(prod.getTip())));
            this->tblProduse->setItem(row, 3, new QTableWidgetItem(QString::number(prod.getPret())));
            this->tblProduse->setItem(row, 4, new QTableWidgetItem(QString::number(prod.get_nr_vocale())));


            if (prod.getPret() <= val) {
                for (int col = 0; col < this->tblProduse->columnCount(); ++col) {
                    this->tblProduse->item(row, col)->setForeground(Qt::red);
                }
            }
        }
    });

    //selectare linie din tabel
    QObject::connect(tblV->selectionModel(), &QItemSelectionModel::selectionChanged, [&]()
    {
        QModelIndexList index = tblV->selectionModel()->selectedIndexes();
        if (index.isEmpty()) {
            return;
        }
        int selRow = tblV->selectionModel()->selectedIndexes().at(0).row();
        auto cel0Index = tblV->model()->index(selRow, 0);
        auto cel0Value = tblV->model()->data(cel0Index, Qt::DisplayRole).toString();
        editId->setText(cel0Value);
        auto cel1Index = tblV->model()->index(selRow, 1);
        auto cel1Value = tblV->model()->data(cel1Index, Qt::DisplayRole).toString();
        editNume->setText(cel1Value);
        auto cel2Index = tblV->model()->index(selRow, 2);
        auto cel2Value = tblV->model()->data(cel2Index, Qt::DisplayRole).toString();
        editTip->setText(cel2Value);
        auto cel3Index = tblV->model()->index(selRow, 3);
        auto cel3Value = tblV->model()->data(cel3Index, Qt::DisplayRole).toString();
        editPret->setText(cel3Value);
    });
}

void GUI::open_window() {
    auto tipuri = this->srv.tipuri();
    for(auto& el : tipuri)
    {
        auto wnd =new TipWnd{srv, el.first, el.second};
        wnd->run();
        cout<<1;
    }
}

void GUI::reloadTabel() {
    modelTabel->setOferte(srv.get_all());
}