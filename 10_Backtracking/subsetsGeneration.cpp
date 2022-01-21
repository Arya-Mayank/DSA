#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> subsets;

void generateSubset(vector<int> &subset, int i, vector<int> elements)
{

    // base case
    if (i == elements.size())
    {
        if (subset.size() == 0)
        {
            // null case
            subsets.push_back({0});
        }
        else
        {
            subsets.push_back(subset);
        }
        return;
    }

    // rec case

    // ith element not in subset
    generateSubset(subset, i + 1, elements);

    // ith element in subset
    subset.push_back(elements[i]);
    generateSubset(subset, i + 1, elements);
    subset.pop_back();
}

bool compare(vector<int> a, vector<int> b)
{
    if (a.size() == b.size())
    {
        return a < b;
    }
    return a.size() < b.size();
}

int main()
{

    vector<int> elements = {1, 2, 3};
    vector<int> empty;
    generateSubset(empty, 0, elements);

    sort(subsets.begin(), subsets.end(), compare);

    for (auto x : subsets)
    {
        for (auto m : x)
        {
            cout << m << ",";
        }
        cout << endl;
    }
    return 0;
}