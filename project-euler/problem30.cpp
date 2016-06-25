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
    void operator=(long l);
    Num& operator++();
    Num operator++(int);
    Num& operator--();
    Num operator--(int);
};

//Num::Num(long num) {
//    cout << "num";
//}
void Num::operator=(long l) {
    cout << l << endl;
}
Num& Num::operator++() {
    cout << "prefix" << endl;
    return *this;
}
Num Num::operator++(int) {
    cout << "post fix" << endl;
    return *this;
}
Num& Num::operator--() {
    return *this;
}
Num Num::operator--(int) {
    return *this;
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

//    cout << pows[6];

    // vähennetään jokaista exponenttia viidesti kunnes 0

//    Num* num = new Num(354294);
    Num num;
    num = 5;
    num++;
    ++num;
//    vector<short> num {};
    // tee oma num array overloadaa+ yms.

//    for (int i = 354294; i > 1; i--) {
//        int d = i % 10;
//    }

    // must be under 354294
}