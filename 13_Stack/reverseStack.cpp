#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int> &s, int data){
    if(s.empty()){
        s.push(data);
        return;
    }

    // rec case
    int temp = s.top();
    s.pop();
    insertAtBottom(s, data);
    s.push(temp);
}

void reverseStack(stack<int> &s){
    //stack empty
    if(s.empty()){
        return;
    }

    int t = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, t);
}

int main()
{   
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    reverseStack(s);

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}