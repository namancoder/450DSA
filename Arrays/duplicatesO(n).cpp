#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 1, 3, 6, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        arr[arr[i] % n] = arr[arr[i] % n] + n;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= n * 2)
            cout << i << endl; //Given an array of n elements that contains elements from 0 to n-1
    }

    return 0;
}