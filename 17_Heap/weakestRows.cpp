#include <bits/stdc++.h>

using namespace std;

class Row
{
public:
    int rowNo;
    int soldierNo;

    Row(int rowNo, int soldierNo){
        this->rowNo = rowNo;
        this->soldierNo = soldierNo;
    }
    
};

class RowCompare{
    public:
    bool operator()(Row A, Row B){
        if(A.soldierNo > B.soldierNo){
            return true;
        }
        else if(A.soldierNo < B.soldierNo){
            return false;
        }
        else{
            return A.rowNo > B.rowNo;
        }
    }
};

vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    int m = mat.size();
    int n = mat[0].size();

    priority_queue<Row, vector<Row>, RowCompare> pq;

    for (int i = 0; i < m; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if(mat[i][j] == 1){
                count++;
            }
        }

        Row r(i, count);
        pq.push(r);

    }

    vector<int> sol;

    // while(!pq.empty()){
    //     cout<< pq.top().rowNo << " " << pq.top().soldierNo << endl;
    //     pq.pop();
    // }

    for(int i=0;i<k;i++){
        sol.push_back(pq.top().rowNo);
        pq.pop();
    }

    return sol;
    
}

int main()
{
    vector<vector<int>> mat = {{1, 0, 0, 0},
                               {1, 1, 1, 1},
                               {1, 0, 0, 0},
                               {1, 0, 0, 0}};

    vector<int> ans = kWeakestRows(mat, 3);

    for(int x: ans){
        cout << x << " ";
    }
}