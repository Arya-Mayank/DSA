#include <bits/stdc++.h>
using namespace std;
  
int binary(vector<int> v, int start, int end, int key){
    int mid = (start+end)/2;

    if(v[mid]==key){
        return mid;
    }

    if(v[mid]>key){
        return binary(v,0,mid-1,key);
    }

    return binary(v,mid+1,end,key);

}


int binarySearch(vector<int> v, int x)
{
    int n = v.size() - 1;
    int result = binary(v,0,n,x);
    return result;
}

int main(){

    vector<int> v = {1,3,5,7,9};

    cout << binarySearch(v, 9);

    return 0;
}