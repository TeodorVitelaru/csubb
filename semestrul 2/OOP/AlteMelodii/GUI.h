#include "Service.h"
#include "TableModel.h"
#include <QtWidgets/QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QTableWidget>
#include <QMessageBox>
#include <QHeaderView>
#include <QGroupBox>
#include <QRadioButton>
#include <qlistwidget.h>
#include <QStringList>
#include <QPainter>
#include "Painter.h"

class GUI : public QWidget {
private:
    Service& srv;

    QTableWidget* tblMelodii;
    void initGUI();
    void connectSignals();
    void reloadData();
    void reloadTabel();

    QLineEdit* editTitlu = new QLineEdit;
    QLabel* lblTitlu = new QLabel{ "Titlu:" };
    QSlider* sliderRank = new QSlider{ Qt::Horizontal };
    QPushButton* btnUpdate;
    QPushButton* btnDelete;

    //pentru tabel
    TableModel* modelTabel;
    QTableView* tblV = new QTableView;

    //pentru painter
    RankWidget* rankWidget;

public:
    GUI(Service& srv) : srv{ srv } {
        modelTabel = new TableModel{ srv.sortare() };
        tblV->setModel(modelTabel);
        this->initGUI();
        this->connectSignals();
        this->reloadData();
        this->reloadTabel();
    }


};



