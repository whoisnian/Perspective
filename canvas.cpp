#include "ui_canvas.h"
#include "canvas.h"
#include "object3d.h"
#include <QPainter>
#include <QMouseEvent>
#include <QtDebug>
#include <cmath>
#include <ctime>
#include <set>
#include <algorithm>

Canvas::Canvas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Canvas)
{
    ui->setupUi(this);
    centerX = 0;
    centerY = 0;
    tran = false;
}

Canvas::~Canvas()
{
    delete ui;
}

void Canvas::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // 灰色背景
    painter.fillRect(0, 0, width(), height(), QColor("#31363b"));
    painter.translate(width()/2, height()/2);

    Object3D a;

    // 构造中心位于坐标原点的立方体
    int l = 100;
    a.addPoint(-l, -l, -l);
    a.addPoint(l, -l, -l);
    a.addPoint(l, l, -l);
    a.addPoint(-l, l, -l);
    a.addPoint(-l, -l, l);
    a.addPoint(l, -l, l);
    a.addPoint(l, l, l);
    a.addPoint(-l, l, l);

    a.addEdge(0, 1);
    a.addEdge(1, 2);
    a.addEdge(2, 3);
    a.addEdge(3, 0);
    a.addEdge(4, 5);
    a.addEdge(5, 6);
    a.addEdge(6, 7);
    a.addEdge(7, 4);
    a.addEdge(0, 4);
    a.addEdge(1, 5);
    a.addEdge(2, 6);
    a.addEdge(3, 7);

    // 绘制立方体移动到不同位置的一点透视图
    a.paint(centerX, centerY, 200, 200, &painter);
    painter.end();
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        oriX = event->pos().x();
        oriY = event->pos().y();
        tran = true;
    }
    else if(event->button() == Qt::RightButton)
    {
        centerX = 0;
        centerY = 0;
        tran = false;
        this->update();
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        tran = false;
        this->update();
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    if(tran)
    {
        nowX = event->pos().x();
        nowY = event->pos().y();
        centerX += (nowX-oriX)*1.5;
        centerY += (nowY-oriY)*1.5;
        oriX = event->pos().x();
        oriY = event->pos().y();
        this->update();
    }
}
