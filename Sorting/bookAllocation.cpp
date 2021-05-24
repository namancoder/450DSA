#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int m, int curr_min)
{
    int studentUsed = 1;
    int pagesReading = 0;

    for (int i = 0; i < n; i++)
    {
        if (pagesReading + arr[i] > curr_min)
        {
            studentUsed++;
            pagesReading = arr[i];
            if (studentUsed > m)
                return false;
        }
        else
            pagesReading += arr[i];
    }
    return true;
}
int findPages(int arr[], int n, int m)
{
    int sum = 0;

    if (n < m)
        return -1;

    int allPagesSum = 0;
    for (int i = 0; i < n - 1; i++)
        allPagesSum += arr[i];

    int s = arr[n - 1];
    int e = allPagesSum;
    int ans = INT_MAX;

    while (s <= e)
    {

        int mid = (s + e) / 2;
        if (isPossible(arr, n, m, mid))
        {
            ans = min(ans, mid);
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
            //inceease the number of pages
        }
    }
    return ans;
}
void solve()
{
    int n, m;
    cin >> n >> m;

    int arr[1000];
    for (int j = 0; j < n; j++)
        cin >> arr[j];
    cout << findPages(arr, n, m) << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}


/*
1 4 2 10 20 30 40
60
*/