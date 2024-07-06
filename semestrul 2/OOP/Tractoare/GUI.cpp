

#include "GUI.h"
#include "Circle.h"
#pragma once


void GUI::initGUI()
{
    //GUI
    QHBoxLayout* lyMain = new QHBoxLayout;
    this->setLayout(lyMain);

    //tabel
    QWidget* left = new QWidget;
    QVBoxLayout* lyLeft = new QVBoxLayout;
    left->setLayout(lyLeft);
    lyLeft->addWidget(tblV);
    lyMain->addWidget(left);

    //pentru formular
    QWidget* right = new QWidget;
    QVBoxLayout* lyRight = new QVBoxLayout;
    right->setLayout(lyRight);
    QWidget* form = new QWidget;
    QFormLayout* lyForm = new QFormLayout;
    form->setLayout(lyForm);
    lyForm->addRow(lblId, editId);
    lyForm->addRow(lblDenumire, editDenumire);
    lyForm->addRow(lblTip, editTip);
    lyForm->addRow(lblNrRoti, editNrRoti);
    lyForm->addWidget(btnAdauga);
    lyRight->addWidget(form);
    lyMain->addWidget(right);

    //pentru combo box
    QWidget* comboBox = new QWidget;
    QFormLayout* lyCombo = new QFormLayout;
    comboBox->setLayout(lyCombo);
    for(const string& type : srv.tipuri())
    {
        combo->addItem(QString::fromStdString(type));
    }
    lyCombo->addRow(lblCombo, combo);
    lyRight->addWidget(comboBox);

    cercuri->setLayout(lyCercuri);
    lyRight->addWidget(cercuri);

}

void GUI::connectSignalsSlots() {
    QObject::connect(btnAdauga, &QPushButton::clicked, this, [&]()
    {
       try {
            int id = editId->text().toInt();
            string denumire = editDenumire->text().toStdString();
            string tip = editTip->text().toStdString();
            int nrRoti = editNrRoti->text().toInt();
            srv.adaugare(id, denumire, tip, nrRoti);
            reloadData();
            editId->clear();
            editDenumire->clear();
            editTip->clear();
            editNrRoti->clear();
            QMessageBox::information(this, "Information", "Tractor adaugat cu succes!");
        }
        catch (Exception & e) {
            QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_msg()));
        }
    });

    QObject::connect(combo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [&]()
    {
        string tip = combo->currentText().toStdString();
        modelTabel->set_tip(tip);
        reloadData();

    });

    QObject::connect(tblV->selectionModel(), &QItemSelectionModel::selectionChanged, this, [&]()
    {
        QModelIndexList index = tblV->selectionModel()->selectedIndexes();
        if (index.isEmpty()) {
            return;
        }
        int row = index.at(0).row();
        QModelIndex nrRotiIndex = modelTabel->index(row, 3); // assuming nrRoti is the 4th column
        int nrRoti = modelTabel->data(nrRotiIndex, Qt::DisplayRole).toInt();
        QLayoutItem* item;
        while ((item = lyCercuri->takeAt(0))) {
            if (item->widget()) {
                delete item->widget();
            }
            delete item;
        }
        CircleWidget* circle = new CircleWidget;
        circle->setNumarRoti(nrRoti);
        //circle->show();
        lyCercuri->addWidget(circle);
    });

}

void GUI::reloadData() {
    modelTabel->setOferte(srv.get_all());
}