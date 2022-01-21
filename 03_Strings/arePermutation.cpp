#include <iostream>
#include <string>

using namespace std;

bool arePermutation(string A, string B)
{
    string C;
    for (int i = 0; i < A.length(); i++)
    {
        if (!B.empty())
        {
            for (int j = 0; j < B.length(); j++)
            {
                if (A[i] == B[j])
                {
                    C+=B[j];
                    break;
                }
            }
        }
    }
    
    if(A==C){
        return true;
    }else return false;
}

int main()
{

    string s1 = "test";
    string s2 = "tewt";

    cout << arePermutation(s1, s2);

    return 0;
}