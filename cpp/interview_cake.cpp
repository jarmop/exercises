#include <iostream>
#include <vector>

using namespace std;

/**
 * Question 1
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
 * Question 2
 * https://www.interviewcake.com/question/cpp/product-of-other-numbers
 */
int GetProductsOfAllIntsExceptAtIndex(const vector<int> vec) {
    if (vec.size() < 1) {
        return 0;
    }

    vector<int> products;
    int total_product = vec[0];
    for (int i = 0; i < vec.size(); i++) {
        total_product *= vec[i];
    }

    return total_product;
}

void ProductsOfAllIntsExceptAtIndex() {
    const vector<int> vec = {1, 7, 3, 4};
    cout << GetProductsOfAllIntsExceptAtIndex(vec) << endl;
}

int main() {
//    MaxStockProfit();
    ProductsOfAllIntsExceptAtIndex();
}

