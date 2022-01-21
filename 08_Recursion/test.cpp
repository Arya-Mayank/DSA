#include <bits/stdc++.h>
using namespace std;

// void swapElements(int arr[], int sizeof_array)
// {

//     // Your code here
//     for (int i = 0; i <= sizeof_array; i++)
//     {
//         if(i+2 < sizeof_array){
//             swap(arr[i], arr[i + 2]);
//         }

//     }
// }

// int main()
// {
//     int arr[]={1,2,3,4,5};
//     int n = 5;

//     swapElements(arr, 5);

//     for (int x : arr)
//     {
//         cout << x << " ";
//     }
// }

// map<int, int> m;

// int countSpecials(int arr[], int sizeof_array, int K)
// {
//     int f = floor(sizeof_array/K);
//     int count = 0;
//     for (int i = 0; i < sizeof_array; i++)
//         m[arr[i]]++;

//     map<int,int>::iterator itr;

//     for(itr = m.begin(); itr != m.end(); itr++){
//         if(itr->second == f){
//             count++;
//         }
//     }

//     return count;
// }

// int main(){

//     int arr[]={1,4,1,2,4};
//     cout << countSpecials(arr,5,2);

//     map<int,int>::iterator itr;

//     for(itr = m.begin(); itr != m.end();itr++){
//         cout << '\t' << itr->first
//              << '\t' << itr->second << '\n';
//     }

//     return 0;
// }

int columnWithMaxZeros(vector<vector<int>> arr, int N)
{
    vector<int> count;

    for (int j = 0; j < N; j++)
    {
        int columnZeroes = 0;
        for (int i = 0; i < N; i++)
        {
            if (arr[i][j] == 0)
            {
                columnZeroes++;
            }
        }
        count.push_back(columnZeroes);
    }

    int max = *max_element(count.begin(), count.end());

    auto it = find(count.begin(), count.end(), max);

    int index = it - count.begin();

    return index;
}

int main()
{

    vector<vector<int>> arr = {
        {1, 1, 0},
        {1, 1, 0},
        {1, 1, 0}};

    cout << columnWithMaxZeros(arr, 3);

    return 0;
}