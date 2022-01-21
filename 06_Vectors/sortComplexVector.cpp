#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int calcTotalMarks(vector<int> v){
    return v[0] + v[1] + v[2];
}


bool compare(pair<string, vector<int>> s1, pair<string, vector<int>>s2){
    vector<int> v1 = s1.second;
    vector<int> v2 = s2.second;
    return calcTotalMarks(v1)>calcTotalMarks(v2);
}


int main(){

    vector<pair<string, vector<int>>> marks = {
        {"piyush", {10,20,21}},
        {"ashish", {11,25,9}},
        {"mayank", {13,16,19}},
        {"ishika", {9,25,17}},
        {"charvi", {21,7,19}}
    };

    sort(marks.begin(), marks.end(),compare);

    for(auto s: marks){
        cout << s.first << " " <<  calcTotalMarks(s.second) << endl;
    }

    return 0;
}