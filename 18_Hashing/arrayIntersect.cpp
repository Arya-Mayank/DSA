#include <bits/stdc++.h>

using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    map<int, int> mp;

    for (int a : nums1)
    {
        for (int b : nums2)
        {
            if (a == b)
            {
                if (mp[a] == 0)
                {
                    mp[a]++;
                    break;
                }
            }
        }
    }

    for(auto it: mp){
        ans.push_back(it.first);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{

    vector<int> a = {1, 2, 2, 1,5,1,5,2,4,9};
    vector<int> b = {2, 2,9,2,5,};
    vector<int> sol = intersection(a, b);
    for(auto i: sol){
        cout << i << " ";
    }
    return 0;
}