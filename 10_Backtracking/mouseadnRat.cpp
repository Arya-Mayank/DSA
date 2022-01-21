#include <bits/stdc++.h>
using namespace std;



void solveRAM(vector<string> arr, int totalRow, int totalCol, int currentRow, int currentCol)
{
    // base case
    if (currentRow == totalRow-1 && currentCol == totalCol-1)
    {
        for(int i=0;i<=totalRow;i++){
            for(int j=0;j<totalCol;j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }

    // rec case
    // move right
    if (currentCol<totalCol-1 && arr[currentRow][currentCol+1]!='X' && arr[currentRow][currentCol+1]!='1')
    {
        arr[currentRow][currentCol + 1] = '1';
        solveRAM(arr, totalRow, totalCol, currentRow, currentCol+1);
        arr[currentRow][currentCol + 1] = 'O';
    }

    //move down
    if(currentRow<totalRow-1 && arr[currentRow+1][currentCol]!='X' && arr[currentRow+1][currentCol]!='1'){
        arr[currentRow+1][currentCol] = '1';
        solveRAM(arr,totalRow, totalCol, currentRow+1, currentCol);
        arr[currentRow+1][currentCol] = 'O';
    }

    //move left
    if(currentCol >0 && arr[currentRow][currentCol-1]!='X' && arr[currentRow][currentCol-1]!='1'){
        arr[currentRow][currentCol-1] = '1';
        solveRAM(arr, totalRow, totalCol, currentRow, currentCol-1);
        arr[currentRow][currentCol-1] = 'O';
    }

    //move up
    if(currentRow>0 && arr[currentRow-1][currentCol]!='X' && arr[currentRow-1][currentCol]!='1' ){
        arr[currentRow-1][currentCol]='1';
        solveRAM(arr, totalRow, totalCol, currentRow-1, currentCol);
        arr[currentRow-1][currentCol]='O';
    }

    return;
}

vector<vector<int>> ratAndMice(vector<string> arr)
{

    int totalRow = arr.size();
    int totalCol = arr[0].size();
    arr[0][0] = '1';

    solveRAM(arr,totalRow, totalCol, 0,0);
}

int main()
{
    vector<string> solution;
    vector<string> arr = {"OOXO", "XOOO", "OOXX", "OXXX", "OOOO"};
    ratAndMice(arr);

    return 0;
}