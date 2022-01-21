#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(string str)
{

    int length = str.length();
    bool isPalindrome = true;

    for (int i = 0; i < length / 2; i++)
    {
        if (str[i] != str[length - i - 1])
        {
            isPalindrome = false;
            break;
        }
    }
    return isPalindrome;
}

int main()
{
    // bool ans;
    string word;
    cin >> word;

    cout << isPalindrome(word);
    // cout << length/2;

    return 0;
}