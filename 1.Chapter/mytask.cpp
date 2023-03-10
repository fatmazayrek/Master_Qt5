#include "mytask.h"
#include "ui_mytask.h"

#include <QInputDialog>
#include <QPushButton>
#include <QFont>

myTask::myTask(QString name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myTask)
{
    ui->setupUi(this);

    setName(name);

    connect(ui->remove, &QPushButton::clicked, [=]()
    {
        emit removeTask(this);
    });
    connect(ui->edit, &QPushButton::clicked, this, &myTask::editName);
    connect(ui->checkBox, &QCheckBox::toggled, this, &myTask::checked);
}

myTask::~myTask()
{
    delete ui;
}

void myTask::setName(const QString &name)
{
    ui->checkBox->setText(name);
}

QString myTask::name() const
{
    return ui->checkBox->text();
}

bool myTask::isCompleted() const
{
    return ui->checkBox->isChecked();
}

void myTask::checked(bool check)
{
    QFont font(ui->checkBox->font());
    font.setStrikeOut(check);

    ui->checkBox->setFont(font);

    emit statusChanged();
}

void myTask::editName(const bool &ok)
{
    bool enter;

    QString taskName = QInputDialog::getText(this, tr("Set Task name"), tr("Enter the task name"), QLineEdit::Normal, tr("Untitle task"), &enter);

    if(enter && !taskName.isEmpty())
    {
        ui->checkBox->setText(taskName);
    }
}

