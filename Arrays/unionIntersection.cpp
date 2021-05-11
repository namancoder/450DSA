/*
1) Use two index variables i and j, initial values i = 0, j = 0 
2) If arr1[i] is smaller than arr2[j] then print arr1[i] and increment i. 
3) If arr1[i] is greater than arr2[j] then print arr2[j] and increment j. 
4) If both are same then print any of them and increment both i and j. 
5) Print remaining elements of the larger array.



UNION

*/

#include <bits/stdc++.h>
using namespace std;

void printUnion(int a[], int b[], int n, int m)
{
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            cout << a[i] << " ";
            i++;
        }
        else if (b[j] < a[i])
        {
            cout << b[j] << " ";
            j++;
        }
        else
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }

    while (i < n)
        cout << a[i++] << " ";

    while (j < m)
        cout << b[j++] << " ";
}
void printIntersection(int a[], int b[], int n, int m)
{
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
            i++;
        else if (b[j] < a[i])
            j++;
        else
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
}
int main()
{
    int arr1[] = {4, 7, 10, 242, 2, 9, 16};
    int arr2[] = {8, 3, 5, 1, 7, 2, 10};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    sort(arr1, arr1 + n1);
    sort(arr2, arr2 + n2);

    printUnion(arr1, arr2, n1, n2);
    cout << endl;
    printIntersection(arr1, arr2, n1, n2);

    return 0;
}