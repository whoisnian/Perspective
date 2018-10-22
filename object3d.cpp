#include "object3d.h"

Object3D::Object3D()
{
    PointsNum = 0;
    EdgeNum = 0;
    points.clear();
    edges.clear();
}

void Object3D::addPoint(double x, double y, double z)
{
    points.push_back(Point3D(x, y, z));
    PointsNum++;
}

void Object3D::addEdge(int u, int v)
{
    if(u >= PointsNum||v >= PointsNum)
        return;
    edges.push_back(Edge(u, v));
    EdgeNum++;
}

void Object3D::paint(double l, double m, double n, double d, QPainter *p)
{
    int i, u, v;
    p->setPen(Qt::white);
    for(i = 0;i < EdgeNum;i++)
    {
        u = edges[i].u;
        v = edges[i].v;
        p->drawLine(QPointF((points[u].x+l)*d/(d+n+points[u].z), (points[u].y+m)*d/(d+n+points[u].z)), QPointF((points[v].x+l)*d/(d+n+points[v].z), (points[v].y+m)*d/(d+n+points[v].z)));
    }
    p->setPen(Qt::red);
    p->drawLine(QPointF((points[4].x+l)*d/(d+n+points[4].z), (points[4].y+m)*d/(d+n+points[4].z)), QPointF(0, 0));
    p->drawLine(QPointF((points[5].x+l)*d/(d+n+points[5].z), (points[5].y+m)*d/(d+n+points[5].z)), QPointF(0, 0));
    p->drawLine(QPointF((points[6].x+l)*d/(d+n+points[6].z), (points[6].y+m)*d/(d+n+points[6].z)), QPointF(0, 0));
    p->drawLine(QPointF((points[7].x+l)*d/(d+n+points[7].z), (points[7].y+m)*d/(d+n+points[7].z)), QPointF(0, 0));
}
