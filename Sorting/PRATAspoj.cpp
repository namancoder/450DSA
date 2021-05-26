#include <bits/stdc++.h>
using namespace std;

bool isPossible(int ranks[], int p, int cooks, int mid)
{
    int count1 = 0;
    for (int i = 0; i < cooks; i++)
    {
        int j = 1;
        int sum = 0;
        while (sum <= mid)
        {
            sum += j * ranks[i];
            count1++;
            j++;
        }
        count1--;
    }
    if (count1 >= p)
        return true;
    else
        return false;
}
int findMIn(int ranks[], int p, int cooks)
{
    int s = 0, ans = INT_MAX;
    int e = INT_MAX;

    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (isPossible(ranks, p, cooks, mid))
        {
            e = mid - 1;
            ans = min(mid, ans);
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}
int main()
{

    int p, cooks;
    cin >> p >> cooks;
    int ranks[cooks];
    for (int i = 0; i < cooks; i++)
        cin >> ranks[i];

    cout << findMIn(ranks, p, cooks) << endl;
    return 0;
}