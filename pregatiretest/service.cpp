//
// Created by Asus on 5/27/2024.
//

#include "Service.h"

Service::Service() {
    this->repository = repository;
}

void Service::add(Bill bill) {
    this->repository.add(bill);
}

void Service::remove(Bill bill) {
    this->repository.remove(bill);
}

void Service::update(Bill bill, Bill NewBill) {
    this->repository.update(bill, NewBill);

}

std::vector<Bill> Service::getAll() {
    return this->repository.getAll();
}

std::vector<Bill> Service::filteredPaid() {
    std::vector<Bill> allBills = repository.getAll();
    std::vector<Bill> paidBills;

    for (const auto& bill : allBills) {
        if (bill.getIsPaid()) {
            paidBills.push_back(bill);
        }
    }

    return paidBills;
}

std::vector<Bill> Service::filteredUnpaid() {
    std::vector<Bill> allBills = repository.getAll();
    std::vector<Bill> paidBills;

    for (const auto& bill : allBills) {
        if (! bill.getIsPaid()) {
            paidBills.push_back(bill);
        }
    }

    return paidBills;
}

int Service::calculateTotal(std::string company) {
    std::vector<Bill> allBills = repository.getAll();
    int total = 0;

    for (const auto& bill : allBills) {
        if (bill.getCompany() == company) {
            total = total + bill.getSum();
        }
    }

    return total;
}
