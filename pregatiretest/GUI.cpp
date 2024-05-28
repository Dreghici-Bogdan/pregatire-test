//
// Created by Asus on 5/27/2024.
//

#include "GUI.h"
#include <QLineEdit>
#include <QFormLayout>
#include <QListWidget>
#include <QListWidgetItem>
#include <QString>
#include <QColor>
#include <fstream>
#include <sstream>
#include <QMessageBox>


void GUI::presentationWindow() {
    QWidget *window1 = new QWidget{};
    QVBoxLayout *modemanu = new QVBoxLayout{};

    this->company = new QLineEdit{};
    this->serial = new QLineEdit{};
    this->sum = new QLineEdit{};
    this->isPaid = new QLineEdit{};
    this->total = new QLineEdit{};

    this->billsListWidget = new QListWidget{};
    this->filteredListWidget = new QListWidget{};

    this->paid = new QPushButton{"Paid"};
    this->unpaid = new QPushButton{"Unpaid"};
    this->calculateTotal = new QPushButton{"Calculate Total"};
    this->add = new QPushButton{"Add"};

    QFormLayout *form = new QFormLayout{};
    form ->addRow("Company", this->company);
    form ->addRow("serial", this->serial);
    form ->addRow("sum", this->sum);
    form ->addRow("isPaid", this->isPaid);
    form ->addRow("Total", this->total);

    modemanu->addWidget(this->billsListWidget);
    modemanu->addWidget(this->filteredListWidget);

    modemanu->addLayout(form);
    modemanu->addWidget(this->paid);
    modemanu->addWidget(this->unpaid);
    modemanu->addWidget(this->calculateTotal);
    modemanu->addWidget(this->add);

    window1->setLayout(modemanu);
    //window1->setStyleSheet("background-color: blue;");
    window1->show();
    this->populate();
    connect(this->paid, &QPushButton::clicked, this, &GUI::filteredPaid);
    connect(this->unpaid, &QPushButton::clicked, this, &GUI::filteredUnpaid);
    connect(this->calculateTotal, &QPushButton::clicked, this, &GUI::calculate);
    connect(this->add, &QPushButton::clicked, this, &GUI::addBill);

}

void GUI::populate() {
    this->billsListWidget->clear();
    std::ifstream file("D:\\Faculta\\Semestrul_2\\New_OOP\\pregatiretest\\bills.txt");
    if(!file.is_open())
    {
        printf("Error opening file");
    }
    Bill bill;
    while(file >> bill)
    {
        service.add(bill);
    }

    file.close();

    std::vector<Bill> bills = service.getAll();

    //sorting the companies
    auto compareByCompany = [](const Bill& a, const Bill& b) {
        return a.getCompany() < b.getCompany();
    };
    std::sort(bills.begin(), bills.end(), compareByCompany);
    //finished sorting the companies
    for (const auto& bill : bills)
    {
        QString itemInList = QString::fromStdString(bill.getCompany()) + ", " +
                             QString::number(bill.getSerialNumber()) + ", " +
                             QString::number(bill.getSum()) + ", " +
                             (bill.getIsPaid() ? "Paid" : "Unpaid");
        //this->billsListWidget->addItem(itemInList); - this also adds a row to the list view
        QListWidgetItem* item = new QListWidgetItem(itemInList, this->billsListWidget);

        if (!bill.getIsPaid()) {
            item->setBackground(Qt::red); // Set background color to red
            item->setForeground(Qt::white); // Set text color to white for better readability
            // Make the font bold
            QFont font = item->font();
            font.setItalic(true);
            item->setFont(font);

        }
    }

}

void GUI::filteredPaid() {
    this->filteredListWidget->clear();
    std::vector<Bill> paid = service.filteredPaid();
    for (const auto &bill: paid) {
        QString itemInList = QString::fromStdString(bill.getCompany()) + ", " +
                             QString::number(bill.getSerialNumber()) + ", " +
                             QString::number(bill.getSum()) + ", " +
                             (bill.getIsPaid() ? "Paid" : "Unpaid");
        this->filteredListWidget->addItem(itemInList);
    }
}

void GUI::filteredUnpaid() {
    this->filteredListWidget->clear();
    std::vector<Bill> paid = service.filteredUnpaid();
    for (const auto &bill: paid) {
        QString itemInList = QString::fromStdString(bill.getCompany()) + ", " +
                             QString::number(bill.getSerialNumber()) + ", " +
                             QString::number(bill.getSum()) + ", " +
                             (bill.getIsPaid() ? "Paid" : "Unpaid");
        this->filteredListWidget->addItem(itemInList);
    }

}

void GUI::calculate() {
    std::string company = this->company->text().toStdString();
    int totalCost = service.calculateTotal(company);
    this ->total->setText(QString::fromStdString(std::to_string(totalCost)));
    QMessageBox::warning(this, "Error", "There is no such company");
    QMessageBox::information(this, "succesfull", "Here are the unpaid bills");
}

void GUI::addBill() {
    std::string company = this->company->text().toStdString();
    int serial = this->serial->text().toInt();
    float sum = this->sum->text().toFloat();
    bool isPaid = this->isPaid->text() == "Paid";

    Bill newBill(company, serial, sum, isPaid);
    service.add(newBill);
    this->billsListWidget->clear();
    std::vector <Bill> bills = service.getAll();

    auto compareByCompany = [](const Bill& a, const Bill& b) {
        return a.getCompany() < b.getCompany();
    };
    std::sort(bills.begin(), bills.end(), compareByCompany);

    for (const auto& bill : bills)
    {
        QString itemInList = QString::fromStdString(bill.getCompany()) + ", " +
                             QString::number(bill.getSerialNumber()) + ", " +
                             QString::number(bill.getSum()) + ", " +
                             (bill.getIsPaid() ? "Paid" : "Unpaid");
        this->billsListWidget->addItem(itemInList);
    }
    QMessageBox::information(this, "GOOD", "COMPANY ADDED");
}
