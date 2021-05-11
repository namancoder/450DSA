#include <bits/stdc++.h>
using namespace std;

long long merge(int arr[], int l, int mid, int r)
{
    long long inv = 0;
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1];
    int b[n2];

    for (int i = 0; i < n1; i++)
        a[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        b[i] = arr[(mid + 1) + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            inv += n1 - i;
            k++;
            j++;
        }
    }
    while (i < n1)
        arr[k++] = a[i++];

    while (j < n2)
        arr[k++] = b[j++];
    return inv;
}
long long mergeSort(int arr[], int l, int r)
{
    long long inv = 0;
    if (l < r)
    {
        int mid = (l + r) / 2;
        inv = mergeSort(arr, l, mid) + mergeSort(arr, mid + 1, r) + merge(arr, l, mid, r);
    }
    return inv;
}
int getInvCount(int arr[], int n)
{
    multiset<int> set1;
    set1.insert(arr[0]);
    int invcount = 0;
    

    multiset<int>::iterator itset1;

    for (int i = 1; i < n; i++)
    {
        set1.insert(arr[i]);
        itset1 = set1.upper_bound(arr[i]);
        cout << arr[i] << " " << *itset1 <<" ";
        invcount += distance(itset1, set1.end());
        cout << invcount <<endl;
    }

    return invcount;
}
int32_t main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //cout << mergeSort(arr, 0, n - 1) << endl;
    cout << getInvCount(arr, n) << endl;
}
//Thanks to Apni Kaksha