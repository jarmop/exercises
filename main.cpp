#include <iostream>

using namespace std;

int main(){
    int n;
    int q;
    cin >> n >> q;
    
    int* seqs[n];
    for (int i=0; i<n; i++) {
        int size;
        cin >> size;
        seqs[i] = new int[size];
        for (int j=0; j<size; j++) {
            int val;
            cin >> val;
            seqs[i][j] = val;
        }
    }

    for (int i=0; i<q; i++) {
        int a,b;
        cin >> a >> b;
        cout << seqs[a][b] << endl;
    }

    return 0;
}