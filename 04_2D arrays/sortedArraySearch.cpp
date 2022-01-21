#include <iostream>
#include<vector>
using namespace std;

pair<int, int> find(int arr[4][4], int r, int c, int key){
    int startRow = 0;
    int startCol = c-1;

    while(startRow<r and startCol>=0){
        if(arr[startRow][startCol] == key){
            return {startRow,startCol};
        }
        if(arr[startRow][startCol] > key){
            startCol--; 
        }
        else{
            startRow++;
        }
    }
    return {-1,-1};
}

int main()
{
    int arr[4][4] = {
                        {10,20,30,40},
                        {15,25,35,45},
                        {27,29,37,48},
                        {32,33,39,50}
                        };
    
    pair<int,int> pair1 = find(arr,4,4,29);
    cout << pair1.first;
    cout << pair1.second;

    return 0;
}