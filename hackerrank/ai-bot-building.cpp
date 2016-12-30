#include <iostream>
#include <vector>
using namespace std;
void nextMove(int n, int mx, int my, vector <string> grid) {
    // vertaile stringien kokoa niin löydät oikean rivin nopeasti
    cout << mx << endl;
    cout << my << endl;
}
int main(void) {

    int n, r, c;
    vector <string> grid;

    cin >> n;
    cin >> r;
    cin >> c;

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    nextMove(n, r, c, grid);
    return 0;
}