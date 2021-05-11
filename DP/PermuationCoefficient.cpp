#include <bits/stdc++.h>
using namespace std;

int permutationCoeff(int n, int k)
{
    int P[n + 1][k + 1];

    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < k + 1; j++)
            P[i][j] = 0;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, k); j++)
        {
            // Base Case
            if (j == 0)
                P[i][j] = 1;

            else
                P[i][j] = P[i - 1][j] +
                          (j * P[i - 1][j - 1]);
        }
    }
    return P[n][k];
}

// Driver Code
int main()
{
    int n = 10, k = 2;
    printf("Value of P(%d, %d) is %d ",
           n, k, permutationCoeff(n, k));
    return 0;
}
