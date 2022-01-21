#include <iostream>
#include <vector>
using namespace std;

void CountingSort(int arr[], int n)
{

    // fing largest element in given array
    int largest = -1;
    for (int i = 0; i < n; i++)
    {
        largest = max(largest, arr[i]);
    }

    // creating array "freq" to count frequency of each element
    vector<int> freq(largest + 1, 0);

    // updating the freq array
    for (int i = 0; i < n; i++)
    {
        // iteration 1: index 4 of freq will have value 1
        freq[arr[i]]++;
    }

    //putting values back

    int j = 0;
    for (int i = 0; i < largest + 1; i++)
    {
        while (freq[i] > 0)
        {
            arr[j] = i;
            freq[i]--;
            j++;
        }
    }
}

int main()
{

    int arr[] = {4, 6, 8, 5, 1, 2, 2};
    int n = sizeof(arr) / sizeof(int);

    CountingSort(arr, n);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    return 0;
}