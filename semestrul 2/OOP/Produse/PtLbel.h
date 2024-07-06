#pragma once

#include <qwidget.h>
#include <qpainter.h>
#include <QLabel>
#include <QHBoxLayout>
#include "observer.h"
#include "Service.h"

class TipWnd :public Observer, public QWidget {
private:
    Service& srv;
    int nr;
    string tip;
    QLabel* lbl = new QLabel;
    QWidget* wnd = new QWidget;
    QHBoxLayout* layout = new QHBoxLayout;
public:
    TipWnd(Service& srv, string tip, int nr) :srv{ srv }, tip(tip), nr{ nr }{
        this->srv.addObserver(this);
        auto txt = to_string(nr);
        lbl->setText(QString::fromStdString(txt));
        wnd->setWindowTitle(QString::fromStdString(tip));
        wnd->setLayout(layout);
        layout->addWidget(lbl);
        wnd->resize(500, 500);
    }
    ~TipWnd() {
        this->srv.removeObserver(this);
    }
    void update() override {
        nr = srv.nr_prod(tip);
        auto txt = to_string(nr);
        lbl->setText(QString::fromStdString(txt));
    }
    void run() { wnd->show(); }
};