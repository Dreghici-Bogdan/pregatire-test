//
// Created by Asus on 5/27/2024.
//

#ifndef PREGATIRETEST_GUI_H
#define PREGATIRETEST_GUI_H
#include <qwidget.h>
#include <QArgument>
#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QMainWindow>
#include "Service.h"


class GUI: public QWidget {
    Q_OBJECT
private:
    Service& service;
    QListWidget *billsListWidget, *filteredListWidget;
    QLineEdit *company, *serial, *sum, *isPaid, *total;
    QPushButton *paid, *unpaid, *calculateTotal, *add;

    void presentationWindow();
    void populate();
    void filteredPaid();
    void filteredUnpaid();
    void calculate();
    void addBill();

public:
    GUI(Service& service): service {service}{
        this->presentationWindow();
    }

};


#endif //PREGATIRETEST_GUI_H
