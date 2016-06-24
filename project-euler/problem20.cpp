#include <iostream>
#include <vector>

using namespace std;

void printNum(vector<unsigned long long> v) {
    for (int i=0; i<v.size(); i++) {

    }
}

int main() {
//    cout << 1 % 10;
//    cout << 21 * 9223372036854775808;
//    return 0;

    // 94 * 85827 7728

    unsigned long long n = 10;
    vector<unsigned long long> v;

    for (int i = n - 1; i > 0 && n>0; i--) {
        while (n > 0 && n % 10 == 0) {
//            cout << n << endl;
            n = n / 10;
//            cout << n << endl;
        }
        cout << i << " * " << n << endl;

        n = n * i;

        cout << "==== " << n << endl;
    }

    cout << n;
}