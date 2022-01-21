#include <bits/stdc++.h>

using namespace std;

void permutation(string str, int i, int n)
{

    // base case:
    if (i == n)
    {
        cout << str << " ";
        return;
    }

    // rec case

    for (int j = i; j < n; j++)
    {
        swap(str[j], str[i]);
        permutation(str, i + 1, n);
        swap(str[j], str[i]);
    }
}

vector<string> subsets;

void generateSubset(string str, int i, int n, string word)
{

    // base case:
    if (i == n)
    {
        subsets.push_back(str);
        return;
    }

    // rec case:

    // ith element not in subset
    generateSubset(str, i + 1, n, word);

    // ith element in subset
    str.push_back(word[i]);
    generateSubset(str, i + 1, n, word);
    str.pop_back();
}

string empty = "";

int main()
{

    string str = "abc";

    permutation(str, 0, 3);
    cout << endl;
    generateSubset(empty, 0, 3, str);

    for (auto x : subsets)
    {
        cout <<"--> "<< x << " ";
    }

    return 0;
}