#include <iostream>
#include <string>
using namespace std;

void RLE(string str)
{
    int n = str.length();
    string output;
    for(int i =0;i<n;i++){
        int count =1;
        // cout << "current: " << str[i]  << i<< endl;
        while(i<n-1 and str[i]== str[i+1]){
            count++;
            i++;
        }
        output += str[i];
        if(count!=1){
            output += to_string(count);
        }
        
    }
    cout << output << endl;
}

int main()
{

    string s1 = "abcccdeeee ";
    RLE(s1);
    return 0;
}