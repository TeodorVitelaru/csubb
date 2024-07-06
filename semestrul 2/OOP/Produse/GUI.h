#include "Service.h"
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
#include "TableModel.h"

class GUI : public QWidget{
private:
    Service& srv;

    //pentru tabel;
    QTableWidget* tblProduse;

    //pentru alt tabel
    TableModel* modelTabel;
    QTableView* tblV = new QTableView;

    //pentru adaugare
    QLineEdit* editId = new QLineEdit;
    QLineEdit* editNume = new QLineEdit;
    QLineEdit* editTip = new QLineEdit;
    QLineEdit* editPret = new QLineEdit;
    QLabel* lblId = new QLabel{ "Id:" };
    QLabel* lblNume = new QLabel{ "Nume:" };
    QLabel* lblTip = new QLabel{ "Tip:" };
    QLabel* lblPret = new QLabel{ "Pret:" };
    QPushButton* btnAdauga = new QPushButton("Adauga");

    //pentru filtrare
    QSlider* sliderPret = new QSlider{ Qt::Horizontal };

    void initGUI();
    void connectSignalsSlots();
    void reloadData();
    void reloadTabel();
    void open_window();
public:
    GUI(Service& srv) : srv{ srv } {
        modelTabel = new TableModel{ srv.get_all() };
        tblV->setModel(modelTabel);
        this->initGUI();
        this->connectSignalsSlots();
        this->reloadData();
        this->open_window();
    }

};


