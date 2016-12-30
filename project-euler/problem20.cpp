#include <iostream>
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

int main() {
    vector<short> num = {0, 0, 1};

//    num.push_back(7);

//    printNum(num);

    for (int n = 99; n > 1; n--) {
        int b = 0;
        cout << "n: " << n << endl;
        for (int i = 0; i < num.size(); i++) {
            int a = num[i] * n + b;
            b = a / 10;
            a = a % 10;
            num[i] = a;
//            cout << "a: " << a << ", b: " << b << endl;
        }
        while (b > 0) {
            int a = b % 10;
            b = b / 10;
            num.push_back(a);
        }
        printNum(num);
    }

    printNum(num);

//    cout << n;
}