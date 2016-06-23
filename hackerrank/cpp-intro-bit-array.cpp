//You are given four integers: N, S, P, Q. You will use them in order to create the sequence  with the following pseudo-code.
//
//a[0] = S (modulo 2^31)
//for i = 1 to N-1
//a[i] = a[i-1]*P+Q (modulo 2^31)
//Your task is to calculate the number of distinct integers in the sequence .
//
//Input Format
//
//Four space separated integers on a single line, N, S, P, and Q respectively.
//
//Output Format
//
//A single integer that denotes the number of distinct integers in the sequence .

#include <iostream>
#include <cmath>
#include <vector>
#include <list>

using namespace std;

int main() {
    int n, s, p, q;
//    cin >> n >> s >> p >> q;
    n = 3, s = 1, p = 1, q = 1;
//    n = 100000000, s = 658061970, p = 695098531, q = 1430548937;

    int *a = new int[n];
    long b = pow(2,31);
    long long value = s % b;
    a[0] = value;
//    int counter = 1;
    for (int i=1; i<n; i++) {
        value = value * p + q % b;
        //if (i % 1000000 == 0) {
//          cout << value << endl;
        //}

        a[i] = i;
//        counter++;
    }





//    cout << counter << endl;

    return 0;
}