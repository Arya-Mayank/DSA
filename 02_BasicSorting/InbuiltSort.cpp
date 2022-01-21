#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
    // comparison sign here will result in inc or dec order
    // a<b gives increasaing order
    // a>b gives decreasaing order
    return a < b;
}

int main()
{
    int arr[] = {5, 76, -23, 756, 43, -4, -12, 87, 16, 33};
    int n = sizeof(arr) / sizeof(int);

    // inbuilt sort function provided in algo header file

    sort(arr, arr + n, compare); // compare func passed as parameter
                                 // optional


    // another way to reverse order of array => reverse(arr, arr+arr.size());
    // reverse(arr,arr+n);

    for (auto x : arr)
    {
        cout << x << " ";
    }

    return 0;
}