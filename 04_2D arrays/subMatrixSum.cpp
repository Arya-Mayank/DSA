#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> preProcess(vector<vector<int>> a, vector<vector<int>> b)
{
    for (int i = 0; i < a[0].size(); i++)
    {
        b[0][i] = a[0][i];
    }

    for (int i = 1; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            b[i][j] = a[i][j] + b[i - 1][j];
        }
    }

    for (int i = 1; i < a.size(); i++)
    {
        for (int j = 1; j < a[i].size(); j++)
        {
            b[i][j] += b[i][j-1];
        }
    }
    return b;
}

int sum(vector<vector<int>> v, int sr, int sc, int er, int ec){

    vector<vector<int>> d(v.size(), vector<int>(v[0].size()));
    vector<vector<int>> m = preProcess(v, d);

    int result = m[er][ec] - m[sr-1][ec]-m[er][sc-1] + m[sr-1][sc-1];
    
    return result;
}


int main()
{

    vector<vector<int>> v = {
        {1, 2, 3, 4, 6},
        {5, 3, 8, 1, 2},
        {4, 6, 7, 5, 5},
        {2, 4, 8, 9, 4}};

    cout << sum(v,2,2,3,4);


    // for (int i = 0; i < m.size(); i++)
    // {
    //     for (int j = 0; j < m[i].size(); j++)
    //     {
    //         cout << m[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}