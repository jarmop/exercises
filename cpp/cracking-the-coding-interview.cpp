#include <iostream>
#include <map>
#include <set>

#include "gtest/gtest.h"

using namespace std;

/********* 1.1 IS UNIQUE *********/

bool IsUnique(string str) {
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

TEST(IsUniqueTest, IsUnique) {
    ASSERT_TRUE(IsUnique("abc"));
    ASSERT_FALSE(IsUnique("abca"));
}

/********* 1.2 CHECK PERMUTATION ********/

bool isPermutation(string str1, string str2) {
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    return str1.compare(str2) == 0;
}

TEST(CheckPermutationTest, isPermutation) {
    ASSERT_TRUE(isPermutation("bca", "abc"));
    ASSERT_FALSE(isPermutation("bcaa", "abc"));
    ASSERT_FALSE(isPermutation("bcA", "abc"));
    ASSERT_FALSE(isPermutation("bca ", "abc"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
//    ::testing::GTEST_FLAG(filter) = "IsUnique*";
    ::testing::GTEST_FLAG(filter) = "CheckPermutationTest*";
    return RUN_ALL_TESTS();
}