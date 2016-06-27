//
// Created by Jarmo Pihlajaniemi on 26/06/16.
//

#include <iostream>

#include "Num.h"

void Num::operator=(long long num) {
    this->value = num;
    while (num > 0) {
        this->numVector.push_back(num % 10);
        num = num / 10;
    }
}
bool Num::operator>(long long num) {
    return this->value > num;
}
bool Num::operator<(long long num) {
    return this->value < num;
}
void Num::operator++() {
    int i = 0;
    while (i < this->numVector.size() && this->numVector[i] == 9) {
        this->numVector[i] = 0;
        i++;
    }
    if (i == this->numVector.size()) {
        this->numVector.push_back(1);
    } else {
        this->numVector[i]++;
    }
    this->value++;
}
void Num::operator++(int) {
    ++*this;
}
void Num::operator--() {
    int i = 0;
    while (i < this->numVector.size() - 1 && this->numVector[i] == 0) {
        this->numVector[i] = 9;
        i++;
    }
    if (i == this->numVector.size() - 1) {
        this->numVector.pop_back();
    } else {
        this->numVector[i]--;
    }
    this->value--;
}
void Num::operator--(int) {
    --*this;
}
ostream& operator<<(ostream& os, const Num& n) {
//    for (int i = n.numVector.size() - 1; i >= 0; i--) {
//        os << n.numVector[i];
//    }
    os << n.value;
    return os;
}
int Num::operator[](int i) {
    return this->numVector[i];
}
int Num::length() {
    return this->numVector.size();
}
int Num::getValue() {
    return this->value;
}