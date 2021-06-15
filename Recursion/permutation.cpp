
//https://i.stack.imgur.com/z8wvD.png

#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int> a)
{
    for (auto i : a)
        cout << i << " ";
    printf("\n");
}

void recurPermute(int index, vector<int> &nums)
{
    if (index == nums.size())
    {
        printArr(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        recurPermute(index + 1, nums);
        swap(nums[index], nums[i]);
    }
}

int main()
{
    vector<int> arr;

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);

    recurPermute(0, arr);
    return 0;
}
