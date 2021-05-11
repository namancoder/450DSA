#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {4, 7, 10, 242, 2, 9, 16};

    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    int k = 2;
    cout << endl;
    int ks = arr[k - 1];
    int kb = arr[n - k ];

    cout << ks << " " << kb << endl;
    return 0;
}