#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QSignalMapper>
#include "Parcare.h"
#include "Service.h"
#include <iostream>

class GridWindow : public QWidget, public Observer {

private:
    Service& srv;
    Parcare* p;
    QGridLayout* layout = new QGridLayout(this);
    string stare;
    vector<vector<QPushButton*>> buttons;
public:
    GridWindow(Service& srv, Parcare& p) : srv{srv}, p{&p} {
        this->srv.addObserver(this);
        this->stare = p.getStare();
        int linii = p.getLinii();
        int coloane = p.getColoane();
        buttons.resize(linii, vector<QPushButton*>(coloane, nullptr)); // Resize the vector
        for (int i = 0; i < linii; i++) {
            for (int j = 0; j < coloane; j++) {
                int index = i * coloane + j;
                buttons[i][j] = new QPushButton(this); // Create the QPushButton objects
                buttons[i][j]->setText(QString(stare.at(index)));
                layout->addWidget(buttons[i][j], i, j);
                connect(buttons[i][j], &QPushButton::clicked, this, &GridWindow::onButtonClicked);
            }
        }
        reload_Data();
        this->setLayout(layout);
    }
    void onButtonClicked() {
        if (p) { // Check if p is not nullptr before trying to access it
            string newStare = getStareFromButtons();
            p->set_stare(newStare);
            srv.modificare(p->get_id(), p->getAdresa(), p->getLinii(), p->getColoane(), p->getStare());
        }
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        if (btn) {
            if (btn->text() == "X") {
                btn->setText("-");
            } else if (btn->text() == "-") {
                btn->setText("X");
            }
            string newStare = getStareFromButtons();
            p->set_stare(newStare);
            srv.modificare(p->get_id(), p->getAdresa(), p->getLinii(), p->getColoane(), p->getStare());
        }
    }

    void reload_Data()
    {
        try {



            int linii = p->getLinii();
            int coloane = p->getColoane();
            for (int i = 0; i < linii; i++) {
                for (int j = 0; j < coloane; j++) {
                    int index = i*coloane+ j;
                    if (index < stare.size()) {
                        buttons[i][j]->setText(QString(stare.at(index))); // Update the text of the QPushButton objects
                    }
                }
            }
        } catch (const std::bad_alloc& e) {
            std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        }
    }


    void update() override
    {
        this->stare = p->getStare();
        reload_Data();
    }


    string getStareFromButtons() {
        string stare1="";
        for (int i = 0; i < layout->rowCount(); i++) {
            for (int j = 0; j < layout->columnCount(); j++) {
                QLayoutItem* item = layout->itemAtPosition(i, j);
                if (item) {
                    QPushButton* btn = qobject_cast<QPushButton*>(item->widget());
                    if (btn) {
                        stare1 += btn->text().toStdString();
                    }
                }
            }
        }
        return stare1;
    }

};
