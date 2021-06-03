#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s)
{
    if (s.empty())
        return "";
    if (s.size() == 1)
        return s;

    int ms = 0;
    int ml = 1;
    int i = 0;

    while (i < s.size())
    {
        int j = i, k = i;

        while (k < s.size() - 1 && s[k + 1] == s[k])
            ++k;
        i = k + 1;

        while (j > 0 && k < s.size() - 1 && s[k + 1] == s[j - 1])
        {
            k++, j--;
        }

        int nl = k - j + 1;
        if (nl > ml)
        {
            ms = j;
            ml = nl;
        }
    }
    return s.substr(ms, ml);
}

int main()
{
    string s = longestPalindrome("ggggnamangg");
    cout << s << endl;
    return 0;
}