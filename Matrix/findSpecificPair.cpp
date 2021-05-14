#include <bits/stdc++.h>
using namespace std;
#define N 5

int findMaxValue(int mat[N][N])
{
    int maxValue = INT_MIN;
    int maxArr[N][N];

    maxArr[N - 1][N - 1] = mat[N - 1][N - 1];
    int maxv = mat[N - 1][N - 1];

    for (int j = N - 2; j >= 0; j--)
    {
        if(mat)
    }
}
int main()
{

    int mat[N][N] = {
        {1, 2, -1, -4, -20},
        {-8, -3, 4, 2, 1},
        {3, 8, 6, 1, 3},
        {-4, -1, 1, 7, -6},
        {0, -4, 10, -5, 1}};

    cout << findMaxValue(mat);
    return 0;
}