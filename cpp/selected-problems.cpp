/**
 * My own selection for the best code interview problems covering wide range of algorithms and data structures.
 */

#include <iostream>

using namespace std;

/******** 1. Factorial **********
 * Easy brute force solution
 * Faster with recursion?
 * Save space with dynamic programming?
 */

/**
 * O (n!) time, O(1) space
 */
int factorialBrute(int n) {
    int sum = 1;
    for (int i = 2; i <= n; i++) {
        sum *= i;
    }
    return sum;
}

/**
 * O(n) space
 */
int factorialRecursive(int n) {
    if (n == 1) {
        return 1;
    }
    return n * factorialRecursive(n - 1);
}

void factorialDynamic(int n) {

}

void factorial() {
    int n = 6;
//  int sum = factorialBrute(n);
    int sum = factorialRecursive(n);
//  int sum = factorialDynamic(n);

    cout << sum << endl;
}

int main() {
    factorial();
}