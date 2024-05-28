//
// Created by Asus on 5/27/2024.
//

#ifndef PREGATIRETEST_SERVICE_H
#define PREGATIRETEST_SERVICE_H
#include "repository.h"

class Service {
private:
    repository repository;
public:
    Service();
    Service(class repository& repo) : repository(repo) {}  // Constructor that takes a repository reference
    ~Service() = default;
    void add(Bill bill);
    void remove(Bill bill);
    void update(Bill bill, Bill NewBill);
    std::vector<Bill> getAll();
    std::vector<Bill> filteredPaid();
    std::vector<Bill> filteredUnpaid();
    int calculateTotal(std::string company);

};


#endif //PREGATIRETEST_SERVICE_H
