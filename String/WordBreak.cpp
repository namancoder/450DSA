#include <bits/stdc++.h>
using namespace std;

int dictionaryContains(string word)
{
    string dictionary[] = {"mobile", "samsung", "sam", "sung",
                           "man", "mango", "icecream", "and",
                           "go", "i", "like", "ice", "cream"};

    int size = sizeof(dictionary) / sizeof(dictionary[0]);
    for (int i = 0; i < size; i++)
    {
        if (dictionary[i].compare(word) == 0)
            return true;
    }
    return false;
}
// bool wordBreak(string str)
// {
//     int size = str.size();
//     if (size == 0)
//         return true;
//     for (int i = 1; i <= size; i++)
//     {
//         if (dictionaryContains(str.substr(0, i)) && wordBreak(str.substr(i, size - i)))
//         {
//             return true;
//         }
//     }

//     return false;
// }

// bool wordBreak(string str)
// {
//     int size = str.size();
//     if (size == 0)
//         return true;
//     bool wb[size + 1];
//     memset(wb, 0, sizeof(wb));

//     for (int i = 1; i <= size; i++) //start from 1 character words and increasing it to size aka n.
//     {
//         if (wb[i] == false && dictionaryContains(str.substr(0, i)))
//             wb[i] = true;

//         if (wb[i] == true)
//         {
//             if (i == size)
//                 return true;
//             for (int j = i + 1; j <= size; j++) //prefix left behind with wb[i]=true meaning prefix is a word in dictionary and checking for words in sufix
//             {
//                 if (wb[j] == false && dictionaryContains(str.substr(i, j - i)))
//                     wb[j] = true;

//                 if (j == size && wb[j] == true)
//                     return true;
//             }
//         }
//     }
//     cout << str << "   ";
//     for (int i = 0; i <= size; i++)
//     {
//         cout << wb[i] << " ";
//     }
//     cout << endl;
//     return false;
// }

bool wordBreak(string str)
{
    int i = 0, j = 1;

    int n = str.size();

    int totalSegnmented = 0;
    while (j <= n)
    {
        if (dictionaryContains(str.substr(i, j)))
        {
            totalSegnmented += j - i;
            i = j;
            j++;
        }
        else
            j++;
    }
    if (totalSegnmented == n)
        return true;

    return false;
}
int main()
{
    wordBreak("ilikesamsung") ? cout << "Yes\n" : cout << "No\n";
    wordBreak("iiiiiiii") ? cout << "Yes\n" : cout << "No\n";
    wordBreak("") ? cout << "Yes\n" : cout << "No\n";
    wordBreak("ilikelikeimangoiii") ? cout << "Yes\n" : cout << "No\n";
    wordBreak("samsungandmango") ? cout << "Yes\n" : cout << "No\n";
    wordBreak("samsungandmangokk") ? cout << "Yes\n" : cout << "No\n";
    wordBreak("kkkksamsungandmango") ? cout << "Yes\n" : cout << "No\n";
    return 0;
}