#include <bits/stdc++.h>
using namespace std;
int getminnDiff(int a[], int n, int k)
{
    sort(a, a + n);
    int i, maxx, minn, ans;
    ans = a[n - 1] - a[0]; // this can be one possible solution

    for (i = 0; i < n; i++)
    {
        if (a[i] >= k) // since height of tower can't be -ve so taking only +ve heights
        {
            minn = min(a[0] + k, a[i] - k);
            maxx = max(a[n - 1] - k, a[i - 1] + k);
            ans = min(ans, maxx - minn);
        }
    }
    return ans;
}
int main()
{
    int arr[] = { 1,2,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << getminnDiff(arr, n, 2) << endl;

    return 0;
}