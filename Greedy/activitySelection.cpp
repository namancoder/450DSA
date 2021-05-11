#include <bits/stdc++.h>
using namespace std;

struct Activity
{
    int start, finish;
};

bool activityCompare(Activity s1, Activity s2)
{
    return (s1.finish < s2.finish);
}

void printMaxActivities(Activity arr[], int n)
{
    sort(arr, arr + n, activityCompare);

 
    int j = 0;
    cout << arr[j].start << " " << arr[j].finish << endl;

    for (int i = 1; i < n; i++)
    {
        if (arr[i].start >= arr[j].finish)
        {
            cout << arr[i].start << " " << arr[i].finish << endl;
            j=i;//IMPORTANT///////////////////
        }
    }
}
int main()
{
    Activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    int n = sizeof(arr) / sizeof(arr[0]);

    printMaxActivities(arr, n);

    return 0;
}
