
#include <iostream>
#include "GUI.h"
#include "Errors.h"
#include "Fereastra.h"

void GUI::initializareGUI() {
    //main layout
    QHBoxLayout* lyMain = new QHBoxLayout;
    this->setLayout(lyMain);

    //partea din stanga pentru tabel
    QWidget* left = new QWidget;
    QVBoxLayout* lyLeft = new QVBoxLayout;
    left->setLayout(lyLeft);
    this->tblParcare  = new QTableWidget;
    this->tblParcare->setColumnCount(6);
    QStringList labels;
    labels <<"id" << "adresa" << "linii" << "coloane" << "stare"<< "nrLocuri";
    this->tblParcare->setHorizontalHeaderLabels(labels);
    lyLeft->addWidget(this->tblParcare);
    lyMain->addWidget(left);

    //partea dreapta
    QWidget* right = new QWidget;
    QVBoxLayout* lyRight = new QVBoxLayout;
    right->setLayout(lyRight);
    lyMain->addWidget(right);
    QWidget* form = new QWidget;
    QFormLayout* formLy = new QFormLayout;
    form->setLayout(formLy);
    lyRight->addWidget(form);
    formLy->addRow(lblId, editId);
    formLy->addRow(lblAdresa, editAdresa);
    formLy->addRow(lblLinii, editLinii);
    formLy->addRow(lblColoane, editColoane);
    formLy->addRow(lblStare, editStare);
    formLy->addWidget(btnAdauga);
    formLy->addWidget(btnModificare);
    formLy->addWidget(aleator);
    formLy->addWidget(btnFereastra);


}

void GUI::connectSignalsSlots() {
    QObject::connect(this->btnAdauga, &QPushButton::clicked, this, [&]
    {
        int id = this->editId->text().toInt();
        string adresa = this->editAdresa->text().toStdString();
        int linii = this->editLinii->text().toInt();
        int coloane = this->editColoane->text().toInt();
        string stare = this->editStare->text().toStdString();
        try {
            this->srv.adaugare(id, adresa, linii, coloane, stare);
            this->reloadData();
            editId->clear();
            editAdresa->clear();
            editLinii->clear();
            editColoane->clear();
            editStare->clear();
            QMessageBox::information(this, "Succes", "Parcare adaugata cu succes!");
        }
        catch (Exception& ex) {
            QMessageBox::warning(this, "Warning", QString::fromStdString(ex.get_msg()));
        }

    });

    QObject::connect(this->btnModificare, &QPushButton::clicked, this, [&]
    {
        try {
            int id = this->editId->text().toInt();
            string adresa = this->editAdresa->text().toStdString();
            int linii = this->editLinii->text().toInt();
            int coloane = this->editColoane->text().toInt();
            string stare = this->editStare->text().toStdString();

            this->srv.modificare(id, adresa, linii, coloane, stare);
            this->reloadData();
            editId->clear();
            editAdresa->clear();
            editLinii->clear();
            editColoane->clear();
            editStare->clear();
            QMessageBox::information(this, "Succes", "Parcare modificata cu succes!");

        }
        catch (Exception& ex) {
            QMessageBox::warning(this, "Warning", QString::fromStdString(ex.get_msg()));
        }

    });
    QObject::connect(this->aleator, &QPushButton::clicked, this, [&]
    {
        int linii = this->editLinii->text().toInt();
        int coloane = this->editColoane->text().toInt();
        string stare = this->srv.aleator(linii, coloane);
        editStare->setText(QString::fromStdString(stare));
    });
    QObject::connect(btnFereastra, &QPushButton::clicked, this, [&]()
    {
        try{
            auto items = this->tblParcare->selectedItems();
            if (items.isEmpty())
            {
                return;
            }

            int id = items.at(0)->text().toInt();

            auto p = srv.cauta(id);
            GridWindow* wnd1 = new GridWindow{srv, p };
            wnd1->show();
            connect(wnd1, &QWidget::destroyed, this, [wnd1]() { delete wnd1; });

            GridWindow* wnd2 = new GridWindow{srv, p };
            wnd2->show();
            connect(wnd2, &QWidget::destroyed, this, [wnd2]() { delete wnd2; });
        }
        catch (Exception& ex) {
            QMessageBox::warning(this, "Warning", QString::fromStdString(ex.get_msg()));
        }
    });

}

void GUI::reloadData() {
    this->tblParcare->setRowCount(0);
    vector<Parcare> tasks = this->srv.sortare();
    for (const auto& task : tasks) {
        int row = this->tblParcare->rowCount();
        this->tblParcare->setRowCount(row + 1);
        this->tblParcare->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(to_string(task.get_id()))));
        this->tblParcare->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(task.getAdresa())));
        this->tblParcare->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(to_string(task.getLinii()))));
        this->tblParcare->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(to_string(task.getColoane()))));
        this->tblParcare->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(task.getStare())));
        this->tblParcare->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(to_string(task.get_nr_locuri()))));
    }

}
