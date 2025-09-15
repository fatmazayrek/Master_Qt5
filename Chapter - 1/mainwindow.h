#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mytask.h"

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addTask();
    void removeTask(myTask *task);
    void upgradeStatus();

private:
    Ui::MainWindow *ui;

    QVector<myTask*> myTasks;

};
#endif // MAINWINDOW_H
