#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QStatusBar>
#include <set>

namespace Ui {
class Canvas;
}

class Canvas : public QWidget
{
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = nullptr);
    ~Canvas();

private:
    Ui::Canvas *ui;
    // 用于计算鼠标拖动时的偏移量
    int oriX, oriY, nowX, nowY, centerX, centerY;
    // 鼠标拖动中
    bool tran;

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // CANVAS_H
