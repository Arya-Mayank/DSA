// #include <iostream>

// using namespace std;

// int main()
// {
//     char paragraph[1000];
//     cin.getline(paragraph,1000,'#'); //terminate at #
//     // if the third parameter isn't given, it stops at newline
//     cout << paragraph << endl;
//     return 0;
// }

// ************************************************************************************************

// Practice Problem

#include <iostream>
using namespace std;

int main()
{

    char sentence[20];
    cin.getline(sentence, 20);
    int x = 0;
    int y = 0;

    for (auto i : sentence)
    {
        if (i == 'S')
        {
            x--;
        }
        else if (i == 'N')
        {
            x++;
        }
        else if (i == 'E')
        {
            y++;
        }
        else if (i == 'W')
        {
            y--;
        }
    }

    if(x==0 and y==0){
        cout<<"Final position same as starting position";
    }

    if (x > 0)
    {
        for (int i = 0; i < x; i++)
        {
            cout << 'N';
        }
    }
    else

        for (int i = 0; i > x; i--)
        {
            cout << 'S';
        }

    if (y > 0)
    {
        for (int i = 0; i < y; i++)
        {
            cout << 'E';
        }
    }
    else

        for (int i = 0; i > y; i--)
        {
            cout << 'W';
        }

    return 0;
}