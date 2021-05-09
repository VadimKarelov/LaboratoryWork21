#ifndef QTGRAPH_H
#define QTGRAPH_H
#include <QColor>
#include <QFile>
#include <QFont>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QString>
#include <QtCore/qmath.h>
#include <QTextStream>
#include "Graph.h"

class QtGraph :  public Graph
{
public:
    QtGraph() : Graph() {}

    QtGraph(vector<vector<int>> source) : Graph(source) {}

    void Draw(QGraphicsScene *scene);

private:
    void DrawWays(QGraphicsScene *scene);

    void DrawNodes(QGraphicsScene *scene);
};

#endif // QTGRAPH_H
