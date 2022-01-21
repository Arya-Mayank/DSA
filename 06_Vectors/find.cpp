#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int>::iterator itr;

    itr = find(v.begin(), v.end(), 8);

    if (itr != v.end())
    {
        cout << "Element present at: " << itr - v.begin() << endl;
    }
    else
    {
        cout << "Element not present" << endl;
    }

    return 0;
}