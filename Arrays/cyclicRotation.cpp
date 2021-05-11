#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {4, 7, 10, 242, 2, 9, 16};
    int n = sizeof(arr) / sizeof(arr[0]);

    int x = arr[n - 1];

    for (int i = n - 1; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = x;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    return 0;
}