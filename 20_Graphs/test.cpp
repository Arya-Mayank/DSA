
// #include<iostream>

// using namespace std;

// int main(){
// 	int T, N, K;

// 	cin>>T;

// 	for(int i =0;i<T;i++){
// 		cin>>N>>K;

// 		int *arr;
//         arr = new int[N];

// 		for(int j=0;j<N;j++){
// 			cin>>arr[j];
// 		}

// 	int idx = N - (K%N);
// 	for(int i=idx; i<N;i++){
// 		cout << arr[i] << " ";
// 	}
// 	for(int i = 0 ;i<idx;i++){
// 		cout << arr[i] << " ";
// 	}
// 	}	
		
// 	return 0;
// }




#include<bits/stdc++.h>

using namespace std;

int main(){
	int total;
	cin >> total;

	for(int i=0;i<total;i++){
		int row, col;
		cin >> row >> col;

		char grid[row][col];
		
		int highest = 0;

		for(int i=0;i<row;i++){
			for(int j =0;j<col;j++){
				cin >> grid[i][j];
			}
		}

		for(int i=0;i<row;i++){
			int count = 0;
			for(int j =0;j<col;j++){
				if(grid[i][j] == '#'){
					count++;
				}
				
					highest = max(count,highest);
				
			}
		}

		cout << highest << endl;

	}
	return 0;
}

