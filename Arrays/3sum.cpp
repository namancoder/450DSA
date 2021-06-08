#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {4, 7, 10, 242, 2, 9, 16};
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 2;
    for (int i = 0; i < n-2; i++)
    {
        unordered_set<int> s;
        int curSum = sum - arr[i];
        for (int j = i + 1; j<n; j++)
        {
            if (s.find(curSum - arr[j]) != s.end())
            {
                cout << "YES";
                return 0;
            }
            else
                s.insert(arr[j]);
        }
        cout << "NO" << endl;
        return 0;
    }
}