#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QApplication>
#include <QString>
#include <QInputDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->addTask, &QPushButton::clicked, this, &MainWindow::addTask);

    upgradeStatus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::upgradeStatus()
{
    int completedTask = 0;

    for(auto t: myTasks)
    {
       if(t->isCompleted())
       {
           completedTask++;
       }
    }

    int todoCount = myTasks.size() - completedTask;

    ui->todoLabel->setText(QString("Status: %1 todo / %2 completed").arg(todoCount).arg(completedTask));
}

void MainWindow::addTask()
{
    bool ok;

    QString taskName = QInputDialog::getText(this, tr("Add a task please"), tr("Task Name: "), QLineEdit::Normal, tr("Enter a taskName"), &ok);

    if(ok && !taskName.isEmpty())
    {
        qDebug() << "New task is adding..";

        myTask *task = new myTask(taskName);

        connect(task, &myTask::statusChanged, this, &MainWindow::upgradeStatus);
        connect(task, &myTask::removeTask, this, &MainWindow::removeTask);
        myTasks.append(task);

        ui->taskLayout->addWidget(task);
    }

    upgradeStatus();
}

void MainWindow::removeTask(myTask *task)
{
    myTasks.removeOne(task);

    ui->taskLayout->removeWidget(task);

    delete task;

    upgradeStatus();
}


