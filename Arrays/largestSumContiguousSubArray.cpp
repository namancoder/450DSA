#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int current_sum =0;
    int maximum_sum =0;

    for(int i=0;i<n;i++)
    {
        current_sum+=arr[i];
        current_sum = current_sum<0?0:current_sum;
        maximum_sum = max(maximum_sum,current_sum);
    }

    cout << maximum_sum <<endl;


    return 0;
}