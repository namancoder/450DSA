// Approach : The concept here is that if there is a larger wall to the right then the water can be retained with height
// equal to the smaller wall on the left. If there are no larger walls to the right then start from the left. There must
// be a larger wall to the left now. Let’s take an example if the heights are {….,3, 2, 1, 4,….}, So here 3 and 4 are boundaries
// the heights 2 and 1 are submerged and cannot act as boundaries. So at any point or index knowing the previous boundary is sufficient
//  if there is a higher or equal length boundary in the remaining part of the array.
// If not then traverse the array backwards and now must be a larger wall to the left.

#include <iostream>
using namespace std;

int maxWater(int arr[], int size)
{
    int prev = arr[0];

    int prev_index = 0;
    int water = 0;
    int temp = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] >= prev)
        {
            prev = arr[i];
            prev_index = i;

            temp = 0;
        }

        else
        {
            water += prev - arr[i];
            temp += prev - arr[i];
        }
    }

    if (prev_index < size)
    {
        water -= temp;
        prev = arr[size];

        for (int i = size; i >= prev_index; i--)
        {
            if (arr[i] >= prev)
                prev = arr[i];
            else
                water += prev - arr[i];
        }
    }

    return water;
}
int main()
{
    int arr[] = {3, 0, 2, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << maxWater(arr, n - 1);
    return 0;
}