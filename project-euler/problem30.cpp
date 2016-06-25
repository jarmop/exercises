#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void printNum(vector<short> num) {
    int sum = 0;
    for (int i=num.size()-1; i>=0; i--) {
        sum += num[i];
        cout << num[i] << ",";
    }
    cout << endl;
    cout << "sum = " << sum << endl;
}

class Num {
    vector<int> numVector;
public:
//    Num(long num);
    void operator=(unsigned long long num);
    void operator++();
    void operator++(int);
    void operator--();
    void operator--(int);
    friend ostream& operator<<(ostream& os, const Num& n);
};

void Num::operator=(unsigned long long num) {
    while (num > 0) {
        cout << num << endl;

        this->numVector.push_back(num % 10);
        num = num / 10;
    }
    cout << num << endl;

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
ostream& operator<<(ostream& os, const Num& n)
{
    for (int i = n.numVector.size() - 1; i >= 0; i--) {
        os << n.numVector[i];
    }
    return os;
}

int main() {

    vector<int> pows {0,1};
    pows.push_back(pow(2,5)); // 32
    pows.push_back(pow(3,5)); // 243
    pows.push_back(pow(4,5)); // 1024
    pows.push_back(pow(5,5)); // 3125
    pows.push_back(pow(6,5)); // 7776
    pows.push_back(pow(7,5)); // 16807
    pows.push_back(pow(8,5)); // 32768
    pows.push_back(pow(9,5)); // 59049

    long max = 354294;

    Num num;
    num = max;

    cout << num << endl;

    num--;
    num--;
    num--;
    num--;
    num--;

    cout << num;


//    for (int n = max; n > )

}