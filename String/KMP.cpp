#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100005
int reset[MAX_N];
void KMPpreprocess(string pat)
{
    int i = 0, j = -1;
    reset[0] = -1;
    while (i < pat.size())
    {
        while (j >= 0 && pat[i] != pat[j])
        {
            j = reset[j];
        }
        i++;
        j++;
        reset[i] = j;
    }
}
void KMPSearch(string str, string pat)
{
    KMPpreprocess(pat);
    int i = 0, j = 0;
    while (i < str.size())
    {
        while (j >= 0 && str[i] != pat[j])
        {
            j = reset[j];
        }
        i++;
        j++;
        if (j == pat.size())
        {
            cout << "Pattern is found at " << i - j << endl;
            j = reset[j];
        }
    }
}

int main()
{
    string str, pat;
    str = "AABAACAADAABAABA";
    pat = "AABA";
    KMPSearch(str, pat);
    return 0;
}