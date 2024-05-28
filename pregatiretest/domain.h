//
// Created by Asus on 5/27/2024.
//

#ifndef PREGATIRETEST_DOMAIN_H
#define PREGATIRETEST_DOMAIN_H
#include "iostream"

class Bill {
public:
    std::string company;
    int serialNumber;
    float sum;
    bool isPaid;

    Bill() = default;

    Bill(std::string company, int serialNumber, float sum, bool isPaid);

    ~Bill() = default;

    std::string getCompany() const {
        return this->company;
    };

    int getSerialNumber() const {
        return this->serialNumber;
    };
    float getSum() const {
        return this->sum;
    };
    bool getIsPaid() const {
        return this->isPaid;
    }

    bool operator==(const Bill& other) const {
        return company == other.company &&
               serialNumber == other.serialNumber &&
               sum == other.sum &&
               isPaid == other.isPaid;
    }
    friend std::istream& operator>>(std::istream& in, Bill& bill);

};

#endif //PREGATIRETEST_DOMAIN_H
