#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int startNum = 10;
    for (int x = 3; x < 10; x++) {
        int num = startNum;
//        cout << "f(" << x << ")=" << endl;
        cout << "f(" << x << ")=";
        bool found = false;
        for (int i = 2; !found && i < 10; i++) {
            int diipa = num;
//            while (num < diipa) {
                for (int j = 1; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        //                cout << "Try: " << num << endl;

                        if (num % x == 0) {
                            //                    cout << "Found: " << num << endl;
                            cout << num << endl;
                            found = true;
                            break;
                        }
                        num++;
                    }
                    num += 10 * j;
                }
//            }
            num = pow(10, i);

        }
        if (x % 10 == 0) {
            startNum = x;
        }
    }

}