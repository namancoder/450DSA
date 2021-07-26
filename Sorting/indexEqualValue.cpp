class Solution
{
public:
    vector<int> valueEqualToIndex(int arr[], int n)
    {
        // code here
        vector<int> vect;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == i + 1)
                vect.push_back(arr[i]);
        }

        return vect;
    }
};