#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    window = new QWidget;

    button1 = new QPushButton("Время", this);
    button2 = new QPushButton("Создать", this);
    button3 = new QPushButton("Удалить", this);

    m_verticalLayout = new QVBoxLayout(window);
    m_horizontalLayout = new QHBoxLayout(window);

    m_verticalLayout->addWidget(button1);
    m_horizontalLayout->addWidget(button2);
    m_horizontalLayout->addWidget(button3);

    m_verticalLayout->addLayout(m_horizontalLayout);
    window->setLayout(m_verticalLayout);

    QObject::connect(button1, SIGNAL(clicked()), this, SLOT(clickedSlot()));
    QObject::connect(button2, SIGNAL(clicked()), this, SLOT(createSlot()));
    QObject::connect(button3, SIGNAL(clicked()), this, SLOT(deleteSlot()));


    window -> show();

}

MainWindow::~MainWindow()
{
    delete button1;
    delete button2;
    delete button3;
    delete button4;
    delete window;

}

void MainWindow::clickedSlot(){
    QString CurrentTime = QDateTime::currentDateTime().toString("dd.MM HH:mm:ss");
    qDebug()<< CurrentTime;
}

void MainWindow::createSlot(){

    if(!button4) {
        //QRandomGenerator generator; //если эти объекты определить в хедере, то все крашится,
        QString color; //заходит в элсе, где кнопка уже создана
        //QRandomGenerator * generator = new QRandomGenerator();
        //uint32_t r = generator.bounded(256); было так, не работало как надо

        uint32_t r = QRandomGenerator::global()->bounded(256); //здесь аналогично
        uint32_t g = QRandomGenerator::global()->bounded(256);
        uint32_t b = QRandomGenerator::global()->bounded(256);

        button4 = new QPushButton(this);

        //pallete.setBrush(QPalette::Window, QColor(r, g, b));


        QColor colors = QColor(r, g, b);
        QString style = QString("background-color: %1").arg(colors.name());
        button4->setStyleSheet(style);
        color = QString("%1").arg(colors.name());

       // color = "#" + QString("%1").arg(r,0,16) + QString("%1").arg(g,0,16) + QString("%1").arg(b,0,16);
       // button4->setPalette(pallete);

        button4->setText(color);

        m_verticalLayout->addWidget(button4);

    } else qDebug() << "button is already create";

    QObject::connect(button4, SIGNAL(clicked()), this, SLOT(changeColor()));

}

void MainWindow::deleteSlot(){

    if (button4 == nullptr){
        qDebug() << "button is already deleted";
    } else {
        delete button4;
        button4 = nullptr;
    }
}

void MainWindow::changeColor()
{

    //QRandomGenerator * generator = new QRandomGenerator();
    QString color1;

    uint32_t r1 = QRandomGenerator::global()->bounded(256);
    uint32_t g1 = QRandomGenerator::global()->bounded(256);
    uint32_t b1 = QRandomGenerator::global()->bounded(256);

//    pallete = button4->palette();
//    pallete.setBrush(QPalette::Base, QColor(r1, g1, b1));
//    color1 = "#" + QString("%1").arg(r1,0,16) + QString("%1").arg(g1,0,16) + QString("%1").arg(b1,0,16);
//    button4->setPalette(pallete);
    QColor colors = QColor(r1, g1, b1);
    QString style = QString("background-color: %1").arg(colors.name());
    button4->setStyleSheet(style);
    color1 = QString("%1").arg(colors.name());
    button4->setText(color1);

}


