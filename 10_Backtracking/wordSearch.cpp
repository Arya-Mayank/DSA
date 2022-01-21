#include <bits/stdc++.h>

using namespace std;

bool ans;

void help(vector<vector<char>> &board, string word, int cx, int cy, int k)
{

    // base case
    if (word.length() == k)
    {
        ans = true;
        return;
    }

    // rec case
    //out of bounds or repeating character
    if(cx==board.size() || cy == board[0].size() || cx<0||cy<0 || board[cx][cy] =='1'){
        return;
    }

    if(board[cx][cy] == word[k]){
        char c = word[k];
        board[cx][cy] = '1';
        help(board,word,cx,cy+1,k+1);
        help(board,word,cx+1,cy,k+1);
        help(board,word,cx-1,cy,k+1);
        help(board,word,cx,cy-1,k+1);
        //backtrack
        board[cx][cy] = c;
    }
    return;


}

bool wordSearch(vector<vector<char>> &board, string word)
{
    ans = false;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == word[0])
            {
                help(board, word, i, j, 0);
            }
        }
    }

    return ans;
}

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};

    string word = "ABCCED";

    cout << wordSearch(board, word);

    return 0;
}