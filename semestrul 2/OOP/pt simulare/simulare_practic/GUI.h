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
#include "Service.h"

class GUI : public QWidget
{
private:
    Service& srv;
    QListWidget* lstElevi;
    QLineEdit* ateliere;
    QLabel* lblAteliere;
    QPushButton* btnSortare;
    QPushButton* btnMuzica;
    QPushButton* btnSport;
    QPushButton* btnStiinte;
    QPushButton* btnInformatica;
    void reload_list(const vector<Elev>& elevi);
    void initializare();
    void connect_signals();
public:
    GUI(Service& srv) : srv{ srv } {
        initializare();
        connect_signals();
        reload_list(srv.getElevi());
    }



};



