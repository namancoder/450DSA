
#include <bits/stdc++.h>
using namespace std;
//Using Kadanes Algorithm
int maxSubArraySum(int a[], int n)
{
    int max_so_far = 0;
    int max_ending_here = 0;
    for (int i = 0; i < n; i++)
    {
        max_ending_here += a[i];
        if (max_ending_here < 0)
            max_ending_here = 0;

        else if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}
//Using Dynamic Programming
int maxSubArraySumDP(int a[], int n)
{
    int max_so_far = a[0];
    int curr_max = a[0];
    for (int i = 0; i < n; i++)
    {
        curr_max = max(a[i], curr_max + a[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

//if we need the indices of the Largest Sum Contiguous Subarray
int maxSubArraySumIndices(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0, start = 0, end = 0, s = 0;
    for (int i = 0; i < size; i++)
    {
        max_ending_here += a[i];
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    cout << "Starting index " << start
         << endl
         << "Ending index " << end << endl;
    return max_so_far;
}
int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);
    int max_sum = maxSubArraySumIndices(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}
