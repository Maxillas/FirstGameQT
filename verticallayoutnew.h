#ifndef VERTICALLAYOUTNEW_H
#define VERTICALLAYOUTNEW_H
#include <QVBoxLayout>

class VerticalLayoutNew: public QVBoxLayout
{
public:
    VerticalLayoutNew(QWidget *parent = nullptr);
public slots:
    void addButton();
};

#endif // VERTICALLAYOUTNEW_H
