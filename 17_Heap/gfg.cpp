#include <bits/stdc++.h>

using namespace std;

void checkString(string s)
{
    int v = 0;
    int c = 0;

    int size = s.length();

    for (int i = 0; i < size; i++)
    {
        int current = s[i];
        if (current == 97 || current == 101 || current == 105 || current == 111 || current == 117)
        {
            v++;
        }
        else
        {
            c++;
        }
    }

    if (v > c)
        cout << "Yes";
    else if (c > v)
        cout << "No";
    else
        cout << "Same";

    cout << endl;
}

int countChars(string s1, string s2)
{

    // Your code here
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for (int i = s1.length() - 1; i >= 0; i--)
    {
        for (int j = s2.length() - 1; j >= 0; j--)
        {
            if (s1[i] == s2[j])
            {
                s2.pop_back();
                s1.pop_back();
                break;
            }
        }
    }

    return max(s1.length(), s2.length());
}

void follPatt(string s)
{
    // Your code here
    if (s[s.length() - 1] == 'x')
    {
        cout << "0";
        return;
    }

    int xcount = 0;
    int ycount = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'x')
        {
            xcount++;
        }
        else
        {
            ycount++;
        }
    }

    if (xcount / ycount == 1)
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
    cout << endl;
}

void help(string s)
{
    stack<char> stack;
    int xc = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'x')
        {
            xc++;
            stack.push(s[i]);
        }
        else
        {
            if (xc == 0)
            {
                cout << "0" << endl;
                return;
            }
            else
            {
                while (xc > 0 && i < s.length())
                {
                    stack.push(s[i]);
                    xc--;
                    i++;
                }
                if (xc > 0)
                {
                    cout << "0" << endl;
                    return;
                }
                else if (stack.top() == 'x')
                {
                    cout << "0" << endl;
                    return;
                }
            }
        }
    }
    if (stack.top() == 'x')
    {
        cout << "0" << endl;
    }
    else
    {
        cout << "1" << endl;
    }
}

int main()
{

    // string s = "the quick brown fox jumps over the lazy dog";
    // checkString(s);
    help("xxyyxxy");
    return 0;
}