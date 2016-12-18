#include <iostream>
using namespace std;

/********* 1. VALID PALINDROME **************!
/**
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

https://leetcode.com/problems/valid-palindrome/
*/

bool notAlnum (char c) {
    return !isalnum(c);
}

bool isPalindrome(string str) {
    str.erase(remove_if(str.begin(), str.end(), notAlnum), str.end());
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    if (str.length() == 0) {
        return true;
    }

    unsigned long middle = str.length() / 2;

    string str1 = str.substr(0, middle);
    reverse(str1.begin(), str1.end());

    string str2;
    if (str.length() % 2 == 0) {
        str2 = str.substr(middle);
    } else {
        str2 = str.substr(middle + 1);
    }

    return str1.compare(str2) == 0;
}

void validPalindrome() {
    string str1 = "A man, a plan, a canal: Panama";
    string str2 = "race a car";
    string str3 = "aba";

    cout << isPalindrome(str3);
}


/******* 2. REVERSE STRING *********/
/**
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".

https://leetcode.com/problems/reverse-string/
*/

void reverseString(string::iterator begin, string::iterator end) {
    end--;
    while (begin < end) {
        char temp = *begin;
        *begin = *end;
        *end = temp;
        cout << temp << endl;
        begin++;
        end--;
    }
}

int reverseStringTest() {
    string s = "test";
    reverseString(s.begin(), s.end());

    cout << s << endl;
}

int main() {
//    validPalindrome();
    reverseStringTest();
}