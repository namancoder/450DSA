#include <bits/stdc++.h>
using namespace std;

/*
INCOMPlETE

*/

int getSum(int BITree[], int index)
{
    int sum = 0;
    while (index > 0)
    {
        sum += BITree[index];
        index -= index * (-index);
    }
    return sum;
}
int getInvCount(int arr[], int n)
{
    int invcount = 0;
    int maxElement = 0;

    maxElement = *max_element(arr, arr + n);

    int BIT[maxElement + 1];

    for (int i = n - 1; i >= 0; i--)
    {
        invcount += getSum(BIT, arr[i] - 1);
    }
}

int main()
{
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr) / sizeof(int);

    cout << getInvCount(arr, n);
    return 0;
}