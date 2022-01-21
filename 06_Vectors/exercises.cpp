// **************** SORT CABS **********************
// #include <bits/stdc++.h>

// using namespace std;

// int distance(pair<int, int> p)
// {
//     int a = p.first;
//     int b = p.second;
//     return ((a * a) + (b * b));
// }

// bool compare(pair<int, int> p1, pair<int, int> p2)
// {

//     return distance(p1) < distance(p2);
// }

// vector<pair<int, int>> sortCabs(vector<pair<int, int>> v)
// {

//     sort(v.begin(), v.end(), compare);

//     return v;
// }

// int main()
// {

//     vector<pair<int, int>> arr = {{2, 3}, {1, 2}, {3, 4}, {2, 4}, {1, 4}};

//     vector<pair<int, int>> m = sortCabs(arr);

//     for (auto cab : m)
//     {
//         cout << cab.first << " " << cab.second << endl;
//     }
//     return 0;
// }

// **************** SORT FRUITS **********************

// #include <bits/stdc++.h>
// using namespace std;

// bool compareName(pair<string, int> p1, pair<string, int> p2)
// {
//     string a = p1.first;
//     string b = p2.first;

//     return a < b;
// }

// bool comparePrice(pair<string, int> p1, pair<string, int> p2)
// {
//     int a = p1.second;
//     int b = p2.second;

//     return a < b;
// }

// vector<pair<string, int>> sortFruits(vector<pair<string, int>> v, string S)
// {
//     // your code  goes here
//     if (S == "price")
//     {
//         sort(v.begin(), v.end(), comparePrice);
//     }else{
//         sort(v.begin(), v.end(), compareName);
//     }
//     return v;
// }

// int main()
// {
//     vector<pair<string ,int>> fruits = {{"mango",100},{"guava", 70},{"grapes",40},{"apple", 60}, {"banana", 30}};
//     vector<pair<string, int>> m = sortFruits(fruits, "name");

//     for(int i=0;i<m.size();i++){
//         cout << m[i].first << " " << m[i].second << endl;
//     }
//     return 0;
// }

// **************** ROTATE MAT CLOCKWISE**********************

// #include <bits/stdc++.h>
// using namespace std;

// // void rotate(vector<vector<int>> &matrix)
// // {
// //     for(int j=0;j<matrix.size();j++){
// //         for(int i=matrix.size()-1;i>=0;i--){
// //             cout << matrix[i][j] <<" ";
// //         }
// //         cout << endl;
// //     }
// // }

// void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int a = 0;
//         int b = n-1;
//         while(a<b){
//             for(int i=0;i<(b-a);++i){
//                 swap(matrix[a][a+i], matrix[a+i][b]);
//                 swap(matrix[a][a+i], matrix[b][b-i]);
//                 swap(matrix[a][a+i], matrix[b-i][a]);
//             }
//             ++a;
//             --b;
//         }
//     }

// int main()
// {

//     vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

//     rotate(mat);

//     for(auto x: mat){
//         for(auto m: x){
//             cout << m << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// **************** MAKE ZEROES **********************

#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> findZeroes(vector<vector<int>> arr){
    vector<pair<int,int>> m;
    for(int i =0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            if(arr[i][j] == 0){
                m.push_back(pair<int,int>(i,j));
            }
        }
    }
    return m;
}


vector<vector<int>> makeZeroes(vector<vector<int>> arr)
{
    // your code goes here
    vector<pair<int,int>> n = findZeroes(arr);

    for(int z =0;z<n.size();z++){
        int row = n[z].first;
        int col = n[z].second;

        for(int j=0;j<4;j++){
            arr[row][j] =0;
        }

        for(int i=0;i<4;i++){
            arr[i][col]=0;
        }
    }

    return arr;
}

int main()
{

    vector<vector<int>> arr = { {5, 4, 3, 9},
                                {2, 0, 7, 6},
                                {1, 3, 4, 0},
                                {9, 8, 3, 4}
    };

    vector<vector<int>> m = makeZeroes(arr);

    for(auto x: m){
        for(auto n:x){
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}