#include <iostream>

using namespace std;

void subArray(int arr[], int n)
{
    
    int highest =0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k < j; k++)
            {
                sum += arr[k];
                cout << arr[k] << ", ";
            }
            if (sum>highest){
                highest = sum;
            }
            if(sum!=0){
                cout << "sum: " << sum << endl;
            }
            cout << endl;

        }
    }

    cout << "largest sum: " << highest << endl;
    
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(int);

    subArray(arr, n);

    return 0;
}