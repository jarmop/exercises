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

int main() {
//    MaxStockProfit();
    ProductsOfAllIntsExceptAtIndex();
}

