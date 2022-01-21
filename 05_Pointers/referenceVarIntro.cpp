#include <iostream>

using namespace std;

int main()
{
    int x = 10;

    // Reference variable, creating an alias of x
    int &y = x;

    x++;
    y++;

    cout << x << " " << y << endl;

    return 0;
}