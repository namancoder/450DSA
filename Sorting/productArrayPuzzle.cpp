

#include<bits/stdc++.h>
using namespace std;

// product array puzzle such that P[i] is equal to  the product of all the elements of A except A[i].

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int prod[n];
    prod[0]=1;

    // calculate product of all elements of array in consecutive manner and store it in prod array which is like product of array from left side with prod[0]==1.
    
    for(int i=1;i<n;i++)
    {
        prod[i]=prod[i-1]*a[i-1];
    }

    // now we need to calculate product of all elements of array from right side and store it in prod array which is like product of array from right side.
    int right=1;
    for(int i=n-1;i>=0;i--)
    {
        prod[i]=prod[i]*right;
        right*=a[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<prod[i]<<" ";
    }
    return 0;
}













