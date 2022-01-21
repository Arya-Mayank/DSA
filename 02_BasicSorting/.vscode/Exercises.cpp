// #include <bits/stdc++.h>
// using namespace std;

// vector<int> sortingWithComparator(vector<int> a, bool flag)
// {
//     if (flag)
//     {
//         sort(a.begin(), a.end());
//         return a;
//     }
//     else
//     {
//         sort(a.begin(), a.end(), greater<int>());
//         return a;
//     }
// }

// int main()
// {

//     vector<int> arr = {5, 8, 2, -12, 9, 56, -7, 34};
//     bool flag = true;
//     vector<int> m = sortingWithComparator(arr, flag);

//     for (auto x : m)
//     {
//         cout << x << " ";
//     }
//     return 0;
// }

// *************************************************************************************************************

// #include <bits/stdc++.h>
// using namespace std;

// vector<pair<int, int>> sortCartesian(vector<pair<int, int>> v)
// {
//     int N = v.size();
//     // your code goes here
//     for (int i = 0; i < N - 1; i++)
//     {
//         for (int j = 0; j < N - i - 1; j++)
//         {
//             if (v[j].first > v[j + 1].first)
//             {
//                 swap(v[j], v[j + 1]);
//             }
//             else if (v[j].first == v[j + 1].first)
//             {
//                 if (v[j].second > v[j + 1].second)
//                 {
//                     swap(v[j], v[j + 1]);
//                 }
//             }

//         }
//     }
//     return v;
// }

// int main()
// {

//     vector<pair<int, int>> arr = {{3, 4}, {2, 3}, {3, 7}, {3, 4}, {1, 5}};

//     vector<pair<int, int>> m = sortCartesian(arr);

//     for (int i = 0; i < m.size(); i++)
//     {
//         cout << "(" << m[i].first << "," << m[i].second << ")"
//              << " ";
//     }

//     return 0;
// }

// ***************************************************************

// #include<bits/stdc++.h>
// using namespace std;

// int pairSticks(vector<int> length, int D)
// {
//     // your code goes here
//     sort(length.begin(), length.end());
//     int validPairs = 0;
//     for (int i = 0; i < length.size(); i++)
//     {
//         for (int j = i + 1; j < length.size(); j++)
//         {
//             while (abs(length[i] - length[j]) <= D)
//             {
//                 validPairs++;
//                 length.erase(length.begin() + i);
//                 length.erase(length.begin() + j);
//             }
//         }
//     }

//     return validPairs;

// }

// int main()
// {

//     vector<int> a = {1,3,3,9,4};

//     int m = pairSticks(a, 2);

//     cout << m;

//     return 0;
// }

// *****************************************************************************

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int defkin(int W, int H, vector<pair<int, int>> position)
{

    //  two empty vectors to hold x and y values
    vector<int> xValues;
    vector<int> yValues;

    // fill xValues and yValues
    for (int i = 0; i < position.size(); i++)
    {
        xValues.push_back(position[i].first);
        yValues.push_back(position[i].second);
    }

    // sort x and y value vectors
    sort(xValues.begin(), xValues.end());
    sort(yValues.begin(), yValues.end());

    // create vector dx and initialize w/ 1st value of xvalues
    vector<int> dx = {xValues[0]};

    // fill rest values with consecutive difference
    // last value should be subtracted from width in X's case
    for (int i = 0; i < xValues.size() - 1; i++)
    {
        dx.push_back(xValues[i + 1] - xValues[i]);
    }
    dx.push_back(W - xValues[xValues.size() - 1]);

    // create vector dy and initialize w/ 1st value of yvalues
    vector<int> dy = {yValues[0]};

    // fill rest values with consecutive difference
    // last value should be subtracted from height in Y's case
    for (int i = 0; i < yValues.size() - 1; i++)
    {
        dy.push_back(yValues[i + 1] - yValues[i]);
    }
    dy.push_back(H - yValues[yValues.size() - 1]);

    // multiply (dx and dy's max values -1) together, ie answer 
    int answer = (*max_element(dx.begin(), dx.end()) - 1) * (*max_element(dy.begin(), dy.end()) - 1);
    return answer;
}

int main()
{
    vector<pair<int, int>> position = {{3, 8}, {11, 2}, {8, 6}};
    cout << defkin(15, 8, position);

    return 0;
}