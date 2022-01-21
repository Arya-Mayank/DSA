// #include<bits/stdc++.h>
// #include<vector>
// using namespace std;

// int largestElement(vector<int> arr) {
//     int n = arr.size();
//     int highest = 0;
//     for(int i=0;i<n;i++){
//         if(arr[i]>highest){
//             highest = arr[i];
//         }
//     }
//     return highest;

// }

// int main(){

//     vector<int> arr = {2,5,12,44,1,7,25};

//     cout << largestElement(arr);

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// int maxSumSubarray(vector<int> A) {
//     int n = A.size();
//     int cs=0;
//     int highest=0;
//     for(int i=0;i<n;i++){
//         cs = cs+A[i];
//         if(cs<0){
//             cs=0;
//         }else highest = max(highest, cs);
//     }
//    return highest;
// }

// int main(){

//     vector<int> arr = {2,5,6,-12,5,-3,8,2,-3};

//     cout << maxSumSubarray(arr);

//     return 0;
// }

// #include<iostream>
// #include<vector>

// using namespace std;

// int lowerBound(vector<int> A, int Val){
//     int n = A.size();
//     int start=0;
//     int end = n-1;

//     if(Val!=0){
//         while(start<end){
//             int mid = (start + end)/2;
//             if(A[mid] == Val){
//                 return A[mid];
//             }
//             else if(A[mid]>Val){
//                 end = mid-1;
//             }else start = mid +1;

//             if(start==end){
//                 return A[start];
//             }
//         }
//     }else{
//         int lb = A[0];
//         for(int i=0;i<n;i++){
//             if(A[i]<Val){
//                 lb = max(lb,A[i]);
//             }
//         }
//         return lb;
//     }
// }

// int main(){

//     vector<int> A = {-5,-3,-2,-1,0,1};
//     int Val = 0;

//     cout << lowerBound(A,Val);

//     return 0;
// }

// #include<iostream>
// #include <bits/stdc++.h>
// using namespace std;

// pair<int,int> closestSum(vector<int>A , int x){
//     int res_r, res_l;
//     pair<int,int> pair1;
//     int n=A.size();
//     int l=0,r=n-1,diff = INT_MAX;

//     while(r>l){
//         if(abs(A[l] + A[r] - x) < diff){
//             res_l = l;
//             res_r=r;
//             diff = abs(A[l] + A[r] -x);
//         }

//         if(A[l] + A[r] > x){
//             r--;
//         }
//         else l++;
//     }
//     pair1.first = A[res_l];
//     pair1.second = A[res_r];
//     cout << pair1.first << " and " << pair1.second;
// }

// int main(){

//     vector<int> A = {10, 22, 28, 29, 30, 40};
//     int x = 54;

//     closestSum(A, x);
//     return 0;
// }

#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

vector<int> kRotate(vector<int> a, int k)
{
    // your code  goes here
    vector<int> arr;

    for(int i=0;i<a.size();i++){
        if(i<k){
            arr.push_back(a[a.size()+i-k]);
        }
        else arr.push_back(a[i-k]);
    }

    return arr;
}

int main()
{
    vector<int> a = {1, 3, 5, 7, 9};
    int k = 2;

    vector<int> m = kRotate(a, k);
 
    for (int i = 0; i < m.size(); i++)
    {
        cout << m[i] << " ";
    }

    return 0;
}