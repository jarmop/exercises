#ifndef CODING_CHALLENGES_NUM_H
#define CODING_CHALLENGES_NUM_H

#include <vector>

using namespace std;

class Num {
    vector<int> numVector;
public:
    void operator=(unsigned long long num);
    void operator++();
    void operator++(int);
    void operator--();
    void operator--(int);
    friend ostream& operator<<(ostream& os, const Num& n);
    unsigned long long operator[](int i);
    int length();
};

#endif //CODING_CHALLENGES_NUM_H
