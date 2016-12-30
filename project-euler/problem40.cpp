#include <iostream>

using namespace std;

int main() {
    long maxLength = 1000000;
    string num = "";
    int i = 0;
    while (num.length() < maxLength + 1) {
        num += to_string(i);
        i++;
    }

    int sum = 1;
    for (int i=10; i<maxLength + 1; i*=10) {
        cout << "char: " << num[i] << endl;
        cout << "int: " << (num[i] - 48) << endl;
        sum *= (num[i] - 48);
    }

    cout << sum << endl;

    cout << "length: " << num.length();

}