#include <bits/stdc++.h>

using namespace std;

bool isSafe(int board[][9], int i, int j, int no){

    //check row and column
    for(int k=0;k<9;k++){
        if(board[i][k] == no or board[k][j] == no){
            return false;
        }
    }

    //check subgrid
    int sx = (i/3) *3;
    int sy = (j/3) *3;

    for(int x=sx;x<sx+3;x++){
        for(int y = sy;y<sy+3;y++){
            if(board[x][y] == no){
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int board[][9], int i, int j, int n){
    //base case 
        // all rows completed
    if(i==n){
		//print the solution 
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}

		return true;
	}

    //rec case
        //repeat after every row is complete || columns over
    if(j==n){
        return solveSudoku(board, i+1, 0,n);
    }

        //skip prefilled cells
    if(board[i][j] != 0){
        return solveSudoku(board, i, j+1, n);
    }

    //cells to be filled
        // from 1 to 9
    for(int no=1;no<=n;no++){
        //check whether no can be placed or not
        if(isSafe(board, i,j, no)){
            board[i][j] = no;
            bool subProblem = solveSudoku(board, i,j+1,n);
            if(subProblem == true){
                return true;
            }
        }
    }

    //if no solution existed, backtrack
    board[i][j] = 0;
    return false;
}

int main()
{

    int board[9][9] =
        {{5, 3, 0, 0, 7, 0, 0, 0, 0},
         {6, 0, 0, 1, 9, 5, 0, 0, 0},
         {0, 9, 8, 0, 0, 0, 0, 6, 0},
         {8, 0, 0, 0, 6, 0, 0, 0, 3},
         {4, 0, 0, 8, 0, 3, 0, 0, 1},
         {7, 0, 0, 0, 2, 0, 0, 0, 6},
         {0, 6, 0, 0, 0, 0, 2, 8, 0},
         {0, 0, 0, 4, 1, 9, 0, 0, 5},
         {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    solveSudoku(board,0,0,8);

    if(!solveSudoku(board,0,0,9)){
        	cout<<"No solution exists!";
        }

    return 0;
}