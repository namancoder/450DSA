#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {4,7,10,242,2,9,16};
    int n = sizeof(arr)/sizeof(arr[0]);

    int max = INT_MIN;
    int min = INT_MAX;

    for(int i=0;i<n;i++)
    {
        if(max<arr[i])
        max=arr[i];
        if(min>arr[i])
        min=arr[i];
    }

    cout << min << " "<<max<<endl;
    return 0;
}