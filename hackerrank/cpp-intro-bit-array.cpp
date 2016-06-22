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
//    n = 3, s = 1, p = 1, q = 1;
    n = 10000000, s = 658061970, p = 695098531, q = 1430548937;

//    long long *a = new long long[n];
//    vector<long long> a;
    list<long long> a;
    list<long long>::iterator it;
    list<long long>::iterator begin;
    list<long long>::iterator end;
    int b = pow(2,31);
    long long value = s % b;
    a.push_front(value);
//    cout << "front: " << a.front() << ", back: " << a.back() << endl;

    cout << value << endl;
    it = a.begin();
    for (int i=1; i<100000; i++) {
        long long previousValue = value;
        value = value * p + q % b;

        if (i%10000==0) {
            cout << value << endl;
            cout << i << endl;
        }

        if (value > previousValue) {
            begin = a.begin();
            if (it == begin) {
//                cout << "a0" << endl;
                a.insert(it, value);
            }
//            it--;
            while (it != begin) {
                if (value < *it) {
//                    cout << "aa" << endl;
                    it++;
                    a.insert(it, value);
                    break;
                } else if (value == *it) {
//                    cout << "egrg" << endl;
                    break;
                }
                it--;
                if (it == begin) {
//                    cout << "ab" << endl;
                    if (value > *it) {
                        a.insert(it,value);
                    } else {
                        it++;
                        a.insert(it, value);
                    }
                    break;
                }
            }
        } else if (value < previousValue) {
            end = a.end();
            if (it == end) {
//                cout << "b0" << endl;
                a.insert(it, value);
            }
//            it++;
            while (it != end) {
                if (value > *it) {
//                    cout << "ba" << endl;
                    a.insert(it, value);
                    break;
                } else if (value == *it) {
//                    cout << "egrg" << endl;
                    break;
                }
                it++;
                if (it == end) {
//                    cout << "bb" << endl;
                    a.insert(it, value);
                    break;
                }
            }
        }
    }

    cout << a.size() << endl;

    return 0;
}