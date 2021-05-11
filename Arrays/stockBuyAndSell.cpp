#include <bits/stdc++.h>
using namespace std;
int maxProfit(int prices[], int n)
{
    int cost = 0;
    int maxCost = 0;

    if (!n)
        return 0;

    int min_price = prices[0];
    for (int i = 0; i < n; i++)
    {
        min_price = min(min_price, prices[i]);
        cost = prices[i] - min_price;
        maxCost = max(cost, maxCost);
    }
    return maxCost;
}
int maxProft(int prices[], int n)
{
    int maxPro = 0;
    int minPrice = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        minPrice = min(minPrice, prices[i]);
        maxPro = max(maxPro, prices[i] - minPrice);
    }
    return maxPro;
}

int main()
{

    // Stock prices on consecutive days
    int prices[] = {100, 180, 260, 310, 40, 535, 695};
    int N = sizeof(prices) / sizeof(prices[0]);

    // cout << maxProfit(prices, N);
    cout << maxProft(prices, N);

    return 0;
}
