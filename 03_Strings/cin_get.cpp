#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<char> sentence;

    char temp = cin.get();

    int length = 0;
    int alpha = 0;
    int spaces = 0;
    int digits = 0;

    while (temp != '#')
    {
        if (temp == '\n')
        {
            sentence.push_back(' ');
        }
        else
        {
            sentence.push_back(temp);
        }

        length++;
        temp = cin.get();
    }

    for (auto x : sentence)
    {
        if(x>='a' and x<='z' or x>='A' and x<='Z'){
            alpha++;
        }
        else if(x == ' '){
            spaces++;
        }
        else digits++;
    }

    cout << "alpha: " << alpha << " spaces: " << spaces << " digits: " << digits << endl;
    return 0;
}