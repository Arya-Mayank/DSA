#include <bits/stdc++.h>
using namespace std;


queue<int> interLeave(queue<int> &q)
{   
    queue<int> sol;
    int size = q.size();
    int half = q.size() / 2;
    queue<int> s;

    for (int i = 0; i < half; i++)
    {
        int front = q.front();
        
        s.push(front);
        q.pop();
    }


    for(int i=0;i<half;i++){
        sol.push(s.front());
        s.pop();
        sol.push(q.front());
        q.pop();
    }

    queue<int> ans;
    for(int i =0;i<size;i++){
        ans.push(sol.front());
        sol.pop();
    }
    return ans;
}

int main()
{

    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);

    queue<int> ans = interLeave(q);

    while(!ans.empty()){
        cout << ans.front() << " ";
        ans.pop();
    }

    return 0;
}