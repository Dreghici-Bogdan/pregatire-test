//
// Created by Asus on 5/27/2024.
//

#include "repository.h"
#include <algorithm>

repository::repository() {

}

repository::~repository() {

}

void repository::add(Bill bill) {
    auto it = find(bills.begin(), bills.end(), bill);
    if (it == bills.end())
    {
        bills.push_back(bill);
    }
}

void repository::remove(Bill bill) {
    auto it = find(bills.begin(), bills.end(), bill);
    if (it != bills.end())
    {
        bills.erase(it);
    }
}

void repository::update(Bill bill, Bill newBill) {
    auto it = find(bills.begin(), bills.end(), bill);
    if (it != bills.end())
    {
        *it = newBill;
    }
}

std::vector<Bill> repository::getAll() {
    return this->bills;
}


