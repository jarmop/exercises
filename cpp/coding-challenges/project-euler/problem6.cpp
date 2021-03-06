//The sum of the squares of the first ten natural numbers is,
//
//12 + 22 + ... + 102 = 385
//The square of the sum of the first ten natural numbers is,
//
//(1 + 2 + ... + 10)2 = 552 = 3025
//Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
//
//Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int sum = 0;
    int sum2 = 0;
    for (int i=1; i<101; i++) {
        sum += i;
        sum2 += pow(i,2);
    }


    cout << sum << endl;
    sum = pow(sum, 2);
    cout << sum << endl;
    cout << sum2 << endl;

    cout << sum << " - " << sum2 << " = " << (sum - sum2) << endl;

}