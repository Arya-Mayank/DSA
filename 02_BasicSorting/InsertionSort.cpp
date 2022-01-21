#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int current = arr[i];
        int prev = i - 1;

        while (prev >= 0 and arr[prev] > current)
        {
            arr[prev + 1] = arr[prev];
            prev = prev - 1;
        }
            arr[prev + 1] = current;
    }
} 

int main()
{
    int arr[] = {1,6,4,5};
    int n = sizeof(arr)/sizeof(int);

    InsertionSort(arr,n);

    for (int x: arr){
        cout << x << " ";
    }

    return 0;
}