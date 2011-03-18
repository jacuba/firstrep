//using namespace std;
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QWidget>
#include <QStyle>
#include <QToolButton>
#include <QMessageBox>
#include <QVBoxLayout>

QVBoxLayout *vb;


void *ColorButton(void *threadid)
{
    QPushButton *button2 = new QPushButton("Button2");
    button2->setGeometry(10, 60, 180, 40);
    button2->setStyleSheet(" background-color: green ;border-radius: 8px; border-color: black; border-style: outset; border-width: 2px");
    if(vb != NULL)
        vb->addWidget(button2);
    button2->show();
}

int main(int argc, char *argv[])
{
    pthread_t thread1;

    QApplication app(argc, argv);
    QWidget *window = new QWidget;
    window->resize(200, 120);

    vb = new QVBoxLayout(window);
    window->setLayout(vb);

    QPushButton *button1 = new QPushButton("Button1");
    button1->setGeometry(10, 10, 180, 40);
    button1->setStyleSheet(" background-color: gold;border-radius: 8px; border-color: black; border-style: outset; border-width: 2px" );
    vb->addWidget(button1);
    window->show();
    //ColorButton(vb);
    pthread_create(&thread1, NULL, ColorButton, NULL);
    sleep(5);

    return app.exec();
}

