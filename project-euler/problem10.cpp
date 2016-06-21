//The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
//
//Find the sum of all the primes below two million.

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    clock_t begin = clock();
    unsigned long long sum = 2;
    vector<long> pastPrimeNumbers {2};
    int i = 3;
    int printCounter = 0;
    // ei ole kahta peräkkäistä 3:n jälkeen?
    unsigned long count = 1;
    while (i < 100000) {
        unsigned long pi = 0;
        while (i % pastPrimeNumbers[pi] != 0) {
            if (pastPrimeNumbers[pi] > (i / 2)) {
                sum += i;
                printCounter++;
                if (printCounter == 1000) {
                    cout << i << endl;
                    printCounter = 0;
                }

                int diff = i - pastPrimeNumbers[count - 1];
                if (diff==1) {
                    cout << "diff: " << diff << endl;
                }
                pastPrimeNumbers.push_back(i);
                count++;
                break;
            }
            pi++;
        }

//        count: 9592
//        sum: 454396537
//        Seconds passed: 0.863194
//        i+=2;

        i++;
    }

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;



    cout << "count: " << count << endl;

    cout << "sum: " << sum << endl;

    cout << "Seconds passed: " << elapsed_secs << endl;

    // correct answer: 142913828922
    // record 137.039 s

    return 0;
}