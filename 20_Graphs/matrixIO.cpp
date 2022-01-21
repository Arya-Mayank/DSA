#include<iostream>
#include<vector>

using namespace std;

int main(){

    int row, col;
    cin >> row >>col;

    char grid[row][col];

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin >> grid[i][j];
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}