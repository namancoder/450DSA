#include <bits/stdc++.h>
using namespace std;
bool subArrayExists(int arr[], int n)
{
    unordered_set<int> s1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0 || s1.find(sum) != s1.end())
            return true;

        s1.insert(sum);
    }

    return false;
}
int main()
{
    int arr[] = {1, 4, -2, -2, 5, -4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (subArrayExists(arr, n))
        cout << "Found a subarray with 0 sum";
    else
        cout << "No Such Sub Array Exists!";

    return 0;
}