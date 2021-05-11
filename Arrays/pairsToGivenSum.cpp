#include <bits/stdc++.h>
using namespace std;

int getPairsCount(int arr[], int n, int sum)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
        m[arr[i]]++;

    int tc = 0;
    for (int i = 0; i < n; i++)
    {
        tc += m[sum - arr[i]];
        if (sum == 2 * arr[i])
            tc--;
    }

    return tc / 2;
}
int main()
{
    int arr[] = {10, 12, 10, 15, -1, 7, 6, 5, 4, 2, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 11; //9
    cout << "Count of pairs is "
         << getPairsCount(arr, n, sum);
    return 0;
}