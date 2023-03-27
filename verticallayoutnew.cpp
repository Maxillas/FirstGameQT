#include "verticallayoutnew.h"
#include <QPushButton>

VerticalLayoutNew::VerticalLayoutNew(QWidget *parent)
    : QVBoxLayout(parent)
{

}

void VerticalLayoutNew::addButton(){
    QPushButton *button4 = new QPushButton("TIME EJI");
    this->addWidget(button4);
}
