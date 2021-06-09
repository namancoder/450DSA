#include <bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);

    int platform = 1;
    int result = 1;
    int j = 0;
    for (int i = 1; i < n&& j<n;)
    {
        if (arr[i] >= dep[j])
        {
            platform--;
            j++;
        }
        else if (arr[i] < dep[j])
        {
            platform++;
            i++;
        }

        if (platform > result)
             result=platform;
    }
    return result;
}

int main()
{
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum Number of Platforms Required = "
         << findPlatform(arr, dep, n);
    return 0;
}