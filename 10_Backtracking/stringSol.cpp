#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void help(string s, int n, string res, vector<string> &word)
{
    for (int i = 1; i <= n; i++)
    {
        string ss = s.substr(0, i);
        int l = word.size();
        bool flag = false;

        for (int j = 0; j < l; j++)
            if (word[j] == ss)
                flag = true;

        if (flag)
        {
            if (i == n)
            {
                res += ss;
                cnt++;
                return;
            }
            help(s.substr(i, n - i), n - i, res + ss + " ", word);
        }
    }
}

int wordBreak(string s, vector<string> &dictionary)
{
    cnt = 0;
    help(s, s.size(), "", dictionary);
    return cnt;
}

int main()
{

    vector<string> dictionary = {"i", "like", "sam", "sung", "samsung", "mobile"};
    string str = "ilikesamsungmobile";

    cout << wordBreak(str, dictionary);

    return 0;
}