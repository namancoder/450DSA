#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int a[n][m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int row = 0;

    int maxRowIndex = 0;
    int count = 0;
    while (n--)
    {
        int tempCount = 0;
        for (int i = 0; i < m; i++)
        {
            if (a[row][i] == 1)
                tempCount++;
        }
        if (tempCount > count)
        {
            count = tempCount;
            maxRowIndex = row;
        }
        row++;
    }
    cout << maxRowIndex << endl;
    return 0;
}