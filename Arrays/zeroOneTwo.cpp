//https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0//


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1,2,0,0,2,1,0,2,0,1,2,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    int zero=0,one=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        zero++;
        else if(arr[i]==1)
        one++;
        else{}
    }

    for(int i=0;i<n;i++)
    {
        if(zero-->0)
        arr[i]=0;
        else if (one-->0)
        arr[i]=1;
        else
        arr[i]=2;
    }

    for(int i=0;i<n;i++)
    cout << arr[i] <<" ";
    return 0;
}