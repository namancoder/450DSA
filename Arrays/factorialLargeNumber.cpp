#include <bits/stdc++.h>
using namespace std;
void multiply(int *a, int &n, int no)
{
    int carry = 0;
    for (int i = 0; i < n; i++)
    {
        int prod = a[i] * no + carry;
        a[i] = prod % 10;
        carry = prod / 10;
    }
    while (carry)
    {
        a[n] = carry % 10;
        carry = carry / 10;
        n++;
    }
}
void bigFactorial(int number)
{
    int *a = new int[1000];
    for (int i = 0; i < 1000; i++)
        a[i] = 0;
    a[0] = 1;
    int n = 1;
    for (int i = 2; i <= number; i++)
    {
        multiply(a, n, i);
    }
    //print the array
    for (int i = n - 1; i >= 0; i--)
    {
        cout << a[i];
    }
}
int main()
{
    int number = 7;
    bigFactorial(number);
    return 0;
}