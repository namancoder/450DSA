#include <bits/stdc++.h>
using namespace std;

void MergeON2(int arr[], int start, int mid, int end)
{
    int start2 = mid + 1;
    if (arr[mid] <= arr[start2])
        return;

    while (start <= mid && start2 <= end)
    {
        if (arr[start] <= arr[start2])
        {
            start++;
        }
        else
        {
            int value = arr[start2];
            int index = start2;

            while (index != start)
            {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[start] = value;
            start++;
            mid++;
            start2++;
        }
    }
}

// void Merge(int arr[] int l, int m, int r)
// {
//     int mx = max(a[m], a[r]) + 1;

//     int i = l;
//     int j = m + 1;
//     int k = l;
//     while (i <= m && j <= r && k <= r)
//     {
//         int e1 = arr[i] % mx;
//         int e2 = arr[j] % mx;
//         if (e1 <= e2)
//         {
//             arr[k] += e2 * mx;
//             i++;
//             k++;
//         }
//     }
// }

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        Merge(arr, l, mid, r);
    }
}
int main()
{
    int arr[] = {7, 6, 5, 4, 3, 2, 1};
    //int n = sizeof(arr) / sizeof(arr[0]);
    int n = 7;
    mergeSortON2(arr, 0, n - 1);
    //mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}