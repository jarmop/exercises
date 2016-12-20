#include <iostream>
#include <map>
#include <set>

using namespace std;

/********* 1.1 IS UNIQUE *********/

bool IsUniqueChars(string str) {
    set<char> uniqueChars;
    for (string::iterator it = str.begin(); it != str.end(); it++) {
        if (uniqueChars.find(*it) != uniqueChars.end()) {
            return false;
        } else {
            uniqueChars.insert(*it);
        }
    }

    return true;
}

void IsUnique() {
    map<string, bool> testData = {{"abc", true}, {"abca", false}};

    for (map<string, bool>::iterator it = testData.begin(); it != testData.end(); it++) {
        cout << boolalpha << IsUniqueChars(it->first) << " - " << boolalpha << it->second << endl;
    }
}

int main() {
    IsUnique();
}