#include <bits/stdc++.h>
using namespace std;

stack<int> sol;

void help(int n)
{
    // base case
    if (n == 0)
    {
        return;
    }

    int last = n % 10;
    sol.push(last);
    help(n / 10);
};

int reverse(int n)
{

    help(n);
    int m = 0;
    int i = 1;
    while (!sol.empty())
    {
        m += sol.top() * i;
        sol.pop();
        i *= 10;
    }
    return m;
}

int main()
{

    cout<<reverse(456);

    return 0;
}