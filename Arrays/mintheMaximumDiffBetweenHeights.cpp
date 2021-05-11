#include <bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k)
{
    if (n == 1)
        return 0;

    sort(arr, arr + n);

    int ans = arr[n - 1] - arr[0];

    int small = arr[0] + k;
    int big = arr[n - 1] - k;
    if (small > big)
        swap(small, big);

    //Traversing elements

    for (int i = 1; i < n - 1; i++)
    {
        int subtract = arr[i] - k;
        int add = arr[i] + k;
        if (subtract >= small || add <= big) //basically this condtion is too check whhether the made changes make any difference in the current answer;
            continue;

        if (big - subtract <= add - small)
            small = subtract;
        else
            big = add;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return min(ans, big - small);
}

int getMinDiff1(int a[], int n, int k)
{
    sort(a, a + n);
    int i, mx, mn, ans;
    ans = a[n - 1] - a[0];

    for (i = 0; i < n; i++)
    {
        if (a[i] >= k) // since height of tower can't be -ve so taking only +ve heights
        {
            mn = min(a[0] + k, a[i] - k);
            mx = max(a[n - 1] - k, a[i - 1] + k);
            cout << a[i] << "-->>" << a[i - 1] + k << endl;
            ans = min(ans, mx - mn);
        }
    }
    return ans;
}
int main()
{
    int arr[] = {6, 10, 14, 14, 14, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;
    cout << getMinDiff(arr, n, k) << endl;
    cout << getMinDiff1(arr, n, k) << endl;
    return 0;
}