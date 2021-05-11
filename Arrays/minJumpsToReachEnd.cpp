#include <bits/stdc++.h>
using namespace std;
// int MinJUMPS(int arr[], int n)
// {
//     if (n <= 1)
//         return 0;
//     int m_r = nums[0];
//     int step = nums[0];
//     int jump = 1;
//     for (int)
// }

int jump(int nums[], int n)
{
    if (n <= 1 || nums[0] == 0)
        return 0;

    int m_r = nums[0];
    int step = nums[0];
    int jump = 1;
    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
            return jump;
        m_r = max(m_r, i + nums[i]);
        step--;
        if (step == 0)
        {
            jump += 1;

            step = m_r - i;
        }
    }
    return jump;
}

int jump1(int arr[], int n)
{
    if (arr[0] == 0 || n <= 1)
        return 0;

    int max_jump = arr[0];
    int step = arr[0];
    int jump = 1;
    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
            return jump;

        max_jump = max(max_jump, i + arr[i]);
        step--;
        if (step == 0)
        {
            jump++;
            step = max_jump - i;
        }
    }
    return jump;
}
int main()
{
    int arr[] = {2, 3, 1, 1, 4};

    int n = sizeof(arr) / sizeof(arr[0]);
    //cout << MinJUMPS(arr, n) << endl;
    cout << jump1(arr, n) << endl;
    return 0;
}