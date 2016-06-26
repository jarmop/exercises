//
// Created by Jarmo Pihlajaniemi on 26/06/16.
//

#include <iostream>

#include "Num.h"

void Num::operator=(unsigned long long num) {
    while (num > 0) {
//        cout << num << endl;
        this->numVector.push_back(num % 10);
        num = num / 10;
    }
//    cout << num << endl;

}
void Num::operator++() {
    cout << "Not implemented :(" << endl;
}
void Num::operator++(int) {
    ++*this;
}
void Num::operator--() {
    int i = 0;
    while (i < this->numVector.size() && this->numVector[i] == 0) {
        this->numVector[i] = 9;
        i++;
    }
    this->numVector[i]--;
}
void Num::operator--(int) {
    --*this;
}
ostream& operator<<(ostream& os, const Num& n) {
    for (int i = n.numVector.size() - 1; i >= 0; i--) {
        os << n.numVector[i];
    }
    return os;
}
unsigned long long Num::operator[](int i) {
    return this->numVector[i];
}
int Num::length() {
    return this->numVector.size();
}