#include <bits/stdc++.h>
using namespace std;

bool help2(string str)
{
    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] == ')')
        {

            char top = s.top();
            s.pop();

            int elementInside = 0;
            while (top != '(')
            {
                elementInside++;
                top = s.top();
                s.pop();
            }

            if (elementInside < 1)
            {
                return true;
            }
        }
        else
        {
            s.push(str[i]);
        }
    }

    return false;
}

bool help(string str)
{
    stack<char> s;

    for (char ch : str)
    {

        if (ch == ')')
        {

            char top = s.top();
            s.pop();

            int elementInside = 0;
            while (top != '(')
            {
                elementInside++;
                top = s.top();
                s.pop();
            }

            if (elementInside < 1)
            {
                return true;
            }
        }
        else
        {
            s.push(ch);
        }
    }

    return false;
}

bool duplicateParentheses(string str)
{
    return help(str);
}

int main()
{

    string exp = "((a+b)+((c+d)))";

    cout << duplicateParentheses(exp);
    cout << help2(exp);
    return 0;
}