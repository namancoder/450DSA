#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int k, int mid)
{
    int painter = 1;
    int boardUnit = 0;
    for (int i = 0; i < n; i++)
    {
        if (boardUnit + arr[i] > mid)
        {
            painter++;
            boardUnit = arr[i];
            if (painter > k)
                return false;
        }
        else
        {
            boardUnit += arr[i];
        }
    }
    return true;
}

int main()
{
    int k, n;
    cin >> k >> n;
    int arr[1000];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    int s = *max_element(arr, arr + n);
    int e = sum;
    int ans = 0;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (isPossible(arr, n, k, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    cout << "ANS is" << ans << endl;

    return 0;
}