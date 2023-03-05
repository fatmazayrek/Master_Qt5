#ifndef MYTASK_H
#define MYTASK_H

#include <QWidget>
#include <QString>

namespace Ui {
class myTask;
}

class myTask : public QWidget
{
    Q_OBJECT

public:
    explicit myTask(QString name, QWidget *parent = nullptr);
    ~myTask();

    void setName(const QString& name);
    QString name() const;
    bool isCompleted() const;

signals:
    void removeTask(myTask *task);
    void statusChanged();

private slots:
    void checked(bool check);

private:
    Ui::myTask *ui;
};

#endif // MYTASK_H
