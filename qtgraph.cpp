#include "QtGraph.h"

void QtGraph::Draw(QGraphicsScene *scene)
{
    DrawWays(scene);
    DrawNodes(scene);
}

void QtGraph::DrawWays(QGraphicsScene *scene)
{
    double step = 2 * 3.14 / _mat.size();
    int centerX = scene->width() / 2;
    int centerY = scene->height() / 2;
    int r = 15;
    int l = 170;

    for (int i = 0; i < _mat.size(); i++)
    {
        for (int j = 0; j < _mat.size(); j++)
        {
            if (RoadLength(i + 1, j + 1) > 0)
            {
                int x1 = centerX + sin(step * i) * l;
                int x2 = centerX + sin(step * j) * l;
                int y1 = centerY + cos(step * i) * l;
                int y2 = centerY + cos(step * j) * l;
                QGraphicsItem *ell = scene->addLine(x1, y1, x2, y2);
                scene->addItem(ell);

                // draw text
                QFont font("Times");
                QGraphicsTextItem *txt = scene->addText(QString::number(RoadLength(i + 1, j + 1)), font);
                txt->setPos(x2 + (x1 - x2) / 8, y2 + (y1 - y2) / 8);
            }
        }
    }
}

void QtGraph::DrawNodes(QGraphicsScene *scene)
{
    double step = 2 * 3.14 / _mat.size();
    int centerX = scene->width() / 2;
    int centerY = scene->height() / 2;
    int r = 15;
    int l = 170;

    for (int i = 0; i < _mat.size(); i++)
    {
        QGraphicsItem *ell = scene->addEllipse(centerX + sin(step * i) * l - r, centerY + cos(step * i) * l - r,
                                               2 * r, 2 * r,
                                               QPen(Qt::black), QBrush(Qt::green));
        scene->addItem(ell);

        // draw text
        QFont font("Times");
        QGraphicsTextItem *txt = scene->addText(QString::number(i + 1), font);
        txt->setPos(centerX + sin(step * i) * l - r, centerY + cos(step * i) * l - r);
    }
}
