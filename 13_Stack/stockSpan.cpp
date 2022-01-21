#include <bits/stdc++.h>
using namespace std;

void help(int price[], int n, int span[])
{

    stack<int> s; // stack of indices
    s.push(0);    // first index

    span[0] = 1; // span of first days is 1
    for (int i = 1; i < n; i++)
    {

        int currentPrice = price[i];
        while (!s.empty() && price[s.top()] <= currentPrice)
        {
            s.pop();
        }

        if (!s.empty())
        {
            span[i] = i - s.top();
        }
        else
        {
            span[i] = i + 1;
        }

        s.push(i);
    }
}


int main()
{

    int stocks[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(stocks) / sizeof(stocks[0]);
    int span[10000] = {0};

    help(stocks,n, span);

    for(int i=0;i<n;i++){
        cout << span[i] << " ";
    }
    return 0;
}