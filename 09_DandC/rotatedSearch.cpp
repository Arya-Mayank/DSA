#include <bits/stdc++.h>

using namespace std;

int rotatedSearch(vector<int> v, int key)
{
    int n = v.size();

    int start = 0;
    int end = n - 1;

    while (start <= end)
    {

        int mid = (start + end) / 2;

        if (v[mid] == key)
        {
            return mid;
        }

        // if mid on line 1 or left part
        if (v[start] <= v[mid])
        {
            if (key >= v[start] and key <= v[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            if (key <= v[end] and key >= v[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{

    vector<int> arr = {7, 8, 10, 12, 1, 3, 5, 6};

    cout << rotatedSearch(arr, 12);

    return 0;
}