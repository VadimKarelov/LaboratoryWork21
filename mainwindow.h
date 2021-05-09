#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "QtGraph.h"
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QtGraph *myGraph;
    QGraphicsScene *scene = new QGraphicsScene(this);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Compute_clicked();

private:
    Ui::MainWindow *ui;

    bool CheckFields();

    int GetInt(string text);
};
#endif // MAINWINDOW_H
