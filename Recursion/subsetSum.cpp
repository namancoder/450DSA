#include <bits/stdc++.h>
using namespace std;

void subsetSum(int arr[], int n)
{
    int total = 1 << n;

    for (int i = 0; i < total; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                sum += arr[j];
        }
        cout << sum << " ";
    }
}

int main()
{

    int arr[] = {5, 4, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    subsetSum(arr, size);
    return 0;
}