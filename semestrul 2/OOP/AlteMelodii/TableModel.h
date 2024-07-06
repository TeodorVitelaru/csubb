#pragma once
#include <QAbstractTableModel>
#include "Melodie.h"
#include <vector>
#include <qdebug.h>
#include <iostream>


using namespace std;

class TableModel : public QAbstractTableModel
{
    vector<Melodie> melodii;
public:
    TableModel(const std::vector<Melodie>& melodii) : melodii{melodii } {
    }

    int rowCount(const QModelIndex& parent = QModelIndex{}) const override
    {
        return melodii.size();
    }

    int columnCount(const QModelIndex& parent = QModelIndex{}) const override
    {
        return 5;
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override
    {
        if (role == Qt::DisplayRole)
        {
            Melodie p = melodii[index.row()];
            if(index.column() == 0)
                return QString::fromStdString(to_string(p.getId()));
            else if(index.column() == 1)
            {
                return QString::fromStdString(p.getTitlu());
            }
            else if(index.column() == 2)
            {
                return QString::fromStdString(p.getArtist());
            }
            else if(index.column() == 3)
            {
                return QString::fromStdString(to_string(p.getRank()));

            }
            else if(index.column() == 4)
            {
                int cnt=0;
                for(auto& mel : melodii)
                {
                    if(mel.getRank() == p.getRank())
                        cnt++;
                }
                return QString::fromStdString(to_string(cnt));

            }
        }
        return QVariant{};
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
                        return QString("Title");
                    case 2:
                        return QString("Artist");
                    case 3:
                        return QString("Rank");
                    case 4:
                        return QString("Count");
                }
            }
        }
        return QVariant{};
    }

    void setOferte(const vector<Melodie>& melodii1)
    {
        emit layoutAboutToBeChanged();
        this->melodii = melodii1;
        auto topLeft = createIndex(0, 0);
        auto bottomRight = createIndex(rowCount(), columnCount());
        emit dataChanged(topLeft, bottomRight);
        emit layoutChanged();
    }

};