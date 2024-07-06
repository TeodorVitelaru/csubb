#include <QPainter>

class RankWidget : public QWidget {
private:
vector<int> ranks;
public:
    explicit RankWidget(vector<int> ranks, QWidget* parent = nullptr) : QWidget(parent), ranks(ranks) {}

    void paintEvent(QPaintEvent* event) override {
        QPainter painter(this);
        painter.setPen(Qt::darkRed);
        int rank = 0;
        for (auto& c : ranks) {
            int x = (rank + 1) * 10;
            painter.drawLine(x, painter.device()->height()*50000, x, painter.device()->height() - c * 50);  // Increase the multiplier
            rank++;
        }
    }

void setRanks(vector<int> newRanks) {
    ranks = newRanks;
    update();  // Trigger a repaint
}
};