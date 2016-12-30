#ifndef CODING_CHALLENGES_NUM_H
#define CODING_CHALLENGES_NUM_H

#include <vector>

using namespace std;

class Num {
    vector<int> numVector;
    // TODO Handle situations where actual value is greater than max long long
    long long value;
public:
    void operator=(long long num);
    bool operator>(long long num);
    bool operator<(long long num);
    void operator++();
    void operator++(int);
    void operator--();
    void operator--(int);
    friend ostream& operator<<(ostream& os, const Num& n);
    int operator[](int i);
    int length();
    int getValue();
};

#endif //CODING_CHALLENGES_NUM_H
