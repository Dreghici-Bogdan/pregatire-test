#include "domain.h"
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <vector>

Bill::Bill(std::string company, int serialNumber, float sum, bool isPaid) {
    this->company = company;
    this->serialNumber = serialNumber;
    this->sum = sum;
    this->isPaid = isPaid;
}

std::vector<std::string> tokensize(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        result.push_back(token);
    }
    return result;
}

std::istream& operator>>(std::istream& in, Bill& bill) {
    std::string line;
    if (std::getline(in, line)) {
        std::vector<std::string> tokens = tokensize(line, ';');
        if (tokens.size() == 4) {
            try {
                bill.company = tokens[0];
                bill.serialNumber = std::stoi(tokens[1]);
                bill.sum = std::stof(tokens[2]);
                bill.isPaid = std::stoi(tokens[3]) != 0;
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid argument: " << e.what() << " in line: " << line << std::endl;
            } catch (const std::out_of_range& e) {
                std::cerr << "Out of range error: " << e.what() << " in line: " << line << std::endl;
            }
        } else {
            std::cerr << "Incorrect number of tokens: " << tokens.size() << " in line: " << line << std::endl;
        }
    }
    return in;
}
