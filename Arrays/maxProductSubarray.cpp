#include <bits/stdc++.h>
using namespace std;

int maxSubarrayProduct(int arr[], int n)
{
    int maxEH = 1, minEH = 1;
    int maxSF = 0;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            maxEH = maxEH * arr[i];
            minEH = min(minEH * arr[i], 1);
            flag = 1;
        }

        else if (arr[i] == 0)
        {
            maxEH = 1;
            minEH = 1;
        }
        else
        {

            int temp = maxEH;
            maxEH = max(1, minEH * arr[i]);
            minEH = arr[i] * temp;
        }

        if (maxEH > maxSF)
            maxSF = maxEH;
    }

    if (flag == 0 && maxSF == 0)
        return 0;

    return maxSF;
}

int main()
{
    int arr[] = {1, -2, -3, 0, 7, -8, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSubarrayProduct(arr, n);
    return 0;
}