//The prime factors of 13195 are 5, 7, 13 and 29.
//
//What is the largest prime factor of the number 600851475143 ?

#include <iostream>
#include <vector>

using namespace std;

int main() {
//    int num = 13195;
    unsigned long num = 600851475143;

    cout << num << endl;

    vector<int> primeFactors;

    int i = 2;
    while (i < num && i < 10000) {
        if (num % i == 0) {
            primeFactors.push_back(i);
            num = num / i;
            cout << i << " ";
        }
        i++;
    }

    cout << num;

    return 0;
}