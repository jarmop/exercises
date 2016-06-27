#include <iostream>
#include "Num.h"

using namespace std;

//int multiplicationTable[9][9];

bool digitsLessThanThree(int i) {
    if (i % 10 > 2) {
        return false;
    }
    int m = 1;
    int b = 1;
    while (b != 0) {
        int d = m * 10;
//        int a = i % d;
        int b = i / d;
        m++;
    }
}

int magic(Num num) {
    bool found = false;
    for (int i = 12598; i < 12599; i++) {
//        cout << i << endl;
//        int result;
//        int j = 0;
//        while (result < 3) {
        int b = 0;
        for (int j = 0; j < num.length(); j++) {
            cout << "----" << endl;
            cout << i << ' ' << num[j] << ' ' << b << endl;


            int c = i * num[j] + b;

            cout << c << endl;
            cout << "----" << endl;

            int d = 10;
//            int d = (j + 1) * 10;
            int a = c % d;
            b = c / d;
            cout << a << endl;
            cout << b << endl;
            if (j < num.length() - 1) {
//                cout << (i * num[j + 1]);
//                if (a > 2 || ((i * num[j + 1] % 10) + b) > 2) {
                if (a > 2) {
                    break;
                }
            } else {
//                cout << a << endl;
//                cout << b << endl;
                if (a < 3 && b < 3) {
                    cout << i * num.getValue();
                    found = true;
                    break;
                }
            }
        }
        if (found) {
            break;
        }
    }

    return 0;
}

int main() {
    Num num;
    num = 89;
    magic(num);

    // Populate multiplication table
//    for (int i = 1; i < 10; i++) {
//        for (int j = 1; j < 10; j++) {
//            multiplicationTable[i][j] = i * j;
//        }
//    }

//    while (num > 8) {
//        magic(num);
//        num--;
//    }
}