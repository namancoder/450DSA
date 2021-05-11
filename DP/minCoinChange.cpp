#include <bits/stdc++.h>
using namespace std;

int minCoins(int coin[], int n, int amount)
{
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        coins[i] = coin[i];
    }

    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = coins[i]; j < dp.size(); j++)
            dp[j] += dp[j - coins[i]];
    }
    return dp[amount];
}
int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int v = 4;
    cout << minCoins(arr, n, v) << endl;
    return 0;
}