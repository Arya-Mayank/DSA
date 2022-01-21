#include <iostream>
using namespace std;

int countMangoes(int arr[6][6], int row, int col)
{
    int count =0;
    for (int i = 0; i <= row; i++)
    {
        for (int j = 0; j <= col; j++)
        {
            if(arr[i][j] == '#'){
                count ++; 
            }
        }
    }
    return count;
}

void calcuate(int arr[6][6], int row, int col)
{
    int topLeftMangoes = 0;
    int topRightMangoes = 0;
    int bottomLeftMangoes = 0;
    int bottomRightMangoes = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            topLeftMangoes = countMangoes(arr, i,j);
            topRightMangoes = countMangoes(arr,6,i) - countMangoes(arr, i,j);
        }
      
    }
    cout << topLeftMangoes << endl;
    cout << topRightMangoes;
}

int main()
{

    int arr[6][6] = {{'.', '#', '#', '.', '.', '.'},
                     {'#', '.', '.', '#', '#', '.'},
                     {'.', '#', '.', '.', '.', '.'},
                     {'.', '#', '#', '.', '.', '#'},
                     {'#', '.', '.', '#', '#', '.'},
                     {'.', '#', '.', '.', '.', '.'}};

    calcuate(arr,2,3);
    return 0;
}
