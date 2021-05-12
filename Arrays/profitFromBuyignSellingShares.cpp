#include <bits/stdc++.h>
using namespace std;
void solve(int prices[], int n)
{
    int profit = 0;

    for (int i = 1; i < n; i++)
    {
        int sub = prices[i] - prices[i - 1];
        if (sub > 0)
            profit += sub;
    }

    cout << profit << endl;
}
int main()
{

    int price[] = {2, 30, 15, 10, 8, 25, 80, 2, 30};
    int n = 9;
    solve(price, n);
    return 0;
}