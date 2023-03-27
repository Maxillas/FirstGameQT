#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QRandomGenerator>
#include <QDateTime>
#include <iostream>
#include <QDebug>
#include <QTime>
#include <string>
#include <ctime>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;
    QHBoxLayout * m_horizontalLayout;
    QVBoxLayout * m_verticalLayout;
    QPalette pallete;
    QWidget *window;

private slots:
    void clickedSlot();
    void createSlot();
    void deleteSlot();
    void changeColor();


};

#endif // MAINWINDOW_H
