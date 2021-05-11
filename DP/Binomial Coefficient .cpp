#include <bits/stdc++.h>
using namespace std;

int binomialCoefficient(int n, int k)
{
    int C[n + 1][k + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][k];
}

int binCoeffSpace(int n, int k)//generating pascal's triangle with every loop
{
    int C[k + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, k); j > 0; j--)
        {
            C[j] += C[j - 1];
        }
    }
    return C[k];
}
int main()
{

    int n = 5, k = 2;
    //cout << binomialCoefficient(n, k) << endl;
    cout << binCoeffSpace(n, k) << endl;

    return 0;
}
