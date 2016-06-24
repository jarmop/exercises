#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int wall = 35;
int empty = 45;
int door = 101;

void nextMove(vector<string> grid) {
    int upLeft = grid[0][0];
    int up = grid[0][1];
    int upRight = grid[0][2];
    int left = grid[1][0];
    int right = grid[1][2];
    int downLeft = grid[2][0];
    int down = grid[2][1];
    int downRight = grid[2][2];


    if (up == door || (up == empty && right == wall)) {
        cout << "UP";
    } else if (right == door || (right == empty && (down == wall || downRight == wall))) {
        cout << "RIGHT";
    } else if (down == door || (down == empty && left == wall)) {
        cout << "DOWN";
    } else {
        cout << "LEFT";
    }
}

int main() {
    int id;
    cin >> id;

    vector<string> grid;
    for(int i=0; i<3; i++) {
        string s; cin >> s;
        cout << s << endl;
        grid.push_back(s);
    }

    nextMove(grid);

    return 0;
}