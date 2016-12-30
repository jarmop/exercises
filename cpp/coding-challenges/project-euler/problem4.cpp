//A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
//
//Find the largest palindrome made from the product of two 3-digit numbers.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPalindrome(int num) {
    int parts[6];
    int i = 10;
    int c = 0;
    while (num > i) {
        parts[c] = num % i;
        c++;
        num = num / i;
    }
    parts[c] = num % i;
//    for (int i=0; i<=c; i++) {
//        cout << parts[i];
//    }

    int b=0;
    bool ret = true;
    while (b < c) {
        if (parts[b] != parts[c]) {
            ret = false;
            break;
        }
        b++;
        c--;
    }

    return ret;
}

int main() {
//    cout << isPalindrome(989010);

    int a = 999;
    int b = 999;
    int largestPalindrome = 0;
    int pCounter = 0;
//    while (a > 995 && !isPalindrome(a*b)) {
    while (a > 99 && pCounter < 10) {
        int sum = a*b;
        if (isPalindrome(sum)) {
            pCounter++;
            if (sum > largestPalindrome) {
                largestPalindrome = sum;
            }
        }

        if (a == b) {
            a--;
            b = 999;
        } else {
            b--;
        }
        cout << "a = " << a << ", b = " << b << ", a*b = " << a*b << endl;
    }

    cout << "a * b = " << a*b << endl;
    cout << "largest palindrome = " << largestPalindrome << endl;



//    int max = 998001;
    // int max = 997799;
    // int max = 996699;
    // int max = 995599;
    // int max = 994499;
    // 990099
    // int max = 989989:


    return 0;
}