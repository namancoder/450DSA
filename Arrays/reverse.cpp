#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {4,7,10,242,2,9,16};

    int n = sizeof(arr)/sizeof(arr[0]);
    int arr2[n];
    int j = 0;
    for(int i=n-1;i>=0;i--)
    {
    arr2[j++]=arr[i];
    }
    for(int i=0;i<n;i++)
    cout << arr2[i]<<endl;

    return 0;
}