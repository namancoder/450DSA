#include <bits/stdc++.h>
using namespace std;
 
void productArray(int arr[], int n)
{
 
    if (n == 1) {
        cout << 0;
        return;
    }
 
    int i, temp = 1;
 
    int* prod = new int[(sizeof(int) * n)];
 
    memset(prod, 1, n);
 
    for (i = 0; i < n; i++) {
        prod[i] = temp;
        temp *= arr[i];
    }
 
    temp = 1;
 
    for (i = n - 1; i >= 0; i--) {
        prod[i] *= temp;
        temp *= arr[i];
    }
 
    for (i = 0; i < n; i++)
        cout << prod[i] << " ";
 
    return;
}
 
int main()
{
    int arr[] = { 10, 3, 5, 6, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The product array is: \n";
    productArray(arr, n);
}