#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    int start, end;
};
bool compareInterval(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}

void mergeIntervals(Interval arr[], int n) //O(nlogn) + O(n)space
{
    if (n <= 0)
        return;

    stack<Interval> s;

    sort(arr, arr + n, compareInterval);
    s.push(arr[0]);

    for (int i = 1; i < n; i++)
    {
        Interval top = s.top();
        if (top.end < arr[i].start)
            s.push(arr[i]);
        else if (top.end < arr[i].end)
        {
            top.end = arr[i].end;
            s.pop();
            s.push(top);
        }
    }
    while (!s.empty())
    {
        Interval t = s.top();
        cout << "[" << t.start << "," << t.end << "] ";
        s.pop();
    }
    return;
}
void mergeIntervals1(Interval arr[], int n)
{
    // if(n<=0)
    // return;

    sort(arr, arr + n, compareInterval);

    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[index].end >= arr[i].start)
        {
            arr[index].end = max(arr[index].end, arr[i].end);
            arr[index].start = min(arr[index].start, arr[i].start);
        }
        else //when no overlapping happens
        {
            index++;
            arr[index] = arr[i];
        }
    }
    for (int i = 0; i <= index; i++)
        cout << "[" << arr[i].start << ", " << arr[i].end << "] ";
    return;
}
int main()
{
    Interval arr[] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeIntervals(arr, n);
    cout << endl;
    mergeIntervals1(arr, n);
    return 0;
}


// There can be three cases with two intervals 
// Casee 1:- No overlap

//  _______________        ________________
// | left interval |      | right interval |
// |_______________|      |________________|

//Case 2:- Partial overlap

//  _______________
// | left interval |
// |_______________|
//            ________________
//           | right interval |
//           |________________|

// Case 3:- Full overlap

//  _____________________
// |    left interval    |
// |_____________________|
//    ________________
//   | right interval |
//   |________________|

/*
class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& v) 
    {
        // Sort the intervals so that the comparison between two intervals becomes easier 
        sort(v.begin(),v.end());
        int n=v.size(),left=0,right=1;
        vector<vector<int>>ans; // For storing the result
        while(left<n && right<n)
        {
            // Case 1(No overlap so proceed)
            if(v[left][1]<v[right][0])
            {
                left=right;
                right++;
            }
            // Else overlap occurs (Case 2 or Case 3)
            else
            {
                // Case 3(Full overlap)
                if(v[left][1]>=v[right][1])
                {
                    // Mark the overlapped interval so that it can be deleted later
                    v[right]={-1,-1};
                    right++;
                }
                // Case 2(partial overlap)
                else
                {
                    // Extend the end point of the left interval( by making end point of left interval=end point of right interval) so that the intervals can be merged 
                    v[left][1]=v[right][1];
                    // Mark the partially overlapped interval so that it can be deleted later
                    v[right]={-1,-1};
                    right++;
                }
            }
        }
        // Now we'll traverse the intervals again and populate the ans vector i.e the result vector
        for(int i=0;i<n;i++)
        {
            // If any interval is marked then don't push it to the ans vector cause after merging marked intervals can't have their existence
            if(v[i][0]!=-1)
            {
                ans.push_back(v[i]);
            }
        }
        // Finally return the answer
        return ans;
    }
}
*/