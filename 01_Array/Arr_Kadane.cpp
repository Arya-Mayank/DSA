#include <iostream>
using namespace std;

int kadane(int arr[], int n)
{

    int cs = 0;
    int largest = 0;
    for (int i = 0; i < n; i++)
    {
        cs = cs + arr[i];
        if (cs < 0)
        {
            cs = 0;
        }
        largest = max(largest, cs);
    }
    return largest;
}

int main()
{

    int arr[] = {2, 5, 6, -12, 5, -3, 8, 2, -3};
    int n = sizeof(arr)/sizeof(int);
    cout << kadane(arr, n) << endl;
    return 0;
}