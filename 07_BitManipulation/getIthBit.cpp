#include <iostream>
#include <cmath>
using namespace std;

int getIthBit(int n, int i)
{
    int mask = 1 << i;
    return (n & mask) > 0 ? 1 : 0;
}

void clearIthBit(int &n, int i)
{
    int mask = ~(1 << i);
    n = (n & mask);
}

void setIthBit(int &n, int i)
{
    int mask = 1 << i;
    n = (n | mask);
}

void updateIthBit(int &n, int i, int v)
{
    clearIthBit(n, i);
    int mask = (v << i);
    n = n | mask;
}

void clearIBits(int &n, int i)
{
    int mask = (-1 << i);
    n = n & mask;
}

void clearInRange(int &n, int i, int j)
{
    int left = (-1 << (j + 1));
    int right = pow(2, i) - 1;
    int mask = left | right;
    n = (n & mask);
}

void replace(int &n, int m, int i, int j)
{
    clearInRange(n, i, j);
    int mask = m << i;
    n = (n | mask);
}

int countSetBits(int n)
{
    int count = 0;
    while (n > 0)
    {
        int lastBit = (n & 1);
        count += lastBit;
        n = n >> 1;
    }
    return count;
}

int countSetBitsFaster(int n)
{
    int ans = 0;
    while (n > 0)
    {
        n = (n & (n - 1));
        ans++;
    }
    return ans;
}

int main()
{
    cout << "Regular: " << countSetBits(81) << endl;
    cout << "Faster : " << countSetBitsFaster(81) << endl;

    return 0;
}