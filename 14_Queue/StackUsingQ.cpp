#include <iostream>
#include<stack>
#include <queue>

using namespace std;

class Stack
{
    queue<int> q1, q2;

public:
    void push(int d)
    {
        if (!q1.empty())
        {
            q1.push(d);
        }
        else
        {
            q2.push(d);
        }
    }

    void pop()
    {
        if(q1.empty()){
            while(q2.size()!=1){
                int front = q2.front();
                q2.pop();
                q1.push(front);
            }
            q2.pop();
        }else{
            while(!q1.empty()){
                int front = q1.front();
                q1.pop();
                if(q1.empty()){
                    break;
                }
                q2.push(front);
            }
        }
    }

    int top()
    {

        if (q1.empty())
        {
            while (!q2.empty())
            {
                int temp = q2.front();
                q2.pop();
                q1.push(temp);

                if(q2.empty()){
                    return temp;
                }
            }
        }
        else{
            while(!q1.empty()){
                int temp = q1.front();
                q2.push(temp);
                q1.pop();

                if(q1.empty()){
                    return temp;
                }
            }
        }
    }

    bool empty(){
        return q1.empty() and q2.empty();
    }

};

int main()
{
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    s.push(4);
    s.pop();
    s.push(8);
    s.push(12);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}