#include <iostream>

using namespace std;

// arrays are passed into functions using pass by reference

int printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        //  update values of arraya
        arr[i] = arr[i] * 2;
        cout << arr[i] << ", ";
    }
}

int main()
{

    int arr[100] = {0};
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    //  insert values in array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // display values of array
    printArray(arr, n);

    return 0;
}