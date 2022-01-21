#include <iostream>
#include <vector>

using namespace std;

vector<int> BubbleSort(vector<int> &arr)
{
    int flag = 0;
    int n = arr.size();
    for (int times = 0; times < n; times++)
    {
        for (int j = 0; j < n - times - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    return arr;
}

int main()
{

    vector<int> arr = {4, 5, 1, 6, 7, 2, 7, 3, 78, 8};

    int n = sizeof(arr) / sizeof(int);

    BubbleSort(arr);

    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}