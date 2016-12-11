#include <iostream>
#include <vector>

using namespace std;

/**
 ************ Question 1 *************************
 * https://www.interviewcake.com/question/python/stock-price
 * O(n)
 */
int GetMaxProfit(const vector<int> stock_prices_yesterday) {
    if (stock_prices_yesterday.size() < 2) {
        throw "Less than two stock prices.";
    }
    int min_price = stock_prices_yesterday[0];
    int price = stock_prices_yesterday[1];
    int max_profit = price - min_price;
    min_price = min(price, min_price);
    for (int i = 2; i < stock_prices_yesterday.size(); i++) {
        price = stock_prices_yesterday[i];
        max_profit = max(price - min_price, max_profit);
        min_price = min(price, min_price);
    }

    return max_profit;
}

void MaxStockProfit() {
    const vector<int> stock_prices_yesterday = {500, 490, 450, 470, 480};
//    const vector<int> stock_prices_yesterday = {520, 510, 470, 460, 440};

    cout << GetMaxProfit(stock_prices_yesterday) << endl;
}

/**
 ************ QUESTION 2 ******************************
 * https://www.interviewcake.com/question/cpp/product-of-other-numbers
 * O(n)
 */
vector<int> GetProductsOfAllIntsExceptAtIndex(const vector<int> values) {
    vector<int> products(values.size(), 1);
    int product_so_far = 1;
    for (unsigned long i = 0; i < values.size(); i++) {
        products[i] = product_so_far;
        product_so_far *= values[i];
    }

    product_so_far = 1;
    for (unsigned long i = values.size() - 1; i >= 0; i--) {
        products[i] *= product_so_far;
        product_so_far *= values[i];
    }

    return products;
}

void ProductsOfAllIntsExceptAtIndex() {
    const vector<int> values = {1, 7, 3, 4};
    vector<int> products = GetProductsOfAllIntsExceptAtIndex(values);
//    for (vector<int>::const_iterator i = products.begin(); i < products.end(); i++) {
//        cout << *i << ' ';
//    }
    for (const auto product: products) {
        cout << product << ' ';
    }
}

/**
 *************** QUESTION 3 ******************************
 * https://www.interviewcake.com/question/cpp/highest-product-of-3
 * Brute force O(n^3)
 */
int GetHighestProductOfThreeN3(const vector<int> values) {
    int highest_product = values[0] * values[1] * values[2];
    for (int i = 0; i < values.size(); i++) {
        for (int j = 0; j < values.size(); j++) {
            for (int k = 0; k < values.size(); k++) {
                if (i != j && i != k && j != k) {
                    highest_product = max(highest_product, values[i] * values[j] * values[k]);
                }
            }
        }
    }
    return highest_product;
}

/**
 * You would think you only need three largest, which could be done in O(3n), but that actually fails with negative numbers (- * - = +)
 */
int GetHighestProductOfThreeFail(const vector<int> values) {
    vector<int> three_largest;
    for (auto value: values) {
        for (int i = 0; i < 3; i++) {
            if (three_largest.size() < i + 1) {
                three_largest.push_back(value);
            }
            if (value > three_largest[i]) {
                int temp = three_largest[i];
                three_largest[i] = value;
                value = temp;
            }
        }
    }

    int highest_product_of_three = 1;
    for (const auto value: three_largest) {
        highest_product_of_three *= value;
    }

    return highest_product_of_three;
}

/**
 * Find three largest positive numbers and two smallest negative numbers, and get largest combination of these.
 * O(5n) time, essentially O(1) space, and works with negative numbers!
 */
int GetHighestProductOfThree(const vector<int>& values) {
    vector<int> three_largest;
    vector<int> two_smallest;

    for (int value: values) {
        for (int i = 0; i < 3; i++) {
            if (three_largest.size() < i + 1) {
                three_largest.push_back(value);
                continue;
            }
            if (value > three_largest[i]) {
                int temp = three_largest[i];
                three_largest[i] = value;
                value = temp;
            }
        }
        for (int i = 0; i < 2; i++) {
            if (two_smallest.size() < i + 1) {
                two_smallest.push_back(value);
                continue;
            }
            if (value < two_smallest[i]) {
                int temp = two_smallest[i];
                two_smallest[i] = value;
                value = temp;
            }
        }
    }

    int highest_product_of_three = 1;
    for (int value: three_largest) {
        highest_product_of_three *= value;
    }

    int product_of_two_smallest = 0;
    if (two_smallest.size() == 2) {
        product_of_two_smallest = two_smallest[0] * two_smallest[1];
    } else if (two_smallest.size() == 1) {
        product_of_two_smallest = three_largest[2] * two_smallest[0];
    }

    return max(highest_product_of_three, three_largest[0] * product_of_two_smallest);
}

/**
 * Bonus questions for question 3:
 * 1. highest product of k items?
 * - Pass k as a parameter (amount of largest positive). Amount of smallest negative is k/2*2. And then just replace hard coded values 3 and 2 with these values. O(kn)
 * 2. Protect against overflow?
 * - use long long for the highest product
 */

void HighestProductOfThree() {
//    vector<int> values = {1,2,5,2,7};
//    vector<int> values = {-10,-10,1,3,2};
//    vector<int> values = {-10,-10,-1,-3,-2};
    vector<int> values = {-10,-10,1,3};
    cout << GetHighestProductOfThree(values) << endl;
}

/********* QUESTION 4 ***********/


int main() {
//    MaxStockProfit();
//    ProductsOfAllIntsExceptAtIndex();
    HighestProductOfThree();
}

