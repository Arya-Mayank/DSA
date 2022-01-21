#include <bits/stdc++.h>

using namespace std;

vector<string> solution;

int ways;

// int check(vector<string> &dictionary, string str)
// {
//     // base case
//     if (str.length() == 0)
//     {
//         return 1;
//     }

//     // rec case

//     // for every word in dictionary

//     for (int i = 0; i < dictionary.size(); i++)
//     {
//         // check if word in str
//         if (str.find(dictionary[i]) != string::npos)
//         {
//             str.erase(0, dictionary[i].length());

//             ways += check(dictionary, str);
//         }
//     }

//     return ways;
// }

void help(string s, int size, string res, vector<string> &word)
{

    for (int i = 1; i <= size; i++)
    {
        string ss = s.substr(0, i);
        int l = word.size();
        bool flag = false;

        for (int j = 0; j < l; j++)
        {
            if (word[j] == ss)
            {
                flag = true;
            }
        }

        if (flag)
        {
            if (i == size)
            {
                res += ss;
                ways++;
                return;
            }
            help(s.substr(i, size - i), size - i, res + ss + " ", word);
        }
    }
}

int wordBreak(string s, vector<string> &dictionary)
{
    ways = 0;
    help(s, s.size(), "", dictionary);

    return ways;
}

int main()
{
    vector<string> dictionary = {"i", "like", "sam", "sung", "samsung", "mobile"};
    string str = "ilikesamsungmobile";

    cout << wordBreak(str, dictionary);

    return 0;
}