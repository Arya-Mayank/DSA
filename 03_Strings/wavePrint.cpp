#include <iostream>
#include <vector>
using namespace std;

vector<int> WavePrint(int m, int n, vector<vector<int>> arr)
{
    // your code goes here
    int startRow = 0;
    int endRow = m-1;
    int startCol = 0;
    int endCol= n-1;

    vector<int> result;

    for(int i=0;i<=endCol;i++){
        if(i%2==0){
            for(int row=startRow; row<=endRow; row++){
                // cout << arr[row][endCol -i] << " ";
                result.push_back(arr[row][endCol -i]);

            }
        }
        else{
            for(int row = endRow; row >= startRow; row--){
                // cout << arr[row][endCol-i] << " ";
                result.push_back(arr[row][endCol-i]);
            }
        }
    }
    return result;

}

int main()
{

    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}, {17,18,19,20}};
    WavePrint(5,4,arr);
    return 0;
}