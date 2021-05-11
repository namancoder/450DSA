#include <bits/stdc++.h>
using namespace std;

void printUnion(int arr1[], int arr2[], int n1, int n2)
{
    set<int> hs;

    for (int i = 0; i < n1; i++)
        hs.insert(arr1[i]);

    for (int i = 0; i < n2; i++)
        hs.insert(arr2[i]);

    for (auto it = hs.begin(); it != hs.end(); it++)
        cout << *it << " ";
    cout << endl;
}

void printIntersection(int arr1[], int arr2[], int n1,
                       int n2)
{
    set<int> hs;

    for (int i = 0; i < n1; i++)
        hs.insert(arr1[i]);

    for (int i = 0; i < n2; i++)

        if (hs.find(arr2[i]) != hs.end())
            cout << arr2[i] << " ";
}

int main()
{
    int arr1[] = {7, 1, 5, 2, 3, 6};
    int arr2[] = {3, 8, 6, 20, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printUnion(arr1, arr2, n1, n2);
    printIntersection(arr1, arr2, n1, n2);

    return 0;
}