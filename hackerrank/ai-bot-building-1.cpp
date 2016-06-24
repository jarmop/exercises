#include <iostream>
#include <vector>
#include <string>
using namespace std;
void displayPathtoPrincess(int n, vector <string> grid) {
    int mx = n/2;
    int my = mx;
    int px;
    int py;
    string p = "p";

//    cout << mx << " " << my << endl;

    for (int i=0; i<grid.size(); i++) {
        string row = grid[i];
        size_t found = row.find(p);
        if (found != string::npos) {
            px = found;
            py = i;
        }

//        cout << grid[i] << endl;
    }

//    cout << px << " " << py << endl;


    while (mx < px) {
        cout << "RIGHT" << endl;
        mx++;
    }
    while (mx > px) {
        cout << "LEFT" << endl;
        mx--;
    }
    while (my < py) {
        cout << "DOWN" << endl;
        my++;
    }
    while (my > py) {
        cout << "UP" << endl;
        my--;
    }
}
int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}