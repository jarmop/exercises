#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int wall = 35;
int empty = 45;
int door = 101;

bool isNotEmpty(string s) {
    return s.compare("---") != 0;
}

void nextMove() {
    bool isAllEmpty = true;
    string s;

    cin >> s;
//    cout << s << endl;
    if (isAllEmpty && isNotEmpty(s)) {
        isAllEmpty = false;
    }
    int upLeft = s[0];
    int up = s[1];
    int upRight = s[2];

    cin >> s;
//    cout << s << endl;
    if (isAllEmpty && isNotEmpty(s)) {
        isAllEmpty = false;
    }
    int left = s[0];
    int right = s[2];

    cin >> s;
//    cout << s << endl;
    if (isAllEmpty && isNotEmpty(s)) {
        isAllEmpty = false;
    }
//    int downLeft = s[0];
    int down = s[1];
    int downRight = s[2];

    if (isAllEmpty || up == door || (up == empty && right == wall)) {
        cout << "UP";
    } else if (right == door || (right == empty && (down == wall || downRight == wall))) {
        cout << "RIGHT";
    } else if (down == door || (down == empty && left == wall)) {
        cout << "DOWN";
    } else {
        cout << "LEFT";
    }
    cout << endl;
}

int main() {
    int id;
    cin >> id;

//    for (int i=0; i<4; i++) {
        nextMove();
//    }

    return 0;
}