#include <iostream>

using namespace std;

void SelectionSort(int arr[], int n)
{

    for (int pos = 0; pos <= n - 2; pos++)
    {

        int current = arr[pos];
        int minimum_position = pos;
        cout << "assumed minimum: " << arr[minimum_position] << endl;

        for (int j = pos; j < n; j++)
        {
            if (arr[j] < arr[minimum_position])
            {
                minimum_position = j;
            }
        }
        cout << "correct minimum: " << arr[minimum_position] << endl;
        cout << "swapping " << arr[pos] << " with " << arr[minimum_position] << endl;
        swap(arr[pos], arr[minimum_position]);
        cout << endl;
    }
    
}

int main()
{

    int arr[] = {7, 8, 6, 5, 9, 1};
    int n = sizeof(arr) / sizeof(int);

    SelectionSort(arr, n);

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}