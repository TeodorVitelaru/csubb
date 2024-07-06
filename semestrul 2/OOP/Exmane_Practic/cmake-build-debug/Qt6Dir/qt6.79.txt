#pragma once
#include <QAbstractTableModel>
#include "Tractor.h"
#include <vector>
#include <qdebug.h>
#include <iostream>

using namespace std;

class TableModel : public QAbstractTableModel
{
    vector<Tractor> tractoare;
    string tip;
public:
    TableModel(const std::vector<Tractor>& tractoare) : tractoare{tractoare} {
    }

    int rowCount(const QModelIndex& parent = QModelIndex{}) const override
    {
        return tractoare.size();
    }

    int columnCount(const QModelIndex& parent = QModelIndex{}) const override
    {
        return 5;
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override
    {
        if (role == Qt::BackgroundRole && tractoare[index.row()].get_tip() == tip) {
            return QBrush(QColor(Qt::red)); // replace with your desired color
        }
        if (role == Qt::DisplayRole)
        {
            Tractor p = tractoare[index.row()];
            if(index.column() == 0)
                return QString::fromStdString(to_string(p.get_id()));
            else if(index.column() == 1)
            {
                return QString::fromStdString(p.get_denumire());
            }
            else if(index.column() == 2)
            {
                return QString::fromStdString(p.get_tip());
            }
            else if(index.column() == 3)
            {
                return QString::fromStdString(to_string(p.get_numarRoti()));
            }else if(index.column() == 4)
            {
                int nr = 0;
                for(auto& t: tractoare)
                {
                    if(t.get_tip() == p.get_tip())
                        nr++;
                }
                return QString::fromStdString(to_string(nr));
            }
        }
        return QVariant{};
    }

    void set_tip(string tip1)
    {
        this->tip = tip1;
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role) const
    {
        if (role == Qt::DisplayRole)
        {
            if (orientation == Qt::Horizontal) {
                switch (section)
                {
                    case 0:
                        return QString("ID");
                    case 1:
                        return QString("denumire");
                    case 2:
                        return QString("tip");
                    case 3:
                        return QString("nrRoti");
                    case 4:
                        return QString("acelasi tip");
                }
            }
        }
        return QVariant{};
    }

    void setOferte(const vector<Tractor>& tractoare1)
    {
        emit layoutAboutToBeChanged();
        this->tractoare = tractoare1;
        auto topLeft = createIndex(0, 0);
        auto bottomRight = createIndex(rowCount(), columnCount());
        emit dataChanged(topLeft, bottomRight);
        emit layoutChanged();
    }

};