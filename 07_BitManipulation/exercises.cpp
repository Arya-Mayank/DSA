// #include<bits/stdc++.h>
// using namespace std;

// int xoring(vector<int> v)
// {
//     sort(v.begin(), v.end());

//     for(int i=0;i<v.size();i+=2){
//         if((v[i]^v[i+1]) != 0){
//             return v[i];
//         }
//     }

//     return v[v.size()-1];

// }

// int main(){

//    vector<int> arr = {1,2,3,1,4,3,2};

//    cout << xoring(arr) << endl;

//     return 0;
// }

// #include <iostream>
// using namespace std;

// int power(int x, int y, int mod)
// {
//     // your code goes here
//     int ans = 1;
//     while (y > 0)
//     {
//         int lastBit = y & 1;
//         if (lastBit)
//         {
//             ans *= x;
//         }
//         x = x * x;
//         y = y >> 1;
//     }
//     return ans;
// }

// int main()
// {
//     int m = 2;
//     int n = 5;
//     cout << power(m, n, 1007);
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int earthLevel(int k)
{
    //your code goes here
    // int ans =0;
    // int res = pow(2,ans);
    // while(k>res){
    //     ans++;
    //     k=k>>1;
    //     res = pow(2,ans);
    // }
    // return ans;

    int ans = ((k^2)/2)+1;
    return ans;
}

int main(){

    cout << earthLevel(2);
    return 0;
}