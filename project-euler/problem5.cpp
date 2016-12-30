//2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
//
//What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int min = 1;
    int max = 20;
    int num = 20;
    int divider = max - 1;
    while (divider > 1 && num < 1000000000) {
        divider = max - 1;
        while (divider > min && num % divider == 0) {
//            cout << divider << endl;
            divider--;
        }
        if (divider == 1) {
            break;
        }

        num += max;
    }

    cout << "num = " << num << ", divider = " << divider << endl;

    return 0;
}