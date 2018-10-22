#ifndef OBJECT3D_H
#define OBJECT3D_H

#include <QPainter>
#include <vector>

class Point3D
{
public:
    double x, y, z;

    Point3D(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

class Edge
{
public:
    int u, v;

    Edge(int u, int v)
    {
        this->u = u;
        this->v = v;
    }
};

class Object3D
{
private:
    int PointsNum;
    int EdgeNum;
    std::vector<Point3D> points;
    std::vector<Edge> edges;

public:
    Object3D();
    void addPoint(double x, double y, double z);
    void addEdge(int u, int v);
    void paint(double l, double m, double n, double d, QPainter *p);
};

#endif // OBJECT3D_H
