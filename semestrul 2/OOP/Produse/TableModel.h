#pragma once
#include <QAbstractTableModel>
#include "Produs.h"
#include <vector>
#include <qdebug.h>
#include <iostream>

using namespace std;

class TableModel : public QAbstractTableModel
{
    vector<Produs> produse;
public:
    TableModel(const std::vector<Produs>& produse) : produse{produse } {
    }

    int rowCount(const QModelIndex& parent = QModelIndex{}) const override
    {
        return produse.size();
    }

    int columnCount(const QModelIndex& parent = QModelIndex{}) const override
    {
        return 5;
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override
    {
        if (role == Qt::DisplayRole)
        {
            Produs p = produse[index.row()];
            if(index.column() == 0)
                return QString::fromStdString(to_string(p.getId()));
            else if(index.column() == 1)
            {
                return QString::fromStdString(p.getNume());
            }
            else if(index.column() == 2)
            {
                return QString::fromStdString(p.getTip());
            }
            else if(index.column() == 3)
            {
                return QString::fromStdString(to_string(p.getPret()));
            }
            else if(index.column() == 4)
            {
                return QString::fromStdString(to_string(p.get_nr_vocale()));
            }
        }
        return QVariant{};
    }

    void setOferte(const vector<Produs>& produs1)
    {
        emit layoutAboutToBeChanged();
        this->produse = produs1;
        auto topLeft = createIndex(0, 0);
        auto bottomRight = createIndex(rowCount(), columnCount());
        emit dataChanged(topLeft, bottomRight);
        emit layoutChanged();
    }

};