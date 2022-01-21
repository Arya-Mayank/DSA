#include <iostream>
#include <cmath>
using namespace std;

int fastExpo(int n, int i)
{
    int ans = 1;

    while (i > 0)
    {
        int lastBit = (i & 1);

        if (lastBit)
        {
            ans *= n;
        }
        n = n * n;
        i = i >> 1;
    }
    return ans;
}

int convertToBinary(int n)
{
    int ans=0;
    int power =1;
    while (n > 0)
    {
        int digit = (n&1);
        ans += power * digit;
        n=n>>1;
        power*=10;
    }
    return ans;
}

int main()
{

    cout << convertToBinary(27);

    return 0;
}