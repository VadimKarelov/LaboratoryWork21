#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // create scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    scene->clear();

    // create graph
    myGraph = new QtGraph();
    myGraph->Draw(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// slots
void MainWindow::on_pushButton_Compute_clicked()
{
    if (CheckFields())
    {
        // drawing
        scene->clear();
        myGraph->Draw(scene);

        // show message
        QMessageBox::warning(this, "Вычисления", "Путь = " +
                             QString::number(myGraph->MinLength(GetInt(ui->lineEdit_dep->text().toStdString()),
                                                                      GetInt(ui->lineEdit_arr->text().toStdString()))));
    }
}

// methods to checking fields
bool MainWindow::CheckFields()
{
    if (ui->lineEdit_arr->text() != "" && GetInt(ui->lineEdit_arr->text().toStdString()) > 0
            && GetInt(ui->lineEdit_arr->text().toStdString()) < myGraph->Size())
    {
        QMessageBox::warning(this, "Ошибка","Ошибка пункта прибытия");
        return false;
    }
    if (ui->lineEdit_dep->text() != "" && GetInt(ui->lineEdit_dep->text().toStdString()) > 0
            && GetInt(ui->lineEdit_dep->text().toStdString()) < myGraph->Size())
    {
        QMessageBox::warning(this, "Ошибка","Ошибка пункта отправления");
        return false;
    }

    return true;
}

int MainWindow::GetInt(string text)
{
    int res = -1;
    try
    {
        res = stoi(text);
    }
    catch (...)
    {

    }
    return res;
}
