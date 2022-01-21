#include<iostream>
#include "StackVector.h"

using namespace std;

int main(){

    Stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    s.pop();

    while(!s.isempty()){
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}