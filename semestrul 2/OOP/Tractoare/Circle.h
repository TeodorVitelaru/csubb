#include "GUI.h"
#include "Tractor.h"
#include <QMouseEvent>
#pragma once



class CircleWidget : public QWidget
{
    Q_OBJECT
    int numarRoti;
public:
    CircleWidget(QWidget* parent = nullptr) : QWidget(parent), numarRoti(0) {
    }

    void setNumarRoti(int numarRoti) {
        this->numarRoti = numarRoti;
        //update();
    }

protected:
    void paintEvent(QPaintEvent* event) override {
        QPainter painter(this);
        int radius = 50; // adjust as needed
        for (int i = 0; i < numarRoti; i++) {
            int x = i * 2 * radius + radius; // adjust as needed
            int y = height() / 2; // adjust as needed
            painter.drawEllipse(QPoint(x, y), radius, radius);
        }
    }

    void mousePressEvent(QMouseEvent* event) override {
        int radius = 50; // adjust as needed
        for (int i = 0; i < numarRoti; i++) {
            int x = i * 2 * radius + radius; // adjust as needed
            int y = height() / 2; // adjust as needed
            int dx = event->pos().x() - x;
            int dy = event->pos().y() - y;
            if (dx * dx + dy * dy <= radius * radius) { // if the click is within the circle
                numarRoti -= 2;
                 update();
                break;
            }
        }
    }
};