#include <bits/stdc++.h>
using namespace std;

int ways;

int canPlace(int board[][20], int N, int row, int col){

    //check column
    for(int k=0;k<row;k++){
        if(board[k][col]==1){
            return 0;
        }
    }

    //check top left diagonal
    int r =row;
    int c = col;
    while(r>=0 && c>=0){
        if(board[r][c]==1){
            return 0;
        }
        r--;
        c--;
    }

    //check top right diagonal
    r=row;
    c=col;
    while(r>=0 && c<N){
        if(board[r][c]==1){
            return 0;
        }
        r--;
        c++;
    }

    //can place
    return 1;
}

void solve(int board[][20], int n, int r){
    //base case
    //all N queens have been placed
    if(r==n){
        ways++;
        return;
    }

    //rec case
    for(int j=0;j<n;j++){
        // if safe, place queen
        if(canPlace(board,n,r,j)){
            board[r][j] =1;

            solve(board,n,r+1);

            board[r][j]=0;

        }
    }
}

int nQueen(int n){

    ways =0;    
    int board[20][20] ={0};
    solve(board,n,0);
    return ways;
}

int main(){

    cout << nQueen(4);
    return 0;
}