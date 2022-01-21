#include <iostream>

using namespace std;

void arrayReverse(int arr[], int n)
{
    int start = 0;
    int end = n - 1;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        start += 1;
        end -= 1;
    }
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(int);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arrayReverse(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}