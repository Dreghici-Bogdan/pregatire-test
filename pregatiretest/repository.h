//
// Created by Asus on 5/27/2024.
//

#ifndef PREGATIRETEST_REPOSITORY_H
#define PREGATIRETEST_REPOSITORY_H
#include "vector"
#include "domain.h"

class repository {
private:
    std::vector <Bill> bills;
public:
    repository();
    ~repository();
    void add(Bill bill);
    void remove(Bill bill);
    void update(Bill bill, Bill newBill);
    std::vector<Bill> getAll();
};


#endif //PREGATIRETEST_REPOSITORY_H
